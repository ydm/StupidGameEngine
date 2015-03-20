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
    virtual ~Vec3();
    const double x, y, z;
};

SGE_NS_END;
#endif // __SGE_BASEH_H__
