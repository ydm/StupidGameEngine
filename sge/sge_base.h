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

namespace sge
{
  void loge(const char *fmt, ...);
}

#endif // __SGE_BASEH_H__
