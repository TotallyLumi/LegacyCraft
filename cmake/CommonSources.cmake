set(_LCE_FILESYSTEM
    "${CMAKE_SOURCE_DIR}/Minecraft.Common/lce_filesystem/lce_filesystem.cpp"
    "${CMAKE_SOURCE_DIR}/Minecraft.Common/lce_filesystem/lce_filesystem.h"
)
source_group("Minecraft.Common/lce_filesystem" FILES ${_LCE_FILESYSTEM})

set(_BUILDVER
    "${CMAKE_SOURCE_DIR}/Minecraft.Common/BuildVer.h"
)
source_group("Common" FILES ${_BUILDVER})

set(SOURCES_COMMON
    ${_LCE_FILESYSTEM}
    ${_BUILDVER}
)