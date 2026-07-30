for L in range(1, 11):
    print(f"--- Tabla del {L} ---")
    for X in range(1, 11):
        resultado = L * X
        print(f"{L} x {X:2} = {resultado:3}")
    print()