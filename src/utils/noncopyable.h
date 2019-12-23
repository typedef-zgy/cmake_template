/*
 * noncopyable.h
 *
 *  Created on: 五 12/20 16:15:14 2019
 *      Author: zhangguangyu
 */

#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

namespace zlib {
namespace utils {

class Noncopyable {
protected:
    Noncopyable(){}
    ~Noncopyable(){}
private:
    Noncopyable(const Noncopyable&);
    Noncopyable& operator=(const Noncopyable&);
};

}
}
#endif  // NONCOPYABLE_H_
