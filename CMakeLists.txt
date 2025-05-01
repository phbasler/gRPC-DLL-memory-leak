cmake_minimum_required(VERSION 3.28)
project(LeakTest CXX)

add_library(TestLib_WithSplice SHARED)
target_sources(TestLib_WithSplice PRIVATE src/TestLib.cpp)
target_compile_definitions(TestLib_WithSplice PRIVATE UseSplice=1)

add_library(TestLib_WithoutSplice SHARED)
target_sources(TestLib_WithoutSplice PRIVATE src/TestLib.cpp)

add_executable(LoadTestWithSplice src/LoadTest.cpp)
target_link_libraries(LoadTestWithSplice ${CMAKE_DL_LIBS})
target_compile_definitions(LoadTestWithSplice PRIVATE LibPath="$<TARGET_FILE:TestLib_WithSplice>")

add_executable(LoadTestWithoutSplice src/LoadTest.cpp)
target_link_libraries(LoadTestWithoutSplice ${CMAKE_DL_LIBS} )
target_compile_definitions(LoadTestWithoutSplice PRIVATE LibPath="$<TARGET_FILE:TestLib_WithoutSplice>")
