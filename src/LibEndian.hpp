/**
 * \file LibEndian.hpp
 * \brief Common define for the library
 */
#ifndef __LIB_ENDIAN_HPP__
#define __LIB_ENDIAN_HPP__

// ─────────────────────────────────────────────────────────────
//                  INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header
#include <stdint.h>

// C++ Header

// Dependencies Header

// Application Header

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

#ifdef WIN32
    #ifdef LIBENDIAN_SHARED
/** Class decorator to handle dynamic linkage in windows */
        #define LIBENDIAN_API_ __declspec(dllexport)
    #elif LIBENDIAN_STATIC
/** Class decorator to handle dynamic linkage in windows */
        #define LIBENDIAN_API_
    #else
/** Class decorator to handle dynamic linkage in windows */
        #define LIBENDIAN_API_ __declspec(dllimport)
    #endif
#else
/** Class decorator to handle dynamic linkage in windows */
    #define LIBENDIAN_API_
#endif

/** Set by build system. Define if a namespace should be used */
#ifdef LIBENDIAN_USE_NAMESPACE
#ifndef LIBENDIAN_NAMESPACE
/** Name of then namespace. By default Endn. Using this macro give the same result no matters if the library is compiled with or without a namespace */
#define LIBENDIAN_NAMESPACE Endn
#endif
/** Start of the namespace declaratio. Using this macro give the same result no matters if the library is compiled with or without a namespace */
#define LIBENDIAN_NAMESPACE_START namespace LIBENDIAN_NAMESPACE {
/** End of the namespace declaration. Using this macro give the same result no matters if the library is compiled with or without a namespace */
#define LIBENDIAN_NAMESPACE_END }
/** Use the namespace. Using this macro give the same result no matters if the library is compiled with or without a namespace */
#define LIBENDIAN_USING_NAMESPACE using namespace LIBENDIAN_NAMESPACE;
#else
#undef LIBENDIAN_NAMESPACE
#define LIBENDIAN_NAMESPACE
/** Start of the namespace declaratio. Using this macro give the same result no matters if the library is compiled with or without a namespace */
#define LIBENDIAN_NAMESPACE_START
/** End of the namespace declaration. Using this macro give the same result no matters if the library is compiled with or without a namespace */
#define LIBENDIAN_NAMESPACE_END
/** Use the namespace. Using this macro give the same result no matters if the library is compiled with or without a namespace */
#define LIBENDIAN_USING_NAMESPACE
#endif

LIBENDIAN_NAMESPACE_START

// ─────────────────────────────────────────────────────────────
//                  CLASS
// ─────────────────────────────────────────────────────────────

/** Define common variable size */
class LIBENDIAN_API_ LibEndian
{
    // ────── SIZE ──────────────────────────────────────────────────────
public:
    virtual ~LibEndian() = default;
    /** Size of uint8_t variable (1 byte) */
    static const uint8_t UINT8_SIZE = 1;
    /** Size of uint16_t variable (2 bytes) */
    static const uint8_t UINT16_SIZE = 2;
    /** Size of uint32_t variable (4 bytes) */
    static const uint8_t UINT32_SIZE = 4;
    /** Size of uint48_t variable (6 bytes) */
    static const uint8_t UINT48_SIZE = 6;
    /** Size of uint64_t variable (8 bytes) */
    static const uint8_t UINT64_SIZE = 8;

    /** Size of int8_t variable (1 byte) */
    static const uint8_t INT8_SIZE = 1;
    /** Size of int16_t variable (2 bytes) */
    static const uint8_t INT16_SIZE = 2;
    /** Size of int32_t variable (4 bytes) */
    static const uint8_t INT32_SIZE = 4;
    /** Size of int48_t variable (6 bytes) */
    static const uint8_t INT48_SIZE = 6;
    /** Size of int64_t variable (8 bytes) */
    static const uint8_t INT64_SIZE = 8;

    /** Size of float variable (6 bytes) */
    static const uint8_t FLOAT32_SIZE = 4;
    /** Size of double variable (8 bytes) */
    static const uint8_t FLOAT64_SIZE = 8;

    static bool IS_16_ALIGNED(const uintptr_t ptr) { return ptr % 2 == 0; }
    static bool IS_32_ALIGNED(const uintptr_t ptr) { return ptr % 4 == 0; }
    static bool IS_64_ALIGNED(const uintptr_t ptr) { return ptr % 8 == 0; }

    static bool IS_16_ALIGNED(const uint8_t* ptr) { return IS_16_ALIGNED(uintptr_t(ptr)); }
    static bool IS_32_ALIGNED(const uint8_t* ptr) { return IS_32_ALIGNED(uintptr_t(ptr)); }
    static bool IS_64_ALIGNED(const uint8_t* ptr) { return IS_64_ALIGNED(uintptr_t(ptr)); }
};

/** Get the version of the library */
class LIBENDIAN_API_ Version
{
public:
    /** Library Major Version */
    static uint32_t getMajor();
    /** Library Minor Version */
    static uint32_t getMinor();
    /** Library Patch Version */
    static uint32_t getPatch();
    /** Library Tag Version */
    static uint32_t getTag();
};

LIBENDIAN_NAMESPACE_END

#endif
