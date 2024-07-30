find_package(Qt6 REQUIRED CONFIG COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)  # detects MOC macros and generates relevant code
set(CMAKE_AUTOQUIC ON) # compiles QUIC ui files
add_executable(osc main.cpp mainwindow.cpp mainwindow.h mainwindow.ui)
target_link_libraries(osc Qt6::Widgets Qt6::Core)
