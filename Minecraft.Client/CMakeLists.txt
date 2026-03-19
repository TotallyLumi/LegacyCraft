include("${CMAKE_SOURCE_DIR}/cmake/sources/Common.cmake")

include("${CMAKE_SOURCE_DIR}/cmake/CommonSources.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/Utils.cmake")

set(MINECRAFT_CLIENT_SOURCES
    ${MINECRAFT_CLIENT_COMMON}
    $<$<STREQUAL:${PLATFORM_NAME},Windows64>:${MINECRAFT_CLIENT_WINDOWS}>
    ${SOURCES_COMMON}
)

add_executable(Minecraft.Client ${MINECRAFT_CLIENT_SOURCES})

if(PLATFORM_NAME STREQUAL "Windows64")
    set_target_properties(Minecraft.Client PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

target_include_directories(Minecraft.Client PRIVATE
        "${CMAKE_BINARY_DIR}/generated/"
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_NAME}/Iggy/include"
        "${CMAKE_SOURCE_DIR}/include/"
)
target_compile_definitions(Minecraft.Client PRIVATE
        ${MINECRAFT_SHARED_DEFINES}
)
target_precompile_headers(Minecraft.Client PRIVATE "$<$<COMPILE_LANGUAGE:CXX>:stdafx.h>")
set_source_files_properties(compat_shims.cpp PROPERTIES SKIP_PRECOMPILE_HEADERS ON) # This redefines internal MSVC CRT symbols which will cause an issue with PCH

configure_compiler_target(Minecraft.Client)

set_target_properties(Minecraft.Client PROPERTIES
        OUTPUT_NAME "Minecraft.Client"
        VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:Minecraft.Client>"
)

target_link_libraries(Minecraft.Client PRIVATE
        Minecraft.World
        d3d11
        d3dcompiler
        XInput9_1_0
        wsock32
        legacy_stdio_definitions
        $<$<CONFIG:Debug>: # Debug 4J libraries
        "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_NAME}/4JLibs/libs/4J_Input_d.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_NAME}/4JLibs/libs/4J_Storage_d.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_NAME}/4JLibs/libs/4J_Render_PC_d.lib"
        >
        $<$<NOT:$<CONFIG:Debug>>: # Release 4J libraries
        "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_NAME}/4JLibs/libs/4J_Input.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_NAME}/4JLibs/libs/4J_Storage.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_NAME}/4JLibs/libs/4J_Render_PC.lib"
        >
)

foreach(lib IN LISTS IGGY_LIBS)
    target_link_libraries(Minecraft.Client PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_NAME}/Iggy/lib/${lib}")
endforeach()

include("${CMAKE_SOURCE_DIR}/cmake/CopyAssets.cmake")
set(ASSET_FOLDER_PAIRS
        "${CMAKE_CURRENT_SOURCE_DIR}/music"                  "music"
        "${CMAKE_CURRENT_SOURCE_DIR}/Common/Media"           "Common/Media"
        "${CMAKE_CURRENT_SOURCE_DIR}/Common/res"             "Common/res"
        "${CMAKE_CURRENT_SOURCE_DIR}/Common/Trial"           "Common/Trial"
        "${CMAKE_CURRENT_SOURCE_DIR}/Common/Tutorial"        "Common/Tutorial"
        "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_NAME}Media"  "${PLATFORM_NAME}Media"
)
setup_asset_folder_copy(Minecraft.Client "${ASSET_FOLDER_PAIRS}")

add_copyredist_target(Minecraft.Client)

if(PLATFORM_NAME STREQUAL "Windows64")
    add_gamehdd_target(Minecraft.Client)
endif()