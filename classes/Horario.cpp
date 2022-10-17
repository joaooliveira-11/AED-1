#include "Horario.h"
using namespace std;

void Horario::addAula(Aula nAula){
    aulasMarcadas.push_back(nAula);
}
void Horario::removeAula(Aula nAula){

}
vector<Aula> Horario::getAulas() {
    return aulasMarcadas;
}