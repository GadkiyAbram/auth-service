cmake_minimum_required(VERSION 3.28)
project(CplusPlusLazy)

set(CMAKE_CXX_STANDARD 11)

# Find and include PostgreSQL
find_package(PostgreSQL REQUIRED)
include_directories(${PostgreSQL_INCLUDE_DIRS})

set(SOURCES
    main.cpp
    database/DBConnection.cpp
    topics/pointers/Pointer.cpp
    server/Server.cpp
    models/User/User.cpp
    models/User/User.h
        models/Auth/Auth.cpp models/Auth/Auth.h)

# Executable
add_executable(cplusplus ${SOURCES})

# Link libraries
target_link_libraries(
    cplusplus
    ${PostgreSQL_LIBRARIES}
    pq
    pthread
)
