find_package(Qt6 REQUIRED CONFIG COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)  # detects MOC macros and generates relevant code
set(CMAKE_AUTORCC ON)

set(THESE_SOURCES main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
    abstractviewer.cpp abstractviewer.h
    viewerfactory.cpp viewerfactory.h
    recentfiles.cpp recentfiles.h
    recentfilemenu.cpp recentfilemenu.h
    viewerinterfaces.h
    documentviewer.qrc
)
qt6_wrap_ui(THESE_SOURCES mainwindow.ui)
add_executable(osc ${THESE_SOURCES})
target_link_libraries(osc Qt6::Widgets Qt6::Core Qt6::Gui)
target_include_directories(osc PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

if (WIN32)
    add_custom_command(
        TARGET osc
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:osc> $<TARGET_FILE_DIR:osc>
        COMMAND_EXPAND_LISTS
    )
endif()