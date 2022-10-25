#include "Bst.h"
#include "Aluno.h"
#include <iostream>
using namespace std;

Bst::Bst() {
    atual = Aluno();
    Left = Right = NULL;
}

Bst::Bst(Aluno imp){
    atual = imp;
    Left = Right = NULL;
}

Bst* Bst::insert_by_upcode(Bst* base, Aluno imp){
    if (!base){
        return new Bst(imp);
    }
    if (imp > base->atual){
        base->Right = insert_by_upcode(base->Right, imp);
    }
    else if (imp < base->atual){
        base->Left = insert_by_upcode(base->Left, imp);
    }
    return base;

}
void Bst::view(Bst* base){
    if(!base){
        return;
    }
    view(base->Left);
    cout << base->atual.getStudentCode() << " | ";
    cout << base->atual.getStudentName()  << endl;
    view(base->Right);
}

void Bst::view_by_NUCS(Bst* base, int x){
    if(!base){
        return;
    }
    view_by_NUCS(base->Left, x);
    if ( base->atual.getNUCS() > x ){
        cout << base->atual.getStudentCode() << " | ";
        cout << base->atual.getStudentName()  << endl;
    }
    view_by_NUCS(base->Right, x);
}
Aluno Bst::find_by_upcode(Bst *base, int upcode){
    if ( !base){
        return Aluno();
    }
    else if ( upcode == base->atual.getStudentCode()){
        return base->atual;
    }
    else if( upcode > base->atual.getStudentCode()){
        return find_by_upcode(base->Right, upcode);
    }
    return find_by_upcode(base->Left, upcode);
}
