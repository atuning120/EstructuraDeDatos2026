#include <iostream>
#include "lista.h"
#include <string>

using namespace std;


void imprimirLista (Nodo *head){
    //si la lista esta vacia
    if(head == nullptr){
        return;
    }

    //si la lista solo tiene un nodo
    if(head->getNext() == nullptr){
        cout << head->getDato() << endl;
        return; 
    }

    //si la lista tiene mas de un nodo
    Nodo *current= head;
    while (current->getNext() != nullptr){
        cout << current->getDato() << " -> ";
        current=current->getNext();
    }

    cout << current->getDato() << endl;
}


Nodo* addInicio(Nodo *head, Nodo *nuevo){
    //Si la lista viene vacia
    if(head == nullptr){
        head=nuevo;
        return head;
    }

    //si no
    nuevo->setNext(head);
    return nuevo;
}


Nodo* addFin(Nodo *head, Nodo *nuevo){
     //Si la lista viene vacia
    if(head == nullptr){
        return nullptr;
    }

    //si la lista tiene 1 elemento
    if(head->getNext() == nullptr){
        head->setNext(nuevo);
        return head;
    }

    //si hay muchos nodos
    Nodo *current=head;
    while (current->getNext() != nullptr){
        current= current->getNext();
    }
    current->setNext(nuevo);
    return head;
}

Nodo* dropElemento(Nodo *head, int n){
    //si la lista está vacia
    if(head==nullptr) return nullptr;

    //si se tiene que eliminar el primer elemento
    if(head->getDato() == n) return head->getNext();


    //si la lista tiene muchos elementos
    Nodo *current = head;
    Nodo *last= nullptr;
    while (current!= nullptr){

        if (current->getDato()==n){
            last->setNext(current->getNext());
            current->setNext(nullptr);
            return head;
        }
        last=current;
        current= current->getNext();
    }

    return head;
}

int main() {
    Nodo *head=new Nodo(0);
    Nodo *nodo1= new Nodo(1);
    Nodo *nodo2= new Nodo(2);
    Nodo *nodo3= new Nodo(3);


    head->setNext(nodo1);
    nodo1->setNext(nodo2);
    nodo2->setNext(nodo3);

    imprimirLista(head);



    Nodo *nodo4= new Nodo(4);
    head=addInicio(head,nodo4);
    imprimirLista(head);


    Nodo *nodo5= new Nodo(5);
    head=addFin(head,nodo5);
    imprimirLista(head);


    dropElemento(head, 4);
    imprimirLista(head); 
}   
