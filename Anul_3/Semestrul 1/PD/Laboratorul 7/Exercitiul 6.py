from sympy import symbols, log, diff

# Definim simbolul
x = symbols('x')

# Definim funcția logaritmică
functie_log = log(x)

# Calculăm derivata în raport cu x
derivata = diff(functie_log, x)

# Afișăm rezultatul
print(derivata)
