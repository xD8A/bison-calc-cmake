set(HEADERS
    driver.hh
)
set(SOURCES
    driver.cc
)

find_package(BISON)
find_package(FLEX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

bison_target(Parser parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cc)
flex_target(Scanner scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc)

add_flex_bison_dependency(Scanner Parser)

add_library(parser
            STATIC
            ${FLEX_Scanner_OUTPUTS}
            ${BISON_Parser_OUTPUTS}
            ${HEADERS}
            ${SOURCES}
)
