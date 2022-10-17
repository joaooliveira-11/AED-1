cmake_minimum_required(VERSION 3.23)
project(AED_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(AED_1 main.cpp classes/Reading.cpp classes/Reading.h classes/Aluno.cpp classes/Aluno.h classes/Aula.h classes/Aula.cpp classes/Horario.h classes/Horario.cpp classes/Turma.cpp classes/Turma.h)
