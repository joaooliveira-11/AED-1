#include "Menu.h"
#include "Horario.h"
#include "Aluno.h"
#include <iostream>
using namespace std;

void Menu::readmenu() {
    int test, turma, tecla;
    bool flag = true;
    string again = "No";
    cout << ("What class are you in? \n");
    cin >> turma;
    while (turma < 1 or turma > 16) {
        cout << ("Write a number between 1 and 16. \n");
        cin >> turma;
    }
    while (flag) {
        cout << ("Press a key according to what you want to do: \n 1 : See schedule. \n 2 : Edit schedule. \n 3 : Quit \n");
        cin >> tecla;
        switch (tecla) {
            case 1:
                //Horario horario = Horario();
                //horario.printHorario();
                cout << ("Would you like to do something else? (Yes/No) \n");
                cin >> again;
                if (again == "No") flag = false;
                break;
            case 2:
                //mudar o horario
                cout << ("Teste \n");
                break;
            case 3:
                flag = false;
                break;
            default:
                cout << ("Press a valid key! \n");
                break;
        }
    }
}

