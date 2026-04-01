#include <iostream>
#include "lista.h"

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
        return nuevo;
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
    if(head == nullptr){
        return nullptr;
    }

    //si el nodo a eliminar es el head
    if(head->getDato() == n){
        Nodo *temp= head->getNext();
        head->setNext(nullptr);
        delete head;
        return temp;
    }

    //si el nodo a eliminar no es el head
    Nodo *current= head;
    while (current->getNext() != nullptr){
        if(current->getNext()->getDato() == n){
            Nodo *temp= current->getNext();
            current->setNext(current->getNext()->getNext());
            temp->setNext(nullptr);
            delete temp;
            return head;
        }
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


    head=dropElemento(head, 2);
    imprimirLista(head);
}   
