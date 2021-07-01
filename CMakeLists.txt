
cmake_minimum_required(VERSION 3.0)
project(OmniZShooters)

set(FS_BUILD 0)
set(NO_OPTS CACHE BOOL "Set this flag to disable std c++ -O flags")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g)
endif()

if(NO_OPTS)
    add_compile_options(-O0)
else()
    add_compile_options(-O0)
endif()

add_compile_options(-std=c++17)

if(UNIX)
    link_directories(${PROJECT_SOURCE_DIR}/extlib/linux/shared)
    link_directories(${PROJECT_SOURCE_DIR}/extlib/linux/static)
elseif(WIN32)
# To be added in the nearest future
    link_directories(${PROJECT_SOURCE_DIR}/extlib/windows/shared)
    link_directories(${PROJECT_SOURCE_DIR}/extlib/windows/static)
endif()

include_directories(${PROJECT_SOURCE_DIR}/impl/src/
    ${PROJECT_SOURCE_DIR}/impl/include
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/lua
    ${PROJECT_SOURCE_DIR}/SigmaDev/include
    )
   

   
add_subdirectory(${PROJECT_SOURCE_DIR}/impl)
add_subdirectory(${PROJECT_SOURCE_DIR}/SigmaDev)

add_compile_options(-fmax-errors=3)

add_executable(omnizshooters
    ${SOURCE}
    ${HEADERS}
    )

set_target_properties( PROPERTIES LINKER_LANGUAGE CXX)

if (WIN32)
    target_link_libraries(omnizshooters lua dl sfml-graphics sfml-window sfml-system sfml-network sfml-audio boost_filesystem boost_system boost_program_options)
elseif(UNIX)
    target_link_libraries(omnizshooters lua dl sfml-graphics sfml-window sfml-system sfml-network sfml-audio boost_filesystem boost_system boost_program_options)
endif()
