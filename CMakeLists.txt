cmake_minimum_required(VERSION 3.12)
project(sfml)

set(CMAKE_CXX_STANDARD 14)

add_executable(sfml main.cpp)

# Define sources and executable
set(EXECUTABLE_NAME "MySFML")
add_executable(${EXECUTABLE_NAME} main.cpp window.cpp window.h soldado.cpp soldado.h Enemigo.cpp Enemigo.h Inicio.cpp Inicio.h)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()