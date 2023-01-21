file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
)

add_library(${PROJECT_LIBRARY} SHARED ${SRC_FILES})
target_include_directories(${PROJECT_LIBRARY} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(${PROJECT_LIBRARY} PRIVATE -Wall -Werror)
target_compile_features(${PROJECT_LIBRARY} PRIVATE cxx_std_17)

include(FetchContent)

# import fmt
FetchContent_Declare(
    Fmt
    GIT_REPOSITORY "https://github.com/fmtlib/fmt"
    GIT_TAG "7.1.3"
)
FetchContent_MakeAvailable(Fmt)
target_link_libraries(${PROJECT_LIBRARY} PRIVATE fmt)
