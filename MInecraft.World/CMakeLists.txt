include("../cmake/sources/Common.cmake")
include("../cmake/CommonSources.cmake")

set(MINECRAFT_WORLD_SOURCES
    ${MINECRAFT_WORLD_COMMON}
    ${SOURCES_COMMON}
)

add_library(Minecraft.World STATIC ${MINECRAFT_WORLD_SOURCES})

target_include_directories(Minecraft.World
    PRIVATE
    "${CMAKE_BINARY_DIR}/generated/"
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/include/"
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/x64headers"
)
target_compile_definitions(Minecraft.World
    PRIVATE
    ${MINECRAFT_SHARED_DEFINES}
    _LIB
)
target_precompile_headers(Minecraft.World
    PRIVATE
    "$<$<COMPILE_LANGUAGE:CXX>:stdafx.h>"
)

configure_compiler_target(Minecraft.World)