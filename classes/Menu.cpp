#include "Menu.h"
#include "Horario.h"
#include "Reading.h"
#include <iostream>
using namespace std;
void Menu::readmenu() {
    int up, NUCS;
    string Classcode, Uccode, again = "No";
    list<Turma> turmas;
    char tecla;
    bool flag = true, flag2 = true, flag3 = true;
    Bst aux = Bst();
    Bst *Alunos = nullptr;
    Reading reading = Reading();
    Alunos = reading.readAlunos();
    turmas = reading.readTurmas();
    aux.num_students_uc(Alunos, turmas);

    while (flag) {
        cout << "Press a key according to what you want to do: \n"
                "1 : See schedule. \n"
                "2 : Edit schedule. \n"
                "3 : See all students. \n"
                "4 : See the number of students with more than x UCs. \n"
                "5 : See students in a certain UC-CLASS. \n"
                "6 : See students in a certain UC. \n"
                "7 : See the number of students in a certain UC-CLASS. \n"
                "8 : Remove a UC-CLASS from a student. \n";
        cin >> tecla;
        switch (tecla) {
            case '1':
                cout << "Insert your UPCode \n";
                while (flag2) {
                    cin >> up;
                    if (aux.find_by_upcode(Alunos, up).getStudentName() == "") {
                        cout << "This student doesn't exist in this database, insert a valid number " << endl;
                    } else {
                        cout << "Numero de ucs do aluno/aluna" << " " << aux.find_by_upcode(Alunos, up).getStudentName()
                             << ": " << aux.find_by_upcode(Alunos, up).getNUCS() << endl;
                        cout << "Horario:" << endl;
                        aux.find_by_upcode(Alunos, up).getHorario().printHorario();
                        break;
                    }
                }
                break;
            case '2':
                //mudar o horario
                cout << "Teste \n";
                break;
            case '3' :
                aux.view(Alunos);
                break;
            case '4' :
                cout << "Type the number minimum of UCs:";
                cin >> NUCS;
                aux.view_by_NUCS(Alunos, NUCS);
                break;
            case '5' :
                cout << "Insert the class UCcode:";
                cin >> Uccode;
                cout << "Insert the class Classcode:";
                cin >> Classcode;
                aux.view_by_turma(Alunos, Uccode, Classcode);
                break;
            case '6' :
                cout << "Insert the UCode: ";
                cin >> Uccode;
                aux.view_by_uc(Alunos, Uccode);
                break;
            case '7' :
                cout << "Insert the class UCcode:";
                cin >> Uccode;
                cout << "Insert the class Classcode:";
                cin >> Classcode;
                for (Turma turma: turmas) {
                    if (turma.get_classcode() == Classcode and turma.get_uccode() == Uccode) {
                        cout << turma.get_numeroalunos() << endl;
                    }
                }
                break;
            case '8' :
                cout << "Insert your UPCode \n";
                while (flag3) {
                    cin >> up;
                    if (aux.find_by_upcode(Alunos, up).getStudentName() == "") {
                        cout << "This student doesn't exist in this database, inster a valid number " << endl;
                    } else {
                        flag3 = false;
                    }
                }
                cout << "Insert the class UCcode:";
                cin >> Uccode;
                cout << "Insert the class Classcode:";
                cin >> Classcode;
                aux.removerAula(Alunos, up, Uccode, Classcode);
                aux.find_by_upcode(Alunos, up).removeUcs();
                flag3 = true;
                break;
            default:
                cout << "Press a valid key! \n";
                break;
        }

        cout << "Would you like to do something else? (Yes/No) \n";
        cin >> again;
        if (again == "No") flag = false;
        while (again != "Yes"){
            if (again == "No"){
                flag = false;
                break;
            }
            cout << "Please type \"Yes\" or \"No\" ." <<  endl ;
            cin >> again;

        }
    }
}




