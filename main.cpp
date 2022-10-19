#include "classes/ReadingClasses.h"
#include "classes/Menu.h"
#include <iostream>
#include <map>
using namespace std;

int main() {

    Menu menu = Menu();
    menu.readmenu();

    ReadingClasses reading = ReadingClasses();
    vector<Aula*> res = reading.readAulas();
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
    /*for(Aula* aula: res){
        auto it = UcCodeToName.find(aula->get_UcCode());
        cout << "Aulas=("<< aula->get_ClassCode() << "," << it->second << "," << aula->get_WeekDay() << "," << aula->get_StartHour() << "," << aula->get_Duration() << "," << aula->get_Type() << ")" << endl;
    }
     */
    return 0;
}

