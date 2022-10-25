#include "classes/ReadingClasses.h"
#include "classes/Aluno.h"
#include "classes/Menu.h"
#include "classes/Bst.h"
#include <iostream>
#include <list>
#include <map>
using namespace std;

int main() {
    /*
    Menu menu = Menu();
    menu.readmenu();
     */

    int i = 600    ;

    Bst test = Bst();
    Bst* res = NULL;
    ReadingClasses reading = ReadingClasses();
    Aluno aluno;
    /*
    vector<Aula> a;
    Horario hor = a;
    Aluno aluno = Aluno(1,"aha", hor);
    Aluno aluno2 = Aluno(2,"aha", hor);
    Aluno aluno3 = Aluno(-1,"aha", hor);
    Bst test = Bst();
    Bst* res = NULL;
    res = test.insert_by_upcode(res, aluno );
    test.insert_by_upcode(res, aluno2);
    test.insert_by_upcode(res, aluno3);
     */
    res = reading.readAlunos() ;
    //test.view( res);
    aluno = test.find_by_upcode(res, 202029992);
    aluno.getHorario().printHorario();

    /*
    vector<Aula> res1 = res[i].getHorario().getAulas();

    cout << "Horario do aluno:" << res[i].getStudentCode() << endl;
    cout << res[i].getHorario().printHorario() << endl;
    cout << "Numero total de aulas" << " " << res1.size();
     */

    return 0;
}

