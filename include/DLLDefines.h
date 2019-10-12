#ifndef _Chronos_DLLDEFINES_H_
#define _Chronos_DLLDEFINES_H_

#if defined (_WIN32)
#if defined(Chronos_EXPORT)
#define  CHRONOS_EXPORT __declspec(dllexport)
#else
#define  CHRONOS_EXPORT __declspec(dllimport)
#endif
#else
#define CHRONOS_EXPORT
#endif

#endif
