cmake_minimum_required(VERSION 2.6)
project(assembler)

set(CMAKE_C_FLAGS "-O3 -std=c99")

set(ANALYSIS_SRC analysis/analysis.c analysis/commands.c analysis/conditions.c)
set(PARSER_SRC parser/parser.c)
set(ASSEMBLE_SRC assemble/compiler.c)

add_library(parser ${PARSER_SRC})
add_library(assemble ${ASSEMBLE_SRC})
add_library(analysis ${ANALYSIS_SRC})

add_executable(assembler assemble/assemble.c)
target_link_libraries(assembler parser assemble analysis)
