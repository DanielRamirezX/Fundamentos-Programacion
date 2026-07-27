# =============================================================
#  PRÁCTICA 6 · Tipos de datos estructurados
#  "UniData" · créditos aprobados y materias seriadas
#  Fundamentos de Programación · UNITEC · Ciclo 26-3
# =============================================================
#  Este archivo es un PLANO: trae los pasos comentados.
#  Escribe TÚ el código debajo de cada PASO.
#
#  Nota: C++ agrupa campos con struct. En Python el puente más
#  cercano es un diccionario: mismos campos, misma idea. El
#  arreglo es una lista y la matriz, una lista de listas.
#
#  Las tres piezas que pide la práctica:
#    ARREGLO -> las materias aprobadas del estudiante
#    CADENA  -> los nombres de materia y de estudiante
#    MATRIZ  -> el plan de estudios (3 x 3)
# =============================================================

PLAN = 3   # cuántas materias tiene el plan

# ---------- LAS DOS ESTRUCTURAS (indicación 1) ----------

# PASO 1: define cómo se ve una MATERIA. En Python, un
#         diccionario con tres campos:
#           {"nombre": "", "creditos": 0, "aprobado": False}

# PASO 2: define cómo se ve un ESTUDIANTE:
#           {"nombre": "", "matricula": "", "aprobadas": []}
#         El campo "aprobadas" es el ARREGLO (lista) de materias.

# ---------- LAS TRES FUNCIONES (indicaciones 2 y 3) ----------

# PASO 3: def ingresar_materias(estudiante):
#   Pregunta cuántas materias aprobó y, con un ciclo for, agrega
#   a estudiante["aprobadas"] un diccionario por cada materia
#   (nombre, créditos y estado). Usa append().

# PASO 4: def sumar_creditos(estudiante):
#   Recorre la lista con un for y SUMA los créditos de las
#   materias aprobadas. Devuelve el total con return.

# PASO 5: def contar_materias(estudiante):
#   Recorre la lista y devuelve CUÁNTAS materias tiene
#   registradas el estudiante.

# ---------- EL PROGRAMA PRINCIPAL ----------

# PASO 6: declara el plan y su MATRIZ de seriación.
#         plan = ["Álgebra", "Cálculo I", "Estadística"]
#         seriacion = [[...], [...], [...]]
#         Renglón = materia; columna = la que DEPENDE de ella.
#         Pon 1 donde hay seriación y 0 donde no.

# PASO 7: crea un estudiante, pide su nombre y su matrícula,
#         llama a ingresar_materias(...) y muestra el reporte
#         usando contar_materias y sumar_creditos.

# PASO 8: recorre la MATRIZ con dos ciclos for ANIDADOS
#         (exterior = renglón, interior = columna) y muestra qué
#         materias abre cada una.

# CONCLUSIONES:
# 1) ¿Por qué es importante utilizar arreglos?
# 2) ¿Para qué sirven las cadenas y las matrices?
# Escribe aquí una redacción breve con tus observaciones sobre
# los resultados y lo aprendido al concluir la práctica.
