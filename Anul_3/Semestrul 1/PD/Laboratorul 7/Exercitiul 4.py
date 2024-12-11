from sympy import symbols,  cos, sin, simplify

# Definim simbolul
x = symbols('x')

# Definim expresia trigonometrică
expresie_trig = sin(x)/cos(x)

expresie_simplificata = simplify(expresie_trig)

# Afișăm expresia simplificată
print(expresie_simplificata)
