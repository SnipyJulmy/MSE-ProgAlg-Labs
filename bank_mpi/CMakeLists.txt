cmake_minimum_required(VERSION 3.4)
project(bank_mpi)

find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.c)
add_executable(bank_mpi ${SOURCE_FILES})
target_link_libraries(bank_mpi ${MPI_LIBRARIES})

if (MPI_COMPILE_FLAGS)
    set_target_properties(bank_mpi PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif ()

if (MPI_LINK_FLAGS)
    set_target_properties(bank_mpi PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif ()