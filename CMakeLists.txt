cmake_minimum_required(VERSION 3.1)

project(studypengl LANGUAGES CXX)

cmake_host_system_information(RESULT _HOST_NAME QUERY HOSTNAME)
message(STATUS "HOSTNAME:${_HOST_NAME}")

# trineedle pc
if( _HOST_NAME STREQUAL "zzingo")
    set(BASE_DIR_GLUT "C:/opengl/freeglut-MSVC-3.0.0-2.mp/freeglut")
    set(BASE_DIR_GLFW3 "C:/opengl/glfw-3.2.1.bin.WIN64/glfw-3.2.1.bin.WIN64")
    set(BASE_DIR_GLEW "C:/opengl/glew-2.1.0-win32/glew-2.1.0")
    set(BASE_DIR_GLM "C:/opengl/glm-0.9.9.6/glm")
# my pc
elseif( _HOST_NAME STREQUAL "happy")	
    set(BASE_DIR_GLUT "D:/opengl/freeglut-MSVC-3.0.0-2.mp/freeglut")
    set(BASE_DIR_GLFW3 "D:/opengl/glfw-3.2.1.bin.WIN64/glfw-3.2.1.bin.WIN64")
    set(BASE_DIR_GLEW "D:/opengl/glew-2.1.0-win32/glew-2.1.0")
    set(BASE_DIR_GLM "D:/opengl/glm-0.9.9.6/glm")
endif()

set(SOURCE_FILES    
    main.cpp    
)

# Find GL
find_library( glut NAMES "freeglut" PATHS "${BASE_DIR_GLUT}/lib/x64" )
message(STATUS "Found glut in ${glut}")
find_library( glfw3 NAMES "glfw3" PATHS "${BASE_DIR_GLFW3}/lib-vc2015" )
message(STATUS "Found glfw3 in ${glfw3}")
find_library( GLEW NAMES "glew32" PATHS "${BASE_DIR_GLEW}/lib/Release/x64" )
message(STATUS "Found GLEW in ${GLEW}")

include_directories( "${BASE_DIR_GLUT}/include" )
include_directories( "${BASE_DIR_GLFW3}/include" )
include_directories( "${BASE_DIR_GLEW}/include" )
include_directories( "${BASE_DIR_GLM}" )

# Opengl library
set( LIBS ${glut} ${glfw3} ${GLEW} )
message(STATUS "${LIBS}")
message(STATUS -------------------------------------)

# Build App    
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# libray link - (Build App 후에 라이브러리 연결)
target_link_libraries( ${PROJECT_NAME} ${LIBS} )