# =============================================================
#  PRÁCTICA 6 · Tipos de datos estructurados
#  "UniData" · créditos aprobados y materias seriadas
#  Fundamentos de Programación · UNITEC · Ciclo 26-3
# =============================================================
#  SOLUCIÓN DOCENTE — versión completa y comentada.
#
#  Es la clave de referencia del profesor. NO se enlaza desde el
#  cuaderno: lo que descargan los alumnos es el plano vacío
#  unidata.py (solo comentarios PASO N, sin código).
#
#  Combina los cuatro temas de la sesión 22:
#    - ESTRUCTURAS: dos diccionarios (Materia y Estudiante)
#    - ARREGLO: una lista de diccionarios (materias aprobadas)
#    - CADENAS: nombres y matrícula
#    - MATRIZ 3x3 recorrida con dos ciclos for anidados
#
#  Correr:  python unidata_solucion.py
# =============================================================


# ---------- EL PLAN DE ESTUDIOS (la matriz · 6.3) ----------

PLAN = 3

# Los nombres del plan: un ARREGLO de CADENAS.
plan = ["Álgebra", "Cálculo I", "Estadística"]

# La MATRIZ de materias seriadas: en Python, una lista de listas.
#   renglón = materia;  columna = materia que DEPENDE de ella
#   seriacion[f][c] == 1  ->  aprobar plan[f] abre plan[c]
seriacion = [
    [0, 1, 0],   # Álgebra     abre Cálculo I
    [0, 0, 1],   # Cálculo I   abre Estadística
    [0, 0, 0],   # Estadística no abre ninguna
]


# ---------- LAS DOS ESTRUCTURAS (indicación 1) ----------
#  C++ las declara con struct. En Python la estructura es un
#  DICCIONARIO con esos mismos campos:
#
#    MATERIA    -> {"nombre": cadena, "creditos": entero,
#                   "aprobada": True o False}
#
#    ESTUDIANTE -> {"nombre": cadena, "matricula": cadena,
#                   "aprobadas": [ ... arreglo de materias ... ]}


# ---------- LAS TRES FUNCIONES (indicaciones 2 y 3) ----------

def ingresar_materias(lista, cuantas):
    """Indicación 2 (primera función).
    Llena el ARREGLO de materias aprobadas. Cada vuelta arma una
    estructura Materia completa y la mete en un casillero."""
    for i in range(cuantas):
        print()
        print("  Materia", i + 1)
        nombre = input("    Nombre         : ")
        puntos = int(input("    Créditos       : "))
        respuesta = input("    ¿Aprobada? (s/n): ")

        materia = {
            "nombre": nombre,
            "creditos": puntos,
            "aprobada": (respuesta == "s")
        }
        lista.append(materia)


def sumar_creditos(lista, cuantas):
    """Indicación 2 (segunda función).
    Recorre el arreglo y ACUMULA los créditos de las materias
    aprobadas. Devuelve la suma."""
    total = 0
    for i in range(cuantas):
        if lista[i]["aprobada"]:
            total = total + lista[i]["creditos"]
    return total


def contar_materias(lista, cuantas):
    """Indicación 3 (primera parte).
    Recorre el arreglo y CUENTA cuántas materias aprobadas tiene
    registradas el estudiante."""
    total = 0
    for i in range(cuantas):
        if lista[i]["aprobada"]:
            total = total + 1
    return total


# ---------- EL PROGRAMA PRINCIPAL ----------

print("=================================")
print("   UniData · créditos aprobados")
print("=================================")
print()

# Se arma la estructura ESTUDIANTE, con su arreglo vacío
nombre_alumno = input("Nombre del estudiante: ")
matricula = input("Número de matrícula  : ")

alumno = {
    "nombre": nombre_alumno,
    "matricula": matricula,
    "aprobadas": []
}

print()
cuantas = int(input("¿Cuántas materias vas a registrar? "))

ingresar_materias(alumno["aprobadas"], cuantas)


# --- El reporte del alumno, con las funciones de arriba ---

print()
print("===== UniData · expediente =====")
print("Alumno:    " + alumno["nombre"])
print("Matrícula: " + alumno["matricula"])
print()
print("Materias aprobadas:", contar_materias(alumno["aprobadas"], cuantas))
print("Créditos aprobados:", sumar_creditos(alumno["aprobadas"], cuantas))

# El detalle materia por materia: se lee cada estructura completa
print()
print("--- Detalle de las materias ---")
for i in range(cuantas):
    materia = alumno["aprobadas"][i]
    if materia["aprobada"]:
        estado = "aprobada"
    else:
        estado = "pendiente"
    print(materia["nombre"], "-", materia["creditos"], "créditos -", estado)


# --- El recorrido de la MATRIZ con dos for ANIDADOS ---
#     (es la "operación dentro de la matriz" que se evalúa)

print()
print("--- Seriación del plan de estudios ---")

for f in range(PLAN):                  # ciclo exterior: el renglón
    print(plan[f], "abre:", end=" ")

    abiertas = 0
    for c in range(PLAN):              # ciclo interior: las columnas
        if seriacion[f][c] == 1:
            print(plan[c], end=" ")
            abiertas = abiertas + 1

    if abiertas == 0:
        print("(ninguna)", end="")
    print()


# =============================================================
#  CONCLUSIONES
# =============================================================
#
#  1) ¿Por qué es importante utilizar arreglos?
#
#  Porque un programa real nunca maneja un solo dato. Sin
#  arreglos habría que inventar una variable por cada materia
#  —materia1, materia2, materia3...— y el código crecería tanto
#  como los datos. El arreglo pone muchos datos bajo UN nombre y
#  los numera, y eso permite trabajarlos con un solo ciclo: el
#  mismo for sirve para 3 materias o para 300.
#
#  Y cuando cada elemento tiene varios datos de distinto tipo,
#  el arreglo se combina con la ESTRUCTURA: cada casillero
#  guarda un registro completo, en vez de repartir los datos
#  entre varios arreglos que habría que sincronizar a mano.
#
#  2) ¿Para qué sirven las cadenas y las matrices?
#
#  Las CADENAS guardan texto: nombres de materias, de alumnos,
#  matrículas. Por dentro son un arreglo de caracteres, así que
#  se les puede pedir su longitud, indexar una posición o
#  recorrerlas con un for, igual que a cualquier arreglo.
#
#  Las MATRICES sirven cuando el dato relaciona DOS cosas y ya no
#  cabe en una fila. La seriación de un plan de estudios es justo
#  eso: no es una lista de materias, sino qué materia abre la
#  puerta a cuál. Con renglones y columnas esa relación cabe en
#  una sola estructura, y se recorre con dos ciclos anidados.
#
#  Lo aprendido: elegir bien la estructura de datos es la mitad
#  del programa; el ciclo que la recorre sale casi solo.
# =============================================================
