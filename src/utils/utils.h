/*
 * utils.h
 *
 *  Created on: 日 12/22 23:01:14 2019
 *      Author: zhangguangyu
 */

#ifndef UTILS_H_
#define UTILS_H_
#include <time.h>

namespace zlib {
namespace utils {

class Utils {
    static const int64_t NS_PER_S = 1000000000LL;
    static const int64_t US_PER_S = 1000000LL;
    static const int64_t MS_PER_S = 1000LL;

    static const int64_t NS_PER_MS = NS_PER_S / MS_PER_S;
    static const int64_t NS_PER_US = NS_PER_S / US_PER_S;
    static const int64_t US_PER_MS = US_PER_S / MS_PER_S;
public:
    static void ms2TimeSpec(struct timespec& ts, uint64_t ms) {
        ts.tv_sec = ms / MS_PER_S;
        ts.tv_nsec = (ms % MS_PER_S) * NS_PER_MS;
    }
};

}
}
#endif  // UTILS_H_
