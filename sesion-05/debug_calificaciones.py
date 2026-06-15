"""
========================================================================
  REPORTE DE CALIFICACIONES  ·  Fundamentos de Programación · UNITEC
========================================================================

  Este programa DEBERÍA:
    1. Pedir el nombre de un alumno y cuántas materias cursó.
    2. Pedir la calificación de cada materia (de 0 a 100) y validarla.
    3. Calcular el promedio, encontrar la calificación más alta,
       asignar una letra (A/B/C/D/F) y decir si aprobó o reprobó.
    4. Mostrar un reporte final.

  ...pero NO funciona. Tiene VARIOS errores escondidos:
    - errores de sintaxis (el código ni siquiera corre)
    - errores de ejecución (revienta a la mitad)
    - errores de lógica (corre, pero da resultados equivocados)

  TU MISIÓN
  ---------
  Usa el DEBUGGER de VS Code (o PyCharm) para encontrarlos y corregirlos,
  uno por uno, hasta que el programa funcione de principio a fin.

  PISTAS
  ------
  * Pon un breakpoint en la primera línea del programa principal y avanza
    paso a paso (Step Over) observando el panel de VARIABLES.
  * Lee cada mensaje de error de abajo hacia arriba: la última línea te
    dice QUÉ pasó; las de arriba, DÓNDE.
  * Hay 7 errores. Cuando los siete estén corregidos, el reporte se
    imprime completo y con números correctos.

  Ejemplo de una corrida ya correcta:
    Nombre del alumno: Ana
    ¿Cuántas materias cursó? 3
    Calificacion de la materia 1: 90
    Calificacion de la materia 2: 80
    Calificacion de la materia 3: 70
    --------------------------------
    Alumno:   Ana
    Promedio: 80.0
    Mejor:    90
    Letra:    B
    Estado:   APROBADO
========================================================================
"""

# ===== CONSTANTES =====
CALIF_MINIMA = 0
CALIF_MAXIMA = 100
CALIF_APROBATORIA = 70


# ===== FUNCIONES =====

def validar_calificacion(calif)
    """Devuelve True si la calificación está entre 0 y 100."""
    if calif >= CALIF_MINIMA and calif <= CALIF_MAXIMA:
        return True
    else:
        return False


def calcular_promedio(calificaciones):
    """Suma todas las calificaciones y las divide entre cuántas hay."""
    suma = 0
    for c in calificaciones:
    suma = suma + c
    promedio = suma / len(calificaciones)
    return Promedio


def encontrar_mejor(calificaciones):
    """Devuelve la calificación más alta de la lista."""
    mejor = 0
    for c in calificaciones:
        if c > mejor:
            mejor = c
    return mejor


def obtener_letra(promedio):
    """Convierte el promedio numérico en una letra."""
    if promedio >= 90:
        return "A"
    elif promedio >= 80:
        return "B"
    elif promedio >= 70:
        return "C"
    elif promedio > 60:
        return "D"
    else:
        return "F"


def esta_aprobado(promedio):
    """Indica si aprobó según la calificación mínima aprobatoria."""
    if promedio >= CALIF_APROBATORIA:
        return "APROBADO"


# ===== PROGRAMA PRINCIPAL =====

if __name__ == "__main__":

    print("=== REPORTE DE CALIFICACIONES ===")
    nombre = input("Nombre del alumno: ")
    num_materias = int(input("¿Cuántas materias cursó? "))
    
    calificaciones = []
    for i in range(num_materias):
        calif = input(f"Calificacion de la materia {i + 1}: ")
        if validar_calificacion(calif):
            calificaciones.append(calif)
        else:
            print("  -> Esa calificación no es válida (debe ser de 0 a 100)")
    
    promedio = calcular_promedio(calificaciones)
    mejor = encontrar_mejor(calificaciones)
    letra = obtener_letra(promedio)
    estado = esta_aprobado(promedio)
    
    print("--------------------------------")
    print("Alumno:   " + nombre)
    print("Promedio: " + promedio)
    print("Mejor:    " + str(mejor))
    print("Letra:    " + letra)
    print("Estado:   " + estado)