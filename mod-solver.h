#include <iostream>
#include <math.h>

using namespace std;

void brute_force_equation_solver(unsigned s, unsigned k);
void fill_array(unsigned *array, unsigned len, int value);
void print_results(unsigned n, unsigned order, unsigned *coefficients, unsigned constant, unsigned *solutions);
bool finished_iterating_coefficients(unsigned order, unsigned *coefficients);
void increment_coefficients(unsigned n, unsigned order, unsigned *coefficients);
void print_array(unsigned *array, unsigned len);
void print_incrementation(unsigned n, unsigned order, unsigned* coefficients);

void brute_force_equation_solver(unsigned n, unsigned k){
    unsigned solutions[n];
    unsigned num_solutions;
    unsigned coefficients[k];
    unsigned to_add;
    unsigned total;
    fill_array(coefficients, k, 0);
    coefficients[0] = 1;
    while(!finished_iterating_coefficients(k, coefficients)){
        for (unsigned constant=0; constant<n; constant++){
            num_solutions=0;
            fill_array(solutions, n, n);
            for(unsigned x=0; x<n; x++){
                total=0;    
                for(unsigned order=0; order<k; order++){
                    total += (unsigned(pow(x, order+1)) * coefficients[order]);
                }
                total+=constant;
                total = total % n;
                if(total == 0){solutions[num_solutions] = x; num_solutions++;}
            }
            print_results(n, k, coefficients, constant, solutions);
        }
        increment_coefficients(n, k, coefficients);
    }
}

void print_incrementation(unsigned n, unsigned order, unsigned* coefficients){
    while(!finished_iterating_coefficients(order, coefficients)){
        print_array(coefficients, order);
        increment_coefficients(n, order, coefficients);
    }
}

void increment_coefficients(unsigned n, unsigned order, unsigned *coefficients){
    // This will iterate through the array until it finds an element which is not carried and the stops
            // This means this function will increment coefficients or return all zeros 
    int index = 0;
    while(index < order){
        coefficients[index] = (coefficients[index] + 1) % n;
        if(coefficients[index] == 0){
            index++;
        }
        else{return;}        
    }
    return;
}

bool finished_iterating_coefficients(unsigned order, unsigned *coefficients){
    for(unsigned i=0; i<order; i++){
        if(coefficients[i]!=0){return false;}
    }
    return true;
}

void fill_array(unsigned *array, unsigned len, int value){
    for(unsigned i=0; i<len; i++){
        array[i] = value;
    }
}

void print_results(unsigned n, unsigned order, unsigned *coefficients, unsigned constant, unsigned *solutions){
    cout<<"Equation: ";
    if(coefficients[0]){
        cout<<coefficients[0]<<"x";
    }
    if(order>1){
        if(coefficients[0]){
            cout<<" + ";
        }
        for(unsigned i=2; i<order; i++){
            if(coefficients[i-1]){
                cout<<coefficients[i-1]<<"x^"<<i<<" + ";
            }
        }
        if(coefficients[order-1]){
            cout<<coefficients[order-1]<<"x^"<<order<<" + ";
        }
    }
    cout<<constant;
    cout<<" = 0";
    cout<<endl<<"Has solutions: ";
    unsigned i=0;
    if(solutions[i]==n){cout<<"None";}
    else{
        while(i<n && solutions[i]<n){
            cout<<solutions[i]<<", ";
            i++;
        }
    }
    cout<<endl<<endl;
}

void print_array(unsigned *array, unsigned len){
    for(unsigned i=0; i<len;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}