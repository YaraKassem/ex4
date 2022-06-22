cmake_minimum_required(VERSION 3.0.0)
project(Mtmchkin VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Mtmchkin test.cpp Players/Player.cpp Cards/Card.cpp Mtmchkin.cpp Cards/Vampire.cpp
 Cards/BattleCard.cpp Cards/Barfight.cpp Cards/Dragon.cpp
 Cards/Fairy.cpp
 Cards/Goblin.cpp
 Cards/Gang.cpp
 Cards/Merchant.cpp
 Cards/Pitfall.cpp
 Cards/Treasure.cpp
 Players/Rogue.cpp
 Players/Wizard.cpp
 Players/Fighter.cpp utilities.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
