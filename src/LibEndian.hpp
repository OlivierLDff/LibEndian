/** 
 * \file LibEndian.hpp
 * \brief Common define for the library
 */
#ifndef __LIB_ENDIAN_HPP__
#define __LIB_ENDIAN_HPP__

// ─────────────────────────────────────────────────────────────
//					INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header
#include <stdint.h>

// C++ Header

// Dependancies Header

// Application Header

// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

#ifdef WIN32
	#ifdef LIBENDIAN_SHARED	
		#define LIBENDIAN_API_ __declspec(dllexport) /** Shared build, decorate for export */
	#elif LIBENDIAN_STATIC 	
		#define LIBENDIAN_API_                       /** No decoration when building staticlly */
	#else 				
		#define LIBENDIAN_API_ __declspec(dllimport) /** Link to lib , decorate for import */
	#endif
#else
	#define LIBENDIAN_API_                           /** Decoration is only required on windows */
#endif

#ifdef LIBENDIAN_USE_NAMESPACE
#ifndef LIBENDIAN_NAMESPACE_NAME
#define LIBENDIAN_NAMESPACE_NAME Endn
#endif
#define LIBENDIAN_NAMESPACE_START namespace LIBENDIAN_NAMESPACE {
#define LIBENDIAN_NAMESPACE_END }
#define LIBENDIAN_USING_NAMESPACE using namespace LIBENDIAN_NAMESPACE;
#else
#undef LIBENDIAN_NAMESPACE_NAME
#define LIBENDIAN_NAMESPACE_NAME
#define LIBENDIAN_NAMESPACE_START
#define LIBENDIAN_NAMESPACE_END
#define LIBENDIAN_USING_NAMESPACE
#endif

LIBENDIAN_NAMESPACE_START

// ─────────────────────────────────────────────────────────────
//					CLASS
// ─────────────────────────────────────────────────────────────

/** Define common size */
class LIBENDIAN_API_ LibEndian
{
	// ────── SIZE ──────────────────────────────────────────────────────
public:
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
};

LIBENDIAN_NAMESPACE_END

#endif
