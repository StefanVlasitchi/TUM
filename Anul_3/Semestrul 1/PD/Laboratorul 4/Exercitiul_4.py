# Definiți o listă de valori întregi cu valori duplicate
valori = [1, 2, 3, 3, 4, 4, 5, 7]

# Utilizați funcția filter() pentru a selecta doar valorile distincte
valori_distincte = list(filter(lambda x: valori.count(x) == 1, valori))

# Afișați valorile distincte
print("Valorile distincte din listă:")
print(valori_distincte)
