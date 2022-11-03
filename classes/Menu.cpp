#include "Menu.h"
#include "Horario.h"
#include "Reading.h"
#include <iostream>
#include <algorithm>
#include "map"
#include "queue"
#include "Pedido.h"
#include "Aluno.h"
using namespace std;

bool name_order(const Aluno& aluno1 ,const Aluno& aluno2){
    return aluno1.getStudentName() < aluno2.getStudentName();
}
bool ucs_order(const Aluno& aluno1, const Aluno& aluno2){
    return aluno1.getNUCS() < aluno2.getNUCS();
}

bool ucs_stu_order( Turma& turma1, const Turma& turma2) {
    return turma1.get_numeroalunos() < turma2.get_numeroalunos();
}
bool ucs_stu_order_r(const Turma& turma1, const Turma& turma2) {
    return turma1.get_numeroalunos() > turma2.get_numeroalunos();
}

string Menu::UcCodeToName1(const string &uccode) {
    map<string, string> UcCode_Name1 = {{"L.EIC001", "ALGA"},
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
                                        {"L.EIC030", "PI"},
                                        {"UP001", "PUP"}};
    return UcCode_Name1[uccode];
}

string Menu::Double_to_hour1(double time) {
    string hour = to_string(int(time));
    int minutes = int(((time - int(time)) * 100) * 0.6);
    return int(minutes) == 0 ? hour + ":" + to_string(minutes) + "0" : hour + ":" + to_string(minutes);
}

