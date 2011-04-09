#ifndef COE_GLOBAL_H
#define COE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COE_LIBRARY)
#  define COESHARED_EXPORT Q_DECL_EXPORT
#else
#  define COESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // COE_GLOBAL_H
