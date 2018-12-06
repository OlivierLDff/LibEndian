LibEndian
=============

A cross platform C++ library to get rid with of binary serialization issues. This library can serialize in buffer the most common types.

## Supported Types

All the types are from `stdint.h`.

|    Type    |  Size (in bytes)   |      Read       |      Write      |
| :--------: | :----------------: | :-------------: | :-------------: |
| `uint8_t`  |  `UINT8_SIZE` : 1  |  **GET_UINT8**  |  **SET_UINT8**  |
|  `int8_t`  |  `INT8_SIZE` : 1   |  **GET_INT8**   |  **SET_INT8**   |
| `uint16_t` | `UINT16_SIZE` : 2  | **GET_UINT16**  | **SET_UINT16**  |
| `int16_t`  |  `INT16_SIZE` : 2  |  **GET_INT16**  |  **SET_INT16**  |
| `uint32_t` | `UINT32_SIZE` : 4  | **GET_UINT32**  | **SET_UINT32**  |
| `int32_t`  |  `INT32_SIZE` : 4  |  **GET_INT32**  |  **SET_INT32**  |
| `uint48_t` | `UINT48_SIZE` : 6  | **GET_UINT48**  | **SET_UINT48**  |
| `int48_t`  |  `INT48_SIZE` : 6  |  **GET_INT48**  |  **SET_INT48**  |
| `uint64_t` | `UINT64_SIZE` : 8  | **GET_UINT64**  | **SET_UINT64**  |
| `int64_t`  |  `INT64_SIZE` : 8  |  **GET_INT64**  |  **SET_INT64**  |
|  `float`   | `FLOAT32_SIZE` : 4 | **GET_FLOAT32** | **SET_FLOAT32** |
|  `double`  | `FLOAT64_SIZE` : 8 | **GET_FLOAT64** | **SET_FLOAT64** |

## Build with CMake

The CMake can build the library either as a static or a shared library. It can also generate a doxygen website.

### Input

- **LIBENDIAN_TARGET** : Name of the library target. *Default : "LibEndian"*
- **LIBENDIAN_PROJECT** : Name of the project. *Default : "LibEndian"*
- **LIBENDIAN_BUILD_SHARED** : Build shared library [ON OFF]. *Default: OFF.*
- **LIBENDIAN_BUILD_STATIC** : Build static library [ON OFF]. *Default: ON.*
- **LIBENDIAN_USE_NAMESPACE** : If the library compile with a namespace [ON OFF]. *Default: OFF.*
- **LIBENDIAN_NAMESPACE** : Namespace for the library. Only relevant if LIBENDIAN_USE_NAMESPACE is ON. *Default: "Endn".*
- **LIBENDIAN_BUILD_DOC** : Build the LibEndian Doc [ON OFF]. *Default: OFF.*

### Dependencies

- **LIBENDIAN_DOXYGEN_BT_REPOSITORY** : Repository of DoxygenBt. *Default : "https://github.com/OlivierLDff/DoxygenBootstrapped.git"*
- **LIBENDIAN_DOXYGEN_BT_TAG** : Git Tag of DoxygenBt. *Default : "v1.3.0"*

### Output

- **LIBENDIAN_TARGET** : Output target to link to.
- **LIBENDIAN_VERSION** : Current version of the library

### Integration with CMake project

The main goal of this CMake project is to big included into another CMake project.
```cmake
SET( LIBENDIAN_TARGET LibEndian )
SET( LIBENDIAN_PROJECT LibEndian )
SET( LIBENDIAN_BUILD_SHARED OFF )
SET( LIBENDIAN_BUILD_STATIC ON )
SET( LIBENDIAN_BUILD_DOC OFF )
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/path/to/LibEndian ${CMAKE_CURRENT_BINARY_DIR}/LibEndian_Build)
```
It is also possible to download the repository with the scripts inside `cmake/`. folder Simply call `BuildLibEndian.cmake`.

You will need:

* `DownloadProject.cmake`
* `DownloadProject.CMakeLists.cmake.in`
* `BuildLibEndian.cmake`

```cmake
SET( LIBENDIAN_TARGET LibEndian )
SET( LIBENDIAN_PROJECT LibEndian )
SET( LIBENDIAN_BUILD_SHARED OFF )
SET( LIBENDIAN_BUILD_STATIC ON )
SET( LIBENDIAN_BUILD_DOC OFF )
SET( LIBENDIAN_BUILD_DOC OFF )
SET( LIBENDIAN_USE_NAMESPACE ON )
SET( LIBENDIAN_REPOSITORY "https://github.com/OlivierLDff/LibEndian.git" )
SET( LIBENDIAN_TAG v1.0.0 )
INCLUDE(path/to/BuildLibEndian.cmake)
```

## Revisions

* **1.0.0** : Initial work