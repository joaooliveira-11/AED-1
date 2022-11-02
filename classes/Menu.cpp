#include "Menu.h"
#include "Horario.h"
#include "Reading.h"
#include <iostream>
#include "map"
#include "queue"
#include "Pedido.h"
using namespace std;

void Menu::readmenu() {
    int up, NUCS, n, x;
    string Classcode,Classcode2, Uccode, again = "No", tipo;
    list<Turma> turmas;
    vector<Aula> aulas;
    vector<Aula> aulas_aux;
    char tecla;
    bool flag = true, flag2 = true, flag3 = true, flag4 , flag5, flag6;
    Bst aux = Bst();
    Bst *Alunos = nullptr;
    Bst* Alunos_by_name = nullptr;
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

    while (flag) {
        cout << "Do you want to view or edit something? \n";
        cin >> tipo;
        while (tipo != "view" and tipo != "edit") {
            cout << "Please type \"view\" or \"edit\". \n";
            cin >> tipo;
        }
        if (tipo == "view") {
            cout << "Press a key according to what you want to do: \n"
                    "1 : See schedule. \n"
                    "2 : See all students. \n"
                    "3 : See students with more than n UCs. \n"
                    "4 : See students in a certain UC/class. \n"
                    "5 : See all students in a certain UC. \n"
                    "6 : See the number of students in a certain UC/class. \n"
                    "7 : See the number of students in a certain UC per class. \n"
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
                case '2' :
                    aux.view(Alunos);
                    break;
                case '3' :
                    cout << "Type the number minimum of UCs.";
                    cin >> NUCS;
                    aux.view_by_NUCS(Alunos, NUCS);
                    break;
                case '4' :
                    cout << "Insert the class' UCcode.";
                    cin >> Uccode;
                    cout << "Insert the class' Classcode.";
                    cin >> Classcode;
                    aux.view_by_turma(Alunos, Uccode, Classcode);
                    break;
                case '5' :
                    cout << "Insert the UCode.";
                    cin >> Uccode;
                    aux.view_by_uc(Alunos, Uccode);
                    break;
                case '6' :
                    cout << "Insert the class' UCcode (i.e.: L.EIC001). \n";
                    cin >> Uccode;
                    cout << "Insert the class' Classcode (i.e.: 1LEIC01). \n";
                    cin >> Classcode;
                    for (Turma turma: turmas) {
                        if (turma.get_classcode() == Classcode and turma.get_uccode() == Uccode) {
                            cout << turma.get_numeroalunos() << "/"<< Max_students_by_UC[Uccode] << endl;
                        }
                    }
                    break;
                case '7' :
                    cout << "Insert the class' UCcode (i.e.: L.EIC001). \n";
                    cin >> Uccode;
                    for (Turma turma: turmas) {
                        if (turma.get_uccode() == Uccode) {
                            cout << turma.get_classcode() << " | " << turma.get_numeroalunos() << "/"<< Max_students_by_UC[Uccode] << endl;
                        }
                    }
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
                cout << "Please type \"Yes\" or \"No\"." << endl;
                cin >> again;
            }
        } else {
            cout << "Press a key according to what you want to do: \n"
                    "1 : Edit schedule. \n"
                    "2 : Remove an UC/class from a student. \n"
                    "3 : Add a student to a certain class/UC. \n"
                    "4 : Change between classes, in a certain number of UCs. \n"
                    "5 : Execute queue of requests. \n"
                    "q : Quit. \n";
            cin >> tecla;
            switch (tecla) {
                case '1':
                    //mudar o horario
                    cout << "Teste \n";
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
                    aulas_aux = aux.find_by_upcode(Alunos, up).getHorario().getAulas();
                    flag6 = false;
                    for (Aula aula: aulas_aux) {
                        if (aula.get_ClassCode() == Classcode and aula.get_UcCode() == Uccode) flag6 = true;
                        //break;
                    }
                    if (flag6) {
                        novo_pedido = Pedido("remover", up, Uccode, Classcode, " ");
                        pedidos.push(novo_pedido);
                    } else {
                        cout << "You don't belong to that class. \n";
                    }
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
                    aulas_aux = aux.find_by_upcode(Alunos, up).getHorario().getAulas();
                    flag6 = true;
                    for (Aula aula: aulas_aux) {
                        if (aula.get_UcCode() == Uccode) flag6 = false;
                        //break;
                    }
                    if (flag6) {
                        novo_pedido = Pedido("adicionar", up, Uccode, " ", Classcode);
                        pedidos.push(novo_pedido);
                    } else {
                        cout << "You already belong to a class in this UC, try changing class.";
                    }
                    flag3 = true;
                    break;
                case '4':
                    cout << "Insert how many UCs are you going to change: \n";
                    cin >> n;
                    x = 0;
                    cout << "Insert your UPCode. \n";
                    while (flag3) {
                        cin >> up;
                        if (aux.find_by_upcode(Alunos, up).getStudentName() == "") {
                            cout << "This student doesn't exist in this database, insert a valid number." << endl;
                        } else {
                            flag3 = false;
                        }
                    }
                    flag3 = true;
                    aulas_aux = aux.find_by_upcode(Alunos, up).getHorario().getAulas();
                    while (x < n) {
                        cout << "Insert the class' UCcode (i.e.: L.EIC001). \n";
                        cin >> Uccode;
                        cout << "Insert the class' you want to leave Classcode (i.e.: 1LEIC01). \n";
                        cin >> Classcode;
                        flag6 = false;
                        for (Aula aula: aulas_aux) {
                            if (aula.get_ClassCode() == Classcode and aula.get_UcCode() == Uccode) flag6 = true;
                            break;
                        }
                        if (!flag6) {
                            cout << "You don't belong to that class/UC. \n";
                            x++;
                            continue;
                        }
                        cout << "Insert the class' you want to go Classcode (i.e.: 1LEIC01). \n";
                        cin >> Classcode2;
                        if (Classcode == Classcode2) {
                            cout << "You're already in that Class for that UC. \n";
                            x++;
                            continue;
                        }
                        novo_pedido = Pedido("alterar", up, Uccode, Classcode, Classcode2);
                        pedidos.push(novo_pedido);
                        x++;
                        }
                    break;
                case '5':
                    while (!pedidos.empty()) {
                        flag4 = false;
                        Pedido ped_at = pedidos.front(); //pedido atual da queueueue
                        aux.find_by_upcode(Alunos, up).getHorario().printHorario();// só para teste RETIRAR!!!!
                        if (ped_at.getType() == "remover") {
                            aux.removerAula(Alunos, ped_at.getUp(), ped_at.getUc(), ped_at.getClass_antiga());
                            aux.find_by_upcode(Alunos, ped_at.getUp()).removeUcs();
                            pedidos.pop();
                        } else if (ped_at.getType() == "adicionar") {
                            for (Turma turma: turmas) {
                                if (turma.get_uccode() == ped_at.getUc() and turma.get_classcode() == ped_at.getClass_nova()) {
                                    if (turma.can_add(Max_students_by_UC)) {
                                        for (const Aula &aula: aulas) {
                                            if (aula.get_Type() == "TP" or aula.get_Type() == "PL") {
                                                if (aula.get_UcCode() == ped_at.getUc() and aula.get_ClassCode() == ped_at.getClass_nova() and aux.find_by_upcode(Alunos, up).verificar( aula,aux.find_by_upcode(Alunos,up).getHorario())) {
                                                    aux.adicionarAula(Alunos, ped_at.getUp(), aula);
                                                    aux.find_by_upcode(Alunos, ped_at.getUp()).addUcs();
                                                    flag4 = true;
                                                }
                                            }
                                        }
                                        if (flag4) {
                                            for (const Aula &aula: aulas) {
                                                if (aula.get_Type() == "T" and aula.get_UcCode() == ped_at.getUc() and aula.get_ClassCode() == ped_at.getClass_nova()) {
                                                    aux.adicionarAula(Alunos, ped_at.getUp(), aula);
                                                    aux.find_by_upcode(Alunos, up).getHorario().printHorario();
                                                }
                                            }
                                        } else{
                                            non_accepted.push(ped_at);
                                            cout << "2 ";
                                        }
                                    } else {
                                        non_accepted.push(ped_at);
                                        cout << "aiai ";
                                    }

                                }
                            }
                            pedidos.pop();
                        } else if (ped_at.getType() == "alterar") {
                            flag4 = false;
                            flag5 = false;
                            for (Turma turma: turmas) {
                                if (turma.get_uccode() == ped_at.getUc() and turma.get_classcode() == ped_at.getClass_nova()) {
                                    if (turma.can_add(Max_students_by_UC)) {
                                        for (const Aula &aula: aulas) {
                                            if (aula.get_Type() == "TP" or aula.get_Type() == "PL") {
                                                if (aula.get_UcCode() == ped_at.getUc() and aula.get_ClassCode() == ped_at.getClass_nova() and aux.find_by_upcode(Alunos, up).verificar( aula,aux.find_by_upcode(Alunos,up).getHorario())) {
                                                    aux.adicionarAula(Alunos, ped_at.getUp(), aula);
                                                    aux.find_by_upcode(Alunos, ped_at.getUp()).addUcs();
                                                    flag4 = true;
                                                    flag5 = true;
                                                }
                                            }
                                        }
                                        if (flag4) {
                                            for (const Aula &aula: aulas) {
                                                if (aula.get_Type() == "T" and aula.get_UcCode() == ped_at.getUc() and aula.get_ClassCode() == ped_at.getClass_nova()) {
                                                    aux.adicionarAula(Alunos, ped_at.getUp(), aula);
                                                    aux.find_by_upcode(Alunos, up).getHorario().printHorario();
                                                }
                                            }
                                        } else{
                                            non_accepted.push(ped_at);
                                            cout << "2 ";
                                        }
                                    } else {
                                            non_accepted.push(ped_at);
                                            cout << "aiai ";
                                    }
                                }
                            }
                            if(flag5) {
                                aux.removerAula(Alunos, ped_at.getUp(), ped_at.getUc(), ped_at.getClass_antiga());
                                aux.find_by_upcode(Alunos, ped_at.getUp()).removeUcs();
                            }
                            aux.find_by_upcode(Alunos, up).getHorario().printHorario();// só para teste RETIRAR!!!!
                            pedidos.pop();
                        }
                    }
                    for (Turma &turma : turmas){
                        turma.set_numeroalunos_0();
                    }
                    aux.num_students_uc(Alunos, turmas);
                    while (!non_accepted.empty()){
                        pedidos.push(non_accepted.front());
                        non_accepted.pop();
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
                cout << "Please type \"Yes\" or \"No\"." << endl;
                cin >> again;
            }
        }
    }
}
