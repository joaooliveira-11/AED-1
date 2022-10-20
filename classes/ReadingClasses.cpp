#include "ReadingClasses.h"
#include "Aula.h"
#include "Aluno.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

void Reading() {}

vector<Aula> ReadingClasses::readAulas() {
    vector<Aula> aulas;
    string CLASSCODE, UCCODE, WEEKDAY, TYPE;
    double STARTHOUR, DURATION;
    char c;
    ifstream in("../classes.csv");
    if (!in.is_open()) {
        std::exit(EXIT_FAILURE);
    }
    in >> CLASSCODE >> c;
    for (string line; getline(in, line);) {
        istringstream iss(line);
        getline(iss, CLASSCODE, ',');
        getline(iss, UCCODE, ',');
        getline(iss, WEEKDAY, ',');
        iss >> STARTHOUR >> c;
        iss >> DURATION >> c;
        getline(iss, TYPE, ',');
        //Aula* raula = new Aula(CLASSCODE, UCCODE, WEEKDAY, (STARTHOUR), (DURATION), TYPE);
        Aula raula = Aula(CLASSCODE, UCCODE, WEEKDAY, (STARTHOUR), (DURATION), TYPE);
        aulas.push_back(raula);
    }

    return aulas;
}

vector<Aluno> ReadingClasses::readAlunos(){

    vector<Aula> aulas = readAulas();
    vector<Aluno> alunos;
    vector<Aula> aulasAluno;
    int STUDENTCODE;
    string STUDENTNAME, UCCODE, CLASSCODE;
    char c;
    ifstream in("../students_classes.csv");
    if (!in.is_open()) {
        std::exit(EXIT_FAILURE);
    }
    in >> CLASSCODE >> c;
    for (string line; getline(in, line);) {
        istringstream iss(line);
        iss >> STUDENTCODE >> c;
        getline(iss, STUDENTNAME, ',');
        getline(iss, UCCODE, ',');
        getline(iss, CLASSCODE, ',');
        //StudentCode,StudentName,UcCode,ClassCode
        //UcCode,ClassCode
        //string classCode, string ucCode, string weekDay, double startHour, double duration, string type
        for (Aula aula: aulas) {
            if (aula.get_UcCode() == UCCODE && aula.get_ClassCode() == CLASSCODE) {
                Aula aulateste = Aula(CLASSCODE, UCCODE, aula.get_WeekDay(), aula.get_StartHour(), aula.get_Duration(),
                                      aula.get_Type());
                aulasAluno.push_back(aulateste);
            }
        }
        Aluno aluno = Aluno(STUDENTCODE, STUDENTNAME, aulasAluno);
        alunos.push_back(aluno);
    }
    return alunos;
}