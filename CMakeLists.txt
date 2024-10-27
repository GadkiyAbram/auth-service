cmake_minimum_required(VERSION 3.28)
project(CplusPlusLazy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

find_package(PostgreSQL REQUIRED)
find_package(Boost REQUIRED)
include_directories(${PostgreSQL_INCLUDE_DIRS})
include_directories(/usr/local/include/nlohmann)

set(SOURCES
    main.cpp
    database/DBConnection.cpp
    topics/pointers/Pointer.cpp
    server/Server.cpp
    models/User/User.cpp
    models/User/User.h
    models/Auth/Auth.cpp
    models/Auth/Auth.h
    constants/http/methods/Methods.h
    constants/http/methods/Methods.cpp
    server/IRequestHandler.h
    server/router/Router.h
    server/router/Router.cpp
    constants/http/responseCodes/ResponseCodes.h
    constants/http/responseCodes/ResponseCodes.cpp
    constants/http/Http.h
    constants/http/Http.cpp
    constants/routes/Routes.h constants/routes/Routes.cpp)

# Executable
add_executable(cplusplus ${SOURCES})

# Link libraries
target_link_libraries(
    cplusplus
    ${PostgreSQL_LIBRARIES}
    ${Boost_LIBRARIES}
    pq
    pthread
)