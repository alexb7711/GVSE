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
configure_file(${CMAKE_SOURCE_DIR}/include/version.h.in ${CMAKE_SOURCE_DIR}/include/version.h)

# Find all the source files
file(GLOB_RECURSE SRC_SRC ${CMAKE_SOURCE_DIR}/src/*.cpp)
list(APPEND SRC_SRC
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

file(GLOB_RECURSE SRC_LIB ${CMAKE_SOURCE_DIR}/lib/*.cpp)
list(APPEND SRC_LIB
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)


##==============================================================================
# LIBRARY
##==============================================================================
add_library(${prj} SHARED ${SRC_LIB})
target_include_directories(${prj}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include

        PRIVATE
        ${PROJECT_SOURCE_DIR}/lib/include
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
        ${OPENGL_DIRS}
        ${SDL2_DIRS}
)

target_link_libraries(${prj}
        PUBLIC
        PRIVATE
        ${OPENGL_LIBRARIES}
        ${SDL2_LIBRARIES}
)

##==============================================================================
# EXECUTABLE
##==============================================================================
# Add executable target from the `SRC_SRC` list
add_executable(${prj}_bin ${SRC_SRC})

# Define the include directories during compile time
target_include_directories(${prj}_bin
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include

        PRIVATE
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
        ${OPENGL_DIRS}
        ${SDL2_DIRS}
)

# Specify libraries or flags when linking a given target
target_link_libraries(${prj}_bin
        PUBLIC
        ${prj}

        PRIVATE
        ${OPENGL_LIBRARIES}
        ${SDL2_LIBRARIES}
)

