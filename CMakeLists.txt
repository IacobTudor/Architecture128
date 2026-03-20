cmake_minimum_required(VERSION 3.20)
project(Architecture128)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp)

set(NASM "") # Path to NASM

file(GLOB ASM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/asm/*.asm")

set(OBJECTS)

foreach(asm_file ${ASM_SOURCES})
    get_filename_component(asm_name ${asm_file} NAME_WE)

    set(obj_file ${CMAKE_CURRENT_BINARY_DIR}/${asm_name}.o)

    add_custom_command(
            OUTPUT ${obj_file}
            COMMAND ${NASM} -f win64 ${asm_file} -o ${obj_file}
            DEPENDS ${asm_file}
            COMMENT "Assembling ${asm_name}.asm"
    )

    list(APPEND OBJECTS ${obj_file})
endforeach()

add_executable(Architecture128 ${SOURCES} ${OBJECTS})