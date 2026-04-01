#include <iostream>
#include <string>
#include <stack>

using namespace std;

void imprimirPila(stack<char> pila){
    while (!pila.empty()){
        cout << pila.top();
        pila.pop();
    }
    cout << endl;
}

int main(){

    string cadena= "HOLA MUNDO";
    stack<char> pila;


    for(int i=0; i<cadena.length(); i++){
        pila.push(cadena[i]);
    }

    cout << cadena << endl;
    imprimirPila(pila);

    return 0;
}