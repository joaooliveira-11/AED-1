#include "Menu.h"
#include "Horario.h"
#include "Reading.h"
#include <iostream>
#include "map"
#include "queue"
#include "Pedido.h"
using namespace std;

void Menu::readmenu() {
    int up, NUCS;
    string Classcode, Uccode, again = "No", tipo;
    list<Turma> turmas;
    vector<Aula> aulas;
    char tecla;
    bool flag = true, flag2 = true, flag3 = true;
    Bst aux = Bst();
    Bst *Alunos = nullptr;
    Reading reading = Reading();
    Alunos = Reading::readAlunos();
    turmas = Reading::readTurmas();
    aulas = Reading::readAulas();
    aux.num_students_uc(Alunos, turmas);

    queue<Pedido> pedidos;
    queue<Pedido> non_accepted;
    Pedido novo_pedido;

    map<string, int> Max_students_by_UC = {{"L.EIC001", 0},
                                           {"L.EIC002", 0},
                                           {"L.EIC003", 0},
                                           {"L.EIC004", 0},
                                           {"L.EIC005", 0},
                                           {"L.EIC006", 0},
                                           {"L.EIC007", 0},
                                           {"L.EIC008", 0},
                                           {"L.EIC009", 0},
                                           {"L.EIC010", 0},
                                           {"L.EIC011", 0},
                                           {"L.EIC012", 0},
                                           {"L.EIC013", 0},
                                           {"L.EIC014", 0},
                                           {"L.EIC015", 0},
                                           {"L.EIC016", 0},
                                           {"L.EIC017", 0},
                                           {"L.EIC018", 0},
                                           {"L.EIC019", 0},
                                           {"L.EIC020", 0},
                                           {"L.EIC021", 0},
                                           {"L.EIC022", 0},
                                           {"L.EIC023", 0},
                                           {"L.EIC024", 0},
                                           {"L.EIC025", 0},
                                           {"L.EIC026", 0},
                                           {"L.EIC027", 0},
                                           {"L.EIC028", 0},
                                           {"L.EIC029", 0},
                                           {"L.EIC030", 0}};
    for (Turma turma: turmas) {
        if (Max_students_by_UC[turma.get_uccode()] < turma.get_numeroalunos()) {
            Max_students_by_UC.at(turma.get_uccode()) = turma.get_numeroalunos();
        }
    }

    while(flag) {
        cout << "What do you want do work on - schedules, students or UCs? \n";
        cin >> tipo;
        while (tipo != "schedules" and tipo != "students" and tipo != "UCs"){
            cout << "Please type \"schedules\", \"students\" or \"UCs\". \n";
            cin >> tipo;
        }
        if (tipo == "schedules"){
            cout << "Press a key according to what you want to do: \n"
                    "1 : See schedule. \n"
                    "2 : Edit schedule. \n"
                    "q : Quit. \n";
            cin >> tecla;
            switch (tecla) {
                case '1':
                    cout << "Insert your UPCode. \n";
                    while (flag2) {
                        cin >> up;
                        if (aux.find_by_upcode(Alunos, up).getStudentName() == "") {
                            cout << "This student doesn't exist in this database, insert a valid number." << endl;
                        } else {
                            cout << endl;
                            cout << aux.find_by_upcode(Alunos, up).getStudentName()
                                 << "'s number of UCs: " << aux.find_by_upcode(Alunos, up).getNUCS() << endl;
                            cout << endl;
                            cout << "Schedule:" << endl;
                            aux.find_by_upcode(Alunos, up).getHorario().printHorario();
                            break;
                        }
                    }
                    break;
                case '2':
                    //mudar o horario
                    cout << "Teste \n";
                    break;
                case 'q':
                    break;
                default:
                    cout << "Press a valid key! \n";
                    break;
            }
            cout << "Would you like to do something else? (Yes/No) \n";
            cin >> again;
            if (again == "No") flag = false;
            while (again != "Yes") {
                if (again == "No") {
                    flag = false;
                    break;
                }
                cout << "Please type \"Yes\" or \"No\" ." << endl;
                cin >> again;
            }
        }
        else if (tipo == "students"){
            cout << "Press a key according to what you want to do: \n"
                    "1 : See all students. \n"
                    "2 : See the number of students with more than n UCs. \n"
                    "3 : See students in a certain UC/class. \n"
                    "4 : See all students in a certain UC. \n"
                    "5 : See the number of students in a certain UC/class. \n"
                    "q : Quit. \n";
                cin >> tecla;
                switch (tecla) {
                    case '1' :
                        aux.view(Alunos);
                        break;
                    case '2' :
                        cout << "Type the number minimum of UCs.";
                        cin >> NUCS;
                        aux.view_by_NUCS(Alunos, NUCS);
                        break;
                    case '3' :
                        cout << "Insert the class' UCcode.";
                        cin >> Uccode;
                        cout << "Insert the class' Classcode.";
                        cin >> Classcode;
                        aux.view_by_turma(Alunos, Uccode, Classcode);
                        break;
                    case '4' :
                        cout << "Insert the UCode.";
                        cin >> Uccode;
                        aux.view_by_uc(Alunos, Uccode);
                        break;
                    case '5' :
                        cout << "Insert the class' UCcode.";
                        cin >> Uccode;
                        cout << "Insert the class' Classcode.";
                        cin >> Classcode;
                        for (Turma turma: turmas) {
                            if (turma.get_classcode() == Classcode and turma.get_uccode() == Uccode) {
                                cout << turma.get_numeroalunos() << endl;
                            }
                        }
                        break;
                    case 'q':
                        break;
                    default:
                        cout << "Press a valid key! \n";
                        break;
                }
            cout << endl;
            cout << "Would you like to do something else? (Yes/No) \n";
            cin >> again;
            if (again == "No") flag = false;
            while (again != "Yes") {
                if (again == "No") {
                    flag = false;
                    break;
                }
                cout << "Please type \"Yes\" or \"No\" ." << endl;
                cin >> again;
            }
        }
        else if (tipo == "UCs"){
                cout << "Press a key according to what you want to do: \n"
                        "1 : See the number of students in a certain UC/class. \n"
                        "2 : Remove an UC/class from a student. \n"
                        "3 : Add the student in a class in a certain UC. \n"
                        "q : Quit. \n";
                cin >> tecla;
                switch (tecla) {
                    case '1' :
                        cout << "Insert the class' UCcode (i.e.: L.EIC001). \n";
                        cin >> Uccode;
                        cout << "Insert the class' Classcode (i.e.: 1LEIC01). \n";
                        cin >> Classcode;
                        for (Turma turma: turmas) {
                            if (turma.get_classcode() == Classcode and turma.get_uccode() == Uccode) {
                                cout << turma.get_numeroalunos() << endl;
                            }
                        }
                        break;
                    case '2' :
                        cout << "Insert your UPCode. \n";
                        while (flag3) {
                            cin >> up;
                            if (aux.find_by_upcode(Alunos, up).getStudentName() == "") {
                                cout << "This student doesn't exist in this database, insert a valid number." << endl;
                            } else {
                                flag3 = false;
                            }
                        }
                        cout << "Insert the class' UCcode (i.e.: L.EIC001). \n";
                        cin >> Uccode;
                        cout << "Insert the class' Classcode (i.e.: 1LEIC01). \n";
                        cin >> Classcode;
                        novo_pedido = Pedido("remover", up, Uccode, Classcode, " ");
                        pedidos.push(novo_pedido);
                        flag3 = true;
                        break;
                    case '3' :
                        cout << "Insert your UPCode. \n";
                        while (flag3) {
                            cin >> up;
                            if (aux.find_by_upcode(Alunos, up).getStudentName() == "") {
                                cout << "This student doesn't exist in this database, insert a valid number." << endl;
                            } else {
                                flag3 = false;
                            }
                        }
                        cout << "Insert the class' UCcode (i.e.: L.EIC001). \n";
                        cin >> Uccode;
                        cout << "Insert the class' Classcode (i.e.: 1LEIC01). \n";
                        cin >> Classcode;
                        novo_pedido = Pedido("adicionar", up, Uccode, " ", Classcode);
                        pedidos.push(novo_pedido);
                        flag3 = true;
                        break;
                    case 'q':
                        break;
                    default:
                        cout << "Press a valid key! \n";
                        break;
                }
            cout << endl;
            cout << "Would you like to do something else? (Yes/No) \n";
            cin >> again;
            if (again == "No") flag = false;
            while (again != "Yes") {
                if (again == "No") {
                    flag = false;
                    break;
                }
                cout << "Please type \"Yes\" or \"No\" ." << endl;
                cin >> again;
            }
        }
    }

    while (!pedidos.empty()) {
        Pedido ped_at = pedidos.front(); //pedido atual da queueueue
        if (ped_at.getType() == "remover") {
            aux.removerAula(Alunos, ped_at.getUp(), ped_at.getUc(), ped_at.getClass_antiga());
            aux.find_by_upcode(Alunos, ped_at.getUp()).removeUcs();
            aux.find_by_upcode(Alunos, up).getHorario().printHorario();// só para teste
            pedidos.pop();
        } else if (ped_at.getType() == "adicionar") {
            for (Turma turma: turmas) {
                if (turma.get_uccode() == ped_at.getUc() and turma.get_classcode() == ped_at.getClass_nova()) {
                    if (turma.can_add(Max_students_by_UC)) { //adicionar condição para verficar se aulas se sobrepõem
                        for (const Aula& aula : aulas){
                            if (aula.get_UcCode() == ped_at.getUc() and aula.get_ClassCode()==ped_at.getClass_nova()){
                                aux.adicionarAula(Alunos, ped_at.getUp(), aula);
                                aux.find_by_upcode(Alunos, up).getHorario().printHorario();// só para teste
                                aux.find_by_upcode(Alunos, ped_at.getUp()).addUcs();
                            }
                        }
                    }
                    else {
                        non_accepted.push(ped_at);
                    }
                    pedidos.pop();
                    break;
                }
            }
        }
        for (Turma turma: turmas) {
            if (Max_students_by_UC[turma.get_uccode()] < turma.get_numeroalunos()) {
                Max_students_by_UC.at(turma.get_uccode()) = turma.get_numeroalunos();
            }
        }
    }
}
