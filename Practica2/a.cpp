#include <iostream>
#include <string>

using namespace std;

string convertirMenorQueMil(int n) {
    string unidades[] = { "", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };
    string decenas[] = { "", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
    string especiales[] = { "diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve" };
    string centenas[] = { "", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos" };

    if (n == 0) {
        return "cero";
    }
    else if (n == 100) {
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
    }
    else {
        if (d > 0) {
            if (d == 2 && u > 0) {
                resultado += "veinti" + unidades[u];  // Manejo de casos como "veintiuno"
            }
            else {
                resultado += decenas[d] + (u > 0 ? " y " : "");
            }
        }
        if (d != 2 && u > 0) {
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
        string milesTexto = convertirMenorQueMil(miles);

        if (miles == 1) {
            resultado += "mil ";
        }
        else if (miles % 100 == 1) {  // Caso especial para cualquier número que termine en "101" o "111"
            milesTexto = milesTexto.substr(0, milesTexto.size() - 3) + "un";  // Reemplaza "uno" por "un"
            resultado += milesTexto + " mil ";
        }
        else {
            resultado += milesTexto + " mil ";
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
