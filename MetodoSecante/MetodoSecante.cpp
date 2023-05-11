// MetodoSecante.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    // Esta es la función que queremos encontrar su raíz
    return pow(x, 5) + x - 3;
}

double secante(double x0, double x1, int n_max, double tol) {
    double fx0 = f(x0);
    double fx1 = f(x1);
    double x2;

    cout << setw(3) << "n" << setw(12) << "x_{n-1}" << setw(12) << "x_n" << setw(12) << "x_{n+1}" << setw(12) << "f(x_n)" << endl;

    for (int i = 0; i < n_max; i++) {
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);

        cout << setw(3) << i << setw(12) << x0 << setw(12) << x1 << setw(12) << x2 << setw(12) << f(x1) << endl;

        if (abs(x2 - x1) < tol) {
            // La aproximación es suficientemente buena
            return x2;
        }

        // Actualizamos los valores para la siguiente iteración
        x0 = x1;
        fx0 = fx1;
        x1 = x2;
        fx1 = f(x1);
    }

    // No se encontró una buena aproximación después de n_max iteraciones
    cout << "No se encontró una buena aproximación después de " << n_max << " iteraciones." << endl;
    return 0.0;
}

int main() {
    double x0 = 0.0; // Valor inicial
    double x1 = 1.0; // Otro valor inicial
    int n_max = 100; // Número máximo de iteraciones permitidas
    double tol = 0.01; // Tolerancia para la aproximación

    double raiz = secante(x0, x1, n_max, tol);

    cout << "La raíz de la función es " << raiz << endl;

    return 0;
}
