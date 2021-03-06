/**
 * \file LittleEndian.hpp
 * \brief Serialize binary data in Little Endian way
 */
#ifndef __LITTLE_ENDIAN_HPP__
#define __LITTLE_ENDIAN_HPP__

// ─────────────────────────────────────────────────────────────
//                  INCLUDE
// ─────────────────────────────────────────────────────────────

// Application Header
#include <LibEndian.hpp>

// C++ Header
#include <cstdint>
#include <cstddef>
#include <cstring>

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

LIBENDIAN_NAMESPACE_START

// ─────────────────────────────────────────────────────────────
//                  CLASS
// ─────────────────────────────────────────────────────────────

/** \brief Serialize binary data in little endian way */
class LIBENDIAN_API_ LittleEndian : public LibEndian
{
public:
    /**
     * \brief Deserialize an uint8_t from buffer
     * \param buf Pointer to the uint8_t
     * \return The deserialized data
     */
    static uint8_t GET_UINT8(const uint8_t* buf)
    {
        return ((uint8_t)buf[0]);
    }

    /**
     * \brief Deserialize an uint16_t from buffer
     * \param buf Pointer to the uint16_t
     * \return The deserialized data
     */
    static uint16_t GET_UINT16(const uint8_t* buf)
    {
        #ifdef LIBENDIAN_ENABLE_BSWAP
          #ifdef LIBENDIAN_IS_BIG_ENDIAN
            if(IS_16_ALIGNED(uintptr_t(buf)))
                return bswap_16(uint16_t(*buf));
          #else
            if(IS_16_ALIGNED(uintptr_t(buf)))
                return uint16_t(*(const uint16_t*)(buf));
          #endif
        #endif
        return ((uint16_t)buf[1] << 8) |
               ((uint16_t)buf[0]);
    }

    /**
     * \brief Deserialize an uint32_t from buffer
     * \param buf Pointer to the uint32_t
     * \return The deserialized data
     */
    static uint32_t GET_UINT32(const uint8_t* buf)
    {
        #ifdef LIBENDIAN_ENABLE_BSWAP
          #ifdef LIBENDIAN_IS_BIG_ENDIAN
            if(IS_32_ALIGNED(uintptr_t(buf)))
                return bswap_32(uint32_t(*buf));
          #else
        if (IS_32_ALIGNED(uintptr_t(buf)))
            return uint32_t(*(const uint32_t*)(buf));
          #endif
        #endif
        return ((uint32_t)buf[3] << 24) |
               ((uint32_t)buf[2] << 16) |
               ((uint32_t)buf[1] << 8)  |
               ((uint32_t)buf[0]);
    }

    /**
     * \brief Deserialize an uint48_t from buffer.
     * \note It is return on a uint64_t for convenience
     * \param buf Pointer to the uint48_t
     * \return The deserialized data
     */
    static uint64_t GET_UINT48(const uint8_t* buf)
    {
        #ifdef LIBENDIAN_ENABLE_BSWAP
          #ifdef LIBENDIAN_IS_BIG_ENDIAN
            if(IS_64_ALIGNED(uintptr_t(buf)))
                return bswap_64(uint64_t(*buf)) & uint64_t(0xFFFFFFFFFFFF);
          #else
            if(IS_64_ALIGNED(uintptr_t(buf)))
                return uint64_t(*(const uint64_t*)(buf)) & uint64_t(0xFFFFFFFFFFFF);
          #endif
        #endif
        return ((uint64_t)buf[5] << 40) |
               ((uint64_t)buf[4] << 32) |
               ((uint64_t)buf[3] << 24) |
               ((uint64_t)buf[2] << 16) |
               ((uint64_t)buf[1] << 8)  |
               ((uint64_t)buf[0]);
    }

    /**
     * \brief Deserialize an uint64_t from buffer
     * \param buf Pointer to the uint64_t
     * \return The deserialized data
     */
    static uint64_t GET_UINT64(const uint8_t* buf)
    {
        #ifdef LIBENDIAN_ENABLE_BSWAP
          #ifdef LIBENDIAN_IS_BIG_ENDIAN
            if(IS_64_ALIGNED(uintptr_t(buf)))
                return bswap_64(uint64_t(*buf));
          #else
            if(IS_64_ALIGNED(uintptr_t(buf)))
                return uint64_t(*(const uint64_t*)(buf));
          #endif
        #endif
        return ((uint64_t)buf[7] << 56) |
               ((uint64_t)buf[6] << 48) |
               ((uint64_t)buf[5] << 40) |
               ((uint64_t)buf[4] << 32) |
               ((uint64_t)buf[3] << 24) |
               ((uint64_t)buf[2] << 16) |
               ((uint64_t)buf[1] << 8) |
               ((uint64_t)buf[0]);
    }

