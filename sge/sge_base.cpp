//
//  Created by Yordan on 3/18/15.
//
//

#include <cstdarg>      // log()
#include <cstdio>       // log()
#include <strstream>    // log()
#include <thread>       // log()
#include "sge_base.h"
SGE_NS_BEGIN;


static const std::string& thisThreadsName()
{
    static std::map<std::string, std::string> names;
    static int nextThread = 1;

    std::ostringstream idStream;
    idStream << std::this_thread::get_id();
    const std::string idString(idStream.str());

    if(names.count(idString) == 0)
    {
        std::ostringstream nameStream;
        nameStream << nextThread++;
        names[idString] = nameStream.str();
    }

    return names[idString];
}


// ========================
// Logging
// ========================
// Use correct parameters http://goo.gl/Cxl40S
static void log(const char *prefix, const char *fmt, va_list& args)
{
    static std::mutex m;

    std::ostringstream p;
    p << "[" << prefix << "/" << thisThreadsName() << "] ";

    m.lock();
    fprintf(stderr, "%s", p.str().c_str());
    vfprintf (stderr, fmt, args);
    fprintf(stderr, "\n");
    m.unlock();
}


void logi(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log("INFO", fmt, args);
    va_end(args);
}


void logd(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log("DEBUG", fmt, args);
    va_end(args);
}


void logw(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log("WARNING", fmt, args);
    va_end(args);
}


void loge(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log("ERROR", fmt, args);
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


double Vec3::getX() const {return x_;}
double Vec3::getY() const {return y_;}
double Vec3::getZ() const {return z_;}


SGE_NS_END;