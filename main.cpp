#include "classes/ReadingClasses.h"
#include "classes/Aluno.h"
#include "classes/Menu.h"
#include "classes/Bst.h"
#include <iostream>
#include <list>
#include <map>
using namespace std;

int main() {

    Menu menu = Menu();
    menu.readmenu();
    /*
    ReadingClasses readingClasses = ReadingClasses();
    vector<Aula> aulas = readingClasses.readAulas();

    for(Aula aula : aulas){
        cout << aula.get_ClassCode() << endl;
    }
     */

/*
    Bst test = Bst();
    Bst* res = NULL;
    ReadingClasses reading = ReadingClasses();
    Aluno aluno;

    res = reading.readAlunos() ;

    //test.view( res);
    aluno = test.find_by_upcode(res, 202029992);

    aluno = test.find_by_upcode(res, 202055152);
    aluno.getHorario().printHorario();
    */
    /*
    vector<Aula> res1 = res[i].getHorario().getAulas();

    cout << "Horario do aluno:" << res[i].getStudentCode() << endl;
    cout << res[i].getHorario().printHorario() << endl;
    cout << "Numero total de aulas" << " " << res1.size();
     */

    return 0;
}