    /**
     * \brief Deserialize an int8_t from buffer
     * \param buf Pointer to the int8_t
     * \return The deserialized data
     */
    static int8_t GET_INT8(const uint8_t* buf)
    {
        const uint8_t value = GET_UINT8(buf);
        return *(int8_t*)(&value);
    }

    /**
     * \brief Deserialize an int16_t from buffer
     * \param buf Pointer to the int16_t
     * \return The deserialized data
     */
    static int16_t GET_INT16(const uint8_t* buf)
    {
        const uint8_t value = GET_UINT8(buf);
        return *(int16_t*)(&value);
    }

    /**
     * \brief Deserialize an int32_t from buffer
     * \param buf Pointer to the int32_t
     * \return The deserialized data
     */
    static int32_t GET_INT32(const uint8_t* buf)
    {
        const uint8_t value = GET_UINT8(buf);
        return *(int32_t*)(&value);
    }

    /**
     * \brief Deserialize an int48_t from buffer.
     * \note It is return on a int64_t for convenience
     * \param buf Pointer to the uint48_t
     * \return The deserialized data
     */
    static int64_t GET_INT48(const uint8_t* buf)
    {
        const uint8_t value = GET_UINT8(buf);
        return *(int64_t*)(&value);
    }

    /**
     * \brief Deserialize an int64_t from buffer
     * \param buf Pointer to the int64_t
     * \return The deserialized data
     */
    static int64_t GET_INT64(const uint8_t* buf)
    {
        const uint8_t value = GET_UINT8(buf);
        return *(int64_t*)(&value);
    }

    /**
     * \brief Deserialize an float from buffer
     * \param buf Pointer to the float
     * \return The deserialized data
     */
    static float GET_FLOAT32(const uint8_t* buf)
    {
        const uint32_t value = GET_UINT32(buf);
        return *(float*)(&value);
    }

    /**
     * \brief Deserialize an double from buffer
     * \param buf Pointer to the double
     * \return The deserialized data
     */
    static double GET_FLOAT64(const uint8_t* buf)
    {
        const uint64_t value = GET_UINT64(buf);
        return *(double*)(&value);
    }

    /**
     * \brief Deserialize an uint8_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an uint8_t* (in bytes)
     * \return The deserialized data
     */
    static uint8_t GET_UINT8(const uint8_t* buf, const size_t offset)   { return GET_UINT8(&buf[offset]); }

    /**
     * \brief Deserialize an uint16_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an uint16_t* (in bytes)
     * \return The deserialized data
     */
    static uint16_t GET_UINT16(const uint8_t* buf, const size_t offset) { return GET_UINT16(&buf[offset]); }

    /**
     * \brief Deserialize an uint32_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an uint32_t* (in bytes)
     * \return The deserialized data
     */
    static uint32_t GET_UINT32(const uint8_t* buf, const size_t offset) { return GET_UINT32(&buf[offset]); }

    /**
     * \brief Deserialize an uint48_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an uint48_t* (in bytes)
     * \note Store in a uint64_t for convenience
     * \return The deserialized data
     */
    static uint64_t GET_UINT48(const uint8_t* buf, const size_t offset) { return GET_UINT48(&buf[offset]); }

    /**
     * \brief Deserialize an uint64_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an uint64_t* (in bytes)
     * \return The deserialized data
     */
    static uint64_t GET_UINT64(const uint8_t* buf, const size_t offset) { return GET_UINT64(&buf[offset]); }

    /**
     * \brief Deserialize an int8_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an int8_t* (in bytes)
     * \return The deserialized data
     */
    static int8_t GET_INT8(const uint8_t* buf, const size_t offset)   { return GET_INT8(&buf[offset]); }

    /**
     * \brief Deserialize an int16_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an int16_t* (in bytes)
     * \return The deserialized data
     */
    static int16_t GET_INT16(const uint8_t* buf, const size_t offset) { return GET_INT16(&buf[offset]); }

    /**
     * \brief Deserialize an int32_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an int32_t* (in bytes)
     * \return The deserialized data
     */
    static int32_t GET_INT32(const uint8_t* buf, const size_t offset) { return GET_INT32(&buf[offset]); }

    /**
     * \brief Deserialize an int48_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an int48_t* (in bytes)
     * \note Store in a int64_t for convenience
     * \return The deserialized data
     */
    static int64_t GET_INT48(const uint8_t* buf, const size_t offset) { return GET_INT48(&buf[offset]); }

    /**
     * \brief Deserialize an int64_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an int64_t* (in bytes)
     * \return The deserialized data
     */
    static int64_t GET_INT64(const uint8_t* buf, const size_t offset) { return GET_INT64(&buf[offset]); }

    /**
     * \brief Deserialize an float from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an float* (in bytes)
     * \return The deserialized data
     */
    static float GET_FLOAT32(const uint8_t* buf, const size_t offset) { return GET_FLOAT32(&buf[offset]); }

