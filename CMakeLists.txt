cmake_minimum_required(VERSION 3.10)
project(LeakTest CXX)

find_package(protobuf REQUIRED)
find_package(gRPC REQUIRED)

add_library(TestLib_WithSlice SHARED)
target_sources(TestLib_WithSlice PRIVATE src/TestLib.cpp)
target_compile_definitions(TestLib_WithSlice PRIVATE UseSlice=1)
target_link_libraries(TestLib_WithSlice PUBLIC gRPC::grpc++ gRPC::grpc)

add_library(TestLib_WithoutSlice SHARED)
target_sources(TestLib_WithoutSlice PRIVATE src/TestLib.cpp)
target_link_libraries(TestLib_WithoutSlice PUBLIC gRPC::grpc++ gRPC::grpc)

add_executable(LoadTestWithSlice src/LoadTest.cpp)
target_link_libraries(LoadTestWithSlice ${CMAKE_DL_LIBS})
target_compile_definitions(LoadTestWithSlice PRIVATE LibPath="$<TARGET_FILE:TestLib_WithSlice>")

add_executable(LoadTestWithoutSlice src/LoadTest.cpp)
target_link_libraries(LoadTestWithoutSlice ${CMAKE_DL_LIBS} )
target_compile_definitions(LoadTestWithoutSlice PRIVATE LibPath="$<TARGET_FILE:TestLib_WithoutSlice>")
