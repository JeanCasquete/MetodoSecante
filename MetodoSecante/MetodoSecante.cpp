// MetodoSecante.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>  // Incluye la biblioteca de entrada/salida estándar de C++
#include <iomanip>   // Incluye la biblioteca de manipulación de flujo de C++
#include <cmath>     // Incluye la biblioteca matemática de C++

using namespace std; // Indica que se utilizarán los elementos del espacio de nombres "std"

// Define la función que queremos encontrar su raíz
double f(double x) {
    return pow(x, 5) + x - 3;
}

// Define la función que implementa el método de la secante para encontrar la raíz
double secante(double x0, double x1, int n_max, double tol) {
    double fx0 = f(x0); // Evalúa f(x) en x0
    double fx1 = f(x1); // Evalúa f(x) en x1
    double x2;          // Variable para almacenar la nueva aproximación a la raíz

    // Muestra una cabecera para la tabla de resultados de la secante
    cout << setw(3) << "n" << setw(12) << "x_{n-1}" << setw(12) << "x_n" << setw(12) << "x_{n+1}" << setw(12) << "f(x_n)" << endl;

    // Itera hasta alcanzar el número máximo de iteraciones
    for (int i = 0; i < n_max; i++) {
        // Actualiza la aproximación a la raíz usando el método de la secante
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);

        // Muestra la información relevante de la iteración actual
        cout << setw(3) << i << setw(12) << x0 << setw(12) << x1 << setw(12) << x2 << setw(12) << f(x1) << endl;

        // Si la aproximación es suficientemente buena, devuelve el resultado
        if (abs(x2 - x1) < tol) {
            return x2;
        }

        // Actualiza los valores para la siguiente iteración
        x0 = x1;
        fx0 = fx1;
        x1 = x2;
        fx1 = f(x1);
    }

    // Si no se encontró una buena aproximación después de n_max iteraciones, muestra un mensaje de error y devuelve 0
    cout << "No se encontró una buena aproximación después de " << n_max << " iteraciones." << endl;
    return 0.0;
}

int main() {
    double x0 = 0.0;     // Valor inicial
    double x1 = 1.0;     // Otro valor inicial
    int n_max = 100;     // Número máximo de iteraciones permitidas
    double tol = 0.01;   // Tolerancia para la aproximación

    // Llama a la función "secante" para encontrar la raíz de la función "f"
    double raiz = secante(x0, x1, n_max, tol);

    // Muestra el resultado de la aproximación de la raíz
    cout << "La raíz de la función es " << raiz << endl;

    return 0;   // Termina el programa
}
