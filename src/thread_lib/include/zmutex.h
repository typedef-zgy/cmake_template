/*
 * zmutex.h
 *
 *  Created on: 五 12/20 15:12:26 2019
 *      Author: zhangguangyu
 */

#ifndef ZMUTEX_H_
#define ZMUTEX_H_

#include "utils/noncopyable.h"
#include <stdint.h>
#include <stddef.h>

namespace zlib {
namespace zthread {

class ZMutex : public utils::Noncopyable {
public:
    ZMutex();
    virtual ~ZMutex();

    virtual void lock() const;
    virtual bool try_lock() const;
    virtual bool timed_lock(int64_t ms) const;

    virtual void unlock() const;

    void* native_handle() const;
private:
    class Impl;
    Impl *_impl;
};

class ZLockGuard : public utils::Noncopyable {
public:
    ZLockGuard(const ZMutex& mutex_, int64_t timeout_)
        : _mutex(&mutex_) {
            if(0 == timeout_) {
                mutex_.lock();
            } else if (timeout_ < 0) {
                if(!mutex_.try_lock()) {
                    _mutex = NULL;
                }
            } else {
                if(!mutex_.timed_lock(timeout_)) {
                    _mutex = NULL;
                }
            }
        }

    ~ZLockGuard() {
        if(NULL != _mutex) {
            _mutex->unlock();
        }
    }
private:
    const ZMutex* _mutex;
};

}
}
#endif  // ZMUTEX_H_
