# =============================================================================
#  CAJERO ATM  ·  versión FRÁGIL  ·  base para endurecer (entregas la 2.0)
#  Fundamentos de Programación · UNITEC Atizapán · Ciclo 26-3
#  Profesor: Carlos Daniel Vaca Ramírez
# -----------------------------------------------------------------------------
#  Este es el cajero de la sesión 09 ("Los muchos caminos"). FUNCIONA…
#  mientras el usuario se porte bien. El problema es que el usuario NUNCA
#  se porta bien: escribe "abc" donde esperas un número, intenta retirar
#  más de lo que tiene, reparte entre 0 personas, elige una opción que no
#  existe. Y entonces el cajero CRASHEA con un traceback rojo en pantalla.
#
#  Un cajero real jamás puede tronar: dejaría a la persona con la tarjeta
#  adentro y la fila gritando. Tu trabajo de hoy es ENDURECERLO.
#
#  Busca cada marca  # FRÁGIL  y envuélvela con try / except / else / finally
#  para que el programa NUNCA reviente: que avise con cortesía y siga vivo.
#
#  Errores que vas a domar:
#     ValueError          -> texto donde se esperaba un número
#     ZeroDivisionError   -> repartir entre 0 personas
#     KeyError            -> consultar una cuenta que no existe
#     (lógica de negocio) -> retirar más que el saldo, montos negativos
# =============================================================================


# --- Datos del cajero (esto ya está bien, no lo toques) ----------------------
CUENTAS = {
    "1001": {"titular": "Ana",   "saldo": 2500.0},
    "1002": {"titular": "Beto",  "saldo": 800.0},
    "1003": {"titular": "Carla", "saldo": 15000.0},
}


def mostrar_menu():
    print()
    print("==============================")
    print("   CAJERO  ATM  ·  UNITEC")
    print("==============================")
    print("  1) Consultar saldo")
    print("  2) Retirar efectivo")
    print("  3) Repartir un monto entre N personas")
    print("  4) Salir")
    print("------------------------------")


def consultar_saldo(cuentas):
    numero = input("Número de cuenta: ")
    # FRÁGIL 1: si la cuenta no existe, cuentas[numero] lanza KeyError y truena.
    # PASO 1: envuelve este acceso en try/except KeyError y avisa con cortesía.
    cuenta = cuentas[numero]
    print(f"Titular: {cuenta['titular']}")
    print(f"Saldo disponible: ${cuenta['saldo']:.2f}")


def retirar(cuentas):
    numero = input("Número de cuenta: ")
    cuenta = cuentas[numero]   # (la misma fragilidad del KeyError vive aquí)

    # FRÁGIL 2: input() devuelve TEXTO. Si el usuario escribe "abc",
    # float("abc") lanza ValueError y el cajero truena.
    # PASO 2: envuelve la conversión en try/except ValueError.
    monto = float(input("¿Cuánto deseas retirar? $"))

    # FRÁGIL 3: error de LÓGICA, no de excepción. Hay que VALIDAR a mano:
    #   - el monto no puede ser cero ni negativo
    #   - no puedes retirar más de lo que hay en la cuenta
    # PASO 3: agrega estas validaciones ANTES de descontar el saldo.
    cuenta["saldo"] = cuenta["saldo"] - monto
    print(f"Retiro exitoso. Nuevo saldo: ${cuenta['saldo']:.2f}")


def repartir():
    # FRÁGIL 4: dos conversiones que pueden fallar con ValueError…
    # PASO 4a: envuelve ambas lecturas en try/except ValueError.
    monto = float(input("Monto a repartir: $"))
    personas = int(input("¿Entre cuántas personas? "))

    # FRÁGIL 5: si "personas" es 0, esta división lanza ZeroDivisionError.
    # PASO 4b: captura ZeroDivisionError (o valida que personas > 0 antes).
    cada_uno = monto / personas
    print(f"A cada persona le tocan: ${cada_uno:.2f}")


def main():
    print("Bienvenido al cajero automático.")
    while True:
        mostrar_menu()
        opcion = input("Elige una opción (1-4): ")

        # FRÁGIL 6: el menú solo conoce "1", "2", "3", "4". Si el usuario
        # escribe "9" o "salir", hoy el programa simplemente lo ignora en
        # silencio (mala experiencia) o, peor, asume algo que no es.
        # PASO 5: maneja la opción inexistente con un mensaje claro
        #         dentro del else final.
        if opcion == "1":
            consultar_saldo(CUENTAS)
        elif opcion == "2":
            retirar(CUENTAS)
        elif opcion == "3":
            repartir()
        elif opcion == "4":
            print("Gracias por usar el cajero. ¡Hasta luego!")
            break

    # PASO 6 (opcional pero elegante): usa un bloque finally en las
    # operaciones para imprimir SIEMPRE una línea de cierre, como
    # "— operación finalizada —", pase lo que pase.


if __name__ == "__main__":
    main()


# =============================================================================
#  EJEMPLO DE LAS ENTRADAS QUE HOY LO ROMPEN
# -----------------------------------------------------------------------------
#  Corre el programa SIN endurecer y prueba esto; verás el traceback rojo:
#
#   1) Opción 1 -> cuenta "9999"
#        >>> KeyError: '9999'                         (cuenta inexistente)
#
#   2) Opción 2 -> cuenta "1001" -> monto "mil"
#        >>> ValueError: could not convert string to float: 'mil'
#
#   3) Opción 2 -> cuenta "1002" (saldo 800) -> retira 5000
#        >>> No truena, pero deja el saldo en -4200.00  (¡error de lógica!)
#
#   4) Opción 3 -> monto "500" -> personas "0"
#        >>> ZeroDivisionError: float division by zero
#
#   5) Opción "7" en el menú
#        >>> el programa no hace nada y reaparece el menú sin avisar nada.
#
#  Tu versión 2.0 debe sobrevivir a las cinco SIN un solo traceback,
#  avisando con un mensaje amable y volviendo siempre al menú.
# =============================================================================


# =============================================================================
#  RETOS EXTRA  (suman puntos de actividad)
# -----------------------------------------------------------------------------
#  A) Reintento: si el usuario escribe un número mal, NO lo expulses;
#     vuelve a pedírselo en un while hasta que escriba algo válido.
#  B) Excepción propia: define  class FondosInsuficientes(Exception)  y
#     lánzala con  raise  cuando el retiro supere el saldo; cázala arriba.
#     Discute en clase: ¿cuándo conviene capturar y cuándo dejar propagar?
#  C) Bitácora: usa try/except/else/finally para escribir cada operación
#     en un archivo "bitacora.txt" — el finally garantiza cerrar el archivo.
#  D) PIN: pide un PIN de 4 dígitos; valida con try/except que sean números
#     y exactamente 4. Tres intentos y la tarjeta "se retiene".
# =============================================================================
