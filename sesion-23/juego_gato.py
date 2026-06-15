# =====================================================================
#  EL TABLERO DEL MUNDO  ·  Juego del gato (tres en raya) para 2
#  Fundamentos de Programacion · UNITEC Atizapan · Ciclo 26-3
#  Profesor: Carlos Daniel Vaca Ramirez
# ---------------------------------------------------------------------
#  Un tablero es una MATRIZ 3x3. La fila es la primera dimension y la
#  columna la segunda: tablero[fila][columna]. Lo recorremos con DOS
#  ciclos for anidados (uno por dimension).
#
#  Lo que YA esta hecho:  crear_tablero(), mostrar_tablero()
#  Lo que TE toca a ti:   pedir_jugada(), validar_celda(), hay_ganador()
#
#  Reglas de la casa: sangria de 4 espacios, nombres claros en espanol,
#  comenta lo que hagas con #. Corre el programa despues de cada PASO
#  para asegurarte de que no truena antes de seguir.
# =====================================================================

FILAS = 3          # alto del tablero (constante: no se toca)
COLUMNAS = 3       # ancho del tablero
VACIA = " "        # como se ve una celda libre


def crear_tablero():
    """Devuelve una matriz 3x3 llena de celdas vacias. (YA HECHO)"""
    tablero = []
    for fila in range(FILAS):
        renglon = []
        for columna in range(COLUMNAS):
            renglon.append(VACIA)   # cada celda empieza vacia
        tablero.append(renglon)
    return tablero


def mostrar_tablero(tablero):
    """Dibuja el tablero con sus lineas. Recorre fila por fila. (YA HECHO)"""
    print()
    print("     0   1   2")          # numeros de columna (guia para el jugador)
    print("   +---+---+---+")
    for fila in range(FILAS):
        # arma el renglon: una celda tras otra, separadas por |
        texto = f" {fila} |"
        for columna in range(COLUMNAS):
            texto += f" {tablero[fila][columna]} |"
        print(texto)
        print("   +---+---+---+")
    print()


# ---------------------------------------------------------------------
#  PASO 1: validar_celda(tablero, fila, columna)
#  Devuelve True solo si la jugada es legal:
#    - la fila esta entre 0 y 2  (usa 0 <= fila < FILAS)
#    - la columna esta entre 0 y 2
#    - esa celda esta VACIA (tablero[fila][columna] == VACIA)
#  Si algo falla, devuelve False.
# ---------------------------------------------------------------------
def validar_celda(tablero, fila, columna):
    # TODO: escribe aqui las tres comprobaciones y el return
    pass


# ---------------------------------------------------------------------
#  PASO 2: pedir_jugada(tablero, simbolo)
#  Pregunta al jugador (cuyo simbolo es "X" u "O") la fila y la columna.
#  Repite con un while hasta que validar_celda(...) devuelva True.
#  Cuando la jugada sea valida, ESCRIBE el simbolo en el tablero:
#       tablero[fila][columna] = simbolo
#  Pista: int(input(...)) para convertir el texto a numero.
#  Cuida los datos que no son numeros (puedes usar try / except).
# ---------------------------------------------------------------------
def pedir_jugada(tablero, simbolo):
    # TODO: pide fila y columna en un bucle hasta que la celda sea valida,
    #       luego marca el simbolo en el tablero
    pass


# ---------------------------------------------------------------------
#  PASO 3: hay_ganador(tablero, simbolo)
#  Devuelve True si ese simbolo formo una linea de 3. Revisa:
#    a) las 3 FILAS      -> recorre cada fila con un for y un contador
#    b) las 3 COLUMNAS   -> recorre cada columna (for de columnas, for de filas)
#    c) las 2 DIAGONALES -> [0][0],[1][1],[2][2]  y  [0][2],[1][1],[2][0]
#  Idea con doble for: por cada fila cuenta cuantas celdas son del simbolo;
#  si el contador llega a COLUMNAS, esa fila esta completa -> return True.
# ---------------------------------------------------------------------
def hay_ganador(tablero, simbolo):
    # TODO: revisa filas, columnas y las dos diagonales; devuelve True/False
    pass


# ---------------------------------------------------------------------
#  EL BUCLE PRINCIPAL  (YA HECHO: usa tus funciones de arriba)
#  Alterna entre el jugador X y el jugador O hasta que alguien gane
#  o se llenen las 9 celdas. No lo modifiques hasta terminar los PASOS.
# ---------------------------------------------------------------------
def jugar():
    tablero = crear_tablero()
    jugadores = ["X", "O"]   # X siempre empieza
    turno = 0                # cuenta cuantas jugadas van (max 9)

    print("=" * 34)
    print("        EL TABLERO DEL MUNDO")
    print("     Juego del gato · 2 jugadores")
    print("=" * 34)

    while turno < FILAS * COLUMNAS:          # como mucho 9 jugadas
        simbolo = jugadores[turno % 2]       # 0->X, 1->O, 2->X, ...
        mostrar_tablero(tablero)
        print(f"Turno de {simbolo}")

        pedir_jugada(tablero, simbolo)       # <- tu PASO 2

        if hay_ganador(tablero, simbolo):    # <- tu PASO 3
            mostrar_tablero(tablero)
            print(f"¡Ganó {simbolo}! Tres en raya.")
            return

        turno += 1

    # si salimos del while sin ganador, el tablero se lleno
    mostrar_tablero(tablero)
    print("Empate. El tablero esta lleno y nadie hizo una linea.")


# arranca el juego cuando ejecutas el archivo
if __name__ == "__main__":
    jugar()


# =====================================================================
#  EJEMPLO DE PARTIDA (asi se vera tu juego cuando completes los PASOS)
# ---------------------------------------------------------------------
#       0   1   2
#    +---+---+---+
#  0 | X | O |   |
#    +---+---+---+
#  1 |   | X | O |
#    +---+---+---+
#  2 |   |   | X |
#    +---+---+---+
#
#  Turno de X
#  Fila (0-2): 2
#  Columna (0-2): 2
#  ¡Ganó X! Tres en raya.   <- diagonal [0][0] [1][1] [2][2]
# =====================================================================

# =====================================================================
#  RETOS EXTRA (suman puntos de actividad)
#    1. EMPATE elegante: ya se detecta cuando se llenan las 9 celdas,
#       pero anuncia el empate con un mensaje propio y con estilo.
#    2. NOMBRES de jugadores: pide el nombre de cada quien al inicio y
#       usalo en los mensajes ("Turno de Ana (X)").
#    3. MARCAR la linea ganadora: cuando hay_ganador sea True, devuelve
#       tambien las tres coordenadas y reimprimelas en MAYUSCULA o con
#       color ANSI (recuerda la sesion 07) para resaltar la victoria.
#    4. REVANCHA: al terminar, pregunta "¿Otra partida? (s/n)" y reinicia
#       el tablero envolviendo jugar() en un while.
# =====================================================================
