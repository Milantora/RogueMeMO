project(GameClient)
add_executable(GameClient GameClient.cpp)

target_sources(GameClient PRIVATE GameClient.ixx)
set_source_files_properties(GameClient.ixx PROPERTIES LANGUAGE CXX)

target_link_libraries(GameClient PRIVATE RogueEngine)
target_link_libraries(GameClient PRIVATE compiler_flags)