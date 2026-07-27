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
//  Las tres piezas que pide la practica:
//    ARREGLO -> las materias aprobadas del estudiante
//    CADENA  -> los nombres de materia y de estudiante
//    MATRIZ  -> el plan de estudios (3 x 3)
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
//           bool   aprobado;   // true = aprobada
//         No olvides el punto y coma final:  };

// PASO 3: struct Estudiante, con estos campos:
//           string  nombre;
//           string  matricula;
//           Materia aprobadas[MAX];   // el ARREGLO de materias
//           int     cuantas;          // cuantas lleva guardadas

// ---------- LAS TRES FUNCIONES (indicaciones 2 y 3) ----------

// PASO 4: void ingresar_materias(Estudiante &e)
//   Pregunta cuantas materias aprobo (de 0 a MAX) y, con un ciclo for,
//   llena e.aprobadas[i] con nombre, creditos y estado.
//   Guarda el total en e.cuantas.
//   El & sirve para que la funcion llene el arreglo de verdad.
//   Para leer nombres con espacios: cin.ignore(); getline(cin, ...);

// PASO 5: int sumar_creditos(Estudiante e)
//   Recorre el arreglo con un for y SUMA los creditos de las
//   materias aprobadas. Devuelve el total con return.

// PASO 6: int contar_materias(Estudiante e)
//   Recorre el arreglo y devuelve CUANTAS materias tiene
//   registradas el estudiante.

// ---------- EL PROGRAMA PRINCIPAL ----------

int main() {

    // PASO 7: declara el plan y su MATRIZ de seriacion.
    //         string plan[PLAN] = {"Algebra", "Calculo I", "Estadistica"};
    //         int seriacion[PLAN][PLAN] = { ... };
    //         Renglon = materia; columna = la que DEPENDE de ella.
    //         Pon 1 donde hay seriacion y 0 donde no.

    // PASO 8: declara un Estudiante, pide su nombre y su
    //         matricula, llama a ingresar_materias(...) y muestra
    //         el reporte usando contar_materias y sumar_creditos.

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
