// =============================================================
//  PRÁCTICA 5 · Diseño modular, funciones y aplicaciones gráficas
//  "Mundo-gráfico" · SOLUCIÓN DOCENTE (clave de referencia)
//  Fundamentos de Programación · UNITEC Atizapán · Ciclo 26-3
// -------------------------------------------------------------
//  ⚠ USO INTERNO DEL PROFESOR — NO DISTRIBUIR A LOS ALUMNOS.
//     Es la versión RESUELTA del plano mundo_grafico.cpp.
//
//  Compilar en Dev C++ con la librería graphics.h (WinBGIm).
//  Si hace falta, agrega en el linker (Project Options → Parameters):
//     -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
// =============================================================
#include <graphics.h>
#include <iostream>
using namespace std;

// ============ MÓDULO DE OPERACIONES CON FIGURAS ============
// Crear / dibujar: funciones con VARIOS parámetros (posición,
// tamaño y color). No devuelven valor -> void.

void dibujar_circulo(int x, int y, int radio, int color) {
    setcolor(color);
    circle(x, y, radio);
}

void dibujar_rectangulo(int x, int y, int ancho, int alto, int color) {
    setcolor(color);
    rectangle(x, y, x + ancho, y + alto);   // esquinas: sup-izq / inf-der
}

void dibujar_linea(int x1, int y1, int x2, int y2, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
}

// Operaciones que DEVUELVEN el resultado (return): la lógica de
// negocio, separada del dibujo (interfaz).

int mover_derecha(int x, int paso) {
    return x + paso;                         // nueva posición en X
}

int cambiar_tamano(int radio, int cuanto) {
    int nuevo = radio + cuanto;
    if (nuevo < 5) nuevo = 5;                // nunca menor que 5 px
    return nuevo;
}

// ================== MÓDULO DE INTERFAZ ====================
// Compone la escena llamando al módulo de figuras. El rectángulo
// y la línea quedan fijos; el círculo es el que se mueve y crece.

void dibujar_escena(int x_circulo, int radio_circulo) {
    dibujar_rectangulo(260, 140, 200, 120, RED);
    dibujar_linea(80, 340, 520, 340, YELLOW);
    dibujar_circulo(x_circulo, 200, radio_circulo, GREEN);
}

// ================== MÓDULO PRINCIPAL ======================
// main() no dibuja ni calcula por su cuenta: COORDINA las piezas.

int main() {
    initwindow(600, 400, "Mundo-grafico");   // abre el lienzo

    int x = 90;        // posición inicial del círculo
    int radio = 40;    // tamaño inicial del círculo

    // 1) Escena estática inicial
    dibujar_escena(x, radio);
    delay(1200);

    // 2) Animación básica: mover y agrandar el círculo.
    //    Cada vuelta del for es un "cuadro": borrar, redibujar,
    //    esperar y actualizar los datos con las operaciones.
    for (int i = 0; i < 70; i++) {
        cleardevice();                       // borra el cuadro anterior
        dibujar_escena(x, radio);            // redibuja la escena
        delay(30);                           // ~30 ms por cuadro
        x = mover_derecha(x, 5);             // operación: mover
        if (i % 20 == 0)                     // cada 20 cuadros...
            radio = cambiar_tamano(radio, 8); // ...operación: agrandar
    }

    getch();          // espera una tecla
    closegraph();     // cierra la ventana
    return 0;
}

/* =============================================================
   CONCLUSIONES — ¿Para qué sirve el diseño modular?

   El diseño modular sirve para partir un problema grande en
   funciones pequeñas, cada una con una sola responsabilidad. En
   esta práctica, dibujar cada figura, mover y cambiar de tamaño
   son funciones independientes; main() sólo las coordina. Esto
   hace el programa más LEGIBLE (se lee como frases), REUTILIZABLE
   (una función se usa muchas veces con distintos parámetros) y
   fácil de MANTENER (se cambia una pieza sin romper las demás).
   Además separa la LÓGICA (operaciones que devuelven resultados
   con return) de la INTERFAZ (funciones que sólo dibujan), que es
   la base de una aplicación gráfica ordenada.
   ============================================================= */
