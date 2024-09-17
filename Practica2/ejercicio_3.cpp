#include <iostream>
using namespace std;

int main() {
    int n;
    int* arr = nullptr;  // Puntero para el array

    // Solicitar el tamaño del array y asegurarse de que sea par
    do {
        cout << "Introduce un tamaño de array (debe ser par): ";
        cin >> n;
    } while (n % 2 != 0);  // Repite hasta que el tamaño sea par

    // Reservar memoria para el array
    arr = new int[n];

    // Llenar la primera mitad con números pares y la segunda mitad con números impares
    int par = 2;  // Primer número par
    int impar = 1;  // Primer número impar

    // Usando punteros para llenar el array
    for (int* p = arr; p < arr + n / 2; ++p) {
        *p = par;    // Asignar número par
        par += 2;
    }
    for (int* p = arr + n / 2; p < arr + n; ++p) {
        *p = impar;  // Asignar número impar
        impar += 2;
    }

    // Mostrar el array lleno
    cout << "Array antes de ordenar:\n";
    for (int* p = arr; p < arr + n; ++p) {
        cout << *p << " ";
    }
    cout << endl;

    // Ordenamiento con dos pivotes
    int* pivote1 = arr;             // Pivote que apunta al inicio (primer número par)
    int* pivote2 = arr + n / 2;     // Pivote que apunta al inicio de la mitad de los impares

    // Mover elementos menores que el pivote2 a la primera parte del array
    while (pivote1 < arr + n / 2 && pivote2 < arr + n) {
        if (*pivote1 <= *pivote2) {
            ++pivote1;
        } else {
            // Intercambiar los valores de los pivotes
            int temp = *pivote2;
            int* tempPtr = pivote2;
            while (tempPtr > pivote1) {
                *tempPtr = *(tempPtr - 1);
                --tempPtr;
            }
            *pivote1 = temp;
            ++pivote1;
            ++pivote2;
        }
    }

    // Ordenar la segunda parte que quedó sin ordenar
    for (int* p = arr + n / 2; p < arr + n; ++p) {
        for (int* q = p + 1; q < arr + n; ++q) {
            if (*p > *q) {
                int temp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }

    // Mostrar el array ordenado
    cout << "Array después de ordenar con pivotes:\n";
    for (int* p = arr; p < arr + n; ++p) {
        cout << *p << " ";
    }
    cout << endl;

    // Liberar la memoria del array
    delete[] arr;

    return 0;
}
