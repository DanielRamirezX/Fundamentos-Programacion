# =============================================================
# PRÁCTICA 5 · SOLUCIÓN DOCENTE
# "Mundo-gráfico" · figuras impresas en consola
# Uso interno del profesor. No se enlaza desde la página.
# =============================================================

# RESPONSABILIDAD 1: mostrar el encabezado del programa.
def mostrar_titulo():
    print("--- Mundo-gráfico ---")


# RESPONSABILIDAD 2: imprimir una figura sencilla.
# Recibe varios parámetros y no devuelve un valor.
def dibujar_linea(largo, simbolo):
    for i in range(largo):
        print(simbolo, end="")
    print()


# RESPONSABILIDAD 3: imprimir el cuadrado.
# El for exterior controla las filas y el interior las columnas.
def dibujar_cuadrado(lado, simbolo):
    for fila in range(lado):
        for columna in range(lado):
            print(simbolo, end=" ")
        print()


# RESPONSABILIDAD 4: calcular y devolver un resultado.
def area_cuadrado(lado):
    return lado * lado


# RESPONSABILIDAD 5: coordinar el dibujo y el cálculo del reporte.
def mostrar_reporte(lado):
    print("\nCuadrado:")
    dibujar_cuadrado(lado, "*")
    print("Área:", area_cuadrado(lado))


def main():
    # main solo pide los datos y coordina las funciones.
    mostrar_titulo()
    lado = int(input("Escribe el lado del cuadrado: "))
    mostrar_reporte(lado)
    dibujar_linea(20, "-")


main()

# CONCLUSIÓN:
# El diseño modular divide un programa en funciones pequeñas.
# Así, dibujar, calcular y mostrar tienen tareas separadas.
# El código es más fácil de leer, corregir y reutilizar.
