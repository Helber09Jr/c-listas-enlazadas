#include <iostream>
#include "lista_simple.hpp"
#include "lista_simple_ordenada.hpp"
#include "lista_ld.hpp"
using namespace std;

// ── Submenú lista simple ────────────────────────────────────────────────────
void menu_lista_simple() {
    lista_simple lista;
    int op, valor, ref;
    do {
        cout << "\n--- Lista Simple ---\n"
             << "1. Imprimir\n"
             << "2. Insertar al inicio\n"
             << "3. Insertar al final\n"
             << "4. Insertar antes de\n"
             << "5. Eliminar\n"
             << "0. Volver\n"
             << "Opcion: ";
        cin >> op;
        switch (op) {
            case 1: lista.imprimir(); break;
            case 2: cout << "Valor: "; cin >> valor; lista.insertar_inicio(valor); break;
            case 3: cout << "Valor: "; cin >> valor; lista.insertar_final(valor); break;
            case 4:
                cout << "Nuevo valor: "; cin >> valor;
                cout << "Insertar antes de: "; cin >> ref;
                lista.insertar_antes_de(valor, ref); break;
            case 5: cout << "Valor a eliminar: "; cin >> valor; lista.eliminar(valor); break;
            case 0: break;
            default: cout << "Opcion invalida\n";
        }
    } while (op != 0);
}

// ── Submenú lista simple ordenada ──────────────────────────────────────────
void menu_lista_ordenada() {
    lista_simple_ordenada lista;
    int op, valor;
    do {
        cout << "\n--- Lista Simple Ordenada (ascendente) ---\n"
             << "1. Imprimir\n"
             << "2. Insertar\n"
             << "3. Eliminar\n"
             << "4. Buscar key\n"
             << "0. Volver\n"
             << "Opcion: ";
        cin >> op;
        switch (op) {
            case 1: lista.imprimir(); break;
            case 2: cout << "Valor: "; cin >> valor; lista.insertar(valor); break;
            case 3: cout << "Valor a eliminar: "; cin >> valor; lista.eliminar(valor); break;
            case 4:
                cout << "Valor a buscar: "; cin >> valor;
                if (lista.buscar_key(valor))
                    cout << "Encontrado: " << valor << "\n";
                else
                    cout << "No encontrado\n";
                break;
            case 0: break;
            default: cout << "Opcion invalida\n";
        }
    } while (op != 0);
}

// ── Submenú lista doble ────────────────────────────────────────────────────
void menu_lista_doble() {
    lista_ld lista;
    int op, valor, valor2;
    do {
        cout << "\n--- Lista Doblemente Enlazada ---\n"
             << "1. Imprimir\n"
             << "2. Insertar al inicio\n"
             << "3. Insertar al final\n"
             << "4. Eliminar\n"
             << "5. Size\n"
             << "6. Reemplazar\n"
             << "7. Unir con otra lista\n"
             << "0. Volver\n"
             << "Opcion: ";
        cin >> op;
        switch (op) {
            case 1: lista.imprimir(); break;
            case 2: cout << "Valor: "; cin >> valor; lista.insertar_inicio(valor); break;
            case 3: cout << "Valor: "; cin >> valor; lista.insertar_final(valor); break;
            case 4: cout << "Valor a eliminar: "; cin >> valor; lista.eliminar(valor); break;
            case 5: cout << "Cantidad de elementos: " << lista.size() << "\n"; break;
            case 6:
                cout << "Valor a reemplazar: "; cin >> valor;
                cout << "Nuevo valor: "; cin >> valor2;
                lista.reemplazar(valor, valor2); break;
            case 7: {
                lista_ld lista2;
                int n;
                cout << "Cuantos elementos para la segunda lista: "; cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Elemento " << i+1 << ": "; cin >> valor;
                    lista2.insertar_final(valor);
                }
                cout << "Lista2: "; lista2.imprimir();
                lista.unir(lista2);
                cout << "Resultado: "; lista.imprimir();
                break;
            }
            case 0: break;
            default: cout << "Opcion invalida\n";
        }
    } while (op != 0);
}

// ── Menú principal ─────────────────────────────────────────────────────────
int main() {
    int op;
    do {
        cout << "\n========== MENU PRINCIPAL ==========\n"
             << "1. Lista Simple\n"
             << "2. Lista Simple Ordenada\n"
             << "3. Lista Doblemente Enlazada\n"
             << "0. Salir\n"
             << "Opcion: ";
        cin >> op;
        switch (op) {
            case 1: menu_lista_simple(); break;
            case 2: menu_lista_ordenada(); break;
            case 3: menu_lista_doble(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }
    } while (op != 0);
    return 0;
}
