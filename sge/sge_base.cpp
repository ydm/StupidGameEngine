//
//  Created by Yordan on 3/18/15.
//
//

#include <cstdarg>
#include <cstdio>

#include "sge_base.h"
SGE_NS_BEGIN;


// ========================
// Logging
// ========================
void loge(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "[SGE ERROR] ");
    fprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}


// ========================
// Vec3
// ========================
Vec3::Vec3(double x, double y, double z)
: x_(x)
, y_(y)
, z_(z)
{
}


Vec3::Vec3(const Vec3& other)
: x_(other.x_)
, y_(other.y_)
, z_(other.z_)
{
}


Vec3::~Vec3()
{
}


Vec3&
Vec3::operator=(const Vec3 &other)
{
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;
    return *this;
}


SGE_NS_END;