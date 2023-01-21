file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
)

add_executable(${PROJECT_TEST} ${SRC_FILES})

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.0
)
FetchContent_MakeAvailable(googletest)

target_link_libraries(${PROJECT_TEST} PRIVATE ${PROJECT_LIBRARY} gtest gmock gtest_main)
