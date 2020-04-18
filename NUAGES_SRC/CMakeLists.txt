# cmake
cmake_minimum_required(VERSION 2.8)

# project
project(nuagesDetection)

# compilations
set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-deprecated-declarations -pedantic")
set(CMAKE_C_STANDARD 99)

# sources
add_executable(imaProjet.exe
    main.c
    compute.c
    vector.c
    image.c
)

add_executable(imaProjet_auto.exe
    main_auto.c
    compute.c
    vector.c
    image.c
)

# libs
add_definitions(${GTK2_CFLAGS_OTHER})
find_package(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK2 REQUIRED gtk+-2.0)
include_directories(${GTK2_INCLUDE_DIRS})
link_directories(${GTK2_LIBRARY_DIRS})
target_link_libraries(imaProjet.exe ${GTK2_LIBRARIES})
