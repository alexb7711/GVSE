# Specify minimum required CMake version
cmake_minimum_required(VERSION 3.11)

# Enable CMake Features
include(FetchContent)

# Define project name and set project version
set(prj gvse)
project(${prj} VERSION 0.0)

# Set C minimum standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dependencies
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_TAG        v1.92.1
)
#FetchContent_Declare(
#        implot
#        GIT_REPOSITORY https://github.com/epezent/implot
#        GIT_TAG        v0.16
#)
FetchContent_MakeAvailable(imgui)

# Copy the version file and make appropriate conversion
configure_file(include/version.h.in include/version.h)

# Find all the source files
file(GLOB_RECURSE sources ${CMAKE_SOURCE_DIR}/src/*.cpp)
list(APPEND sources
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

# Add executable target from the `sources` list
add_executable(${prj} ${sources})

# Define the include directories during compile time
target_include_directories(${prj}
        PUBLIC
        ${PROJECT_BINARY_DIR}/include

        PRIVATE
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
        ${OPENGL_DIRS}
        ${SDL2_DIRS}
)

# Specify libraries or flags when linking a given target
target_link_libraries(${prj}
        PRIVATE
        ${OPENGL_LIBRARIES}
        ${SDL2_LIBRARIES}
)
