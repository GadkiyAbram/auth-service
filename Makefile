# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/src/auth-service

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/src/auth-service

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /usr/src/auth-service/CMakeFiles /usr/src/auth-service//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /usr/src/auth-service/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named auth-service

# Build rule for target.
auth-service: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 auth-service
.PHONY : auth-service

# fast build rule for target.
auth-service/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/build
.PHONY : auth-service/fast

constants/auth/Auth.o: constants/auth/Auth.cpp.o
.PHONY : constants/auth/Auth.o

# target to build an object file
constants/auth/Auth.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/auth/Auth.cpp.o
.PHONY : constants/auth/Auth.cpp.o

constants/auth/Auth.i: constants/auth/Auth.cpp.i
.PHONY : constants/auth/Auth.i

# target to preprocess a source file
constants/auth/Auth.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/auth/Auth.cpp.i
.PHONY : constants/auth/Auth.cpp.i

constants/auth/Auth.s: constants/auth/Auth.cpp.s
.PHONY : constants/auth/Auth.s

# target to generate assembly for a file
constants/auth/Auth.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/auth/Auth.cpp.s
.PHONY : constants/auth/Auth.cpp.s

constants/entities/Entities.o: constants/entities/Entities.cpp.o
.PHONY : constants/entities/Entities.o

# target to build an object file
constants/entities/Entities.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/entities/Entities.cpp.o
.PHONY : constants/entities/Entities.cpp.o

constants/entities/Entities.i: constants/entities/Entities.cpp.i
.PHONY : constants/entities/Entities.i

# target to preprocess a source file
constants/entities/Entities.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/entities/Entities.cpp.i
.PHONY : constants/entities/Entities.cpp.i

constants/entities/Entities.s: constants/entities/Entities.cpp.s
.PHONY : constants/entities/Entities.s

# target to generate assembly for a file
constants/entities/Entities.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/entities/Entities.cpp.s
.PHONY : constants/entities/Entities.cpp.s

constants/env/Env.o: constants/env/Env.cpp.o
.PHONY : constants/env/Env.o

# target to build an object file
constants/env/Env.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/env/Env.cpp.o
.PHONY : constants/env/Env.cpp.o

constants/env/Env.i: constants/env/Env.cpp.i
.PHONY : constants/env/Env.i

# target to preprocess a source file
constants/env/Env.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/env/Env.cpp.i
.PHONY : constants/env/Env.cpp.i

constants/env/Env.s: constants/env/Env.cpp.s
.PHONY : constants/env/Env.s

# target to generate assembly for a file
constants/env/Env.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/env/Env.cpp.s
.PHONY : constants/env/Env.cpp.s

constants/http/Http.o: constants/http/Http.cpp.o
.PHONY : constants/http/Http.o

# target to build an object file
constants/http/Http.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/http/Http.cpp.o
.PHONY : constants/http/Http.cpp.o

constants/http/Http.i: constants/http/Http.cpp.i
.PHONY : constants/http/Http.i

# target to preprocess a source file
constants/http/Http.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/http/Http.cpp.i
.PHONY : constants/http/Http.cpp.i

constants/http/Http.s: constants/http/Http.cpp.s
.PHONY : constants/http/Http.s

# target to generate assembly for a file
constants/http/Http.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/http/Http.cpp.s
.PHONY : constants/http/Http.cpp.s

constants/http/methods/Methods.o: constants/http/methods/Methods.cpp.o
.PHONY : constants/http/methods/Methods.o

# target to build an object file
constants/http/methods/Methods.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/http/methods/Methods.cpp.o
.PHONY : constants/http/methods/Methods.cpp.o

constants/http/methods/Methods.i: constants/http/methods/Methods.cpp.i
.PHONY : constants/http/methods/Methods.i

# target to preprocess a source file
constants/http/methods/Methods.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/http/methods/Methods.cpp.i
.PHONY : constants/http/methods/Methods.cpp.i

constants/http/methods/Methods.s: constants/http/methods/Methods.cpp.s
.PHONY : constants/http/methods/Methods.s

