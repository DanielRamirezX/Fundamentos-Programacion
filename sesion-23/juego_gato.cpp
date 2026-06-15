// =====================================================================
//  EL TABLERO DEL MUNDO  ·  Juego del gato (tres en raya) para 2
//  Fundamentos de Programacion · UNITEC Atizapan · Ciclo 26-3
//  Profesor: Carlos Daniel Vaca Ramirez
// ---------------------------------------------------------------------
//  Un tablero es una MATRIZ 3x3. La fila es la primera dimension y la
//  columna la segunda: tablero[fila][columna]. Lo recorremos con DOS
//  ciclos for anidados (uno por dimension).
//
//  Desde la sesion 09 el lenguaje PRINCIPAL es C++; Python queda como
//  puente (ver juego_gato.py, la misma practica en el otro lenguaje).
//
//  Lo que YA esta hecho:  crear_tablero(), mostrar_tablero()
//  Lo que TE toca a ti:   pedir_jugada(), validar_celda(), hay_ganador()
//
//  Reglas de la casa: sangria de 4 espacios, nombres claros en espanol,
//  comenta lo que hagas con //. Compila y corre el programa despues de
//  cada PASO para asegurarte de que no truena antes de seguir.
//      g++ juego_gato.cpp -o juego_gato   &&   ./juego_gato
// =====================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int FILAS = 3;          // alto del tablero (constante: no se toca)
const int COLUMNAS = 3;       // ancho del tablero
const string VACIA = " ";     // como se ve una celda libre

// Un tablero es una matriz (vector de vectores) de cadenas
typedef vector<vector<string>> Tablero;


// Devuelve una matriz 3x3 llena de celdas vacias. (YA HECHO)
Tablero crear_tablero() {
    Tablero tablero;
    for (int fila = 0; fila < FILAS; fila++) {
        vector<string> renglon;
        for (int columna = 0; columna < COLUMNAS; columna++) {
            renglon.push_back(VACIA);   // cada celda empieza vacia
        }
        tablero.push_back(renglon);
    }
    return tablero;
}


// Dibuja el tablero con sus lineas. Recorre fila por fila. (YA HECHO)
void mostrar_tablero(Tablero& tablero) {
    cout << endl;
    cout << "     0   1   2" << endl;     // numeros de columna (guia para el jugador)
    cout << "   +---+---+---+" << endl;
    for (int fila = 0; fila < FILAS; fila++) {
        // arma el renglon: una celda tras otra, separadas por |
        string texto = " " + to_string(fila) + " |";
        for (int columna = 0; columna < COLUMNAS; columna++) {
            texto += " " + tablero[fila][columna] + " |";
        }
        cout << texto << endl;
        cout << "   +---+---+---+" << endl;
    }
    cout << endl;
}


// ---------------------------------------------------------------------
//  PASO 1: validar_celda(tablero, fila, columna)
//  Devuelve true solo si la jugada es legal:
//    - la fila esta entre 0 y 2  (usa 0 <= fila && fila < FILAS)
//    - la columna esta entre 0 y 2
//    - esa celda esta VACIA (tablero[fila][columna] == VACIA)
//  Si algo falla, devuelve false.
// ---------------------------------------------------------------------
bool validar_celda(Tablero& tablero, int fila, int columna) {
    // TODO: escribe aqui las tres comprobaciones y el return
    return false;   // <- cambia esto cuando resuelvas el PASO
}


// ---------------------------------------------------------------------
//  PASO 2: pedir_jugada(tablero, simbolo)
//  Pregunta al jugador (cuyo simbolo es "X" u "O") la fila y la columna.
//  Repite con un while hasta que validar_celda(...) devuelva true.
//  Cuando la jugada sea valida, ESCRIBE el simbolo en el tablero:
//       tablero[fila][columna] = simbolo
//  Pista: cin >> fila >> columna; para leer los dos numeros.
//  Cuida los datos que no son numeros (revisa cin.fail() y limpia
//  con cin.clear() y cin.ignore(10000, '\n') si quieres endurecerlo).
// ---------------------------------------------------------------------
void pedir_jugada(Tablero& tablero, string simbolo) {
    // TODO: pide fila y columna en un bucle hasta que la celda sea valida,
    //       luego marca el simbolo en el tablero
}


