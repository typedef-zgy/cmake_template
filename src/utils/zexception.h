/*
 * zexception.h
 *
 *  Created on: 一 12/23 23:27:40 2019
 *      Author: zhangguangyu
 */

#ifndef ZEXCEPTION_H_
#define ZEXCEPTION_H_

#include <exception>

namespace zlib {
namespace utils{

class ZException : public std::exception {
public:
    ZException() {}
    ZException(const std::string& msg_) : _msg(msg_) {}
    virtual ~ZException() throw() {}

    virtual const char* what() const throw() {
        if(_msg.empty()) {
            return "default exception";
        } else {
            return _msg.c_str();
        }
    }
private:
    std::string _msg;
};

}
}


#endif  // ZEXCEPTION_H_
