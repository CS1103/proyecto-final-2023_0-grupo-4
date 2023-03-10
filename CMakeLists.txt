find_program(LSB_RELEASE_EXEC lsb_release)
execute_process(
  COMMAND ${LSB_RELEASE_EXEC} -is
  OUTPUT_VARIABLE LSB_RELEASE_ID_SHORT
  OUTPUT_STRIP_TRAILING_WHITESPACE)# Get linux distro

message(STATUS "Current distro: ${LSB_RELEASE_ID_SHORT}")
message(STATUS "Debug mode:" ${CMAKE_BUILD_TYPE})

cmake_minimum_required(VERSION 3.22)
project(Maze
  VERSION 0.1
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(${CMAKE_VERSION} VERSION_LESS "3.25.2")
  message(
    STATUS
    "CMake version is less than 3.25.2,
                                                                                                                                                                                                                                                                                              upgrade to silence unnecesary warnings")
endif()

# raylib
message(STATUS "Searching for raylib")
if(NOT LSB_RELEASE_ID_SHORT STREQUAL "Ubuntu")
  # Kevin fix
  find_package(raylib QUIET)
endif()
if(NOT raylib_FOUND)
  message(STATUS "raylib not found, downloading...")
  include(FetchContent)
  if(${CMAKE_VERSION} VERSION_LESS "3.25.2")
    fetchcontent_declare(
      raylib
      GIT_REPOSITORY https://github.com/raysan5/raylib.git
      GIT_TAG 4.2.0)
  else()
    fetchcontent_declare(
      raylib
      GIT_REPOSITORY https://github.com/raysan5/raylib.git
      GIT_TAG 4.2.0
      SYSTEM)
  endif()
  fetchcontent_makeavailable(raylib)
endif()

# raylib-cpp is not installed as cmake package with aur
if(NOT LSB_RELEASE_ID_SHORT STREQUAL "Arch")
  message(STATUS "Searching for raylib_cpp")
  # raylib_cpp
  find_package(raylib_cpp QUIET)
  if(NOT raylib_cpp_FOUND)
    message(STATUS "raylib_cpp not found, downloading...")
    include(FetchContent)
    if(${CMAKE_VERSION} VERSION_LESS "3.25.2")
      fetchcontent_declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/Enriquefft/raylib-cpp.git)
    else()
      fetchcontent_declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/Enriquefft/raylib-cpp.git
        SYSTEM)
    endif()
    fetchcontent_makeavailable(raylib_cpp)
  endif()
endif()

# Set option to control setting the resource path variable
option(USE_INSTALL_RESOURCE_PATH "Set resource path to install location" OFF)

if(NOT USE_INSTALL_RESOURCE_PATH)
  set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/assets/")
else()
  set(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/assets/")
endif()

configure_file(include/resources.hpp.in resources.hpp)

############### MAIN ###############

# This is the main part:

# set(MODULES "System" "Board" "Utils")
set(MODULES "All")

set(INCLUDE_DIRS "")
set(SOURCES "")

if(MODULES STREQUAL "All")
  message(STATUS "Recursively searching for all source files")
  file(GLOB_RECURSE headers_list *.hpp)
  foreach(file_path ${headers_list})
    get_filename_component(dir_path ${file_path} PATH)
    list(APPEND INCLUDE_DIRS ${dir_path})
  endforeach()
  file(GLOB_RECURSE SOURCES "src/*.cpp")
  # If Sources is empty, search in $MODULES
elseif(SOURCES STREQUAL "")
  message(STATUS "Recursively searching for modules: ${MODULES}")
  foreach(MODULE ${MODULES})
    list(APPEND INCLUDE_DIRS "src/${MODULE}")
    file(GLOB_RECURSE SOURCES "${SOURCES}" "src/${MODULE}/*.cpp")
  endforeach()
endif()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

# append src/main to SOURCES
list(APPEND SOURCES src/main.cpp)
message(STATUS "inc: ${CMAKE_CURRENT_SOURCE_DIR}/include")

list(APPEND INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(WIN32)
  set(APP_ICON_RESOURCE "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc")
  add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${APP_ICON_RESOURCE})
else()
  add_executable(${PROJECT_NAME} ${SOURCES})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})

####################################

# if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#   set(FLAGS
#     -Weverything
#     -Wno-string-compare
#     -Wno-c++98-compat
#     -Wno-c++98-compat-pedantic
#     -fsanitize=address
#     -fsanitize=undefined
#     -fno-sanitize-recover=all
#   )
#   target_link_options(
#     ${PROJECT_NAME}
#     PRIVATE -fsanitize=address -fsanitize=undefined)
# else()
#   set(FLAGS
#     -Wall
#     -Wextra
#     -Wshadow
#     -pedantic
#   )
# endif()
set(FLAGS -O3)

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib" CXX_STANDARD 20)

if(LSB_RELEASE_ID_SHORT STREQUAL "Arch")
  target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
else()
  target_link_libraries(${PROJECT_NAME} PRIVATE raylib raylib_cpp)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/assets
  DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}")
