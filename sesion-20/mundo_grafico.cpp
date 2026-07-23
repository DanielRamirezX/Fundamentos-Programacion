// =============================================================
//  PRACTICA 5 · Diseno modular, funciones y aplicaciones graficas
//  "Mundo-grafico" · aplicacion modular de figuras geometricas
//  Fundamentos de Programacion · UNITEC Atizapan · Ciclo 26-3
// =============================================================
//  Este archivo es un PLANO: trae los pasos y las firmas de las
//  funciones comentadas. Escribe TU el cuerpo de cada funcion.
//  No borres los pasos: al final quedaran como los comentarios
//  que documentan tu programa.
//
//  Meta: dibujar figuras (circulo, rectangulo, linea) con
//  funciones modulares y luego moverlas / cambiarlas de tamano.
//  Software oficial: Dev C++ con la libreria graphics.h (WinBGIm).
//
//  Recuerda los tres modulos que acordamos en clase:
//    - MODULO DE FIGURAS   -> crea y dibuja las figuras
//    - OPERACIONES         -> mueve y cambia el tamano
//    - MODULO PRINCIPAL    -> main(): coordina e interactua
// =============================================================

// PASO 1: incluye las librerias
//         #include <graphics.h>   // dibujo: circle, rectangle, line, setcolor
//         #include <iostream>

using namespace std;

// ---------- MODULO DE FIGURAS (funciones con VARIOS parametros) ----------

// PASO 2: void dibujar_circulo(int x, int y, int radio, int color)
//   Funcion con VARIOS parametros. En el cuerpo:
//     setcolor(color);        // color del trazo
//     circle(x, y, radio);    // dibuja el circulo
//   No devuelve nada -> por eso es void.

// PASO 3: void dibujar_rectangulo(int x, int y, int ancho, int alto, int color)
//   setcolor(color);
//   rectangle(x, y, x + ancho, y + alto);

// PASO 4: void dibujar_linea(int x1, int y1, int x2, int y2, int color)
//   setcolor(color);
//   line(x1, y1, x2, y2);

// ---------- OPERACIONES (DEVOLUCION del resultado con return) ----------

// PASO 5: int mover_derecha(int x, int paso)
//   Funcion que RECIBE la posicion y el paso, y DEVUELVE la nueva
//   posicion:  return x + paso;

// PASO 6: int cambiar_tamano(int radio, int cuanto)
//   Devuelve el nuevo radio:  return radio + cuanto;

// ---------- MODULO PRINCIPAL (coordina las piezas) ----------

int main() {

    // PASO 7: abre la ventana grafica
    //         initwindow(600, 400, "Mundo-grafico");

    // PASO 8: dibuja UNA escena llamando a TUS funciones del modulo
    //         de figuras (elige posiciones, tamanos y colores):
    //         dibujar_circulo(...);  dibujar_rectangulo(...);  dibujar_linea(...);

    // PASO 9: ANIMACION BASICA. Un ciclo (por ejemplo 60 vueltas) que:
    //         1) borra la pantalla        -> cleardevice();
    //         2) dibuja el circulo en x   -> dibujar_circulo(x, y, radio, color);
    //         3) espera un momento        -> delay(30);
    //         4) mueve la figura          -> x = mover_derecha(x, 5);

    // PASO 10: espera una tecla y cierra la ventana
    //          getch();  closegraph();

    return 0;
}

/* CONCLUSIONES:
   ¿Para que sirve el diseno modular en la programacion?
   Escribe aqui una redaccion breve con tus observaciones sobre
   los resultados y los conocimientos adquiridos al concluir la
   practica. */
