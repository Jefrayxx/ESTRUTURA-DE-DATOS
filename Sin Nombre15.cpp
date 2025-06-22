#include <iostream>     // Para entrada y salida est�ndar
#include <string>       // Para poder usar strings
using namespace std;

// Estructura que representa un nodo en el �rbol geneal�gico
struct Nodo {
    int id;              // Identificador �nico para la persona
    string nombre;       // Nombre de la persona
    Nodo* izq;           // Puntero al hijo izquierdo
    Nodo* der;           // Puntero al hijo derecho
    Nodo* padre;         // Puntero al nodo padre
};

// Funci�n que crea y retorna un nuevo nodo con los datos entregados
Nodo* crearNodo(int id, string nombre) {
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->padre = NULL;
    return nuevo;
}

// Funci�n para buscar una persona por su ID en todo el �rbol
Nodo* buscarPorID(Nodo* raiz, int id) {
    if (raiz == NULL) return NULL;            // Caso base: �rbol vac�o
    if (raiz->id == id) return raiz;          // Se encontr� el nodo

    Nodo* encontrado = buscarPorID(raiz->izq, id); // Buscar por la izquierda
    if (encontrado != NULL) return encontrado;     // Si lo encontr�, lo retorna

    return buscarPorID(raiz->der, id);             // Buscar por la derecha
}

// Funci�n para insertar un hijo (si hay espacio)
void insertarHijo(Nodo* padre, int id, string nombre) {
    Nodo* hijo = crearNodo(id, nombre);
    hijo->padre = padre;

    if (padre->izq == NULL)
        padre->izq = hijo;
    else if (padre->der == NULL)
        padre->der = hijo;
    else
        cout << "Esta persona ya tiene dos descendientes.\n";
}

// Funci�n que muestra el men� principal
void menuGenealogia() {
    Nodo* raiz = NULL;  // El �rbol parte vac�o
    int opcion, id, idPadre;
    string nombre;

    do {
        cout << "\n--- MENU GENEALOGICO CON ID ---\n";
        cout << "1. Ingresar ancestro principal\n";
        cout << "2. Insertar descendiente\n";
        cout << "3. Salir\n";
        cout << "Ingrese una opci�n: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                if (raiz != NULL) {
                    cout << "Ya hay un ancestro registrado.\n";
                    break;
                }
                cout << "ID del ancestro: ";
                cin >> id;
                cout << "Nombre: ";
                cin >> nombre;
                raiz = crearNodo(id, nombre);
                cout << "Ancestro registrado.\n";
                break;

            case 2:
                cout << "ID del padre existente: ";
                cin >> idPadre;
                cout << "ID del nuevo descendiente: ";
                cin >> id;
                cout << "Nombre del descendiente: ";
                cin >> nombre;
                {
                    Nodo* padreNodo = buscarPorID(raiz, idPadre);
                    if (padreNodo != NULL)
                        insertarHijo(padreNodo, id, nombre);
                    else
                        cout << "No se encontr� ese ID en el �rbol.\n";
                }
                break;

            case 3:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 3);
}

int main() {
    menuGenealogia();
    return 0;
}