# target to generate assembly for a file
constants/http/methods/Methods.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/http/methods/Methods.cpp.s
.PHONY : constants/http/methods/Methods.cpp.s

constants/http/responseCodes/ResponseCodes.o: constants/http/responseCodes/ResponseCodes.cpp.o
.PHONY : constants/http/responseCodes/ResponseCodes.o

# target to build an object file
constants/http/responseCodes/ResponseCodes.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/http/responseCodes/ResponseCodes.cpp.o
.PHONY : constants/http/responseCodes/ResponseCodes.cpp.o

constants/http/responseCodes/ResponseCodes.i: constants/http/responseCodes/ResponseCodes.cpp.i
.PHONY : constants/http/responseCodes/ResponseCodes.i

# target to preprocess a source file
constants/http/responseCodes/ResponseCodes.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/http/responseCodes/ResponseCodes.cpp.i
.PHONY : constants/http/responseCodes/ResponseCodes.cpp.i

constants/http/responseCodes/ResponseCodes.s: constants/http/responseCodes/ResponseCodes.cpp.s
.PHONY : constants/http/responseCodes/ResponseCodes.s

# target to generate assembly for a file
constants/http/responseCodes/ResponseCodes.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/http/responseCodes/ResponseCodes.cpp.s
.PHONY : constants/http/responseCodes/ResponseCodes.cpp.s

constants/routes/Routes.o: constants/routes/Routes.cpp.o
.PHONY : constants/routes/Routes.o

# target to build an object file
constants/routes/Routes.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/routes/Routes.cpp.o
.PHONY : constants/routes/Routes.cpp.o

constants/routes/Routes.i: constants/routes/Routes.cpp.i
.PHONY : constants/routes/Routes.i

# target to preprocess a source file
constants/routes/Routes.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/routes/Routes.cpp.i
.PHONY : constants/routes/Routes.cpp.i

constants/routes/Routes.s: constants/routes/Routes.cpp.s
.PHONY : constants/routes/Routes.s

# target to generate assembly for a file
constants/routes/Routes.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/constants/routes/Routes.cpp.s
.PHONY : constants/routes/Routes.cpp.s

database/DBConnection.o: database/DBConnection.cpp.o
.PHONY : database/DBConnection.o

# target to build an object file
database/DBConnection.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/database/DBConnection.cpp.o
.PHONY : database/DBConnection.cpp.o

database/DBConnection.i: database/DBConnection.cpp.i
.PHONY : database/DBConnection.i

# target to preprocess a source file
database/DBConnection.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/database/DBConnection.cpp.i
.PHONY : database/DBConnection.cpp.i

database/DBConnection.s: database/DBConnection.cpp.s
.PHONY : database/DBConnection.s

# target to generate assembly for a file
database/DBConnection.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/database/DBConnection.cpp.s
.PHONY : database/DBConnection.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/main.cpp.s
.PHONY : main.cpp.s

models/Auth/jwt/JWTAuth.o: models/Auth/jwt/JWTAuth.cpp.o
.PHONY : models/Auth/jwt/JWTAuth.o

# target to build an object file
models/Auth/jwt/JWTAuth.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/models/Auth/jwt/JWTAuth.cpp.o
.PHONY : models/Auth/jwt/JWTAuth.cpp.o

models/Auth/jwt/JWTAuth.i: models/Auth/jwt/JWTAuth.cpp.i
.PHONY : models/Auth/jwt/JWTAuth.i

# target to preprocess a source file
models/Auth/jwt/JWTAuth.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/models/Auth/jwt/JWTAuth.cpp.i
.PHONY : models/Auth/jwt/JWTAuth.cpp.i

models/Auth/jwt/JWTAuth.s: models/Auth/jwt/JWTAuth.cpp.s
.PHONY : models/Auth/jwt/JWTAuth.s

# target to generate assembly for a file
models/Auth/jwt/JWTAuth.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/models/Auth/jwt/JWTAuth.cpp.s
.PHONY : models/Auth/jwt/JWTAuth.cpp.s

