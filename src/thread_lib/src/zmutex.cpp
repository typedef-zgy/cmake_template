/*
 * zmutex.cpp
 *
 *  Created on: 五 12/20 19:49:37 2019
 *      Author: zhangguangyu
 */

#include "zmutex.h"
#include <pthread.h>
#include <string>
#include <sstream>
#include "utils/utils.h"
#include "utils/zexception.h"
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>

#define SYS_ERR_THROW(_CALLSTR, _RET) \
       std::stringstream ss;\
       ss << _CALLSTR << " returned "<< ret << ":" << ::strerror(ret);\
       throw utils::ZException(ss.str());

//看文档说lock函数不会返回EINTR,但是看boost在try
//lock时,做了判断,thrift库都做了判断
#define EINTR_LOOP(_CALL)\
    int ret;\
    do {\
        ret = _CALL;\
    }while(EINTR == ret);\

#define THROW_ONFAIL(_CALL) \
    {\
        EINTR_LOOP(_CALL);\
        if ( 0 != ret ) {\
            SYS_ERR_THROW(#_CALL, ret);\
        }\
    }
#define THROW_TRYFAIL(_CALL) \
    {\
        EINTR_LOOP(_CALL);\
        if(0 == ret) {\
            return true;\
        } else if (EBUSY == ret) {\
            return false;\
        }\
        SYS_ERR_THROW(#_CALL, ret);\
    }

#define THROW_TIMEDFAIL(_CALL) \
    {\
        EINTR_LOOP(_CALL);\
        if(0 == ret) {\
            return true;\
        } else if (ETIMEDOUT == ret) {\
            return false;\
        }\
        SYS_ERR_THROW(#_CALL, ret);\
    }

namespace zlib {
namespace zthread {

class ZMutex::Impl {
public:
     Impl() {
         defautl_init(&_handle);
     }

     ~Impl() {
         int ret = pthread_mutex_destroy(&_handle);
         if(ret) {
             abort();
         }
     }

     void lock() const {
         THROW_ONFAIL(pthread_mutex_lock(&_handle));
     }

     bool try_lock() const {
         THROW_TRYFAIL(pthread_mutex_trylock(&_handle));
     }

     bool timed_lock(int64_t ms) const {
         struct timespec ts;
         utils::Utils::ms2TimeSpec(ts, ms);
#if defined(_POSIX_TIMEOUTS) && _POSIX_TIMEOUTS >= 200112L
         THROW_TIMEDFAIL(pthread_mutex_timedlock(&_handle, &ts));
#else
         return false;
#endif
     }

     void unlock() const {
         THROW_ONFAIL(pthread_mutex_unlock(&_handle));
     }

     void* native_handle() const {
         return static_cast<void*>(&_handle);
     }
private:
    static void defautl_init(void *arg_) {
        pthread_mutex_t* handle = (pthread_mutex_t*)arg_;
        THROW_ONFAIL(pthread_mutex_init(handle, NULL));
    }
private:
    mutable pthread_mutex_t _handle;
};

ZMutex::ZMutex() : _impl(NULL) {
    _impl = new Impl();
}

ZMutex::~ZMutex() {
    if(NULL != _impl) {
        delete _impl;
    }
}

void ZMutex::lock() const {
    _impl->lock();
}

bool ZMutex::try_lock() const {
    return _impl->try_lock();
}

bool ZMutex::timed_lock(int64_t ms) const {
    return _impl->timed_lock(ms);
}

void ZMutex::unlock() const {
    _impl->unlock();
}

void* ZMutex::native_handle() const {
    return _impl->native_handle();
}

}
}
