#ifndef LISTA_SIMPLE_HPP
#define LISTA_SIMPLE_HPP

#include <iostream>
#include "nodo.hpp"

class lista_simple {
public:
    nodo* head;

    lista_simple() { head = NULL; }

    void insertar_inicio(int k) {
        nodo* y  = new nodo();
        y->key   = k;
        y->next  = head;
        head     = y;
    }

    void insertar_final(int k) {
        if (head == NULL) { insertar_inicio(k); return; }
        nodo* y  = new nodo();
        y->key   = k;
        y->next  = NULL;
        nodo* x  = head;
        while (x->next != NULL) x = x->next;
        x->next  = y;
    }

    void insertar_antes_de(int valor, int ref) {
        nodo* y = new nodo();
        y->key  = valor;
        if (head == NULL) {
            std::cout << "Lista vacia\n";
            delete y; return;
        }
        if (head->key == ref) { y->next = head; head = y; return; }
        nodo* x = head;
        while (x->next != NULL && x->next->key != ref) x = x->next;
        if (x->next == NULL) {
            std::cout << "Valor de referencia no encontrado\n";
            delete y; return;
        }
        y->next = x->next;
        x->next = y;
    }

    void eliminar(int k) {
        if (head == NULL) { std::cout << "Lista vacia\n"; return; }
        if (head->key == k) {
            nodo* temp = head;
            head = head->next;
            delete temp; return;
        }
        nodo* x = head;
        while (x->next != NULL && x->next->key != k) x = x->next;
        if (x->next == NULL) { std::cout << "Valor " << k << " no encontrado\n"; return; }
        nodo* temp = x->next;
        x->next    = temp->next;
        delete temp;
    }

    void imprimir() {
        nodo* x = head;
        while (x != NULL) { std::cout << x->key << " -> "; x = x->next; }
        std::cout << "NULL\n";
    }
};

#endif
