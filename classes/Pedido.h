//
// Created by andre on 31/10/2022.
//
#include "string"

using namespace std;
#ifndef AED_1_PEDIDO_H
#define AED_1_PEDIDO_H
class Pedido{
        string type;
        int up;
        string uc;
        string class_antiga;
        string class_nova;
    public:
        Pedido(string, int, string, string, string);
        string getType(){ return type;}
        int getUp(){return up;}
        string getUc(){return uc;}
        string getClass_antiga(){return class_antiga};
        string getClass_nova(){return class_nova;}
};
#endif //AED_1_PEDIDO_H
