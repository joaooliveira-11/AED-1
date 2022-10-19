#include <iostream>
using namespace std;
#include "classes/Reading.h"
#include "classes/Menu.h"

int main() {
    /*
    int test, turma, tecla;

void menu(){
    int tecla;
    bool flag = true;
    while (flag){
        cout << ("Press a key according to what you want to do: \n 1 : See schedule. \n 2 : Edit schedule. \n 3 : Quit \n");
        cin >> tecla;
        switch (tecla) {
            case 1:
                //dar print ao horario
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

int main() {
    /*
    int test, turma;

    cout << ("What class are you in? \n");
    cin >> turma;
    while (turma<1 or turma>16) {
        cout << ("Write a number between 1 and 16. \n");
        cin >> turma;
    }


    }
     */
    /*
    Menu menu = Menu();
    menu.readmenu();
     */
    Reading reading = Reading();
    vector<Aula> res = reading.readAulas();
    for(Aula aula: res){
        cout << "Aulas=("<< aula.get_ClassCode() << "," << aula.get_UcCode() << "," << aula.get_WeekDay() << "," << aula.get_StartHour() << "," << aula.get_Duration() << "," << aula.get_Type() << ")" << endl;
    }
   // menu();
    return 0;
}

