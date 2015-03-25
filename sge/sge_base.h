//
//  Created by Yordan on 17/3/15.
//
//

#ifndef __SGE_BASE_H__
#define __SGE_BASE_H__


// ========================
// Namespace
// ========================
#define SGE_NS_BEGIN namespace sge {
#define SGE_NS_END }
#define SGE_NS_USING using namespace sge


// ========================
// Logging
// ========================
SGE_NS_BEGIN;
void loge(const char *fmt, ...);

// ========================
// Data structures
// ========================
class Vec3
{
public:
    Vec3(double x=0, double y=0, double z=0);
    Vec3(const Vec3& other);
    virtual ~Vec3();
    Vec3& operator=(const Vec3& other);

private:
    double x_, y_, z_;
};


SGE_NS_END;
#endif // __SGE_BASEH_H__
