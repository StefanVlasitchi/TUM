from functools import reduce


def numar_aparitii_caracter(șir, caracter):
    # Utilizați funcția lambda pentru a număra aparițiile caracterului în șir
    numara_aparitii = lambda x, c: x + (c == caracter)

    # Folosiți funcția reduce pentru a aplica funcția lambda la fiecare caracter din șir
    numar = reduce(numara_aparitii, șir, 0)

    return numar


# Exemplu de utilizare a funcției
text = "Aceasta este o propozitie de exemplu: Ana are mere."
caracter_cautat = "e"
rezultat = numar_aparitii_caracter(text, caracter_cautat)
print(f"Caracterul '{caracter_cautat}' apare de {rezultat} ori în șirul dat.")
