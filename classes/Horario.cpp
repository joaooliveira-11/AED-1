#include "Horario.h"
#include "iostream"
#include "algorithm"
using namespace std;

Horario::Horario(vector<Aula> horarioaluno) : horarioAluno(horarioaluno) {}

void Horario::addAula(Aula nAula){
    horarioAluno.push_back(nAula);
}
void Horario::removeAula(Aula nAula){

}
vector<Aula> Horario::getAulas() {
    return horarioAluno;
}

string Horario::printHorario() {
    vector<Aula> Aulas = this->getAulas();
    sort(Aulas.begin(),Aulas.end());
    string temp = " ";
    string answer = "";
    for(Aula& aula : Aulas){
        if (aula.get_WeekDay()== temp){
            answer += ", " + aula.get_UcCode() + " " + "from " + to_string(aula.get_StartHour()) + "h to" + to_string(aula.get_StartHour()+aula.get_Duration()) +"h " + aula.get_Type();
        }
        else{
            temp = aula.get_WeekDay();
            answer +=  "\n" + temp + " : ";
            answer +=  aula.get_UcCode() + " " + "from " + to_string(aula.get_StartHour()) + "h to" + to_string(aula.get_StartHour()+aula.get_Duration()) +"h " + aula.get_Type();
        }
    }
    return answer;
}

