//
//  Created by Yordan on 3/18/15.
//
//

#include <cstdarg>
#include <cstdio>

#include "sge_base.h"
SGE_NS_USING;


void loge(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "[SGE ERROR] ");
    fprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}


Vec3::Vec3(double xx, double yy, double zz)
: x(xx)
, y(yy)
, z(zz)
{
}


Vec3::~Vec3()
{
}