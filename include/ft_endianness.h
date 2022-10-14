#pragma once

/*
** From https://codereview.stackexchange.com/questions/151049/endianness-conversion-in-c
*/

inline uint16_t Reverse16(uint16_t value)
{
    return (((value & 0x00FF) << 8) |
            ((value & 0xFF00) >> 8));
}

inline uint32_t Reverse32(uint32_t value)
{
    return (((value & 0x000000FF) << 24) |
            ((value & 0x0000FF00) <<  8) |
            ((value & 0x00FF0000) >>  8) |
            ((value & 0xFF000000) >> 24));
}

inline uint16_t LittleEndian16(uint16_t value)
{
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    return value;
    #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    return Reverse16(value);
    #else
    #    error unsupported endianness
    #endif
}

inline uint16_t BigEndian16(uint16_t value)
{
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    return Reverse16(value);
    #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    return value;
    #else
    #    error unsupported endianness
    #endif
}

inline uint32_t LittleEndian32(uint32_t value)
{
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    return value;
    #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    return Reverse32(value);
    #else
    #    error unsupported endianness
    #endif
}

inline uint32_t BigEndian32(uint32_t value)
{
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    return Reverse32(value);
    #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    return value;
    #else
    #    error unsupported endianness
    #endif
}