    /**
     * \brief Deserialize an double from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an double  (in bytes)
     * \return The deserialized data
     */
    static double GET_FLOAT64(const uint8_t* buf, const size_t offset) { return GET_FLOAT64(&buf[offset]); }

    /**
     * \brief Serialize a uint8_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_UINT8(uint8_t* buf, const uint8_t val)
    {
        buf[0] = (uint8_t)(val & 0xFF);
    }

    /**
     * \brief Serialize a uint16_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_UINT16(uint8_t* buf, const uint16_t val)
    {
        #ifdef LIBENDIAN_ENABLE_BSWAP
          #ifdef LIBENDIAN_IS_BIG_ENDIAN
            if(IS_16_ALIGNED(uintptr_t(buf)))
            {
                (*(uint16_t*)buf) = bswap_16(val);
                return;
            }
          #else
            if(IS_16_ALIGNED(uintptr_t(buf)))
            {
                (*(uint16_t*)buf) = val;
                return;
            }
          #endif
        #endif
        buf[1] = (uint8_t)((val >> 8) & 0xFF);
        buf[0] = (uint8_t)(val & 0xFF);
    }

    /**
     * \brief Serialize a uint32_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_UINT32(uint8_t* buf, const uint32_t val)
    {
        #ifdef LIBENDIAN_ENABLE_BSWAP
          #ifdef LIBENDIAN_IS_BIG_ENDIAN
            if(IS_32_ALIGNED(uintptr_t(buf)))
            {
                (*(uint32_t*)buf) = bswap_32(val);
                return;
            }
          #else
            if(IS_32_ALIGNED(uintptr_t(buf)))
            {
                (*(uint32_t*)buf) = val;
                return;
            }
          #endif
        #endif
        buf[3] = (uint8_t)((val >> 24) & 0xFF);
        buf[2] = (uint8_t)((val >> 16) & 0xFF);
        buf[1] = (uint8_t)((val >> 8) & 0xFF);
        buf[0] = (uint8_t)(val & 0xFF);
    }

    /**
     * \brief Serialize a uint48_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     * \note For convenience the uint48 is stored into a uint64_t
     */
    static void SET_UINT48(uint8_t* buf, const uint64_t val)
    {
        #ifdef LIBENDIAN_ENABLE_BSWAP
          #ifdef LIBENDIAN_IS_BIG_ENDIAN
            if(IS_64_ALIGNED(uintptr_t(buf)))
            {
                (*(uint64_t*)buf) = bswap_64(val) & uint64_t(0xFFFFFFFFFFFF);
                return;
            }
          #else
            if(IS_64_ALIGNED(uintptr_t(buf)))
            {
                (*(uint64_t*)buf) = val & uint64_t(0xFFFFFFFFFFFF);
                return;
            }
          #endif
        #endif
        buf[5] = (uint8_t)((val >> 40) & 0xFF);
        buf[4] = (uint8_t)((val >> 32) & 0xFF);
        buf[3] = (uint8_t)((val >> 24) & 0xFF);
        buf[2] = (uint8_t)((val >> 16) & 0xFF);
        buf[1] = (uint8_t)((val >> 8) & 0xFF);
        buf[0] = (uint8_t)(val & 0xFF);
    }

    /**
     * \brief Serialize a uint64_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_UINT64(uint8_t* buf, const uint64_t val)
    {
        #ifdef LIBENDIAN_ENABLE_BSWAP
          #ifdef LIBENDIAN_IS_BIG_ENDIAN
            if(IS_64_ALIGNED(uintptr_t(buf)))
            {
                (*(uint64_t*)buf) = bswap_64(val);
                return;
            }
          #else
            if(IS_64_ALIGNED(uintptr_t(buf)))
            {
                (*(uint64_t*)buf) = val;
                return;
            }
          #endif
        #endif
        buf[7] = (uint8_t)((val >> 56) & 0xFF);
        buf[6] = (uint8_t)((val >> 48) & 0xFF);
        buf[5] = (uint8_t)((val >> 40) & 0xFF);
        buf[4] = (uint8_t)((val >> 32) & 0xFF);
        buf[3] = (uint8_t)((val >> 24) & 0xFF);
        buf[2] = (uint8_t)((val >> 16) & 0xFF);
        buf[1] = (uint8_t)((val >> 8) & 0xFF);
        buf[0] = (uint8_t)(val & 0xFF);
    }

    /**
     * \brief Serialize a int8_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_INT8(uint8_t* buf, const int8_t val) { SET_UINT8(buf, *(const uint8_t*)&val); }

    /**
     * \brief Serialize a int16_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_INT16(uint8_t* buf, const int16_t val) { SET_UINT16(buf, *(const uint16_t*)&val); }

    /**
     * \brief Serialize a int32_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_INT32(uint8_t* buf, const int32_t val) { SET_UINT32(buf, *(const uint32_t*)&val); }

    /**
     * \brief Serialize a int48 in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     * \note For convenience the int48 is stored into a int64_t
     */
    static void SET_INT48(uint8_t* buf, const int64_t val) { SET_UINT48(buf, *(const uint64_t*)&val); }

