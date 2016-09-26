cmake_minimum_required(VERSION 3.0)

add_executable(BoilingTire main.cpp)

target_link_libraries(BoilingTire ${POCO_LIBRARIES})