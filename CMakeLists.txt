cmake_minimum_required(VERSION 3.28)
project(auth-service)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

find_package(PostgreSQL REQUIRED)
find_package(Boost REQUIRED)
find_package(OpenSSL REQUIRED)
#find_package(laserpants_dotenv)

find_library(BCRYPT_LIB bcrypt REQUIRED HINTS /usr/local/lib)

include_directories(${PostgreSQL_INCLUDE_DIRS})
include_directories(/usr/local/include/nlohmann)
include_directories("/usr/local/include/laserpants/dotenv-0.9.3")

set(HEADERS
    models/User/User.h
    models/Auth/Auth.h
    constants/http/Http.h
    constants/http/methods/Methods.h
    constants/http/responseCodes/ResponseCodes.h
    server/router/Router.h
    constants/routes/Routes.h
    services/user/UserDTO.h
    services/user/UserRepository.h
    server/IRequestHandler.h
    constants/entities/Entities.h
    models/Auth/jwt/JWTAuth.h
    models/Auth/jwt/entity/JWTAuthEntity.h
    constants/auth/Auth.h
    )

set(SOURCES
    main.cpp
    database/DBConnection.cpp
    topics/pointers/Pointer.cpp
    server/Server.cpp
    models/User/User.cpp
    constants/http/Http.cpp
    constants/http/methods/Methods.cpp
    constants/http/responseCodes/ResponseCodes.cpp
    server/router/Router.cpp
    constants/routes/Routes.cpp
    services/user/UserDTO.cpp
    services/user/UserRepository.cpp
    constants/entities/Entities.cpp
    models/Auth/jwt/JWTAuth.cpp
    models/Auth/jwt/entity/JWTAuthEntity.cpp
    constants/auth/Auth.cpp constants/env/Env.cpp constants/env/Env.h)

# Executable
add_executable(auth-service ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(
    auth-service
    ${PostgreSQL_LIBRARIES}
    ${Boost_LIBRARIES}
    pq
    pthread
    ${BCRYPT_LIB}
    /usr/local/lib
    OpenSSL::SSL
    OpenSSL::Crypto
)