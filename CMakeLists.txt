cmake_minimum_required(VERSION 3.17)

if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
    set(CMAKE_CUDA_ARCHITECTURES 30 75)
endif()

project(SmoothingOfPointCloud CUDA CXX)

set(CMAKE_CXX_STANDARD 17)
set(CGAL_DISABLE_GMP TRUE)
find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

include(CheckLanguage)
check_language(CUDA)
find_package(OpenMP)

add_executable(SmoothingOfPointCloud main.cpp EGT.cu MCLSEXST.h Arrays.h CPointCloud.cpp CPointCloud.h CCreoPointCloud.cpp CCreoPointCloud.h EGT.cuh)

if(OpenMP_CXX_FOUND)
    target_link_libraries(SmoothingOfPointCloud PUBLIC OpenMP::OpenMP_CXX)
endif()

