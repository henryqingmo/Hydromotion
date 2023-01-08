cmake_minimum_required(VERSION 3.20)
project(Hydromotion)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_LINK_FLAGS "-lSDL2 -lSDL2_image")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(Hydromotion src/main.cpp src/RenderWindow.cpp include/RenderWindow.h src/MenuScreen.cpp include/ui_MenuScreen.h src/MenuScreen.cpp include/MenuScreen.h include/ui_MenuScreen.h include/Log.h src/Log.cpp)

target_link_libraries(Hydromotion PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)