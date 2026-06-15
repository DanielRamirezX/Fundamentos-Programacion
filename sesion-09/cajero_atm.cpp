// =============================================================================
//  CAJERO ATM POR CONSOLA  ·  Sesion 09 "Los muchos caminos"
//  Fundamentos de Programacion · UNITEC Atizapan · Ciclo 26-3
//  Profesor: Carlos Daniel Vaca Ramirez
// -----------------------------------------------------------------------------
//  El PLANO (version C++, lenguaje PRINCIPAL del curso desde la sesion 09).
//  Este archivo solo trae comentarios numerados (// PASO N).
//  Tu trabajo: leer cada instruccion y escribir tu codigo en el espacio en
//  blanco que sigue. NO borres los comentarios. Compila y corre el programa
//  despues de cada paso para asegurarte de que no truena antes de continuar.
//
//  Para compilar:   g++ cajero_atm.cpp -o cajero_atm
//  Para ejecutar:   ./cajero_atm        (en Windows: cajero_atm.exe)
//
//  Objetivo: un cajero con MENU de al menos 4 opciones (consultar saldo,
//  depositar, retirar, salir) y validaciones construidas con DECISIONES
//  ANIDADAS y CONDICIONES COMPUESTAS (&&, ||, !).
//
//  NOTA: Python sigue como PUENTE. Si quieres comparar, mira cajero_atm.py:
//  es el MISMO razonamiento en el lenguaje que ya conoces.
// =============================================================================

#include <iostream>
#include <string>
#include <iomanip>   // setprecision para imprimir el dinero con 2 decimales
using namespace std;

int main() {

    // -------------------------------------------------------------------------
    // PASO 1: Crea las CONSTANTES del cajero (MAYUSCULAS, como en la sesion 6).
    //   SALDO_INICIAL   -> con cuanto dinero arranca la cuenta, p. ej. 5000.0
    //   RETIRO_MAXIMO   -> tope por operacion, p. ej. 9000.0
    //   PIN_CORRECTO    -> un PIN de 4 digitos como texto, p. ej. "1234"
    //   En C++ se declaran con la palabra clave  const.
    // -------------------------------------------------------------------------

    //   <- aqui escribes tu codigo


    // -------------------------------------------------------------------------
    // PASO 2: Define una variable 'saldo' (double) que valga SALDO_INICIAL.
    //   Sera el dinero disponible; cambiara con cada deposito o retiro.
    // -------------------------------------------------------------------------

    //   <- aqui escribes tu codigo


    // -------------------------------------------------------------------------
    // PASO 3: VALIDACION DE ACCESO con una DECISION ANIDADA.
    //   Pide el PIN con cin. Da hasta 3 intentos usando un for.
    //   Dentro del for, anida un if:
    //       si el pin escrito == PIN_CORRECTO -> avisa "Acceso concedido",
    //           guarda acceso = true y rompe el ciclo con break.
    //       si no -> avisa cuantos intentos quedan.
    //   Si se agotan los 3 intentos sin acertar, acceso = false.
    //   Pista: declara  bool acceso = false;  antes del for.
    // -------------------------------------------------------------------------

    //   <- aqui escribes tu codigo


    // -------------------------------------------------------------------------
    // PASO 4: Si NO hubo acceso (usa  !acceso  o  acceso == false),
    //   muestra "Tarjeta retenida" y termina el programa con  return 0;
    //   Pista: puedes usar la condicion compuesta para tomar la decision.
    // -------------------------------------------------------------------------

    //   <- aqui escribes tu codigo


    // -------------------------------------------------------------------------
    // PASO 5: EL MENU. Repite con un  while (true)  para que el cajero siga
    //   vivo hasta que el usuario decida salir. Imprime las 4 opciones:
    //       1) Consultar saldo
    //       2) Depositar
    //       3) Retirar
    //       4) Salir
    //   Luego pide la opcion con cin y guardala en  string opcion;
    // -------------------------------------------------------------------------

    //   <- aqui escribes tu codigo


    // -------------------------------------------------------------------------
    // PASO 6: OPCION 1 - Consultar saldo.
    //   Dentro del while, con un  if (opcion == "1")  imprime el saldo con
    //   formato, p. ej.:
    //       cout << fixed << setprecision(2);
    //       cout << "Tu saldo es $" << saldo << endl;
    // -------------------------------------------------------------------------

    //   <- aqui escribes tu codigo


    // -------------------------------------------------------------------------
    // PASO 7: OPCION 2 - Depositar (con VALIDACION ANIDADA).
    //   else if (opcion == "2") {
    //       pide el monto y leelo con cin >> monto;  (monto es double)
    //       if (monto > 0) {          // el deposito debe ser positivo
    //           suma el monto al saldo e informa el nuevo saldo.
    //       } else {
    //           avisa "Monto invalido".
    //       }
    //   }
    // -------------------------------------------------------------------------

    //   <- aqui escribes tu codigo


    // -------------------------------------------------------------------------
    // PASO 8: OPCION 3 - Retirar (DECISIONES ANIDADAS + LOGICA COMPUESTA).
    //   else if (opcion == "3") {
    //       pide el monto y leelo con cin >> monto;
    //       if (monto <= 0) {
    //           "Monto invalido".
    //       } else if (monto > RETIRO_MAXIMO) {
    //           "Excede el retiro maximo por operacion".
    //       } else if (monto > saldo) {
    //           "Fondos insuficientes".
    //       } else {
    //           resta el monto al saldo y entrega el dinero.
    //       }
    //   }
    //   Reto: junta dos reglas con && u || para acortar el if.
    // -------------------------------------------------------------------------

    //   <- aqui escribes tu codigo


    // -------------------------------------------------------------------------
    // PASO 9: OPCION 4 - Salir.
    //   else if (opcion == "4") {
    //       despidete y rompe el ciclo con break;
    //   }
    // -------------------------------------------------------------------------

    //   <- aqui escribes tu codigo


    // -------------------------------------------------------------------------
    // PASO 10: OPCION invalida.
    //   else {
    //       avisa "Opcion no valida, intenta de nuevo".
    //   }
    //   Con esto el menu queda blindado: cualquier tecla equivocada no rompe nada.
    // -------------------------------------------------------------------------

    //   <- aqui escribes tu codigo


    return 0;
}

