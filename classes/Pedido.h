///@file Pedido.h

#ifndef AED_1_PEDIDO_H
#define AED_1_PEDIDO_H

#include "string"
using namespace std;

///@brief A class for our queue's object.
class Pedido{
    private:
        ///@brief The Request type, Class UCcode, The Class code that we want to change, The new Class code
        string type, uc, class_antiga, class_nova;

        ///@brief The StudentCode
        int up;
    public:
        ///@brief Empty request constructor.
        Pedido();

        ///@brief Constructor of new request given it's type
        ///@param tipo
        ///@param up
        ///@param uc
        ///@param class_antiga
        ///@param class_nova
        Pedido(string tipo, int up, string uc, string class_antiga, string class_nova);

        ///@brief Getter for the Request Type
        ///@returns The Request Type (remover, adicionar, alterar)
        string getType() const;

        ///@brief Getter for the StudentCode
        ///@returns The StudentCode
        int getUp() const;

        ///@brief Getter for the Class UCcode
        ///@returns The Class UCcode
        string getUc() const;

        ///@brief Getter for the Class code that we want to change
        ///@returns The Class code that we want to change
        string getClass_antiga() const;

        ///@brief Getter for the new Class code
        ///@returns The new Class code
        string getClass_nova() const;
};

#endif
