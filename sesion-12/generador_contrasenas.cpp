// =============================================================================
//  GENERADOR DE CONTRASEÑAS SEGURAS  ·  Sesión 12 · "Lo finito y lo cíclico"
//  Fundamentos de Programación · UNITEC Atizapán · Ciclo 26-3
//  Profesor: Carlos Daniel Vaca Ramírez
// -----------------------------------------------------------------------------
//  El plano. No borres los comentarios "// PASO N": son tu guía.
//  Debajo de cada paso hay un espacio en blanco; ahí escribes TU código.
//
//  En la sesión 11 repetías HASTA QUE algo pasara (while). Hoy repites un
//  número EXACTO de veces (for). Una contraseña de longitud N es eso:
//  N decisiones al azar, una por cada vuelta del ciclo. La armarás carácter
//  por carácter dentro de un "for" de longitud finita.
//
//  Lenguaje principal: C++ (Python como apoyo, mira la otra pestaña en la web).
//  Herramientas de hoy: for, acumuladores (string que crece con +=), y el azar
//  con rand() de <cstdlib> sembrado con srand(time(0)).
//  Compila y corre después de cada paso para asegurarte de que no truena:
//      g++ generador_contrasenas.cpp -o generador_contrasenas
//      ./generador_contrasenas
// =============================================================================

// PASO 1: Incluye las librerías que necesitas.
//         <iostream> para cout, <string> para la cadena que crece,
//         <cstdlib> para rand() y srand(), <ctime> para sembrar con time(0).
//         Pista:  #include <iostream>   /   #include <string>
//                 #include <cstdlib>    /   #include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// ← (los #include de arriba ya son tu PASO 1)

int main() {
    // Siembra del azar: sin esto, rand() daría siempre la misma "contraseña".
    srand(time(0));

    // PASO 2: Crea cuatro CONSTANTES con los conjuntos de caracteres.
    //         En C++ los tecleamos como string (no hay "string.ascii_lowercase"):
    //           const string MINUSCULAS = "abcdefghijklmnopqrstuvwxyz";
    //           const string MAYUSCULAS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //           const string DIGITOS    = "0123456789";
    //           const string SIMBOLOS   = "!#$%&*+-?@";   // elige los que quieras

    // ← aquí escribes tu código


    // PASO 3: Define los PARÁMETROS de la contraseña como variables.
    //         Estos son los "botones" que el usuario podrá configurar:
    //           int  longitud         = 12;     // ¿cuántos caracteres tendrá?
    //           bool incluir_mayus    = true;   // ¿metemos MAYÚSCULAS?
    //           bool incluir_digitos  = true;   // ¿metemos números?
    //           bool incluir_simbolos = true;   // ¿metemos símbolos?

    // ← aquí escribes tu código


    // PASO 4 (validación): antes de generar, asegúrate de que la longitud sea
    //         sensata. Una contraseña de menos de 4 caracteres no protege nada.
    //         Si longitud < 4, avisa con cout y NO sigas (return 1; corta main):
    //           if (longitud < 4) {
    //               cout << "La longitud minima recomendada es 4." << endl;
    //               return 1;
    //           }

    // ← aquí escribes tu código


    // PASO 5: Construye el "alfabeto" disponible juntando los conjuntos elegidos.
    //         Empieza SIEMPRE con minúsculas y ve SUMANDO (acumulando) los demás
    //         solo si su parámetro es true. Las cadenas se suman con "+" o "+=".
    //           string alfabeto = MINUSCULAS;
    //           if (incluir_mayus)    alfabeto += MAYUSCULAS;
    //           if (incluir_digitos)  alfabeto += ...;
    //           if (incluir_simbolos) alfabeto += ...;

    // ← aquí escribes tu código


    // PASO 6: Crea un ACUMULADOR de texto vacío donde irás pegando cada carácter.
    //         (igual que un acumulador de suma, pero con cadenas)
    //           string contrasena = "";

    // ← aquí escribes tu código


    // PASO 7: El corazón del programa. Un ciclo "for" que se repite "longitud" veces.
    //         En CADA vuelta:
    //           1. elige un índice al azar dentro del alfabeto -> rand() % alfabeto.size()
    //           2. toma ese carácter  -> char c = alfabeto[indice];
    //           3. pégalo al acumulador -> contrasena += c;
    //         El for repite un número FINITO de veces:
    //           for (int i = 0; i < longitud; i++) {
    //               int indice = rand() % alfabeto.size();
    //               char c = alfabeto[indice];
    //               contrasena += c;
    //           }

    // ← aquí escribes tu código


    // PASO 8: Muestra el resultado en pantalla con cout.
    //         Imprime también la longitud real para verificar (size() la mide):
    //           cout << "Tu contrasena es: " << contrasena << endl;
    //           cout << "Longitud: " << contrasena.size() << endl;

    // ← aquí escribes tu código


    return 0;
}

// =============================================================================
//  EJEMPLO DE UNA CORRIDA (así debe verse tu programa terminado)
// -----------------------------------------------------------------------------
//   $ g++ generador_contrasenas.cpp -o generador_contrasenas
//   $ ./generador_contrasenas
//   Tu contrasena es: gT7#mQ2x!pLa
//   Longitud: 12
//
//   $ ./generador_contrasenas        (con incluir_simbolos = false)
//   Tu contrasena es: gT7mQ2xpLaUe
//   Longitud: 12
//
//   (cada vez que lo corres sale una distinta: ese es el poder de rand())
// =============================================================================

// =============================================================================
//  RETOS EXTRA (suman puntos de actividad)
// -----------------------------------------------------------------------------
//  RETO 1 · Pídele al usuario la longitud y las opciones con cin. Recuerda leer
//           la longitud en un int, y traducir 's'/'n' a true/false con un if.
//               cout << "Longitud: ";  cin >> longitud;
//               char op;  cout << "Simbolos? (s/n): ";  cin >> op;
//               incluir_simbolos = (op == 's');
//
//  RETO 2 · Genera VARIAS contraseñas de un jalón. Envuelve la generación en
//           otro "for" que se repita N veces y muestra una lista numerada:
//               for (int n = 1; n <= cuantas; n++) {
//                   // ...genera una contraseña...
//                   cout << n << " -> " << contrasena << endl;
//               }
//
//  RETO 3 · Mide la FUERZA de la contraseña. Cuenta con contadores cuántos
//           caracteres son minúsculas, mayúsculas, dígitos y símbolos; recorre
//           la contraseña con un "for" sobre sus caracteres. Usa find() para
//           ver si un carácter pertenece a un conjunto (string::npos = no está):
//               int minus = 0, mayus = 0, nums = 0, simb = 0;
//               for (char c : contrasena) {
//                   if (MINUSCULAS.find(c) != string::npos) minus++;
//                   else if (MAYUSCULAS.find(c) != string::npos) mayus++;
//                   // ...digitos y simbolos...
//               }
//           Si las cuatro familias aparecen y la longitud >= 12, dila "FUERTE".
//
//  RETO 4 · Garantiza al menos un carácter de cada familia elegida. Si por
//           mala suerte salió "todo minúsculas", vuelve a generarla. Aquí SÍ
//           encaja un while: repetir HASTA QUE cumpla la regla (la herencia
//           de la sesión 11).
//
//  RETO 5 · cmath en acción. Incluye <cmath> y estima el espacio de
//           combinaciones (cuántas contraseñas distintas son posibles):
//               double total = pow(alfabeto.size(), longitud);
//               double bits  = log2(total);
//           Imprime cuántos "bits de entropía" tiene tu contraseña. Más bits,
//           más difícil de adivinar a fuerza bruta.
// =============================================================================