// =============================================================================
//  EJEMPLO DE CORRIDA (asi se debe ver tu cajero terminado)
// -----------------------------------------------------------------------------
//   Ingresa tu PIN: 0000
//   PIN incorrecto. Te quedan 2 intentos.
//   Ingresa tu PIN: 1234
//   Acceso concedido. Bienvenido.
//
//   ===== CAJERO ATM =====
//   1) Consultar saldo
//   2) Depositar
//   3) Retirar
//   4) Salir
//   Elige una opcion: 1
//   Tu saldo es $5000.00
//
//   Elige una opcion: 3
//   ¿Cuanto deseas retirar? 12000
//   Excede el retiro maximo por operacion ($9000.00).
//
//   Elige una opcion: 3
//   ¿Cuanto deseas retirar? 2000
//   Entrega de $2000.00. Tu nuevo saldo es $3000.00
//
//   Elige una opcion: 4
//   Gracias por usar el cajero. Hasta pronto.
// =============================================================================


// =============================================================================
//  RETOS EXTRA (opcionales · suman puntos de actividad)
// -----------------------------------------------------------------------------
//  A. VERSION CON switch-case: refactoriza el menu (PASOS 6 a 10) usando
//     switch sobre el primer caracter de la opcion (opcion[0]):
//         switch (opcion[0]) {
//             case '1': ... break;
//             case '2': ... break;
//             case '3': ... break;
//             case '4': ... break;
//             default:  ...   // el comodin, equivale al "else"
//         }
//     Compara: ¿quedo mas legible que el if-else if-else? Anota tu conclusion.
//     (En Python el equivalente es match-case: mira cajero_atm.py).
//
//  B. Cobra una COMISION del 1.5% en cada retiro usando una constante
//     const double COMISION = 0.015;  y una condicion compuesta para no
//     cobrarla si el retiro es menor a $500 (clientes pequenos no pagan).
//
//  C. Lleva un HISTORIAL: guarda cada operacion en un  vector<string>
//     (#include <vector>) y agrega una 5a opcion "Ver movimientos" que lo
//     imprima recorriendolo con un for.
//
//  D. Tras 3 PIN incorrectos, en vez de terminar, bloquea la tarjeta por
//     "tiempo" mostrando una cuenta regresiva. En C++ puedes usar
//     #include <thread> y <chrono>:  this_thread::sleep_for(chrono::seconds(1));
// =============================================================================