// ---------------------------------------------------------------------
//  PASO 3: hay_ganador(tablero, simbolo)
//  Devuelve true si ese simbolo formo una linea de 3. Revisa:
//    a) las 3 FILAS      -> recorre cada fila con un for y un contador
//    b) las 3 COLUMNAS   -> recorre cada columna (for de columnas, for de filas)
//    c) las 2 DIAGONALES -> [0][0],[1][1],[2][2]  y  [0][2],[1][1],[2][0]
//  Idea con doble for: por cada fila cuenta cuantas celdas son del simbolo;
//  si el contador llega a COLUMNAS, esa fila esta completa -> return true.
// ---------------------------------------------------------------------
bool hay_ganador(Tablero& tablero, string simbolo) {
    // TODO: revisa filas, columnas y las dos diagonales; devuelve true/false
    return false;   // <- cambia esto cuando resuelvas el PASO
}


// ---------------------------------------------------------------------
//  EL BUCLE PRINCIPAL  (YA HECHO: usa tus funciones de arriba)
//  Alterna entre el jugador X y el jugador O hasta que alguien gane
//  o se llenen las 9 celdas. No lo modifiques hasta terminar los PASOS.
// ---------------------------------------------------------------------
void jugar() {
    Tablero tablero = crear_tablero();
    string jugadores[2] = {"X", "O"};   // X siempre empieza
    int turno = 0;                       // cuenta cuantas jugadas van (max 9)

    cout << string(34, '=') << endl;
    cout << "        EL TABLERO DEL MUNDO" << endl;
    cout << "     Juego del gato - 2 jugadores" << endl;
    cout << string(34, '=') << endl;

    while (turno < FILAS * COLUMNAS) {          // como mucho 9 jugadas
        string simbolo = jugadores[turno % 2];  // 0->X, 1->O, 2->X, ...
        mostrar_tablero(tablero);
        cout << "Turno de " << simbolo << endl;

        pedir_jugada(tablero, simbolo);         // <- tu PASO 2

        if (hay_ganador(tablero, simbolo)) {    // <- tu PASO 3
            mostrar_tablero(tablero);
            cout << "Gano " << simbolo << "! Tres en raya." << endl;
            return;
        }

        turno++;
    }

    // si salimos del while sin ganador, el tablero se lleno
    mostrar_tablero(tablero);
    cout << "Empate. El tablero esta lleno y nadie hizo una linea." << endl;
}


// arranca el juego cuando ejecutas el archivo
int main() {
    jugar();
    return 0;
}


// =====================================================================
//  EJEMPLO DE PARTIDA (asi se vera tu juego cuando completes los PASOS)
// ---------------------------------------------------------------------
//       0   1   2
//    +---+---+---+
//  0 | X | O |   |
//    +---+---+---+
//  1 |   | X | O |
//    +---+---+---+
//  2 |   |   | X |
//    +---+---+---+
//
//  Turno de X
//  Fila (0-2): 2
//  Columna (0-2): 2
//  Gano X! Tres en raya.   <- diagonal [0][0] [1][1] [2][2]
// =====================================================================

// =====================================================================
//  RETOS EXTRA (suman puntos de actividad)
//    1. EMPATE elegante: ya se detecta cuando se llenan las 9 celdas,
//       pero anuncia el empate con un mensaje propio y con estilo.
//    2. NOMBRES de jugadores: pide el nombre de cada quien al inicio
//       (getline(cin, nombre)) y usalo en los mensajes ("Turno de Ana (X)").
//    3. MARCAR la linea ganadora: cuando hay_ganador sea true, devuelve
//       tambien las tres coordenadas y reimprimelas en MAYUSCULA o con
//       color ANSI (recuerda la sesion 07) para resaltar la victoria.
//    4. REVANCHA: al terminar, pregunta "Otra partida? (s/n)" y reinicia
//       el tablero envolviendo jugar() en un while.
// =====================================================================
