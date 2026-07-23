# =============================================================
#  PRÁCTICA 5 · Diseño modular, funciones y aplicaciones gráficas
#  "Mundo-gráfico" · SOLUCIÓN DOCENTE (clave de referencia)
#  Fundamentos de Programación · UNITEC Atizapán · Ciclo 26-3
# -------------------------------------------------------------
#  ⚠ USO INTERNO DEL PROFESOR — NO DISTRIBUIR A LOS ALUMNOS.
#     Versión RESUELTA del plano mundo_grafico.py (puente turtle).
# =============================================================
import turtle
import time

# Pantalla y tortuga (interfaz base)
pantalla = turtle.Screen()
pantalla.title("Mundo-gráfico")
pantalla.setup(600, 400)
pantalla.tracer(0)            # nosotros controlamos cada cuadro
t = turtle.Turtle()
t.hideturtle()
t.speed(0)


# ============ MÓDULO DE OPERACIONES CON FIGURAS ============
# Crear / dibujar: funciones con VARIOS parámetros.

def dibujar_circulo(x, y, radio, color):
    t.penup()
    t.goto(x, y - radio)     # baja al borde para centrar en (x, y)
    t.pendown()
    t.color(color)
    t.circle(radio)


def dibujar_rectangulo(x, y, ancho, alto, color):
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.setheading(0)          # orientación estable en cada cuadro
    t.color(color)
    for _ in range(2):
        t.forward(ancho); t.right(90)
        t.forward(alto);  t.right(90)


def dibujar_linea(x1, y1, x2, y2, color):
    t.penup()
    t.goto(x1, y1)
    t.pendown()
    t.color(color)
    t.goto(x2, y2)


# Operaciones que DEVUELVEN el resultado (return).

def mover_derecha(x, paso):
    return x + paso


def cambiar_tamano(radio, cuanto):
    nuevo = radio + cuanto
    if nuevo < 5:
        nuevo = 5
    return nuevo


# ================== MÓDULO DE INTERFAZ ====================
# Compone la escena; el círculo es el que se mueve y crece.

def dibujar_escena(x_circulo, radio_circulo):
    dibujar_rectangulo(-40, 90, 200, 120, "red")
    dibujar_linea(-240, -120, 240, -120, "orange")
    dibujar_circulo(x_circulo, 0, radio_circulo, "green")


# ================== MÓDULO PRINCIPAL ======================
# main() no dibuja ni calcula por su cuenta: coordina las piezas.

def main():
    x = -220          # posición inicial del círculo
    radio = 40        # tamaño inicial del círculo

    # 1) Escena estática inicial
    dibujar_escena(x, radio)
    pantalla.update()
    time.sleep(1.2)

    # 2) Animación básica: mover y agrandar el círculo
    for i in range(70):
        t.clear()
        dibujar_escena(x, radio)
        pantalla.update()
        time.sleep(0.03)
        x = mover_derecha(x, 5)          # operación: mover
        if i % 20 == 0:                  # cada 20 cuadros...
            radio = cambiar_tamano(radio, 8)  # ...operación: agrandar

    pantalla.mainloop()


main()

# =============================================================
# CONCLUSIONES — ¿Para qué sirve el diseño modular?
#
# El diseño modular parte el problema en funciones pequeñas, cada
# una con una responsabilidad. Dibujar cada figura, mover y cambiar
# de tamaño son funciones independientes; main() sólo las coordina.
# El programa queda más legible, reutilizable y fácil de mantener,
# y separa la lógica (return) de la interfaz (dibujar).
# =============================================================
