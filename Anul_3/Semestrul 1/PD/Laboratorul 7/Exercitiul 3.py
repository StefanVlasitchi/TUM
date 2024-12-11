from sympy import symbols, expand

# Definim simbolurile
x, y = symbols('x y')

# Definim expresia
expresie = (x + y)**6

# Calculăm forma extinsă
forma_extinsa = expand(expresie)

# Afișăm rezultatul
print(forma_extinsa)
