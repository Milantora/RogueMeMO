add_library (RE	RE.cpp RE.h)

add_subdirectory(Physic)
add_subdirectory(Graphic)

target_link_libraries(RE PRIVATE RPE RGE)