#include "Horario.h"
#include "Aluno.h"
#include "iostream"
#include "algorithm"
#include <string>
#include <map>
#include <vector>
using namespace std;

Horario::Horario() {vector<Aula> horarioAluno;}
Horario::Horario(vector<Aula> horarioaluno) : horarioAluno(horarioaluno) {}

vector<Aula> Horario::getAulas() {return horarioAluno;}

void Horario::setHorario(vector<Aula> aulas){this->horarioAluno=aulas;}

void Horario::addAula(const Aula& nAula) {return horarioAluno.push_back(nAula);}

string Horario::Double_to_hour(double time){
    string hour = to_string(int(time));
    int minutes = int(((time - int(time)) * 100) * 0.6);
    return int(minutes) == 0 ? hour + ":" + to_string(minutes) + "0" : hour + ":" + to_string(minutes);
}

string Horario::UcCodeToName(const string& uccode){
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
                                        {"L.EIC030", "PI"},
                                        {"UP001", "PUP"}};
    return UcCode_Name[uccode];
}

void Horario::printHorario() {
    vector<Aula> Aulas = this->getAulas();
    if (Aulas.empty()){
        cout << "This student doesn't have any class. \n";
        return;
    }
    sort(Aulas.begin(), Aulas.end());
    string temp = " ";
    for (Aula &aula: Aulas) {
        if (aula.get_WeekDay() == temp) {
            cout << ", " << UcCodeToName(aula.get_UcCode()) << "(" << aula.get_Type() << ") from "
                 << Double_to_hour(aula.get_StartHour()) << " to "
                 << Double_to_hour(aula.get_StartHour() + aula.get_Duration());
        } else {
            temp = aula.get_WeekDay();
            cout << "\n" << temp << ": ";
            cout << UcCodeToName(aula.get_UcCode()) << "(" << aula.get_Type() << ") from "
                 << Double_to_hour(aula.get_StartHour()) << " to "
                 << Double_to_hour(aula.get_StartHour() + aula.get_Duration());
        }
    }
    cout << endl << endl;
}

void Horario::removerAula(const string& Uccode, const string& Classcode) {
    vector<Aula> novo;
    for (const Aula& aula: horarioAluno) {
        if ((aula.get_ClassCode() != Classcode) || (aula.get_UcCode() != Uccode)) {
            novo.push_back(aula);
        }
    }
    setHorario(novo);
}
