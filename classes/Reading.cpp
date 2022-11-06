#include "Reading.h"
#include "Aula.h"
#include "Aluno.h"
#include "Bst.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <list>
#include "Turma.h"
using namespace std;

void Reading() {}

vector<Aula> Reading::readAulas() {
    int verify = 0;
    vector<Aula> aulas;
    string CLASSCODE, UCCODE, WEEKDAY, TYPE, header1;
    double STARTHOUR, DURATION;
    char c;

    ifstream in("../classes.csv");
    if (!in.is_open()) exit(EXIT_FAILURE);

    for (string line; getline(in, line);) {
        istringstream iss(line);
        if (verify == 0) {
            verify++;
            continue;
        }
        getline(iss, CLASSCODE, ',');
        getline(iss, UCCODE, ',');
        getline(iss, WEEKDAY, ',');
        iss >> STARTHOUR >> c;
        iss >> DURATION >> c;
        getline(iss, TYPE, ',');
        Aula raula = Aula(CLASSCODE, UCCODE, WEEKDAY, STARTHOUR, DURATION,TYPE);
        aulas.push_back(raula);
    }
    return aulas;
}

Bst *Reading::readAlunos() {
    int verify = 0, STUDENTCODE, temp_code = -1, UCS_aluno = 0;
    string helper = "T", helper1 = "TP", helper2 = "PL", STUDENTNAME, UCCODE, CLASSCODE, line, temp_name;
    vector<Aula> aulas = readAulas();
    Bst *alunos = nullptr;
    Bst test = Bst();
    vector<Aula> aulasAluno;
    char c;

    ifstream in("../students_classes.csv");

    if (!in.is_open()) exit(EXIT_FAILURE);

    if (verify == 0) {
        for (string line; getline(in, line);) {
            istringstream iss2(line);
            verify++;
            break;
        }
    }

    getline(in, line);
    istringstream iss(line);
    iss >> STUDENTCODE >> c;
    getline(iss, STUDENTNAME, ',');
    getline(iss, UCCODE, ',');
    getline(iss, CLASSCODE, ',');
    temp_code = STUDENTCODE;
    temp_name = STUDENTNAME;

    for (const Aula& aula : aulas) {
        if (aula.get_UcCode() == UCCODE and aula.get_ClassCode() == CLASSCODE) {
            Aula aulateste = Aula(CLASSCODE, UCCODE, aula.get_WeekDay(),
                                  aula.get_StartHour(), aula.get_Duration(),aula.get_Type());
            aulasAluno.push_back(aulateste);
            if((aula.get_Type() != helper and aula.get_Type() != helper1) ||
            (aula.get_Type() != helper and aula.get_Type() != helper2)) UCS_aluno++;
        }
    }

    for (string line; getline(in, line);) {
        istringstream iss(line);
        iss >> STUDENTCODE >> c;
        getline(iss, STUDENTNAME, ',');
        getline(iss, UCCODE, ',');
        getline(iss, CLASSCODE, ',');

        if (temp_code != STUDENTCODE) {
            Aluno aluno = Aluno(temp_code, temp_name, aulasAluno, UCS_aluno);
            if (!alunos) alunos = test.insert_by_upcode(alunos, aluno);
            else test.insert_by_upcode(alunos, aluno);
            UCS_aluno = 0;
            temp_code = STUDENTCODE;
            temp_name = STUDENTNAME;
            aulasAluno.clear();
        }

        for (const Aula& aula : aulas) {
            if (aula.get_UcCode() == UCCODE and aula.get_ClassCode() == CLASSCODE) {
                Aula aulateste = Aula(CLASSCODE, UCCODE, aula.get_WeekDay(), aula.get_StartHour(),aula.get_Duration(),aula.get_Type());
                aulasAluno.push_back(aulateste);
                if (aulateste.get_Type() == "TP" or aulateste.get_Type() == "PL") UCS_aluno++;
            }
        }
    }
    Aluno aluno = Aluno(temp_code, temp_name, aulasAluno, UCS_aluno);
    test.insert_by_upcode(alunos, aluno);
    return alunos;
}

list<Turma> Reading::readTurmas() {
    int verify = 0;
    list<Turma> turmas;
    string CLASSCODE, UCCODE;

    ifstream in("../classes_per_uc.csv");

    if (!in.is_open()) exit(EXIT_FAILURE);

    for (string line; getline(in, line);){
        istringstream iss(line);

        if (verify == 0) {
            verify++;
            continue;
        }

        getline(iss, UCCODE, ',');
        getline(iss, CLASSCODE, ',');
        Turma turma = Turma(CLASSCODE, UCCODE, 0);
        turmas.push_back(turma);
    }
    return turmas;
}

void Reading::writeDown(Bst* alunos)  {
    Bst test = Bst();
    vector<Aluno> Alunos;
    vector<Aula> aulas;
    string temp;
    test.ordenar_alph(alunos, Alunos);
    fstream NewFile;
    NewFile.open("../new_students_classes.csv", ios::out);
    NewFile << "StudentCode,StudentName,UcCode,ClassCode \n";
    for (Aluno &aluno: Alunos) {
        aulas = aluno.getHorario().getAulas();
        for (Aula &aula: aulas) {
            if (aula.get_Type()=="TP" or aula.get_Type()=="PL") {
                temp = to_string(aluno.getStudentCode()) + "," + aluno.getStudentName() + "," + aula.get_UcCode() +
                       "," + aula.get_ClassCode() + "\n";
                NewFile << temp;
            }
        }
    }
    NewFile.close();
}
