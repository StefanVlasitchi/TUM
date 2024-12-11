
# Definiți dicționarul cu chei de tip șir și valori float
dictionar = {
    "cheie1": 3.14,
    "cheie2": 2.71,
    "cheie3": 1.618,
    "cheie4": 0.577
}

# Afișați doar cheile din dicționar
print("Cheile dicționarului:")
for cheie in dictionar.keys():
    print(cheie)

# Afișați tupluri formate din chei și valori
print("Tupluri formate din chei și valori:")
for cheie, valoare in dictionar.items():
    tuplu = (cheie, valoare)
    print(tuplu)
