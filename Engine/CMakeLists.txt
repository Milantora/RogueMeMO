add_library (RogueEngine)

target_sources(RogueEngine PRIVATE RogueEngine.cpp RogueEngine.ixx)
set_source_files_properties(RogueEngine.ixx PROPERTIES LANGUAGE CXX)

add_subdirectory(Physic)
add_subdirectory(Graphic)

target_link_libraries(RogueEngine PRIVATE RoguePhysicEngine RogueGraphicEngine)
target_link_libraries(RogueEngine PRIVATE compiler_flags)
