// =============================================================================
//  CAJERO ATM  ·  versión FRÁGIL  ·  base para endurecer (entregas la 2.0)
//  Fundamentos de Programación · UNITEC Atizapán · Ciclo 26-3
//  Profesor: Carlos Daniel Vaca Ramírez
//  Lenguaje PRINCIPAL: C++  ·  Python como apoyo (cajero_atm_robusto.py)
// -----------------------------------------------------------------------------
//  Este es el cajero de la sesión 09 ("Los muchos caminos"). FUNCIONA…
//  mientras el usuario se porte bien. El problema es que el usuario NUNCA
//  se porta bien: escribe "abc" donde esperas un número, intenta retirar
//  más de lo que tiene, reparte entre 0 personas, elige una opción que no
//  existe. Y entonces el cajero CRASHEA con una excepción sin atrapar.
//
//  Un cajero real jamás puede tronar: dejaría a la persona con la tarjeta
//  adentro y la fila gritando. Tu trabajo de hoy es ENDURECERLO.
//
//  Busca cada marca  // FRÁGIL  y envuélvela con try / catch
//  para que el programa NUNCA reviente: que avise con cortesía y siga vivo.
//
//  Errores que vas a domar (equivalentes en C++ de los de Python):
//     std::invalid_argument  -> texto donde se esperaba un número (stod/stoi)
//                               [en Python era ValueError]
//     división entre 0        -> repartir entre 0 personas (valídalo a mano)
//                               [en Python era ZeroDivisionError]
//     std::out_of_range       -> consultar una cuenta que no existe (map::at)
//                               [en Python era KeyError]
//     (lógica de negocio)     -> retirar más que el saldo, montos negativos
//
//  Compila así:   g++ -std=c++17 cajero_atm_robusto.cpp -o cajero
//  Ejecuta así:   ./cajero
// =============================================================================

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <iomanip>
using namespace std;


// --- Datos del cajero (esto ya está bien, no lo toques) ----------------------
struct Cuenta {
    string titular;
    double saldo;
};

map<string, Cuenta> CUENTAS = {
    {"1001", {"Ana",   2500.0}},
    {"1002", {"Beto",  800.0}},
    {"1003", {"Carla", 15000.0}},
};


void mostrar_menu() {
    cout << endl;
    cout << "==============================" << endl;
    cout << "   CAJERO  ATM  ·  UNITEC" << endl;
    cout << "==============================" << endl;
    cout << "  1) Consultar saldo" << endl;
    cout << "  2) Retirar efectivo" << endl;
    cout << "  3) Repartir un monto entre N personas" << endl;
    cout << "  4) Salir" << endl;
    cout << "------------------------------" << endl;
}


void consultar_saldo(map<string, Cuenta>& cuentas) {
    cout << "Número de cuenta: ";
    string numero;
    cin >> numero;
    // FRÁGIL 1: si la cuenta no existe, cuentas.at(numero) lanza
    //   std::out_of_range (el equivalente del KeyError de Python) y truena.
    // PASO 1: envuelve este acceso en try/catch (out_of_range&) y avisa
    //         con cortesía.
    Cuenta& cuenta = cuentas.at(numero);
    cout << "Titular: " << cuenta.titular << endl;
    cout << fixed << setprecision(2);
    cout << "Saldo disponible: $" << cuenta.saldo << endl;
}


void retirar(map<string, Cuenta>& cuentas) {
    cout << "Número de cuenta: ";
    string numero;
    cin >> numero;
    Cuenta& cuenta = cuentas.at(numero);   // (la misma fragilidad del out_of_range vive aquí)

    // FRÁGIL 2: stod() convierte TEXTO a número. Si el usuario escribe "abc",
    //   stod("abc") lanza std::invalid_argument (el ValueError de Python)
    //   y el cajero truena.
    // PASO 2: lee la línea como string y envuelve la conversión en
    //         try/catch (invalid_argument&).
    cout << "¿Cuánto deseas retirar? $";
    string linea;
    cin >> linea;
    double monto = stod(linea);

    // FRÁGIL 3: error de LÓGICA, no de excepción. Hay que VALIDAR a mano:
    //   - el monto no puede ser cero ni negativo
    //   - no puedes retirar más de lo que hay en la cuenta
    // PASO 3: agrega estas validaciones ANTES de descontar el saldo.
    cuenta.saldo = cuenta.saldo - monto;
    cout << fixed << setprecision(2);
    cout << "Retiro exitoso. Nuevo saldo: $" << cuenta.saldo << endl;
}


