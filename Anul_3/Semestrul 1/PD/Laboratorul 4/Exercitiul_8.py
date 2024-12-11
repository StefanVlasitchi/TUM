def calcul_medie(nota1=4, nota2=4, nota3=4):
    """
    Calculează media a trei note.

    Args:
    nota1 (float): Prima notă.
    nota2 (float): A doua notă.
    nota3 (float): A treia notă.

    Returns:
    float: Media celor trei note.
    """
    media = (nota1 + nota2 + nota3) / 3
    return media

# Exemplu de utilizare a funcției cu diferite combinații de argumente
medie1 = calcul_medie(7, 8, 9)
print(f"Media notelor: {medie1}")

medie2 = calcul_medie(6, 7)
print(f"Media notelor: {medie2}")

medie3 = calcul_medie(nota1=5, nota3=6)
print(f"Media notelor: {medie3}")

medie4 = calcul_medie()
print(f"Media notelor: {medie4}")
