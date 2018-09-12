cmake_minimum_required(VERSION 3.1)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
project(grey_screen_with_no_music)

enable_language(C)
enable_language(CXX)

include("defaults.cmake")

find_ncurses()

output_flags("DEBUG" on)

add_definitions(-DUSE_LD)

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(grey_screen_with_no_music
  "src/grey_screen_with_no_music.cpp")
if(MSVC)
  target_link_libraries(grey_screen_with_no_music debug "${NCURSES_LIBRARY_DEBUG}" optimized "${NCURSES_LIBRARY}")
else()
  target_link_libraries(grey_screen_with_no_music "${NCURSES_LIBRARY}")
endif()
