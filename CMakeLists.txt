cmake_minimum_required(VERSION 3.23)
project(AED_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(AED_1 main.cpp classes/Reading.cpp classes/Reading.h classes/Aluno.cpp classes/Aluno.h classes/Aula.h classes/Aula.cpp classes/Horario.h classes/Horario.cpp classes/Turma.cpp classes/Turma.h classes/Menu.h classes/Menu.cpp classes/Bst.h classes/Bst.cpp classes/Pedido.cpp classes/Pedido.h )

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.txt")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(
            Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
