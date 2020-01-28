cmake_minimum_required(VERSION 3.15)
project(nancy)

set(CMAKE_CXX_STANDARD 14)

add_executable(nancy main.cpp Array/Array.cpp Array/Array.h Layers/Con2d/Con2d.cpp Layers/Con2d/Con2d.h Layers/MaxPooling/MaxPooling.cpp Layers/MaxPooling/MaxPooling.h Activations/Activations.cpp Activations/Activations.h Layers/Flatten/Flatten.cpp Layers/Flatten/Flatten.h)