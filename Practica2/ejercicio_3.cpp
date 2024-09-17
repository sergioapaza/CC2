#include <iostream>
using namespace std;

// Prototipo de la función mostrar
void mostrar(int* p, int tam);

// Función para intercambiar dos valores por referencia
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función para mezclar dos mitades del array
void merge(int* p, int* q) {
    // Mientras los punteros no sean iguales (no hemos terminado de recorrer el array)
    while (p != q) {
        if (*p > *q) {
            // Intercambia los elementos si el valor de *p es mayor que *q
            for (int* ini = p, *fin = q; ini != q; ini++, fin++) {
                if(*ini>*fin){
                    swap(*ini, *fin);
                }
            }
        }
        p++;  // Avanzamos el puntero p
    }
}

// Función para mostrar los elementos del array
void mostrar(int* p, int tam) {
    for (int i = 0; i < tam; i++) {
        cout << *(p + i) << " ";  // Acceso al elemento usando aritmética de punteros
    }
    cout << endl;
}

int main() {
    int a[] = {2, 6, 14, 20, 1, 3, 15, 21};  // Array original
    int tam = sizeof(a) / sizeof(a[0]);     // Tamaño del array

    cout << "Array original: ";
    mostrar(a, tam);  // Muestra el array original

    merge(a, a + 4);   // Mezclar la primera mitad con la segunda

    cout << "Array después de merge: ";
    mostrar(a, tam);  // Muestra el array después de la operación merge

    return 0;
}