    /**
     * \brief Serialize a int64_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_INT64(uint8_t* buf, const int64_t val) { SET_UINT64(buf, *(const uint64_t*)&val); }

    /**
     * \brief Serialize a float in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_FLOAT32(uint8_t* buf, const float val) { SET_UINT32(buf, *(const uint32_t*)&val); }

    /**
     * \brief Serialize a double in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_FLOAT64(uint8_t* buf, const double val) { SET_UINT64(buf, *(const uint64_t*)&val); }

    /**
     * \brief Serialize a uint8_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_UINT8(uint8_t* buf, const size_t offset, const uint8_t val) { SET_UINT8(&buf[offset], val); }

    /**
     * \brief Serialize a uint16_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_UINT16(uint8_t* buf, const size_t offset, const uint16_t val) { SET_UINT16(&buf[offset], val); }

    /**
     * \brief Serialize a uint32_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_UINT32(uint8_t* buf, const size_t offset, const uint32_t val) { SET_UINT32(&buf[offset], val); }

    /**
     * \brief Serialize a uint48_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     * \note For convenience the uint48 is stored into a uint64_t
     */
    static void SET_UINT48(uint8_t* buf, const size_t offset, const uint64_t val) { SET_UINT48(&buf[offset], val); }

    /**
     * \brief Serialize a uint64_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_UINT64(uint8_t* buf, const size_t offset, const uint64_t val) { SET_UINT64(&buf[offset], val); }

    /**
     * \brief Serialize a int8_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_INT8(uint8_t* buf, const size_t offset, const int8_t val) { SET_INT8(&buf[offset], val); }

    /**
     * \brief Serialize a int16_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_INT16(uint8_t* buf, const size_t offset, const int16_t val) { SET_INT16(&buf[offset], val); }

    /**
     * \brief Serialize a int32_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_INT32(uint8_t* buf, const size_t offset, const int32_t val) { SET_INT32(&buf[offset], val); }

    /**
     * \brief Serialize a int48_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     * \note For convenience the int48 is stored into a int64_t
     */
    static void SET_INT48(uint8_t* buf, const size_t offset, const int64_t val) { SET_INT48(&buf[offset], val); }

    /**
     * \brief Serialize a int64_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_INT64(uint8_t* buf, const size_t offset, const int64_t val) { SET_INT64(&buf[offset], val); }

    /**
     * \brief Serialize a float in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_FLOAT32(uint8_t* buf, const size_t offset, const float val) { SET_FLOAT32(&buf[offset], val); }

    /**
     * \brief Serialize a double in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_FLOAT64(uint8_t* buf, const size_t offset, const double val) { SET_FLOAT64(&buf[offset], val); }

    /**
     * \brief Serialize a uint8_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of uint8_t
     * \param val Value to serialize
     */
    static void SET_UINT8(uint8_t* buf, const size_t offset, const uint8_t val, int& length) { SET_UINT8(buf, offset, val); length += UINT8_SIZE; }

    /**
     * \brief Serialize a uint16_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of uint16_t
     * \param val Value to serialize
     */
    static void SET_UINT16(uint8_t* buf, const size_t offset, const uint16_t val, int& length) { SET_UINT16(buf, offset, val); length += UINT16_SIZE; }

    /**
     * \brief Serialize a uint32_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of uint32_t
     * \param val Value to serialize
     */
    static void SET_UINT32(uint8_t* buf, const size_t offset, const uint32_t val, int& length) { SET_UINT32(buf, offset, val); length += UINT32_SIZE; }

    /**
     * \brief Serialize a uint48_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of uint48_t
     * \note For convenience the uint48 is stored into a uint64_t
     * \param val Value to serialize
     */
    static void SET_UINT48(uint8_t* buf, const size_t offset, const uint64_t val, int& length) { SET_UINT48(buf, offset, val); length += UINT48_SIZE; }

    /**
     * \brief Serialize a uint64_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of uint64_t
     * \param val Value to serialize
     */
    static void SET_UINT64(uint8_t* buf, const size_t offset, const uint64_t val, int& length) { SET_UINT64(buf, offset, val); length += UINT64_SIZE; }

    /**
     * \brief Serialize a int8_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of int8_t
     * \param val Value to serialize
     */
    static void SET_INT8(uint8_t* buf, const size_t offset, const int8_t val, int& length) { SET_INT8(buf, offset, val); length += INT8_SIZE; }

    /**
     * \brief Serialize a int16_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of int16_t
     * \param val Value to serialize
     */
    static void SET_INT16(uint8_t* buf, const size_t offset, const int16_t val, int& length) { SET_INT16(buf, offset, val); length += INT16_SIZE; }

