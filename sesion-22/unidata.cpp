// =============================================================
//  PRACTICA 6 · Tipos de datos estructurados
//  "UniData" · creditos aprobados y materias seriadas
//  Fundamentos de Programacion · UNITEC · Ciclo 26-3
// =============================================================
//  Este archivo es un PLANO: trae los pasos comentados.
//  Escribe TU el codigo debajo de cada PASO. No borres los
//  pasos: al final quedaran como los comentarios que
//  documentan tu programa.
//
//  Meta: la Universidad "UniData" necesita saber cuantos
//  creditos lleva aprobados un estudiante, y que materias
//  se abren al aprobar cada una (materias seriadas).
//
//  Las cuatro piezas que combina la practica:
//    ESTRUCTURA -> los tres datos de una materia, juntos
//    ARREGLO    -> las materias aprobadas del estudiante
//    CADENA     -> los nombres de materia y de estudiante
//    MATRIZ     -> el plan de estudios (3 x 3), doble for
//
//  IDEA CLAVE: un ARREGLO guarda muchos datos del MISMO tipo;
//  una ESTRUCTURA guarda pocos datos de DISTINTO tipo. Al
//  combinarlos sale un ARREGLO DE ESTRUCTURAS: una fila de
//  casilleros donde cada casillero es un registro completo.
//
//      aprobadas[0]         aprobadas[1]         aprobadas[2]
//    +---------------+   +---------------+   +---------------+
//    | nombre "Alg." |   | nombre "Cal." |   | nombre "Est." |
//    | creditos   8  |   | creditos  10  |   | creditos   6  |
//    | aprobada true |   | aprobada true |   | aprobada  fls |
//    +---------------+   +---------------+   +---------------+
// =============================================================

// PASO 1: incluye las librerias
//         #include <iostream>
//         #include <string>

using namespace std;

const int MAX = 3;    // cuantas materias caben en el arreglo
const int PLAN = 3;   // cuantas materias tiene el plan

// ---------- LAS DOS ESTRUCTURAS (indicacion 1) ----------

// PASO 2: struct Materia, con TRES campos:
//           string nombre;     // cadena
//           int    creditos;
//           bool   aprobada;   // true = aprobada
//         No olvides el punto y coma final:  };

// PASO 3: struct Estudiante, con estos campos:
//           string  nombre;
//           string  matricula;
//           Materia aprobadas[MAX];   // el ARREGLO de estructuras
//           int     cuantas;          // cuantas lleva guardadas

// ---------- LAS TRES FUNCIONES (indicaciones 2 y 3) ----------

// PASO 4: void ingresar_materias(Materia lista[], int cuantas)
//   Con un ciclo for de 0 a cuantas-1, pide en cada vuelta el
//   nombre, los creditos y el estado, y guardalos en los campos
//   de lista[i]:  lista[i].nombre, lista[i].creditos, ...
//   No lleva &: en C++ un arreglo ya viaja por referencia, asi
//   que lo que escribas aqui se queda guardado de verdad.
//   Para leer nombres con espacios: cin.ignore(); getline(cin, ...);

// PASO 5: int sumar_creditos(Materia lista[], int cuantas)
//   Recorre el arreglo con un for y SUMA lista[i].creditos
//   cuando lista[i].aprobada sea true. Devuelve el total.

// PASO 6: int contar_materias(Materia lista[], int cuantas)
//   Recorre el arreglo y devuelve CUANTAS materias estan
//   aprobadas (suma 1 cada vez que lista[i].aprobada es true).

// ---------- EL PROGRAMA PRINCIPAL ----------

int main() {

    // PASO 7: declara el plan y su MATRIZ de seriacion.
    //         string plan[PLAN] = {"Algebra", "Calculo I", "Estadistica"};
    //         int seriacion[PLAN][PLAN] = { ... };
    //         Renglon = materia; columna = la que DEPENDE de ella.
    //         Pon 1 donde hay seriacion y 0 donde no.

    // PASO 8: declara un Estudiante, pide su nombre, su matricula
    //         y cuantas materias va a registrar (de 0 a MAX).
    //         Llama a ingresar_materias(alumno.aprobadas, alumno.cuantas)
    //         y muestra el reporte usando contar_materias y
    //         sumar_creditos.

    // PASO 9: recorre la MATRIZ con dos ciclos for ANIDADOS
    //         (exterior = renglon, interior = columna) y muestra
    //         que materias abre cada una. Esta es la "operacion
    //         dentro de la matriz" que se evalua.

    return 0;
}

/* CONCLUSIONES:
   1) ¿Por que es importante utilizar arreglos?
   2) ¿Para que sirven las cadenas y las matrices?
   Escribe aqui una redaccion breve con tus observaciones sobre
   los resultados y lo aprendido al concluir la practica. */
