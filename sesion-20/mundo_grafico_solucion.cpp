// =============================================================
//  PRÁCTICA 5 · SOLUCIÓN DOCENTE
//  "Mundo-gráfico" · figuras impresas en consola
//  Uso interno del profesor. No se enlaza desde la página.
// =============================================================
#include <iostream>
using namespace std;

// RESPONSABILIDAD 1: mostrar el encabezado del programa.
void mostrar_titulo() {
    cout << "--- Mundo-grafico ---" << endl;
}

// RESPONSABILIDAD 2: imprimir una figura sencilla.
// Recibe varios parametros y no devuelve un valor (void).
void dibujar_linea(int largo, char simbolo) {
    for (int i = 0; i < largo; i++) {
        cout << simbolo;
    }
    cout << endl;
}

// RESPONSABILIDAD 3: imprimir el cuadrado.
// El for exterior controla las filas y el interior las columnas.
void dibujar_cuadrado(int lado, char simbolo) {
    for (int fila = 0; fila < lado; fila++) {
        for (int columna = 0; columna < lado; columna++) {
            cout << simbolo << " ";
        }
        cout << endl;
    }
}

// RESPONSABILIDAD 4: calcular y devolver un resultado.
int area_cuadrado(int lado) {
    return lado * lado;
}

// RESPONSABILIDAD 5: coordinar el dibujo y el calculo del reporte.
void mostrar_reporte(int lado) {
    cout << endl << "Cuadrado:" << endl;
    dibujar_cuadrado(lado, '*');
    cout << "Area: " << area_cuadrado(lado) << endl;
}

int main() {
    int lado = 0;

    // main solo pide los datos y coordina las funciones.
    mostrar_titulo();
    cout << "Escribe el lado del cuadrado: ";
    cin >> lado;
    mostrar_reporte(lado);
    dibujar_linea(20, '-');
    return 0;
}

/* CONCLUSIÓN:
   El diseño modular divide un programa en funciones pequeñas.
   Así, dibujar, calcular y mostrar tienen tareas separadas.
   El código es más fácil de leer, corregir y reutilizar. */
