//
// Created by andre on 31/10/2022.
//
#include "string"
#include "Pedido.h"

using namespace std;

Pedido::Pedido(string tipo, int up, string uc, string class_antiga, string class_nova){
    this->type = tipo;
    this->up = up;
    this->uc = uc;
    this->class_antiga = class_antiga;
    this->class_nova = class_nova;
}