    /**
     * \brief Serialize a int32_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of int32_t
     * \param val Value to serialize
     */
    static void SET_INT32(uint8_t* buf, const size_t offset, const int32_t val, int& length) { SET_INT32(buf, offset, val); length += INT32_SIZE; }

    /**
     * \brief Serialize a int48_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of int48_t
     * \note For convenience the int48 is stored into a int64_t
     * \param val Value to serialize
     */
    static void SET_INT48(uint8_t* buf, const size_t offset, const int64_t val, int& length) { SET_INT48(buf, offset, val); length += INT48_SIZE; }

    /**
     * \brief Serialize a int64_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of int64_t
     * \param val Value to serialize
     */
    static void SET_INT64(uint8_t* buf, const size_t offset, const int64_t val, int& length) { SET_INT64(buf, offset, val); length += INT64_SIZE; }

    /**
     * \brief Serialize a float in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of float
     * \param val Value to serialize
     */
    static void SET_FLOAT32(uint8_t* buf, const size_t offset, const float val, int& length) { SET_FLOAT32(buf, offset, val); length += UINT32_SIZE; }

    /**
     * \brief Serialize a double in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of double
     * \param val Value to serialize
     */
    static void SET_FLOAT64(uint8_t* buf, const size_t offset, const double val, int& length) { SET_FLOAT64(buf, offset, val); length += UINT64_SIZE; }

    /**
     * \brief memcpy from a little endian 16 bits to a local buffer
     * \param dest ptr to local uint16_t buffer, that contains uint16_t
     * \param src ptr to little endian buffer of uint16_t that need to be deserialized in dest
     * \param count Number of uint16_t in src
     */
    static void MEMCPY_16(uint8_t* dest, const uint8_t* src, const size_t count)
    {
        #ifdef LIBENDIAN_IS_BIG_ENDIAN
        if(IS_16_ALIGNED(src))
        {
            for (int i = 0; i < count; i += 2)
                *reinterpret_cast<uint16_t*>(&dest[i]) = GET_UINT16(src, i);
            return;
        }
        #endif
        if(OVERLAP(uintptr_t(dest), uintptr_t(src), count * 2))
            memmove(dest, src, count * 2);
        else
            memcpy(dest, src, count * 2);
    }

    /**
     * \brief memcpy from a little endian 32 bits to a local buffer
     * \param dest ptr to local uint32_t buffer, that contains uint32_t
     * \param src ptr to little endian buffer of uint32_t that need to be deserialized in dest
     * \param count Number of uint32_t in src
     */
    static void MEMCPY_32(uint8_t* dest, const uint8_t* src, const size_t count)
    {
        #ifdef LIBENDIAN_IS_BIG_ENDIAN
        if(IS_32_ALIGNED(src))
        {
            for (int i = 0; i < count; i += 4)
                *reinterpret_cast<uint32_t*>(&dest[i]) = GET_UINT32(src, i);
            return;
        }
        #endif
        if(OVERLAP(uintptr_t(dest), uintptr_t(src), count * 4))
            memmove(dest, src, count * 4);
        else
            memcpy(dest, src, count * 4);
    }

    /**
     * \brief memcpy from a little endian 64 bits to a local buffer
     * \param dest ptr to local uint64_t buffer, that contains uint64_t
     * \param src ptr to little endian buffer of uint64_t that need to be deserialized in dest
     * \param count Number of uint64_t in src
     */
    static void MEMCPY_64(uint8_t* dest, const uint8_t* src, const size_t count)
    {
        #ifdef LIBENDIAN_IS_BIG_ENDIAN
        if(IS_64_ALIGNED(src))
        {
            for (int i = 0; i < count; i += 8)
                *reinterpret_cast<uint64_t*>(&dest[i]) = GET_UINT64(src, i);
            return;
        }
        #endif
        if(OVERLAP(uintptr_t(dest), uintptr_t(src), count * 8))
            memmove(dest, src, count * 8);
        else
            memcpy(dest, src, count * 8);
    }

    /**
     * \brief Deserialize an uint8_t from buffer
     * \param buf Pointer to the uint8_t
     * \return The deserialized data
     */
    static uint8_t GET_UINT8(const char* buf) { return GET_UINT8((const uint8_t*)buf); }

    /**
     * \brief Deserialize an uint16_t from buffer
     * \param buf Pointer to the uint16_t
     * \return The deserialized data
     */
    static uint16_t GET_UINT16(const char* buf) { return GET_UINT16((const uint8_t*)buf); }

    /**
     * \brief Deserialize an uint32_t from buffer
     * \param buf Pointer to the uint32_t
     * \return The deserialized data
     */
    static uint32_t GET_UINT32(const char* buf) { return GET_UINT32((const uint8_t*)buf); }

