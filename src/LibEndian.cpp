#include <LibEndian.hpp>

LIBENDIAN_USING_NAMESPACE;

uint32_t Version::getMajor()
{
    return LIBENDIAN_VERSION_MAJOR;
}

uint32_t Version::getMinor()
{
    return LIBENDIAN_VERSION_MINOR;
}

uint32_t Version::getPatch()
{
    return LIBENDIAN_VERSION_PATCH;
}

uint32_t Version::getTag()
{
    return LIBENDIAN_VERSION_TAG_HEX;
}
