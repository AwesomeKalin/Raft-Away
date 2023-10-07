cmake_minimum_required(VERSION 3.5)
project(raft_away VERSION 1.0)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.5.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

# tmx
find_package(tmx QUIET)
if (NOT tmx_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        tmx
        GIT_REPOSITORY https://github.com/baylej/tmx.git
        GIT_TAG tmx_1.4.0
    )
    FetchContent_MakeAvailable(tmx)
endif()

# This is the main part:
set(SOURCES 
    main.cpp 
    ./classes/player.cpp
    ./scenes/mainscene/mainscene.cpp
    ./scenes/mainscene/terrainrender.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME}
  PRIVATE
    classes/
    scenes/mainscene
)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp tmx ZLIB LibXml2 Iconv xz)

# Copy the resources
file(GLOB resources resources/*)
set(test_resources)
list(APPEND test_resources ${resources})
file(COPY ${test_resources} DESTINATION "resources/")

# That's it! You should have an example executable that you can run. Have fun!
