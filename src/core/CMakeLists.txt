add_library(lib_core
        MyMain.cpp MyMain.h
    Game.cpp Game.h
        Clicker.cpp Clicker.h
)
target_include_directories(lib_core PUBLIC ./)
target_link_libraries(lib_core PUBLIC pugixml sfml-graphics)