void repartir() {
    // FRÁGIL 4: dos conversiones que pueden fallar con std::invalid_argument…
    // PASO 4a: lee ambas como string y envuelve las conversiones en
    //          try/catch (invalid_argument&).
    cout << "Monto a repartir: $";
    string sMonto;
    cin >> sMonto;
    double monto = stod(sMonto);

    cout << "¿Entre cuántas personas? ";
    string sPersonas;
    cin >> sPersonas;
    int personas = stoi(sPersonas);

    // FRÁGIL 5: si "personas" es 0, esta división da un resultado inválido
    //   (en C++ la división entre 0 con double da inf/nan en vez de lanzar).
    // PASO 4b: valida que personas > 0 ANTES de dividir y avisa con cortesía
    //          (en Python esto era un ZeroDivisionError).
    double cada_uno = monto / personas;
    cout << fixed << setprecision(2);
    cout << "A cada persona le tocan: $" << cada_uno << endl;
}


int main() {
    cout << "Bienvenido al cajero automático." << endl;
    while (true) {
        mostrar_menu();
        cout << "Elige una opción (1-4): ";
        string opcion;
        cin >> opcion;

        // FRÁGIL 6: el menú solo conoce "1", "2", "3", "4". Si el usuario
        // escribe "9" o "salir", hoy el programa simplemente lo ignora en
        // silencio (mala experiencia) o, peor, asume algo que no es.
        // PASO 5: maneja la opción inexistente con un mensaje claro
        //         dentro del else final.
        if (opcion == "1") {
            consultar_saldo(CUENTAS);
        } else if (opcion == "2") {
            retirar(CUENTAS);
        } else if (opcion == "3") {
            repartir();
        } else if (opcion == "4") {
            cout << "Gracias por usar el cajero. ¡Hasta luego!" << endl;
            break;
        }

        // PASO 6 (opcional pero elegante): como C++ no tiene "finally",
        // imprime SIEMPRE una línea de cierre justo después de cada operación
        // (con error o sin él), p. ej. "— operación finalizada —".
    }
    return 0;
}


// =============================================================================
//  EJEMPLO DE LAS ENTRADAS QUE HOY LO ROMPEN
// -----------------------------------------------------------------------------
//  Corre el programa SIN endurecer y prueba esto; verás la excepción sin
//  atrapar (o un resultado absurdo en los casos de lógica):
//
//   1) Opción 1 -> cuenta "9999"
//        >>> terminate called: std::out_of_range          (cuenta inexistente)
//
//   2) Opción 2 -> cuenta "1001" -> monto "mil"
//        >>> terminate called: std::invalid_argument (stod)
//
//   3) Opción 2 -> cuenta "1002" (saldo 800) -> retira 5000
//        >>> No truena, pero deja el saldo en -4200.00     (¡error de lógica!)
//
//   4) Opción 3 -> monto "500" -> personas "0"
//        >>> imprime "inf"  (división entre 0 con double; valídalo tú)
//
//   5) Opción "7" en el menú
//        >>> el programa no hace nada y reaparece el menú sin avisar nada.
//
//  Tu versión 2.0 debe sobrevivir a las cinco SIN una sola excepción sin
//  atrapar, avisando con un mensaje amable y volviendo siempre al menú.
// =============================================================================


// =============================================================================
//  RETOS EXTRA  (suman puntos de actividad)
// -----------------------------------------------------------------------------
//  A) Reintento: si el usuario escribe un número mal, NO lo expulses;
//     vuelve a pedírselo en un while hasta que escriba algo válido.
//  B) Excepción propia: define
//         class FondosInsuficientes : public std::runtime_error {
//         public:
//             FondosInsuficientes() : std::runtime_error("fondos") {}
//         };
//     y lánzala con  throw FondosInsuficientes();  cuando el retiro supere
//     el saldo; cázala arriba con catch (FondosInsuficientes&).
//     Discute en clase: ¿cuándo conviene capturar y cuándo dejar propagar?
//  C) Bitácora: usa <fstream> (ofstream) para escribir cada operación en un
//     archivo "bitacora.txt". En C++ no hay "finally": cierra el archivo
//     explícitamente con archivo.close() pase lo que pase (o deja que el
//     destructor del ofstream lo cierre al salir del ámbito).
//  D) PIN: pide un PIN de 4 dígitos; valida con try/catch (stoi) que sean
//     números y exactamente 4 caracteres. Tres intentos y la tarjeta
//     "se retiene".
// =============================================================================
