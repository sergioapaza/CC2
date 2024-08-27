#include <iostream>

using namespace std;

void calcular_billetes_monedas(double cantidad) {

    int billetes[5] = {200, 100, 50, 20, 10};
    double monedas[6] = {5.0, 2.0, 1.0, 0.5, 0.2, 0.1};

    int cantidad_billetes[5] = {0}; // contador billetes
    int cantidad_monedas[6] = {0}; // contador monedas

    for (int i = 0; i < 5; ++i) { // billetes
        cantidad_billetes[i] = cantidad / billetes[i];
        cantidad -= cantidad_billetes[i] * billetes[i];
    }

    for (int i = 0; i < 6; ++i) { //monedas
        cantidad_monedas[i] = cantidad / monedas[i];
        cantidad -= cantidad_monedas[i] * monedas[i];
    }

    cout << "Billetes:" << endl;
    for (int i = 0; i < 5; ++i) { // mostar billetes
        if (cantidad_billetes[i] > 0) {
            cout << "S/" << billetes[i] << ": " << cantidad_billetes[i] << endl;
        }
    }

    cout << "Monedas:" << endl;
    for (int i = 0; i < 6; ++i) { // mostar monedas
        if (cantidad_monedas[i] > 0) {
            cout << "S/" << monedas[i] << ": " << cantidad_monedas[i] << endl;
        }
    }
}

int main() {
    double cantidad;
    cout << "Ingrese una cantidad: ";
    cin >> cantidad;

    if (cantidad < 0) {
        cout << "La cantidad no puede ser negativa." << endl;
    } else {
        calcular_billetes_monedas(cantidad);
    }

    return 0;
}