models/Auth/jwt/entity/JWTAuthEntity.o: models/Auth/jwt/entity/JWTAuthEntity.cpp.o
.PHONY : models/Auth/jwt/entity/JWTAuthEntity.o

# target to build an object file
models/Auth/jwt/entity/JWTAuthEntity.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/models/Auth/jwt/entity/JWTAuthEntity.cpp.o
.PHONY : models/Auth/jwt/entity/JWTAuthEntity.cpp.o

models/Auth/jwt/entity/JWTAuthEntity.i: models/Auth/jwt/entity/JWTAuthEntity.cpp.i
.PHONY : models/Auth/jwt/entity/JWTAuthEntity.i

# target to preprocess a source file
models/Auth/jwt/entity/JWTAuthEntity.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/models/Auth/jwt/entity/JWTAuthEntity.cpp.i
.PHONY : models/Auth/jwt/entity/JWTAuthEntity.cpp.i

models/Auth/jwt/entity/JWTAuthEntity.s: models/Auth/jwt/entity/JWTAuthEntity.cpp.s
.PHONY : models/Auth/jwt/entity/JWTAuthEntity.s

# target to generate assembly for a file
models/Auth/jwt/entity/JWTAuthEntity.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/models/Auth/jwt/entity/JWTAuthEntity.cpp.s
.PHONY : models/Auth/jwt/entity/JWTAuthEntity.cpp.s

models/User/User.o: models/User/User.cpp.o
.PHONY : models/User/User.o

# target to build an object file
models/User/User.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/models/User/User.cpp.o
.PHONY : models/User/User.cpp.o

models/User/User.i: models/User/User.cpp.i
.PHONY : models/User/User.i

# target to preprocess a source file
models/User/User.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/models/User/User.cpp.i
.PHONY : models/User/User.cpp.i

models/User/User.s: models/User/User.cpp.s
.PHONY : models/User/User.s

# target to generate assembly for a file
models/User/User.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/models/User/User.cpp.s
.PHONY : models/User/User.cpp.s

server/Server.o: server/Server.cpp.o
.PHONY : server/Server.o

# target to build an object file
server/Server.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/server/Server.cpp.o
.PHONY : server/Server.cpp.o

server/Server.i: server/Server.cpp.i
.PHONY : server/Server.i

# target to preprocess a source file
server/Server.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/server/Server.cpp.i
.PHONY : server/Server.cpp.i

server/Server.s: server/Server.cpp.s
.PHONY : server/Server.s

# target to generate assembly for a file
server/Server.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/server/Server.cpp.s
.PHONY : server/Server.cpp.s

server/router/Router.o: server/router/Router.cpp.o
.PHONY : server/router/Router.o

# target to build an object file
server/router/Router.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/server/router/Router.cpp.o
.PHONY : server/router/Router.cpp.o

server/router/Router.i: server/router/Router.cpp.i
.PHONY : server/router/Router.i

# target to preprocess a source file
server/router/Router.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/server/router/Router.cpp.i
.PHONY : server/router/Router.cpp.i

server/router/Router.s: server/router/Router.cpp.s
.PHONY : server/router/Router.s

# target to generate assembly for a file
server/router/Router.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/server/router/Router.cpp.s
.PHONY : server/router/Router.cpp.s

services/user/UserDTO.o: services/user/UserDTO.cpp.o
.PHONY : services/user/UserDTO.o

# target to build an object file
services/user/UserDTO.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/services/user/UserDTO.cpp.o
.PHONY : services/user/UserDTO.cpp.o

services/user/UserDTO.i: services/user/UserDTO.cpp.i
.PHONY : services/user/UserDTO.i

# target to preprocess a source file
services/user/UserDTO.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/services/user/UserDTO.cpp.i
.PHONY : services/user/UserDTO.cpp.i

services/user/UserDTO.s: services/user/UserDTO.cpp.s
.PHONY : services/user/UserDTO.s

# target to generate assembly for a file
services/user/UserDTO.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/services/user/UserDTO.cpp.s
.PHONY : services/user/UserDTO.cpp.s

services/user/UserRepository.o: services/user/UserRepository.cpp.o
.PHONY : services/user/UserRepository.o

