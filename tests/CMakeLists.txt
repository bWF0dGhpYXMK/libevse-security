add_executable(tests tests.cpp)

target_include_directories(tests PUBLIC ${GTEST_INCLUDE_DIRS})

find_package(GTest REQUIRED)

target_link_libraries(tests PRIVATE
    evse_security
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARIES} 
)

add_test(tests tests)

install(
    PROGRAMS "generate_test_certs.sh"
    DESTINATION "${CMAKE_BINARY_DIR}/tests"
)

install(
    DIRECTORY "configs"
    DESTINATION "${CMAKE_BINARY_DIR}/tests"
    FILES_MATCHING PATTERN "*.cnf"
)
