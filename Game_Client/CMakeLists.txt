project(GC)

add_executable (GC "GC.cpp" "GC.h")

target_link_libraries(GC PRIVATE RE)