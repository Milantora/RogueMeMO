add_library (RGE rge.cpp rge.h)

find_package(OpenGL REQUIRED)
set(GLEW_USE_STATIC_LIBS TRUE)
find_package(GLEW REQUIRED)
find_package(glfw3 3.4 REQUIRED)

target_link_libraries(RGE OpenGL::GL)
target_link_libraries(RGE GLEW::glew_s)
target_link_libraries(RGE glfw)