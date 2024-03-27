#ifndef _COMPAT_ENDIAN_H_
#define _COMPAT_ENDIAN_H_

#if defined(__GLIBC__) || defined(__BIONIC__) || defined(__CYGWIN__)
 #include <endian.h>
#elif defined(__APPLE__)
  // Mac OS X / Darwin features
 #include <libkern/OSByteOrder.h>
 // Make sure that byte swap functions are not already defined.
 #if !defined(htole64)
  #define htole64(x) OSSwapHostToLittleConstInt64(x)
 #endif
 #if !defined(le64toh)
  #define le64toh(x) OSSwapLittleToHostConstInt64(x)
 #endif
 #if !defined(htole32)
  #define htole32(x) OSSwapHostToLittleConstInt32(x)
 #endif
 #if !defined(le32toh)
  #define le32toh(x) OSSwapLittleToHostConstInt32(x)
 #endif
 #if !defined(htole16)
  #define htole16(x) OSSwapHostToLittleConstInt16(x)
 #endif
 #if !defined(le16toh)
  #define le16toh(x) OSSwapLittleToHostConstInt16(x)
 #endif
#endif

#endif