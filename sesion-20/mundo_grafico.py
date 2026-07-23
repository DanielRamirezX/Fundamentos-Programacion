# =============================================================
#  PRÁCTICA 5 · Diseño modular, funciones y aplicaciones gráficas
#  "Mundo-gráfico" · aplicación modular de figuras geométricas
#  Fundamentos de Programación · UNITEC Atizapán · Ciclo 26-3
# =============================================================
#  Este archivo es un PLANO: trae los pasos y las firmas de las
#  funciones comentadas. Escribe TÚ el cuerpo de cada función.
#
#  Nota: C++ usa la librería graphics.h (Dev C++). En Python el
#  puente más cercano es turtle, que ya viene incluido y dibuja
#  círculos, rectángulos y líneas con posición, tamaño y color.
#
#  Los tres módulos son los mismos:
#    - MÓDULO DE FIGURAS   -> crea y dibuja las figuras
#    - OPERACIONES         -> mueve y cambia el tamaño
#    - MÓDULO PRINCIPAL    -> coordina e interactúa
# =============================================================

import turtle

# PASO 1: crea la tortuga y la pantalla
#         t = turtle.Turtle()
#         pantalla = turtle.Screen()

# ---------- MÓDULO DE FIGURAS (funciones con VARIOS parámetros) ----------

# PASO 2: def dibujar_circulo(x, y, radio, color):
#   Función con VARIOS parámetros. En el cuerpo:
#     t.penup(); t.goto(x, y); t.pendown()   # coloca sin dibujar
#     t.color(color)                         # color del trazo
#     t.circle(radio)                        # dibuja el círculo

# PASO 3: def dibujar_rectangulo(x, y, ancho, alto, color):
#   Coloca la tortuga en (x, y) y dibuja los 4 lados con un for
#   usando t.forward(...) y t.left(90).

# PASO 4: def dibujar_linea(x1, y1, x2, y2, color):
#   t.penup(); t.goto(x1, y1); t.pendown(); t.goto(x2, y2)

# ---------- OPERACIONES (DEVOLUCIÓN del resultado con return) ----------

# PASO 5: def mover_derecha(x, paso):
#   Recibe la posición y el paso y DEVUELVE la nueva posición:
#       return x + paso

# PASO 6: def cambiar_tamano(radio, cuanto):
#       return radio + cuanto

# ---------- MÓDULO PRINCIPAL (coordina las piezas) ----------

# PASO 7: dibuja UNA escena llamando a TUS funciones del módulo
#         de figuras (posiciones, tamaños y colores a tu gusto).

# PASO 8: ANIMACIÓN BÁSICA. Un ciclo que:
#         1) borra           -> t.clear()
#         2) dibuja el círculo en x
#         3) mueve la figura -> x = mover_derecha(x, 5)

# PASO 9: mantén la ventana abierta -> pantalla.mainloop()

# CONCLUSIONES:
# ¿Para qué sirve el diseño modular en la programación?
# Escribe aquí una redacción breve con tus observaciones sobre
# los resultados y los conocimientos adquiridos al concluir la
# práctica.
