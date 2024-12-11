# Definiți o listă de funcții lambda
functii_lambda = [
    lambda s, c=None: s[1] if len(s) > 1 else None,  # Returnează al doilea caracter din șir
    lambda s, c=None: s.upper(),  # Transformă șirul în litere majuscule
    lambda s, c: s.find(c)  # Returnează poziția caracterului dat în șir
]

# Exemplu de utilizare a funcțiilor
text = "Divide et Impera "
caracter_cautat = "e"

for functie in functii_lambda:
    if functie.__name__ == "<lambda>":
        print("Apelul unei funcții lambda:")
    else:
        print(f"Apelul funcției '{functie.__name__}':")

    print(f"Rezultat: {functie(text, caracter_cautat)}")

    print()
