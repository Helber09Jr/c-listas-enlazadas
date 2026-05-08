#ifndef LISTA_LD_HPP
#define LISTA_LD_HPP

#include <iostream>

struct nodo_ld {
    int      key;
    nodo_ld* prev;
    nodo_ld* next;
};

class lista_ld {
public:
    nodo_ld* head;
    nodo_ld* tail;

    lista_ld() { head = NULL; tail = NULL; }

    void insertar_inicio(int k) {
        nodo_ld* y = new nodo_ld();
        y->key  = k;
        y->prev = NULL;
        y->next = head;
        if (head != NULL) head->prev = y;
        else              tail = y;
        head = y;
    }

    void insertar_final(int k) {
        nodo_ld* y = new nodo_ld();
        y->key  = k;
        y->next = NULL;
        y->prev = tail;
        if (tail != NULL) tail->next = y;
        else              head = y;
        tail = y;
    }

    void eliminar(int k) {
        if (head == NULL) { std::cout << "Lista vacia\n"; return; }
        nodo_ld* x = head;
        while (x != NULL && x->key != k) x = x->next;
        if (x == NULL) { std::cout << "Valor " << k << " no encontrado\n"; return; }
        if (x->prev != NULL) x->prev->next = x->next;
        else                 head = x->next;
        if (x->next != NULL) x->next->prev = x->prev;
        else                 tail = x->prev;
        delete x;
    }

    // Retorna la cantidad de elementos
    int size() {
        int count = 0;
        nodo_ld* x = head;
        while (x != NULL) { count++; x = x->next; }
        return count;
    }

    // Busca el nodo con key==k y reemplaza su key por kk
    void reemplazar(int k, int kk) {
        nodo_ld* x = head;
        while (x != NULL) {
            if (x->key == k) { x->key = kk; return; }
            x = x->next;
        }
        std::cout << "Valor " << k << " no encontrado\n";
    }

    // Une lista2 al final de esta lista (copia profunda de los nodos)
    void unir(lista_ld lista2) {
        nodo_ld* x = lista2.head;
        while (x != NULL) {
            insertar_final(x->key);
            x = x->next;
        }
    }

    void imprimir() {
        nodo_ld* x = head;
        while (x != NULL) { std::cout << x->key << " <-> "; x = x->next; }
        std::cout << "NULL\n";
    }
};

#endif
