///@file Pedido.h

#ifndef AED_1_PEDIDO_H
#define AED_1_PEDIDO_H

#include "string"
using namespace std;

///@brief A class for our queue's object.
class Pedido{
    private:
        ///@brief The request's type, UC's code, the ClassCode that we want to change and the new ClassCode.
        string type, uc, class_antiga, class_nova;

        ///@brief The student's UPcode.
        int up;
    public:
        ///@brief Empty request constructor.
        Pedido();

        ///@brief Constructor of new request given it's type.
        ///@param tipo The type of request.
        ///@param up A student's UPcode
        ///@param uc The class' UCcode
        ///@param class_antiga The class we had.
        ///@param class_nova The class we want to add.
        Pedido(string tipo, int up, string uc, string class_antiga, string class_nova);

        ///@brief Getter for the request's type.
        ///@returns The request's type (remover, adicionar ou alterar).
        string getType() const;

        ///@brief Getter for the StudentCode.
        ///@returns The StudentCode.
        int getUp() const;

        ///@brief Getter for the class' UCcode.
        ///@returns The class' UCcode.
        string getUc() const;

        ///@brief Getter for the ClassCode that we want to change.
        ///@returns The ClassCode that we want to change.
        string getClass_antiga() const;

        ///@brief Getter for the new ClassCode.
        ///@returns The new ClassCode.
        string getClass_nova() const;
};

#endif
