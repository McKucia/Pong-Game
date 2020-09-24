cmake_minimum_required(VERSION 3.17)
project(Pong_sfml)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pong_sfml main.cpp Ball.cpp Ball.hpp Paddle.cpp Paddle.hpp GameManager.cpp GameManager.hpp)

include_directories(includes/sfml)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Pong_sfml ${SFML_LIBRARIES})
endif()