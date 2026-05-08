#ifndef LISTA_SIMPLE_ORDENADA_HPP
#define LISTA_SIMPLE_ORDENADA_HPP

#include <iostream>
#include "nodo.hpp"

class lista_simple_ordenada {
public:
    nodo* head;

    lista_simple_ordenada() { head = NULL; }

    // Inserta k manteniendo orden ascendente
    void insertar(int k) {
        nodo* y = new nodo();
        y->key  = k;
        // Caso 1: lista vacía o k es el menor
        if (head == NULL || k <= head->key) {
            y->next = head;
            head    = y;
            return;
        }
        // Caso 2: buscar posición correcta
        nodo* x = head;
        while (x->next != NULL && x->next->key < k)
            x = x->next;
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

    // Retorna puntero al nodo con key == k, o NULL si no existe
    nodo* buscar_key(int k) {
        nodo* x = head;
        while (x != NULL) {
            if (x->key == k) return x;
            x = x->next;
        }
        return NULL;
    }

    void imprimir() {
        nodo* x = head;
        while (x != NULL) { std::cout << x->key << " -> "; x = x->next; }
        std::cout << "NULL\n";
    }
};

#endif
