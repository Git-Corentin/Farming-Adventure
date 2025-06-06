add_library(lib_core
        MyMain.cpp MyMain.h
        Game/Game.cpp
        Game/Game.h
        Enum/SeedType.h
        Enum/ChestType.h
        Game/Seed.cpp
        Game/Seed.h
        Game/SeedReservoir.cpp
        Game/SeedReservoir.h
        Game/Soil.cpp
        Game/Soil.h
        Game/AutoClicker.cpp
        Game/AutoClicker.h
        Effect/Effect.cpp
        Effect/Effect.h
        Effect/ActiveEffect.cpp
        Effect/ActiveEffect.h
        Effect/Utility.cpp
        Effect/Utility.h
        Effect/Malus.cpp
        Effect/Malus.h
        Chest/Chest.cpp
        Chest/Chest.h
        Game/ClickablePlot.cpp
        Game/ClickablePlot.h
        Game/SeedFactory.cpp
        Game/SeedFactory.h
)
target_include_directories(lib_core PUBLIC ./)
target_link_libraries(lib_core PUBLIC pugixml sfml-graphics)
