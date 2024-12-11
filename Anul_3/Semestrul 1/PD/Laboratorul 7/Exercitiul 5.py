from sympy import symbols, limit, sin

# Definim simbolul
x = symbols('x')

# Definim expresia pentru limită
expresie_limita = sin(x) / x

# Calculăm limita când x se apropie de 0
rezultat_limita = limit(expresie_limita, x, 0)

# Afișăm rezultatul
print(rezultat_limita)
