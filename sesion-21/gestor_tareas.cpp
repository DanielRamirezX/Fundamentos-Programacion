// =============================================================
//  GESTOR DE TAREAS PENDIENTES  ·  plano para construir
//  Fundamentos de Programacion · UNITEC Atizapan · Ciclo 26-3
//  Profesor: Carlos Daniel Vaca Ramirez
// -------------------------------------------------------------
//  Sesion 21 · Buscar y ordenar (listas avanzadas)
//
//  COMO USAR ESTE ARCHIVO
//  ----------------------
//  Este NO es un programa terminado: es un plano. Cada paso
//  empieza con "// PASO N" y debajo hay un espacio en blanco
//  donde TU escribes tu propio codigo. No borres los comentarios.
//  Sigue el orden y compila despues de cada paso para asegurarte
//  de que no truena antes de continuar:
//      g++ gestor_tareas.cpp -o gestor   &&   ./gestor
//
//  La meta: un gestor de tareas en consola con un menu de 5
//  opciones, hecho con UN vector y las herramientas que vimos
//  hoy (push_back, find, erase, count, sort). En C++ el "arreglo
//  que crece" es vector<string>; la BUSQUEDA se hace con find()
//  de <algorithm> (el equivalente de index()/in de Python).
//  Por ahora, cada tarea es una simple CADENA de texto (string).
// =============================================================

#include <iostream>   // cout, cin
#include <vector>     // vector<string>: la lista que crece
#include <string>     // string, getline
#include <algorithm>  // find, count (busqueda y conteo)
using namespace std;


// PASO 1: Crea el vector que guardara tus tareas.
//   Empieza vacio. Sugerencia de nombre: vector<string> tareas;
//   (es la unica "memoria" del programa: todo vive aqui dentro).
//   Declaralo DENTRO de main(), antes del ciclo del PASO 7.

//   ← aqui escribes tu codigo (dentro de main)


// PASO 2: Define una funcion mostrar_menu() que imprima
//   las 5 opciones del gestor. Algo como:
//     ===== GESTOR DE TAREAS =====
//       1) Agregar tarea
//       2) Mostrar tareas
//       3) Completar tarea
//       4) Eliminar tarea
//       5) Salir
void mostrar_menu() {
    // ← aqui escribes tu codigo
}


// PASO 3: Define agregar_tarea(tareas).
//   Pide al usuario el texto de la tarea con getline(cin, ...)
//   y agregala al FINAL del vector con tareas.push_back(...).
//   Avisa que se guardo correctamente.
//   Pista: recibe el vector por REFERENCIA -> vector<string>& tareas
//   para que los cambios se queden en la lista original.
void agregar_tarea(vector<string>& tareas) {
    // ← aqui escribes tu codigo
}


// PASO 4: Define mostrar_tareas(tareas).
//   Si el vector esta vacio (tareas.empty()), avisa que no
//   hay pendientes. Si no, recorrelo con un for normal para
//   imprimir cada tarea con su numero (empezando en 1):
//     for (int i = 0; i < (int)tareas.size(); i++)
//         cout << (i + 1) << ". " << tareas[i] << endl;
//   Aqui basta con leer, asi que puedes recibirlo por
//   referencia const: const vector<string>& tareas.
void mostrar_tareas(const vector<string>& tareas) {
    // ← aqui escribes tu codigo
}


// PASO 5: Define completar_tarea(tareas).
//   Muestra las tareas, pide el texto EXACTO de la que se
//   completo y usa la BUSQUEDA con find() para encontrar su
//   posicion. Quitala con erase().
//   En C++, find() devuelve un ITERADOR: apunta al elemento si
//   existe, o a tareas.end() si NO esta. Protege la busqueda:
//       auto it = find(tareas.begin(), tareas.end(), texto);
//       if (it != tareas.end()) { tareas.erase(it); ... }
//       else { /* avisa que no se encontro */ }
void completar_tarea(vector<string>& tareas) {
    // ← aqui escribes tu codigo
}


// PASO 6: Define eliminar_tarea(tareas).
//   Parecida a la anterior, pero aqui simplemente se descarta.
//   Vuelve a usar find() para localizarla y erase() para
//   quitarla; si no esta (it == tareas.end()), avisa que no
//   se encontro. Un buen gestor valida ANTES de borrar.
void eliminar_tarea(vector<string>& tareas) {
    // ← aqui escribes tu codigo
}


// PASO 7: EL CICLO PRINCIPAL.
//   Dentro de un while (true):
//     - llama a mostrar_menu()
//     - pide la opcion con getline(cin, opcion)  (opcion es string)
//     - segun la opcion ("1".."5") llama a la funcion que toca
//     - con "5" despidete e interrumpe el ciclo con break
//     - con cualquier otra cosa, avisa "Opcion no valida"
//   Pista: usar string para la opcion (y getline) evita los
//   problemas de mezclar cin >> con getline al leer las tareas.
int main() {
    // ← aqui escribes tu codigo (el vector del PASO 1 + el while)

    return 0;
}


// =============================================================
//  EJEMPLO DE CORRIDA (asi se debe ver tu gestor terminado)
// -------------------------------------------------------------
//  ===== GESTOR DE TAREAS =====
//    1) Agregar tarea
//    2) Mostrar tareas
//    3) Completar tarea
//    4) Eliminar tarea
//    5) Salir
//  Elige una opcion: 1
//  Escribe la tarea: Estudiar listas
//  Tarea agregada: "Estudiar listas"
//
//  Elige una opcion: 1
//  Escribe la tarea: Subir practica a GitHub
//  Tarea agregada: "Subir practica a GitHub"
//
//  Elige una opcion: 2
//  Tienes 2 tarea(s) pendiente(s):
//    1. Estudiar listas
//    2. Subir practica a GitHub
//
//  Elige una opcion: 3
//  Que tarea completaste? Estudiar listas
//  Hecho! "Estudiar listas" sale de la lista.
//
//  Elige una opcion: 5
//  Te quedan 1 pendiente(s). Hasta la proxima!
// =============================================================


// =============================================================
//  RETOS EXTRA (suman puntos de actividad)
// -------------------------------------------------------------
//  RETO 1 · Marcar como completada SIN borrar.
//     En vez de quitar la tarea, anteponle un simbolo "[x] "
//     usando find() para localizarla y reasignar por posicion:
//         auto it = find(tareas.begin(), tareas.end(), texto);
//         if (it != tareas.end()) *it = "[x] " + *it;
//     Asi la tarea sigue visible pero se ve "tachada".
//
//  RETO 2 · Contador de pendientes.
//     Al mostrar, cuenta cuantas NO empiezan con "[x] " y di
//     "Te faltan N pendientes". Puedes usar un for con un
//     acumulador y la funcion rfind(prefijo, 0) == 0 para
//     saber si un string empieza con cierto prefijo. (count()
//     de <algorithm> sirve para contar repeticiones EXACTAS.)
//
//  RETO 3 · Ordenar alfabeticamente.
//     Agrega una opcion para ordenar el vector con
//         sort(tareas.begin(), tareas.end());      // orden A-Z
//     y otra para invertir el orden con
//         reverse(tareas.begin(), tareas.end());
//     Observa que ambas trabajan SOBRE el vector (lo modifican
//     en el sitio); no devuelven una lista nueva.
//
//  RETO 4 · A prueba de errores.
//     Compara SIEMPRE el iterador de find() contra .end() antes
//     de usar erase()/*it, para que el programa nunca truene
//     cuando el usuario escriba una tarea que no existe. Un buen
//     gestor jamas revienta.
// =============================================================
