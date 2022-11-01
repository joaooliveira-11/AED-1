///@file Pedido.h

#ifndef AED_1_PEDIDO_H
#define AED_1_PEDIDO_H

#include "string"
using namespace std;

///@brief A class for our queue.
class Pedido{
    private:
        string type, uc, class_antiga, class_nova;
        int up;
    public:
        Pedido();
        Pedido(string, int, string, string, string);
        string getType(){ return type;}
        int getUp(){return up;}
        string getUc(){return uc;}
        string getClass_antiga(){return class_antiga;}
        string getClass_nova(){return class_nova;}
};

#endif