    /**
     * \brief Deserialize an uint48_t from buffer.
     * \note It is return on a uint64_t for convenience
     * \param buf Pointer to the uint48_t
     * \return The deserialized data
     */
    static uint64_t GET_UINT48(const char* buf) { return GET_UINT48((const uint8_t*)buf); }

    /**
     * \brief Deserialize an uint64_t from buffer
     * \param buf Pointer to the uint64_t
     * \return The deserialized data
     */
    static uint64_t GET_UINT64(const char* buf) { return GET_UINT64((const uint8_t*)buf); }

    /**
     * \brief Deserialize an int8_t from buffer
     * \param buf Pointer to the int8_t
     * \return The deserialized data
     */
    static int8_t GET_INT8(const char* buf)
    {
        const uint8_t value = GET_UINT8(buf);
        return *(int8_t*)(&value);
    }

    /**
     * \brief Deserialize an int16_t from buffer
     * \param buf Pointer to the int16_t
     * \return The deserialized data
     */
    static int16_t GET_INT16(const char* buf)
    {
        const uint8_t value = GET_UINT8(buf);
        return *(int16_t*)(&value);
    }

    /**
     * \brief Deserialize an int32_t from buffer
     * \param buf Pointer to the int32_t
     * \return The deserialized data
     */
    static int32_t GET_INT32(const char* buf)
    {
        const uint8_t value = GET_UINT8(buf);
        return *(int32_t*)(&value);
    }

    /**
     * \brief Deserialize an int48_t from buffer.
     * \note It is return on a int64_t for convenience
     * \param buf Pointer to the uint48_t
     * \return The deserialized data
     */
    static int64_t GET_INT48(const char* buf)
    {
        const uint8_t value = GET_UINT8(buf);
        return *(int64_t*)(&value);
    }

    /**
     * \brief Deserialize an int64_t from buffer
     * \param buf Pointer to the int64_t
     * \return The deserialized data
     */
    static int64_t GET_INT64(const char* buf)
    {
        const uint8_t value = GET_UINT8(buf);
        return *(int64_t*)(&value);
    }

    /**
     * \brief Deserialize an float from buffer
     * \param buf Pointer to the float
     * \return The deserialized data
     */
    static float GET_FLOAT32(const char* buf)
    {
        const uint32_t value = GET_UINT32(buf);
        return *(float*)(&value);
    }

    /**
     * \brief Deserialize an double from buffer
     * \param buf Pointer to the double
     * \return The deserialized data
     */
    static double GET_FLOAT64(const char* buf)
    {
        const uint64_t value = GET_UINT64(buf);
        return *(double*)(&value);
    }

    /**
     * \brief Deserialize an uint8_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an uint8_t* (in bytes)
     * \return The deserialized data
     */
    static uint8_t GET_UINT8(const char* buf, const size_t offset)   { return GET_UINT8(&buf[offset]); }

    /**
     * \brief Deserialize an uint16_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an uint16_t* (in bytes)
     * \return The deserialized data
     */
    static uint16_t GET_UINT16(const char* buf, const size_t offset) { return GET_UINT16(&buf[offset]); }

    /**
     * \brief Deserialize an uint32_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an uint32_t* (in bytes)
     * \return The deserialized data
     */
    static uint32_t GET_UINT32(const char* buf, const size_t offset) { return GET_UINT32(&buf[offset]); }

    /**
     * \brief Deserialize an uint48_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an uint48_t* (in bytes)
     * \note Store in a uint64_t for convenience
     * \return The deserialized data
     */
    static uint64_t GET_UINT48(const char* buf, const size_t offset) { return GET_UINT48(&buf[offset]); }

    /**
     * \brief Deserialize an uint64_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an uint64_t* (in bytes)
     * \return The deserialized data
     */
    static uint64_t GET_UINT64(const char* buf, const size_t offset) { return GET_UINT64(&buf[offset]); }

    /**
     * \brief Deserialize an int8_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an int8_t* (in bytes)
     * \return The deserialized data
     */
    static int8_t GET_INT8(const char* buf, const size_t offset)   { return GET_INT8(&buf[offset]); }

    /**
     * \brief Deserialize an int16_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an int16_t* (in bytes)
     * \return The deserialized data
     */
    static int16_t GET_INT16(const char* buf, const size_t offset) { return GET_INT16(&buf[offset]); }

    /**
     * \brief Deserialize an int32_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an int32_t* (in bytes)
     * \return The deserialized data
     */
    static int32_t GET_INT32(const char* buf, const size_t offset) { return GET_INT32(&buf[offset]); }

    /**
     * \brief Deserialize an int48_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an int48_t* (in bytes)
     * \note Store in a int64_t for convenience
     * \return The deserialized data
     */
    static int64_t GET_INT48(const char* buf, const size_t offset) { return GET_INT48(&buf[offset]); }

    /**
     * \brief Deserialize an int64_t from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an int64_t* (in bytes)
     * \return The deserialized data
     */
    static int64_t GET_INT64(const char* buf, const size_t offset) { return GET_INT64(&buf[offset]); }

