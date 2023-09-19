set(TEST_NAME calc_test)

set(TEST_SOURCES
  test_parser.cc
)

add_executable(${TEST_NAME} ${TEST_SOURCES})
include(CTest)
enable_testing()
add_test(NAME Test1 COMMAND ${TEST_NAME} -t Test1)
add_test(NAME Test2 COMMAND ${TEST_NAME} -t Test2)
add_test(NAME Test3 COMMAND ${TEST_NAME} -t Test3)
add_test(NAME Test4 COMMAND ${TEST_NAME} -t Test4)

target_include_directories(${TEST_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(${TEST_NAME} PRIVATE ${PROJECT_BINARY_DIR}/src/parser)
target_link_libraries(${TEST_NAME} parser)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

find_package(Boost 1.80 COMPONENTS unit_test_framework system REQUIRED) 

target_include_directories(${TEST_NAME} PRIVATE ${} ${Boost_INCLUDE_DIRS})
target_link_libraries(${TEST_NAME} ${Boost_LIBRARIES})
