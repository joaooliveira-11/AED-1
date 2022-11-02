#include "string"
#include "Pedido.h"
using namespace std;

Pedido::Pedido(){
    this->type = "";
    this->up = 0;
    this->uc = "";
    this->class_antiga = "";
    this->class_nova = "";
}

Pedido::Pedido(string tipo, int up, string uc, string class_antiga, string class_nova){
    this->type = tipo;
    this->up = up;
    this->uc = uc;
    this->class_antiga = class_antiga;
    this->class_nova = class_nova;
}

string Pedido::getType() const {return type;}

int Pedido::getUp() const {return up;}

string Pedido::getUc() const {return uc;}

string Pedido::getClass_antiga() const{return class_antiga;}

string Pedido::getClass_nova() const {return class_nova;}