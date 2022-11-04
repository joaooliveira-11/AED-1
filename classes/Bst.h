///@file Bst.h

#ifndef AED_1_BST_H
#define AED_1_BST_H

#include "Aluno.h"
#include <iostream>
#include "Turma.h"
#include <list>
using namespace std;

///@brief Class for all the bst we need (i.e.: all students, the students enrolled in more than n UCs).
class Bst {
    private:
        ///@brief The current student.
        Aluno atual;

        ///@brief The left branch.
        Bst* Left;

        ///@brief The right branch.
        Bst* Right;
    public:
        ///@brief Empty binary search tree constructor.
        ///@see Aluno.h
        Bst();

        ///@brief Constructor of a new binary search tree given a student.
        ///@param imp
        ///@see Aluno.h
        explicit Bst(Aluno imp);

        ///@brief Inserts a student in the BST.
        ///@returns Updated BST after adding a new student.
        ///@param base The student's BST we want to add a new student to.
        ///@param atual The student we are going to add to the BST.
        ///@note Time complexity: O(1)
        ///@see Aluno.h
        Bst* insert_by_upcode(Bst* base, const Aluno& atual);

        ///@brief Prints all students (sorted by UC code by default).
        ///@param base
        ///@note Time complexity: O(1)
        ///@see Aluno.h
        void view(Bst* base);

        ///@brief Prints all students that are enrolled in more than n UCs.
        ///@param base
        ///@param x The number (n) UCs we want to check.
        ///@note Time complexity: O(1)
        ///@see Aluno.h
        void view_by_NUCS(Bst* base, int x);

        ///@returns Student in BST who's UP code is the same as the upcode the function receives.
        ///@param base
        ///@param upcode
        ///@note Time complexity: O(1)
        ///@see Aluno.h
        Aluno& find_by_upcode(Bst* base, int upcode);

        ///@brief Prints all students that are in the same UC/class.
        ///@param base
        ///@param uccode
        ///@param classcode
        ///@see Aluno.h
        ///@see Horario.h
        ///@see Aula.h
        ///@note Time complexity: O(
        void view_by_turma(Bst* base, const string& uccode, const string& classcode);

        ///@brief Prints all students that are in an UC.
        ///@param base
        ///@param uccode
        ///@see Aluno.h
        ///@see Horario.h
        ///@see Aula.h
        ///@note Time complexity: O(
        void view_by_uc(Bst* base, const string& uccode);

        ///@brief Counts the number of students in an UC.
        ///@param base
        ///@param turmas
        ///@see Aluno.h
        ///@see Horario.h
        ///@see Aula.h
        ///@see Turma.h
        ///@note Time complexity: O(
        void num_students_uc(Bst* base, list<Turma> &turmas);

        ///@brief Removes a class from a schedule.
        ///@param base All students.
        ///@param upcode Student's UP code.
        ///@param uccode The UC we want to remove the student from's code.
        ///@param classcode The classe's code.
        ///@note Time complexity: O(
        void removerAula(Bst* base, int upcode, const string& uccode, const string& classcode);

        ///@brief Adds a class to a schedule.
        ///@param base All students.
        ///@param upcode Student's UP code.
        ///@param aula The class we want to add to the student's schedule.
        ///@note Time complexity: O(
        void adicionarAula(Bst* base, int upcode, const Aula aula);

        ///@brief Stores students sorted by name in a vector.
        ///@param base BST with all students.
        ///@param alunos Vector where students will be stored when sorted.
        ///@note Time complexity: O(
        void ordenar_alph(Bst* base, vector<Aluno> &alunos);
    };

#endif
