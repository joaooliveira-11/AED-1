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
    aluno = test.find_by_upcode(res, 202055152);
    aluno.getHorario().printHorario();

    /*
    vector<Aula> res1 = res[i].getHorario().getAulas();

    cout << "Horario do aluno:" << res[i].getStudentCode() << endl;
    cout << res[i].getHorario().printHorario() << endl;
    cout << "Numero total de aulas" << " " << res1.size();
     */
    /*
    map<string, string> UcCodeToName = {{"L.EIC001", "ALGA"},
                                        {"L.EIC002", "AMI"},
                                        {"L.EIC003", "FP"},
                                        {"L.EIC004", "FSC"},
                                        {"L.EIC005", "MD"},
                                        {"L.EIC006", "AC"},
                                        {"L.EIC007", "AMII"},
                                        {"L.EIC008", "FI"},
                                        {"L.EIC009", "P"},
                                        {"L.EIC010", "TC"},
                                        {"L.EIC011", "AED"},
                                        {"L.EIC012", "BD"},
                                        {"L.EIC013", "FII"},
                                        {"L.EIC014", "LDTS"},
                                        {"L.EIC015", "SO"},
                                        {"L.EIC016", "DA"},
                                        {"L.EIC017", "ES"},
                                        {"L.EIC018", "LC"},
                                        {"L.EIC019", "LTW"},
                                        {"L.EIC020", "ME"},
                                        {"L.EIC021", "FSI"},
                                        {"L.EIC022", "IPC"},
                                        {"L.EIC023", "LBAW"},
                                        {"L.EIC024", "PFL"},
                                        {"L.EIC025", "RC"},
                                        {"L.EIC026", "C"},
                                        {"L.EIC027", "CG"},
                                        {"L.EIC028", "CPD"},
                                        {"L.EIC029", "IA"},
                                        {"L.EIC030", "PI"}};

    */
    return 0;
}

