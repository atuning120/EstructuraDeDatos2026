#include <iostream>

using namespace std;
class Nodo {
    private:
        int dato;
        Nodo* next;
    public:
        Nodo (int dato);
        int getDato();
        void setDato(int dato);
        Nodo* getNext();
        void setNext(Nodo* next);
        ~Nodo();
};

Nodo::Nodo(int dato) {
    this->dato = dato;
    this->next = nullptr;
}

int Nodo::getDato() {
    return this->dato;
}

void Nodo::setDato(int dato) {
    this->dato = dato;
}
Nodo* Nodo::getNext() {
    return this->next;
}
void Nodo::setNext(Nodo* next) {
    this->next = next;
}
Nodo::~Nodo(){
    cout << "Nodo con dato " << this->dato << " eliminado." << endl;
}