    /**
     * \brief Deserialize an float from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an float* (in bytes)
     * \return The deserialized data
     */
    static float GET_FLOAT32(const char* buf, const size_t offset) { return GET_FLOAT32(&buf[offset]); }

    /**
     * \brief Deserialize an double from buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer to access to an double  (in bytes)
     * \return The deserialized data
     */
    static double GET_FLOAT64(const char* buf, const size_t offset) { return GET_FLOAT64(&buf[offset]); }

    /**
     * \brief Serialize a uint8_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_UINT8(char* buf, const uint8_t val) { SET_UINT8((uint8_t*)buf, *(const uint8_t*)&val); }

    /**
     * \brief Serialize a uint16_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_UINT16(char* buf, const uint16_t val) { SET_UINT16((uint8_t*)buf, *(const uint16_t*)&val); }

    /**
     * \brief Serialize a uint32_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_UINT32(char* buf, const uint32_t val) { SET_UINT32((uint8_t*)buf, *(const uint32_t*)&val); }

    /**
     * \brief Serialize a uint48_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     * \note For convenience the uint48 is stored into a uint64_t
     */
    static void SET_UINT48(char* buf, const uint64_t val) { SET_UINT48((uint8_t*)buf, *(const uint64_t*)&val); }

    /**
     * \brief Serialize a uint64_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_UINT64(char* buf, const uint64_t val) { SET_UINT64((uint8_t*)buf, *(const uint64_t*)&val); }

    /**
     * \brief Serialize a int8_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_INT8(char* buf, const int8_t val) { SET_UINT8(buf, *(const uint8_t*)&val); }

    /**
     * \brief Serialize a int16_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_INT16(char* buf, const int16_t val) { SET_UINT16(buf, *(const uint16_t*)&val); }

    /**
     * \brief Serialize a int32_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_INT32(char* buf, const int32_t val) { SET_UINT32(buf, *(const uint32_t*)&val); }

    /**
     * \brief Serialize a int48 in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     * \note For convenience the int48 is stored into a int64_t
     */
    static void SET_INT48(char* buf, const int64_t val) { SET_UINT48(buf, *(const uint64_t*)&val); }

    /**
     * \brief Serialize a int64_t in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_INT64(char* buf, const int64_t val) { SET_UINT64(buf, *(const uint64_t*)&val); }

    /**
     * \brief Serialize a float in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_FLOAT32(char* buf, const float val) { SET_UINT32(buf, *(const uint32_t*)&val); }

    /**
     * \brief Serialize a double in the buffer
     * \param buf Pointer to the buffer
     * \param val Value to serialize
     */
    static void SET_FLOAT64(char* buf, const double val) { SET_UINT64(buf, *(const uint64_t*)&val); }

    /**
     * \brief Serialize a uint8_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_UINT8(char* buf, const size_t offset, const uint8_t val) { SET_UINT8(&buf[offset], val); }

    /**
     * \brief Serialize a uint16_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_UINT16(char* buf, const size_t offset, const uint16_t val) { SET_UINT16(&buf[offset], val); }

    /**
     * \brief Serialize a uint32_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_UINT32(char* buf, const size_t offset, const uint32_t val) { SET_UINT32(&buf[offset], val); }

    /**
     * \brief Serialize a uint48_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     * \note For convenience the uint48 is stored into a uint64_t
     */
    static void SET_UINT48(char* buf, const size_t offset, const uint64_t val) { SET_UINT48(&buf[offset], val); }

    /**
     * \brief Serialize a uint64_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_UINT64(char* buf, const size_t offset, const uint64_t val) { SET_UINT64(&buf[offset], val); }

    /**
     * \brief Serialize a int8_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_INT8(char* buf, const size_t offset, const int8_t val) { SET_INT8(&buf[offset], val); }

    /**
     * \brief Serialize a int16_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_INT16(char* buf, const size_t offset, const int16_t val) { SET_INT16(&buf[offset], val); }

    /**
     * \brief Serialize a int32_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_INT32(char* buf, const size_t offset, const int32_t val) { SET_INT32(&buf[offset], val); }

    /**
     * \brief Serialize a int48_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     * \note For convenience the int48 is stored into a int64_t
     */
    static void SET_INT48(char* buf, const size_t offset, const int64_t val) { SET_INT48(&buf[offset], val); }

    /**
     * \brief Serialize a int64_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_INT64(char* buf, const size_t offset, const int64_t val) { SET_INT64(&buf[offset], val); }

    /**
     * \brief Serialize a float in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_FLOAT32(char* buf, const size_t offset, const float val) { SET_FLOAT32(&buf[offset], val); }

    /**
     * \brief Serialize a double in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param val Value to serialize
     */
    static void SET_FLOAT64(char* buf, const size_t offset, const double val) { SET_FLOAT64(&buf[offset], val); }

