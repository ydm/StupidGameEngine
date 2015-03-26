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

    std::ostrstream s;
    s << std::this_thread::get_id();
    const std::string name(s.str());

    try {
        names.at(name);
    } catch (std::out_of_range) {
        std::ostrstream t;
        t << nextThread;
        names[name] = std::string(t.str());
    }
    return names[name];
}


// ========================
// Logging
// ========================
static void log(const char *prefix, const char *fmt, ...)
{
    static std::mutex g_logMutex;

    // ydm: It's stupid, but I can't think of another reliable way to print this thread's ID
    std::ostrstream p;
    p << "[" << prefix << "/" << thisThreadsName() << "] ";

    va_list args;
    va_start(args, fmt);

    g_logMutex.lock();
    fprintf(stderr, "%s", p.str());
    fprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    g_logMutex.unlock();

    va_end(args);
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