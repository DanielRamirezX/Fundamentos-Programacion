# =============================================================
#  GESTOR DE TAREAS PENDIENTES  ·  plano para construir
#  Fundamentos de Programacion · UNITEC Atizapan · Ciclo 26-3
#  Profesor: Carlos Daniel Vaca Ramirez
# -------------------------------------------------------------
#  Sesion 21 · Buscar y ordenar (listas avanzadas)
#
#  COMO USAR ESTE ARCHIVO
#  ----------------------
#  Este NO es un programa terminado: es un plano. Cada paso
#  empieza con "# PASO N" y debajo hay un espacio en blanco
#  donde TU escribes tu propio codigo. No borres los comentarios.
#  Sigue el orden y corre el programa despues de cada paso para
#  asegurarte de que no truena antes de continuar.
#
#  La meta: un gestor de tareas en consola con un menu de 5
#  opciones, hecho con UNA lista y los metodos que vimos hoy
#  (append, index, remove/pop, count, sort).
#  Por ahora, cada tarea es una simple CADENA de texto.
# =============================================================


# PASO 1: Crea la lista que guardara tus tareas.
#   Empieza vacia. Sugerencia de nombre: tareas = []
#   (es la unica "memoria" del programa: todo vive aqui dentro)

# ← aqui escribes tu codigo


# PASO 2: Define una funcion mostrar_menu() que imprima
#   las 5 opciones del gestor. Algo como:
#     ===== GESTOR DE TAREAS =====
#       1) Agregar tarea
#       2) Mostrar tareas
#       3) Completar tarea
#       4) Eliminar tarea
#       5) Salir

# ← aqui escribes tu codigo


# PASO 3: Define agregar_tarea(tareas).
#   Pide al usuario el texto de la tarea con input(...)
#   y agregala al FINAL de la lista con tareas.append(...).
#   Avisa que se guardo correctamente.

# ← aqui escribes tu codigo


# PASO 4: Define mostrar_tareas(tareas).
#   Si la lista esta vacia (len(tareas) == 0), avisa que no
#   hay pendientes. Si no, recorrela con un for y enumerate
#   para imprimir cada tarea con su numero:
#     for indice, tarea in enumerate(tareas, start=1):
#         print(f"{indice}. {tarea}")

# ← aqui escribes tu codigo


# PASO 5: Define completar_tarea(tareas).
#   Muestra las tareas, pide el texto EXACTO de la que se
#   completo y usa la BUSQUEDA con el metodo index() para
#   encontrar su posicion. Quitala con pop(posicion).
#   Recuerda: si el texto no esta en la lista, index() lanza
#   un ValueError. Protege la busqueda con un if ... in tareas
#   antes de llamar a index().

# ← aqui escribes tu codigo


# PASO 6: Define eliminar_tarea(tareas).
#   Parecida a la anterior, pero aqui simplemente se descarta.
#   Usa tareas.remove(texto) si la tarea existe; si no,
#   avisa que no se encontro. (remove tambien lanza ValueError
#   cuando el elemento no esta: valida antes con "in".)

# ← aqui escribes tu codigo


# PASO 7: EL CICLO PRINCIPAL.
#   Dentro de un while True:
#     - llama a mostrar_menu()
#     - pide la opcion con input("Elige una opcion: ")
#     - segun la opcion ("1".."5") llama a la funcion que toca
#     - con "5" despidete e interrumpe el ciclo con break
#     - con cualquier otra cosa, avisa "Opcion no valida"

# ← aqui escribes tu codigo


# =============================================================
#  EJEMPLO DE CORRIDA (asi se debe ver tu gestor terminado)
# -------------------------------------------------------------
#  ===== GESTOR DE TAREAS =====
#    1) Agregar tarea
#    2) Mostrar tareas
#    3) Completar tarea
#    4) Eliminar tarea
#    5) Salir
#  Elige una opcion: 1
#  Escribe la tarea: Estudiar listas
#  Tarea agregada: "Estudiar listas"
#
#  Elige una opcion: 1
#  Escribe la tarea: Subir practica a GitHub
#  Tarea agregada: "Subir practica a GitHub"
#
#  Elige una opcion: 2
#  Tienes 2 tarea(s) pendiente(s):
#    1. Estudiar listas
#    2. Subir practica a GitHub
#
#  Elige una opcion: 3
#  Que tarea completaste? Estudiar listas
#  Hecho! "Estudiar listas" sale de la lista.
#
#  Elige una opcion: 5
#  Te quedan 1 pendiente(s). Hasta la proxima!
# =============================================================


# =============================================================
#  RETOS EXTRA (suman puntos de actividad)
# -------------------------------------------------------------
#  RETO 1 · Marcar como completada SIN borrar.
#     En vez de quitar la tarea, anteponle un simbolo "[x] "
#     usando index() para localizarla y reasignar:
#         pos = tareas.index(texto)
#         tareas[pos] = "[x] " + tareas[pos]
#     Asi la tarea sigue visible pero se ve "tachada".
#
#  RETO 2 · Contador de pendientes.
#     Al mostrar, cuenta cuantas NO empiezan con "[x] " y di
#     "Te faltan N pendientes". Puedes apoyarte en count() para
#     contar repeticiones exactas, o en un for con un acumulador.
#
#  RETO 3 · Ordenar alfabeticamente.
#     Agrega una opcion para ordenar la lista con tareas.sort()
#     (orden A-Z) y otra para invertir el orden con
#     tareas.reverse(). Observa que ambos metodos MODIFICAN la
#     lista en el sitio y devuelven None.
#
#  RETO 4 · A prueba de errores.
#     Usa "in" antes de cada index()/remove() para que el
#     programa nunca truene cuando el usuario escriba una tarea
#     que no existe. Un buen gestor jamas revienta.
# =============================================================