    /**
     * \brief Serialize a uint8_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of uint8_t
     * \param val Value to serialize
     */
    static void SET_UINT8(char* buf, const size_t offset, const uint8_t val, int& length) { SET_UINT8(buf, offset, val); length += UINT8_SIZE; }

    /**
     * \brief Serialize a uint16_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of uint16_t
     * \param val Value to serialize
     */
    static void SET_UINT16(char* buf, const size_t offset, const uint16_t val, int& length) { SET_UINT16(buf, offset, val); length += UINT16_SIZE; }

    /**
     * \brief Serialize a uint32_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of uint32_t
     * \param val Value to serialize
     */
    static void SET_UINT32(char* buf, const size_t offset, const uint32_t val, int& length) { SET_UINT32(buf, offset, val); length += UINT32_SIZE; }

    /**
     * \brief Serialize a uint48_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of uint48_t
     * \note For convenience the uint48 is stored into a uint64_t
     * \param val Value to serialize
     */
    static void SET_UINT48(char* buf, const size_t offset, const uint64_t val, int& length) { SET_UINT48(buf, offset, val); length += UINT48_SIZE; }

    /**
     * \brief Serialize a uint64_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of uint64_t
     * \param val Value to serialize
     */
    static void SET_UINT64(char* buf, const size_t offset, const uint64_t val, int& length) { SET_UINT64(buf, offset, val); length += UINT64_SIZE; }

    /**
     * \brief Serialize a int8_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of int8_t
     * \param val Value to serialize
     */
    static void SET_INT8(char* buf, const size_t offset, const int8_t val, int& length) { SET_INT8(buf, offset, val); length += INT8_SIZE; }

    /**
     * \brief Serialize a int16_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of int16_t
     * \param val Value to serialize
     */
    static void SET_INT16(char* buf, const size_t offset, const int16_t val, int& length) { SET_INT16(buf, offset, val); length += INT16_SIZE; }

    /**
     * \brief Serialize a int32_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of int32_t
     * \param val Value to serialize
     */
    static void SET_INT32(char* buf, const size_t offset, const int32_t val, int& length) { SET_INT32(buf, offset, val); length += INT32_SIZE; }

    /**
     * \brief Serialize a int48_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of int48_t
     * \note For convenience the int48 is stored into a int64_t
     * \param val Value to serialize
     */
    static void SET_INT48(char* buf, const size_t offset, const int64_t val, int& length) { SET_INT48(buf, offset, val); length += INT48_SIZE; }

    /**
     * \brief Serialize a int64_t in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of int64_t
     * \param val Value to serialize
     */
    static void SET_INT64(char* buf, const size_t offset, const int64_t val, int& length) { SET_INT64(buf, offset, val); length += INT64_SIZE; }

    /**
     * \brief Serialize a float in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of float
     * \param val Value to serialize
     */
    static void SET_FLOAT32(char* buf, const size_t offset, const float val, int& length) { SET_FLOAT32(buf, offset, val); length += UINT32_SIZE; }

    /**
     * \brief Serialize a double in the buffer
     * \param buf Pointer to the buffer
     * \param offset Offset in the buffer (in bytes)
     * \param length Auto Increment this variable by the size of double
     * \param val Value to serialize
     */
    static void SET_FLOAT64(char* buf, const size_t offset, const double val, int& length) { SET_FLOAT64(buf, offset, val); length += UINT64_SIZE; }

    /**
     * memcpy from a little endian 16 bits to a local buffer
     * \param dest ptr to local uint16_t buffer, that contains uint16_t
     * \param src ptr to little endian buffer of uint16_t that need to be deserialized in dest
     * \param count Number of uint16_t in src
     */
    static void MEMCPY_16(char* dest, const char* src, const size_t count)
    {
        MEMCPY_16((uint8_t*)dest, (const uint8_t*)src, count);
    }

    /**
     * memcpy from a little endian 32 bits to a local buffer
     * \param dest ptr to local uint32_t buffer, that contains uint32_t
     * \param src ptr to little endian buffer of uint32_t that need to be deserialized in dest
     * \param count Number of uint32_t in src
     */
    static void MEMCPY_32(char* dest, const char* src, const size_t count)
    {
        MEMCPY_32((uint8_t*)dest, (const uint8_t*)src, count);
    }

    /**
     * memcpy from a little endian 64 bits to a local buffer
     * \param dest ptr to local uint64_t buffer, that contains uint64_t
     * \param src ptr to little endian buffer of uint64_t that need to be deserialized in dest
     * \param count Number of uint64_t in src
     */
    static void MEMCPY_64(char* dest, const char* src, const size_t count)
    {
        MEMCPY_64((uint8_t*)dest, (const uint8_t*)src, count);
    }

};

LIBENDIAN_NAMESPACE_END

#endif
