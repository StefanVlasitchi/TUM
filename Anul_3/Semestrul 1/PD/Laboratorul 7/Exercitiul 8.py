from sympy import symbols, Not, Or, And, satisfiable

# Definim simbolurile
x, y = symbols('x y')

# Definim expresia
expresie = And(Or(x, Not(y)), Or(y, Not(x)))

# Obținem primul model din generator
primul_model = next(satisfiable(expresie, all_models=True), None)

# Afișăm rezultatul
print(primul_model)
