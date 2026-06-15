# =============================================================================
#  GENERADOR DE CONTRASEÑAS SEGURAS  ·  Sesión 12 · "Lo finito y lo cíclico"
#  Fundamentos de Programación · UNITEC Atizapán · Ciclo 26-3
#  Profesor: Carlos Daniel Vaca Ramírez
# -----------------------------------------------------------------------------
#  El plano. No borres los comentarios "# PASO N": son tu guía.
#  Debajo de cada paso hay un espacio en blanco; ahí escribes TU código.
#
#  En la sesión 11 repetías HASTA QUE algo pasara (while). Hoy repites un
#  número EXACTO de veces (for + range). Una contraseña de longitud N es eso:
#  N decisiones al azar, una por cada vuelta del ciclo. La armarás carácter
#  por carácter dentro de un "for" de longitud finita.
#
#  Herramientas de hoy: for + range(), acumuladores, y la librería random.
#  Corre el programa después de cada paso para asegurarte de que no truena.
# =============================================================================


# PASO 1: Importa la librería "random" (la del azar) y la librería "string".
#         "string" ya trae listos los conjuntos de caracteres, no los teclees
#         a mano y arriesgues una errata.
#         Pista:  import random   /   import string

# ← aquí escribes tu código


# PASO 2: Crea cuatro CONSTANTES con los conjuntos de caracteres.
#         Usa lo que regala "string" para no equivocarte:
#           MINUSCULAS = string.ascii_lowercase   # "abcdefghijklmnopqrstuvwxyz"
#           MAYUSCULAS = string.ascii_uppercase   # "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#           DIGITOS    = string.digits            # "0123456789"
#           SIMBOLOS   = "!#$%&*+-?@"             # elige los que quieras

# ← aquí escribes tu código


# PASO 3: Define los PARÁMETROS de la contraseña como variables.
#         Estos son los "botones" que el usuario podrá configurar:
#           longitud         = 12      # ¿cuántos caracteres tendrá?
#           incluir_mayus    = True    # ¿metemos MAYÚSCULAS?
#           incluir_digitos  = True    # ¿metemos números?
#           incluir_simbolos = True    # ¿metemos símbolos?

# ← aquí escribes tu código


# PASO 4 (validación): antes de generar, asegúrate de que la longitud sea
#         sensata. Una contraseña de menos de 4 caracteres no protege nada.
#         Si longitud < 4, avisa con un print y NO sigas (puedes usar exit()
#         o envolver el resto en un if):
#           if longitud < 4:
#               print("La longitud mínima recomendada es 4.")
#               exit()

# ← aquí escribes tu código


# PASO 5: Construye el "alfabeto" disponible juntando los conjuntos elegidos.
#         Empieza SIEMPRE con minúsculas y ve SUMANDO (acumulando) los demás
#         solo si su parámetro es True. Las cadenas se suman con "+".
#           alfabeto = MINUSCULAS
#           if incluir_mayus:
#               alfabeto = alfabeto + MAYUSCULAS
#           if incluir_digitos:
#               ...
#           if incluir_simbolos:
#               ...

# ← aquí escribes tu código


# PASO 6: Crea un ACUMULADOR de texto vacío donde irás pegando cada carácter.
#         (igual que un acumulador de suma, pero con cadenas)
#           contrasena = ""

# ← aquí escribes tu código


# PASO 7: El corazón del programa. Un ciclo "for" que se repite "longitud" veces.
#         En CADA vuelta:
#           1. elige un carácter al azar del alfabeto -> random.choice(alfabeto)
#           2. pégalo al acumulador  -> contrasena = contrasena + caracter
#         Usa range(longitud) para repetir un número FINITO de veces:
#           for i in range(longitud):
#               caracter = random.choice(alfabeto)
#               contrasena = contrasena + caracter

# ← aquí escribes tu código


# PASO 8: Muestra el resultado en pantalla con print().
#         Imprime también la longitud real para verificar:
#           print("Tu contraseña es:", contrasena)
#           print("Longitud:", len(contrasena))

# ← aquí escribes tu código


# =============================================================================
#  EJEMPLO DE UNA CORRIDA (así debe verse tu programa terminado)
# -----------------------------------------------------------------------------
#   $ python generador_contrasenas.py
#   Tu contraseña es: gT7#mQ2x!pLa
#   Longitud: 12
#
#   $ python generador_contrasenas.py   (con incluir_simbolos = False)
#   Tu contraseña es: gT7mQ2xpLaUe
#   Longitud: 12
#
#   (cada vez que lo corres sale una distinta: ese es el poder de random)
# =============================================================================

# =============================================================================
#  RETOS EXTRA (suman puntos de actividad)
# -----------------------------------------------------------------------------
#  RETO 1 · Pídele al usuario la longitud y las opciones con input(). Recuerda
#           convertir la longitud con int() y traducir "s"/"n" a True/False.
#
#  RETO 2 · Genera VARIAS contraseñas de un jalón. Envuelve la generación en
#           otro "for" que se repita N veces y muestra una lista numerada:
#               for n in range(1, cuantas + 1):
#                   ...genera una contraseña...
#                   print(n, "->", contrasena)
#
#  RETO 3 · Mide la FUERZA de la contraseña. Cuenta con contadores cuántos
#           caracteres son minúsculas, mayúsculas, dígitos y símbolos; recorre
#           la contraseña con un "for" sobre sus letras:
#               minus = mayus = nums = simb = 0
#               for c in contrasena:
#                   if c in MINUSCULAS: minus = minus + 1
#                   elif c in MAYUSCULAS: mayus = mayus + 1
#                   ...
#           Si las cuatro familias aparecen y la longitud >= 12, dila "FUERTE".
#
#  RETO 4 · Garantiza al menos un carácter de cada familia elegida. Si por
#           mala suerte salió "todo minúsculas", vuelve a generarla. Aquí SÍ
#           encaja un while: repetir HASTA QUE cumpla la regla (la herencia
#           de la sesión 11).
#
#  RETO 5 · math en acción. Importa math y estima el espacio de combinaciones:
#               total = len(alfabeto) ** longitud
#               bits  = math.log2(total)
#           Imprime cuántos "bits de entropía" tiene tu contraseña. Más bits,
#           más difícil de adivinar a fuerza bruta.
# =============================================================================
