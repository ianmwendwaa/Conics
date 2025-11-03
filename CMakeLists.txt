cmake_minimum_required(VERSION 3.19)
project(Conics LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(Conics
    main.cpp
    src/parabola/parabola.h src/parabola/parabola.cpp
    src/hyperbola/hyperbola.h src/hyperbola/hyperbola.cpp

    menu/menu.h
)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(Conics
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS Conics
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
