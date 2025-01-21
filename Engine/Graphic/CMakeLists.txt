add_library (RogueGraphicEngine RogueGraphicEngine.cpp RogueGraphicEngine.ixx)

target_sources(RogueGraphicEngine PRIVATE RogueGraphicEngine.cpp RogueGraphicEngine.ixx)
set_source_files_properties(RogueGraphicEngine.ixx PROPERTIES LANGUAGE CXX)

find_package(OpenGL REQUIRED)
set(GLEW_USE_STATIC_LIBS TRUE)
find_package(GLEW REQUIRED)
find_package(glfw3 3.4 REQUIRED)

target_link_libraries(RogueGraphicEngine PRIVATE OpenGL::GL)
target_link_libraries(RogueGraphicEngine PRIVATE GLEW::glew_s)
target_link_libraries(RogueGraphicEngine PRIVATE glfw)
target_link_libraries(RogueGraphicEngine PRIVATE compiler_flags)