# target to build an object file
services/user/UserRepository.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/services/user/UserRepository.cpp.o
.PHONY : services/user/UserRepository.cpp.o

services/user/UserRepository.i: services/user/UserRepository.cpp.i
.PHONY : services/user/UserRepository.i

# target to preprocess a source file
services/user/UserRepository.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/services/user/UserRepository.cpp.i
.PHONY : services/user/UserRepository.cpp.i

services/user/UserRepository.s: services/user/UserRepository.cpp.s
.PHONY : services/user/UserRepository.s

# target to generate assembly for a file
services/user/UserRepository.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/services/user/UserRepository.cpp.s
.PHONY : services/user/UserRepository.cpp.s

topics/pointers/Pointer.o: topics/pointers/Pointer.cpp.o
.PHONY : topics/pointers/Pointer.o

# target to build an object file
topics/pointers/Pointer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/topics/pointers/Pointer.cpp.o
.PHONY : topics/pointers/Pointer.cpp.o

topics/pointers/Pointer.i: topics/pointers/Pointer.cpp.i
.PHONY : topics/pointers/Pointer.i

# target to preprocess a source file
topics/pointers/Pointer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/topics/pointers/Pointer.cpp.i
.PHONY : topics/pointers/Pointer.cpp.i

topics/pointers/Pointer.s: topics/pointers/Pointer.cpp.s
.PHONY : topics/pointers/Pointer.s

# target to generate assembly for a file
topics/pointers/Pointer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/auth-service.dir/build.make CMakeFiles/auth-service.dir/topics/pointers/Pointer.cpp.s
.PHONY : topics/pointers/Pointer.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... auth-service"
	@echo "... constants/auth/Auth.o"
	@echo "... constants/auth/Auth.i"
	@echo "... constants/auth/Auth.s"
	@echo "... constants/entities/Entities.o"
	@echo "... constants/entities/Entities.i"
	@echo "... constants/entities/Entities.s"
	@echo "... constants/env/Env.o"
	@echo "... constants/env/Env.i"
	@echo "... constants/env/Env.s"
	@echo "... constants/http/Http.o"
	@echo "... constants/http/Http.i"
	@echo "... constants/http/Http.s"
	@echo "... constants/http/methods/Methods.o"
	@echo "... constants/http/methods/Methods.i"
	@echo "... constants/http/methods/Methods.s"
	@echo "... constants/http/responseCodes/ResponseCodes.o"
	@echo "... constants/http/responseCodes/ResponseCodes.i"
	@echo "... constants/http/responseCodes/ResponseCodes.s"
	@echo "... constants/routes/Routes.o"
	@echo "... constants/routes/Routes.i"
	@echo "... constants/routes/Routes.s"
	@echo "... database/DBConnection.o"
	@echo "... database/DBConnection.i"
	@echo "... database/DBConnection.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... models/Auth/jwt/JWTAuth.o"
	@echo "... models/Auth/jwt/JWTAuth.i"
	@echo "... models/Auth/jwt/JWTAuth.s"
	@echo "... models/Auth/jwt/entity/JWTAuthEntity.o"
	@echo "... models/Auth/jwt/entity/JWTAuthEntity.i"
	@echo "... models/Auth/jwt/entity/JWTAuthEntity.s"
	@echo "... models/User/User.o"
	@echo "... models/User/User.i"
	@echo "... models/User/User.s"
	@echo "... server/Server.o"
	@echo "... server/Server.i"
	@echo "... server/Server.s"
	@echo "... server/router/Router.o"
	@echo "... server/router/Router.i"
	@echo "... server/router/Router.s"
	@echo "... services/user/UserDTO.o"
	@echo "... services/user/UserDTO.i"
	@echo "... services/user/UserDTO.s"
	@echo "... services/user/UserRepository.o"
	@echo "... services/user/UserRepository.i"
	@echo "... services/user/UserRepository.s"
	@echo "... topics/pointers/Pointer.o"
	@echo "... topics/pointers/Pointer.i"
	@echo "... topics/pointers/Pointer.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