void Menu::readmenu() {

    int up, NUCS, n, x;
    string Classcode, Classcode2, Classcode3, Uccode, again = "No", tipo, ord;
    vector<Aula> aulas_aux1;
    list<Turma> turmas;
    vector<Turma> turmas_aux;
    vector<Aula> aulas;
    vector<Aula> aulas_aux;
    vector<Aluno> alunos;
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
        cout << "Do you want to view or edit something or would you like to process all requests? (view/edit/queue) \n";
        cin >> tipo;
        while (tipo != "view" and tipo != "edit" and tipo != "queue") {
            cout << "Please type \"view\", \"edit\" or \"queue\". \n";
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
                    "7 : See the number of students in each class from an UC. \n"
                    "8 : See a class' schedule. \n"
                    "q : Quit. \n";
            cin >> tecla;
            switch (tecla) {
                case '1':
                    cout << "Insert your UPCode. \n";
                    cin >> up;
                    while (flag2) {
                        if (aux.find_by_upcode(Alunos, up).getStudentName() == "") {
                            cout << "This student doesn't exist in this database, insert a valid number." << endl;
                            cin >> up;
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
                    cout << "Type the minimum number of UCs. \n";
                    cin >> NUCS;
                    cout << "Do you want the students ordered according to their UP, name or number of UCs? (UP/name/UC) \n";
                    cin >> ord;
                    while (ord!="UP" and ord!="name" and ord!="UC"){
                        cout << "Type \"UP\", \"name\" or \"UC\". \n";
                        cin >> ord;
                    }
                    if (ord == "UP") aux.view_by_NUCS(Alunos, NUCS);
                    else if (ord == "name") {
                        aux.ordenar_alph(Alunos, alunos);
                        sort(alunos.begin(), alunos.end(), name_order);
                        for (const Aluno& aluno : alunos){
                            if (aluno.getNUCS() > NUCS)
                                cout << aluno.getStudentName() << " | " << aluno.getStudentCode() <<  " | " << aluno.getNUCS() << endl;
                        }
                    }
                    else {
                        aux.ordenar_alph(Alunos, alunos);
                        sort(alunos.begin(), alunos.end(), ucs_order);
                        for (const Aluno& aluno : alunos){
                            if (aluno.getNUCS() > NUCS)
                                cout <<  aluno.getNUCS() << " | " << aluno.getStudentName() << " | " << aluno.getStudentCode()<<  endl;
                        }
                    }
                    break;
                case '4' :
                    cout << "Insert the class' UCcode (i.e.: L.EIC001). \n";
                    cin >> Uccode;
                    cout << "Insert the class' Classcode (i.e.: 1LEIC01). \n";
                    cin >> Classcode;
                    aux.view_by_turma(Alunos, Uccode, Classcode);
                    break;
                case '5' :
                    cout << "Insert the class' UCcode (i.e.: L.EIC001). \n";
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
                            cout << turma.get_numeroalunos() << " | "<< Max_students_by_UC[Uccode] << endl;
                        }
                    }
                    break;
                case '7' :
                    cout << "Insert the class' UCcode (i.e.: L.EIC001). \n";
                    cin >> Uccode;
                    cout << "Chose the ordenation type: \n"
                            "1 : By Class number. \n"
                            "2 : By number os students (descending order). \n"
                            "3 : By number os students (ascending order). \n";
                    cin >> tecla;
                    switch (tecla) {
                        case '1':
                            for (Turma turma: turmas) {
                                if (turma.get_uccode() == Uccode) {
                                    cout << turma.get_classcode() << " | " << turma.get_numeroalunos() << "/"
                                         << Max_students_by_UC[Uccode] << endl;
                                }
                            }
                            break;
                        case '2' :
                            for (Turma turma: turmas) {
                                if (turma.get_uccode() == Uccode) {
                                    turmas_aux.push_back(turma);
                                }
                            }
                            sort(turmas_aux.begin(),turmas_aux.end(), ucs_stu_order_r);
                            for (Turma turma : turmas_aux) {
                                if (turma.get_uccode() == Uccode) {
                                    cout << turma.get_classcode() << " | " << turma.get_numeroalunos() << "/"
                                         << Max_students_by_UC[Uccode] << endl;
                                }
                            }
                            turmas_aux.clear();
                            break;
                        case '3' :
                            for (Turma turma: turmas) {
                                if (turma.get_uccode() == Uccode) {
                                    turmas_aux.push_back(turma);
                                }
                            }
                            sort(turmas_aux.begin(),turmas_aux.end(), ucs_stu_order);
                            for (Turma turma : turmas_aux) {
                                if (turma.get_uccode() == Uccode) {
                                    cout << turma.get_classcode() << " | " << turma.get_numeroalunos() << "/"
                                         << Max_students_by_UC[Uccode] << endl;
                                }
                            }
                            turmas_aux.clear();
                            break;
                        default:
                            break;
                    }
                    break;
                case '8': {
                    cout << "Insert the Class Code. (i.e.: 1LEIC01) \n";
                    cin >> Classcode3;
                    for (const Aula& aula: aulas) if (aula.get_ClassCode() == Classcode3) aulas_aux1.push_back(aula);
                    vector<Aula> Aulas1 = aulas_aux1;
                    sort(Aulas1.begin(), Aulas1.end());
                    string temp = " ";
                    for (const Aula& aula: Aulas1) {
                        if (aula.get_WeekDay() == temp) {
                            cout << ", " << UcCodeToName1(aula.get_UcCode()) << "(" << aula.get_Type() << ") from "
                                 << Double_to_hour1(aula.get_StartHour()) << " to "
                                 << Double_to_hour1(aula.get_StartHour() + aula.get_Duration());
                        } else {
                            temp = aula.get_WeekDay();
                            cout << "\n" << temp << ": ";
                            cout << UcCodeToName1(aula.get_UcCode()) << "(" << aula.get_Type() << ") from "
                                 << Double_to_hour1(aula.get_StartHour()) << " to "
                                 << Double_to_hour1(aula.get_StartHour() + aula.get_Duration());
                        }
                    }
                    aulas_aux1.clear();
                    cout << endl;
                    break;}
                case 'q':
                    break;
                default:
                    cout << "Not a valid key! \n";
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
        } else if (tipo == "edit"){
            cout << "Press a key according to what you want to do: \n"
                    "1 : Remove an UC/class from a student. \n"
                    "2 : Add a student to a certain class/UC. \n"
                    "3 : Change between classes, in a certain number of UCs. \n"
                    "q : Quit. \n";
            cin >> tecla;
            switch (tecla) {
                case '1' :
                    cout << "Insert your UPCode. \n";
                    cin >> up;
                    while (flag3) {
                        if (aux.find_by_upcode(Alunos, up).getStudentName() == "") {
                            cout << "This student doesn't exist in this database, insert a valid number. \n";
                            cin >> up;
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
                    for (const Aula& aula: aulas_aux) {
                        if (aula.get_ClassCode() == Classcode and aula.get_UcCode() == Uccode) flag6 = true;
                    }
                    if (flag6) {
                        novo_pedido = Pedido("remover", up, Uccode, Classcode, " ");
                        pedidos.push(novo_pedido);
                    } else {
                        cout << "You don't belong to that class. \n";
                    }
                    flag3 = true;
                    break;
                case '2' :
                    cout << "Insert your UPCode. \n";
                    cin >> up;
                    while(flag3){
                        if (aux.find_by_upcode(Alunos, up).getStudentName() == "") {
                            cout << "This student doesn't exist in this database, insert a valid number." << endl;
                            cin >> up;
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
                    for (const Aula& aula: aulas_aux) {
                        if (aula.get_UcCode() == Uccode) flag6 = false;
                    }
                    if (flag6) {
                        novo_pedido = Pedido("adicionar", up, Uccode, " ", Classcode);
                        pedidos.push(novo_pedido);
                    } else {
                        cout << "You already belong to a class in this UC, try changing class.";
                    }
                    flag3 = true;
                    aulas_aux.clear();
                    break;
                case '3':
                    cout << "Insert how many UCs are you going to change: \n";
                    cin >> n;
                    x = 0;
                    cout << "Insert your UPCode. \n";
                    cin >> up;
                    while (flag3) {
                        if (aux.find_by_upcode(Alunos, up).getStudentName() == "") {
                            cout << "This student doesn't exist in this database, insert a valid number." << endl;
                            cin >> up;
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
                        for (const Aula& aula: aulas_aux) {
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
                    aulas_aux.clear();
                    break;
                case 'q':
                    break;
                default:
                    cout << "Not a valid key! \n";
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
        else{
            while (!pedidos.empty()) {
                flag4 = false;
                Pedido ped_at = pedidos.front();
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
                                        }
                                    }
                                } else{
                                    non_accepted.push(ped_at);
                                }
                            } else {
                                non_accepted.push(ped_at);
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
                                } else non_accepted.push(ped_at);
                            } else non_accepted.push(ped_at);
                        }
                    }
                    if(flag5) {
                        aux.removerAula(Alunos, ped_at.getUp(), ped_at.getUc(), ped_at.getClass_antiga());
                        aux.find_by_upcode(Alunos, ped_at.getUp()).removeUcs();
                    }
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
