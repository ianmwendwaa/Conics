cmake_minimum_required(VERSION 3.31)
project(Conics)
set(CMAKE_CXX_STANDARD 20)

add_executable(Conics main.cpp
        src/circle/circle.cpp src/circle/circle.h
        src/engine/queryengine.cpp src/engine/queryengine.h
        src/hyperbola/hyperbola.cpp src/hyperbola/hyperbola.h
        src/parabola/parabola.cpp src/parabola/parabola.h
        src/geometry/geometry.cpp
        src/geometry/geometry.h
        core/core.cpp
        core/core.h
        types/types.h
)
include_directories("C:/Python313/include")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})