//
// Created by Piotr on 11.01.2022.
//

#include "Clause.h"

Clause::Clause(double var1, double var2, double var3, int index1, int index2, int index3) {
    var_array[0] = var1;
    var_array[1] = var2;
    var_array[2] = var3;

    index_array[0] = index1;
    index_array[1] = index2;
    index_array[2] = index3;
}

int Clause::check(vector<bool>& vec_solution) {
    bool b_negate;
    for(int i = 0; i < sizeof(var_array)/sizeof(var_array[0]); i++){
        if(vec_solution.at(index_array[i]) == 0)
            b_negate = true;
        else
            b_negate = false;

        if(signbit(var_array[i]) == 1 && b_negate) //jezeli signbit == 1 to zmienna jest zaprzeczona, jezeli b_negate == true, to negujemy zmienną
            return 1;
        if(signbit(var_array[i]) == 0 && !b_negate)
            return 1;
    }
    return 0;
}

int Clause::iGetIndex(int offset) {
    return index_array[offset];
}

