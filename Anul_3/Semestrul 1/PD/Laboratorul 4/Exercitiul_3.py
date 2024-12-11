# Definiți două obiecte de tip float
numar1 = 3.14
numar2 = 2.71

# Definiți funcții lambda pentru suma și diferența
suma = lambda x, y: x + y
diferenta = lambda x, y: x - y

# Lista cu funcțiile lambda
functii = [suma, diferenta]

# Apelați funcțiile pentru diverse tipuri de date folosind funcția map()
tipuri_de_date = [5.0, 1.1, 4.2, -0.9]

for functie in functii:
    print(f"Funcția: {functie.__name__}")
    for valoare in tipuri_de_date:
        rezultate = map(functie, [numar1, numar2], [valoare, valoare])
        print(list(rezultate))
    print()
