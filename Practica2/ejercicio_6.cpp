#include <iostream>
#include <cstring>
//#include <cctype> 
using namespace std;

bool esPalindromo(char *p) {
    int len = strlen(p); // Obtener la longitud de la cadena
    char *q = p + len - 1; // Asignar a q la última posición válida

    while (p < q) {
        while (*p == ' ') {
            p++;
        }
        while (*q == ' ') {
            q--;
        }

        if (tolower(*p) != tolower(*q)) {
            return false; 
        }
        p++;
        q--; 
    }
    return true; 
}

int main() {
    char cadena[] = "Anita        lava la tina"; 
    if (esPalindromo(cadena)) {
        cout << "La cadena es un palindromo." << endl;
    } else {
        cout << "La cadena no es un palindromo." << endl;
    }
    return 0;
}