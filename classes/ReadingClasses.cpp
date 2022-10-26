#include "ReadingClasses.h"
#include "Aula.h"
#include "Aluno.h"
#include "Bst.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

void Reading() {}

vector<Aula> ReadingClasses::readAulas() {
    int verify = 0;
    vector<Aula> aulas;
    string CLASSCODE, UCCODE, WEEKDAY, TYPE, header1;
    double STARTHOUR, DURATION;
    char c;
    ifstream in("../classes.csv");
    if (!in.is_open()) {
        std::exit(EXIT_FAILURE);
    }


    for (string line; getline(in, line);) {

        //Adicionei novo metodo para dar skip à 1 linha

        istringstream iss(line);
        if (verify == 0) {
            verify++;
            continue;
        }

        //
        getline(iss, CLASSCODE, ',');
        getline(iss, UCCODE, ',');
        getline(iss, WEEKDAY, ',');
        iss >> STARTHOUR >> c;
        iss >> DURATION >> c;
        getline(iss, TYPE, ',');
        Aula raula = Aula(CLASSCODE, UCCODE, WEEKDAY, STARTHOUR, DURATION,
                          TYPE);
        aulas.push_back(raula);
    }

    return aulas;
}

Bst *ReadingClasses::readAlunos() {
    int verify = 0;
    string helper = "T";
    string helper1 = "TP";
    string helper2 = "PL";
    vector<Aula> aulas = readAulas();
    Bst *alunos = NULL;
    Bst test = Bst();
    vector<Aula> aulasAluno;
    int STUDENTCODE, temp_code;
    int UCS_al = 0; //nº UCS do aluno atual
    temp_code = -1;
    string tem_name = "";
    string STUDENTNAME, UCCODE, CLASSCODE, line;
    char c;
    ifstream in("../students_classes.csv");
    if (!in.is_open()) {
        std::exit(EXIT_FAILURE);
    }

    //metodo antigo, comia "20"
    /*
    in >> CLASSCODE >> c;
     */
    //

    //Adicionei novo método de skip da 1 linha, não sei se funciona:

    if (verify == 0) {
        for (string line; getline(in, line);) {
            istringstream iss2(line);
            verify++;
            break;
        }
    }

    //
    getline(in, line);
    istringstream iss(line);
    iss >> STUDENTCODE >> c;
    getline(iss, STUDENTNAME, ',');
    getline(iss, UCCODE, ',');
    getline(iss, CLASSCODE, ',');
    temp_code = STUDENTCODE;
    tem_name = STUDENTNAME;
    for (Aula aula: aulas) {
        if (aula.get_UcCode() == UCCODE && aula.get_ClassCode() == CLASSCODE) {
            Aula aulateste = Aula(CLASSCODE, UCCODE, aula.get_WeekDay(), aula.get_StartHour(), aula.get_Duration(),
                                  aula.get_Type());
            aulasAluno.push_back(aulateste);
            if((aula.get_Type() != helper && aula.get_Type() != helper1) ||aula.get_Type() != helper && aula.get_Type() != helper2)UCS_al++;
        }
    }

    for (string line; getline(in, line);) {
        istringstream iss(line);
        iss >> STUDENTCODE >> c;
        getline(iss, STUDENTNAME, ',');
        getline(iss, UCCODE, ',');
        getline(iss, CLASSCODE, ',');
        if (temp_code != STUDENTCODE) {
            Aluno aluno = Aluno(temp_code, tem_name, aulasAluno, UCS_al);
            if (!alunos) {
                alunos = test.insert_by_upcode(alunos, aluno);
            } else {
                test.insert_by_upcode(alunos, aluno);
            }
            UCS_al = 0;
            temp_code = STUDENTCODE;
            tem_name = STUDENTNAME;
            aulasAluno.clear();
        }
        for (Aula aula: aulas) {
            if (aula.get_UcCode() == UCCODE && aula.get_ClassCode() == CLASSCODE) {
                Aula aulateste = Aula(CLASSCODE, UCCODE, aula.get_WeekDay(), aula.get_StartHour(),
                                      aula.get_Duration(),
                                      aula.get_Type());
                aulasAluno.push_back(aulateste);
                if (aulateste.get_Type() == "TP" or aulateste.get_Type() == "PL") {
                    UCS_al++;
                }
            }
        }
    }
    Aluno aluno = Aluno(temp_code, tem_name, aulasAluno, UCS_al);
    test.insert_by_upcode(alunos, aluno);
    return alunos;
}