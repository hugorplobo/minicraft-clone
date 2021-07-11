cmake_minimum_required(VERSION 3.15)
project(minicraft)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME} main.c)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Add libraries template
# add_library(name ${CMAKE_SOURCE_DIR}/path.c)

add_library(player ${CMAKE_SOURCE_DIR}/entities/player/player.c)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libraylib.a msvcrt opengl32 gdi32 winmm kernel32 shell32 user32 player)
endif (WIN32)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libraylib.a m GL pthread dl rt X11 player)
endif (UNIX)
