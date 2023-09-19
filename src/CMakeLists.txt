set(PRJ_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(parser/)

add_executable(
  ${PROJECT_NAME}
  main.cc
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/parser)
target_link_libraries(${PROJECT_NAME} parser)
