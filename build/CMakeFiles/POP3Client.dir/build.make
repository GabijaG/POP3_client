# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gabija/Desktop/POP3_client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gabija/Desktop/POP3_client/build

# Include any dependencies generated for this target.
include CMakeFiles/POP3Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/POP3Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/POP3Client.dir/flags.make

CMakeFiles/POP3Client.dir/POP3_Client.c.o: CMakeFiles/POP3Client.dir/flags.make
CMakeFiles/POP3Client.dir/POP3_Client.c.o: ../POP3_Client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabija/Desktop/POP3_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/POP3Client.dir/POP3_Client.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/POP3Client.dir/POP3_Client.c.o   -c /home/gabija/Desktop/POP3_client/POP3_Client.c

CMakeFiles/POP3Client.dir/POP3_Client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/POP3Client.dir/POP3_Client.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gabija/Desktop/POP3_client/POP3_Client.c > CMakeFiles/POP3Client.dir/POP3_Client.c.i

CMakeFiles/POP3Client.dir/POP3_Client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/POP3Client.dir/POP3_Client.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gabija/Desktop/POP3_client/POP3_Client.c -o CMakeFiles/POP3Client.dir/POP3_Client.c.s

CMakeFiles/POP3Client.dir/ssl_connection.c.o: CMakeFiles/POP3Client.dir/flags.make
CMakeFiles/POP3Client.dir/ssl_connection.c.o: ../ssl_connection.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabija/Desktop/POP3_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/POP3Client.dir/ssl_connection.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/POP3Client.dir/ssl_connection.c.o   -c /home/gabija/Desktop/POP3_client/ssl_connection.c

CMakeFiles/POP3Client.dir/ssl_connection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/POP3Client.dir/ssl_connection.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gabija/Desktop/POP3_client/ssl_connection.c > CMakeFiles/POP3Client.dir/ssl_connection.c.i

CMakeFiles/POP3Client.dir/ssl_connection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/POP3Client.dir/ssl_connection.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gabija/Desktop/POP3_client/ssl_connection.c -o CMakeFiles/POP3Client.dir/ssl_connection.c.s

CMakeFiles/POP3Client.dir/user_UI.c.o: CMakeFiles/POP3Client.dir/flags.make
CMakeFiles/POP3Client.dir/user_UI.c.o: ../user_UI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabija/Desktop/POP3_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/POP3Client.dir/user_UI.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/POP3Client.dir/user_UI.c.o   -c /home/gabija/Desktop/POP3_client/user_UI.c

CMakeFiles/POP3Client.dir/user_UI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/POP3Client.dir/user_UI.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gabija/Desktop/POP3_client/user_UI.c > CMakeFiles/POP3Client.dir/user_UI.c.i

CMakeFiles/POP3Client.dir/user_UI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/POP3Client.dir/user_UI.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gabija/Desktop/POP3_client/user_UI.c -o CMakeFiles/POP3Client.dir/user_UI.c.s

CMakeFiles/POP3Client.dir/pop3_clientLib.c.o: CMakeFiles/POP3Client.dir/flags.make
CMakeFiles/POP3Client.dir/pop3_clientLib.c.o: ../pop3_clientLib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabija/Desktop/POP3_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/POP3Client.dir/pop3_clientLib.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/POP3Client.dir/pop3_clientLib.c.o   -c /home/gabija/Desktop/POP3_client/pop3_clientLib.c

CMakeFiles/POP3Client.dir/pop3_clientLib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/POP3Client.dir/pop3_clientLib.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gabija/Desktop/POP3_client/pop3_clientLib.c > CMakeFiles/POP3Client.dir/pop3_clientLib.c.i

CMakeFiles/POP3Client.dir/pop3_clientLib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/POP3Client.dir/pop3_clientLib.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gabija/Desktop/POP3_client/pop3_clientLib.c -o CMakeFiles/POP3Client.dir/pop3_clientLib.c.s

CMakeFiles/POP3Client.dir/loggerLib.c.o: CMakeFiles/POP3Client.dir/flags.make
CMakeFiles/POP3Client.dir/loggerLib.c.o: ../loggerLib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabija/Desktop/POP3_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/POP3Client.dir/loggerLib.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/POP3Client.dir/loggerLib.c.o   -c /home/gabija/Desktop/POP3_client/loggerLib.c

CMakeFiles/POP3Client.dir/loggerLib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/POP3Client.dir/loggerLib.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gabija/Desktop/POP3_client/loggerLib.c > CMakeFiles/POP3Client.dir/loggerLib.c.i

CMakeFiles/POP3Client.dir/loggerLib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/POP3Client.dir/loggerLib.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gabija/Desktop/POP3_client/loggerLib.c -o CMakeFiles/POP3Client.dir/loggerLib.c.s

# Object files for target POP3Client
POP3Client_OBJECTS = \
"CMakeFiles/POP3Client.dir/POP3_Client.c.o" \
"CMakeFiles/POP3Client.dir/ssl_connection.c.o" \
"CMakeFiles/POP3Client.dir/user_UI.c.o" \
"CMakeFiles/POP3Client.dir/pop3_clientLib.c.o" \
"CMakeFiles/POP3Client.dir/loggerLib.c.o"

# External object files for target POP3Client
POP3Client_EXTERNAL_OBJECTS =

POP3Client: CMakeFiles/POP3Client.dir/POP3_Client.c.o
POP3Client: CMakeFiles/POP3Client.dir/ssl_connection.c.o
POP3Client: CMakeFiles/POP3Client.dir/user_UI.c.o
POP3Client: CMakeFiles/POP3Client.dir/pop3_clientLib.c.o
POP3Client: CMakeFiles/POP3Client.dir/loggerLib.c.o
POP3Client: CMakeFiles/POP3Client.dir/build.make
POP3Client: CMakeFiles/POP3Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gabija/Desktop/POP3_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable POP3Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/POP3Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/POP3Client.dir/build: POP3Client

.PHONY : CMakeFiles/POP3Client.dir/build

CMakeFiles/POP3Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/POP3Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/POP3Client.dir/clean

CMakeFiles/POP3Client.dir/depend:
	cd /home/gabija/Desktop/POP3_client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gabija/Desktop/POP3_client /home/gabija/Desktop/POP3_client /home/gabija/Desktop/POP3_client/build /home/gabija/Desktop/POP3_client/build /home/gabija/Desktop/POP3_client/build/CMakeFiles/POP3Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/POP3Client.dir/depend

