cmake_minimum_required(VERSION 3.28)
project(TDD_Course_Tests)
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(TDD_Course_Tests test.cpp ../maian.cpp
        ../src/Dollar.cpp
        ../src/Dollar.h
        ../src/Euro.cpp
        ../src/Euro.h
        ../src/Money.cpp
        ../src/Money.h
        trafficLightTests.cpp
        ../src/TrafficLight.cpp
        ../src/TrafficLight.h
        ../src/TrafficLightTimer.cpp
        ../src/TrafficLightTimer.h)
target_link_libraries(TDD_Course_Tests gtest_main)
# add_test(NAME example_test COMMAND example)
set(CMAKE_CXX_STANDARD 26)
