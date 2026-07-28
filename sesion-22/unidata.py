# =============================================================
#  PRÁCTICA 6 · Tipos de datos estructurados
#  "UniData" · créditos aprobados y materias seriadas
#  Fundamentos de Programación · UNITEC · Ciclo 26-3
# =============================================================
#  Este archivo es un PLANO: trae los pasos comentados.
#  Escribe TÚ el código debajo de cada PASO.
#
#  Las cuatro piezas que combina la práctica:
#    ESTRUCTURA -> los tres datos de una materia, juntos
#    ARREGLO    -> las materias aprobadas del estudiante
#    CADENA     -> los nombres de materia y de estudiante
#    MATRIZ     -> el plan de estudios (3 x 3), doble for
#
#  IDEA CLAVE: un ARREGLO (lista) guarda muchos datos del MISMO
#  tipo; una ESTRUCTURA (diccionario) guarda pocos datos de
#  DISTINTO tipo. Al combinarlos sale una LISTA DE DICCIONARIOS:
#  una fila de casilleros donde cada uno es un registro completo.
#
#      aprobadas[0]         aprobadas[1]         aprobadas[2]
#    +---------------+   +---------------+   +---------------+
#    | nombre "Álg." |   | nombre "Cál." |   | nombre "Est." |
#    | creditos   8  |   | creditos  10  |   | creditos   6  |
#    | aprobada True |   | aprobada True |   | aprobada Fals |
#    +---------------+   +---------------+   +---------------+
# =============================================================

PLAN = 3   # cuántas materias tiene el plan

# ---------- LAS DOS ESTRUCTURAS (indicación 1) ----------

# PASO 1: define cómo se ve una MATERIA. En Python, un
#         diccionario con tres campos:
#           {"nombre": "", "creditos": 0, "aprobada": False}

# PASO 2: define cómo se ve un ESTUDIANTE:
#           {"nombre": "", "matricula": "", "aprobadas": []}
#         El campo "aprobadas" es el ARREGLO (lista) de materias.

# ---------- LAS TRES FUNCIONES (indicaciones 2 y 3) ----------

# PASO 3: def ingresar_materias(lista, cuantas):
#   Con un ciclo for, arma en cada vuelta un diccionario con el
#   nombre, los créditos y el estado, y agrégalo con append().
#   La lista se modifica de verdad: no hace falta return.

# PASO 4: def sumar_creditos(lista, cuantas):
#   Recorre con un for y SUMA lista[i]["creditos"] cuando
#   lista[i]["aprobada"] sea True. Devuelve el total con return.

# PASO 5: def contar_materias(lista, cuantas):
#   Recorre y devuelve CUÁNTAS materias están aprobadas.

# ---------- EL PROGRAMA PRINCIPAL ----------

# PASO 6: declara el plan y su MATRIZ de seriación.
#         plan = ["Álgebra", "Cálculo I", "Estadística"]
#         seriacion = [[...], [...], [...]]
#         Renglón = materia; columna = la que DEPENDE de ella.
#         Pon 1 donde hay seriación y 0 donde no.

# PASO 7: crea el diccionario del alumno con su nombre y su
#         matrícula, pregunta cuántas materias va a registrar,
#         llama a ingresar_materias(alumno["aprobadas"], cuantas)
#         y muestra el reporte.

# PASO 8: recorre la MATRIZ con dos ciclos for ANIDADOS
#         (exterior = renglón, interior = columna) y muestra qué
#         materias abre cada una.

# CONCLUSIONES:
# 1) ¿Por qué es importante utilizar arreglos?
# 2) ¿Para qué sirven las cadenas y las matrices?
# Escribe aquí una redacción breve con tus observaciones sobre
# los resultados y lo aprendido al concluir la práctica.
