#include <iostream>
#include <math.h>
#include "mod-solver.h"

using namespace std;

int main(){
    unsigned n;
    unsigned k;
    cout<<"Please enter modularity: ";
    cin >> n;
    cout<<"Please enter degree polynomial to be solved: ";
    cin >> k;
    brute_force_equation_solver(n, k);
    return 0;
}