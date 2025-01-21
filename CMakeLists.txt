cmake_minimum_required (VERSION 3.28)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("RogueMeMO")


# Enable experimental features for modules in GCC
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(compiler_flags INTERFACE -fmodules-ts)
endif()

# Similar setup for Clang (version 16+ for better module support)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(compiler_flags INTERFACE -fmodules-ts)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

# MSVC has native support for modules in C++20
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /experimental:module")
endif()

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)
target_compile_options(compiler_flags INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-fmodules-ts>")

# target_link_libraries(RogueMeMO PRIVATE compiler_flags)

add_subdirectory ("Engine")
add_subdirectory ("Game_Client")
