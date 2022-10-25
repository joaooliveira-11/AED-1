#include "Horario.h"
#include "iostream"
#include "algorithm"
using namespace std;
#include <cmath>
#include <map>


Horario::Horario() {
    vector<Aula> horarioAluno;
}

Horario::Horario(vector<Aula> horarioaluno) : horarioAluno(horarioaluno) {}

void Horario::addAula(Aula nAula){
    horarioAluno.push_back(nAula);
}
void Horario::removeAula(Aula nAula){

}
vector<Aula> Horario::getAulas() {
    return horarioAluno;
}
string Horario::UcCodeToName(string uccode){
    map<string, string> UcCode_Name = {{"L.EIC001", "ALGA"},
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
    return UcCode_Name[uccode];
}


void Horario::printHorario() {
    vector<Aula> Aulas = this->getAulas();
    sort(Aulas.begin(), Aulas.end());
    string temp = " ";
    for (Aula &aula: Aulas) {
        if (aula.get_WeekDay() == temp) {
            cout << ", " << UcCodeToName(aula.get_UcCode()) << "(" << aula.get_Type() << ")" << " " << "from "
                 << aula.get_StartHour() << "h to " << (aula.get_StartHour() + aula.get_Duration()) << "h ";
        } else {
            temp = aula.get_WeekDay();
            cout << "\n" << temp << " : ";
            cout << UcCodeToName(aula.get_UcCode()) << "(" << aula.get_Type() << ")" << " " << "from "
                 << aula.get_StartHour() << "h to " << (aula.get_StartHour() + aula.get_Duration()) << "h ";
        }
    }
    cout <<endl << endl;
}

