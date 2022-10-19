#include "Horario.h"
#include "iostream"
#include "algorithm"
using namespace std;

Horario::Horario(vector<Aula> horarioaluno):horarioAluno(horarioaluno) {}
void Horario::addAula(Aula nAula){
    horarioAluno.push_back(nAula);
}
void Horario::removeAula(Aula nAula){

}
vector<Aula> Horario::getAulas() {
    return horarioAluno;
}
/*
void Horario::printHorario() {
    vector<Aula> Aulas = this->getAulas();
    sort(Aulas.begin(),Aulas.end());
    string temp = "Monday";
    cout << "Monday : ";
    for(Aula& aula : Aulas){
        if (aula.get_WeekDay()== temp){
            cout << ", " << aula.get_UcCode() << " " << "from " << aula.get_StartHour() << "h to" << (aula.get_StartHour()+aula.get_Duration()) <<"h ";
        }
        else{
            temp = aula.get_WeekDay();
            cout << "\n" << temp << " : ";
            cout << aula.get_UcCode() << " " << "from " << aula.get_StartHour() << "h to" << (aula.get_StartHour()+aula.get_Duration()) <<"h ";
        }
    }
}
*/
