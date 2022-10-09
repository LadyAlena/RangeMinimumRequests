cmake_minimum_required(VERSION 3.22.0)

project(RangeMinimumRequests)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_library(alg1LIB SHARED
../source/alg1/RangeMinimumRequests1.cpp 
../source/alg1/RangeMinimumRequests1.h
)

add_library(alg2LIB SHARED 
../source/alg2/RangeMinimumRequests2.cpp 
../source/alg2/RangeMinimumRequests2.h
)

add_library(alg3LIB SHARED 
../source/alg3/RangeMinimumRequests3.cpp 
../source/alg3/RangeMinimumRequests3.h
)

add_executable(Range_minimum_requests ../source/main.cpp)

target_link_libraries(Range_minimum_requests
PRIVATE alg1LIB
PRIVATE alg2LIB
PRIVATE alg3LIB)