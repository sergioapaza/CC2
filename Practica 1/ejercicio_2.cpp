#include <iostream>
#include <string>

using namespace std;

string convertirMenorQueMil(int n) {
    string unidades[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    string decenas[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    string especiales[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
    string centenas[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

    if (n == 0) {
        return "cero";
    } else if (n == 100) {
        return "cien";
    }

    int c = n / 100;
    int d = (n % 100) / 10;
    int u = n % 10;

    string resultado = "";
    if (c > 0) {
        resultado += centenas[c] + " ";
    }

    if (d == 1) {
        resultado += especiales[u];
    } else {
        if (d > 0) {
            if (d == 2 && u > 0) {  // Manejo de casos como "veintiuno"
                resultado += "veinti" + unidades[u];
            } else {
                resultado += decenas[d] + (u > 0 ? " y " : "");
            }
        }
        if (d != 2 && u > 0) {  // No agregar unidad en "veintiuno", "veintidós", etc.
            resultado += unidades[u];
        }
    }

    return resultado;
}

string convertirAPalabras(int numero) {
    if (numero < 0 || numero > 999999) {
        return "Numero fuera de rango";
    }

    int miles = numero / 1000;
    int resto = numero % 1000;

    string resultado = "";
    if (miles > 0) {
        if (miles == 1) {
            resultado += "mil ";
        } else if (miles == 21) {
            resultado += "veintiun mil ";
        } else if (miles % 10 == 1 && miles != 11) {  // Para manejar casos como "51 mil", "101 mil", etc.
            resultado += convertirMenorQueMil(miles).substr(0, convertirMenorQueMil(miles).size() - 3) + "un mil ";
        } else {
            resultado += convertirMenorQueMil(miles) + " mil ";
        }
    }

    if (resto > 0) {
        resultado += convertirMenorQueMil(resto);
    }

    return resultado;
}

int main() {
    int numero;
    cout << "Ingresa un numero entre 0 y 999999: ";
    cin >> numero;

    cout << convertirAPalabras(numero) << endl;

    return 0;
}
