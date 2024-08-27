#include <iostream>
using namespace std;

string unidades[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
string decenas_diez[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve"};
string decenas_veinte[] = {"", "", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
string centenas[] = {"", "cien", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

string numero_letras(int numero) {
    if (numero == 0) return "cero";
    
    string result = "";

    if (numero >= 1000) { // mil
        if (numero / 1000 > 1) {
            result += unidades[numero / 1000] + " mil ";
        } else {
            result += "mil ";
        }
        numero %= 1000;
    }

    if (numero >= 100) { // centena
        if (numero == 100) {
            result += "cien ";
        } else if (numero < 200) { //Caso 101 a 199
            result += "ciento ";
            numero %= 100;
        } else {
            result += centenas[numero / 100] + " ";
            numero %= 100;
        }
    }

    if (numero >= 20) { // decena
        result += decenas_veinte[numero / 10];
        numero %= 10;
        if (numero > 0) {
            result += " y ";
            result += unidades[numero];
        }
    } else if (numero >= 10) {
        result += decenas_diez[numero - 10];
    } else if (numero > 0) { // unidad
        result += unidades[numero];
    }

    return result;
}

int main() {
    int a;
    cout << "Ingrese un numero entre 0 y 9999: ";
    cin >> a;

    if (a < 0 || a > 9999) {
        cout << "Numero fuera de rango." << endl;
    } else {
        cout << "El numero: " << a << endl;
        cout << "La escritura: " << numero_letras(a) << endl;
    }

    return 0;
}
