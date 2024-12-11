from sympy import symbols, Eq, solve

# Definim simbolurile
x, y = symbols('x y')

# Definim ecuațiile
ecuatie1 = Eq(2*x + 3*y, 5)
ecuatie2 = Eq(4*x - 3*y, -4)

# Rezolvăm sistemul de ecuații
sol = solve((ecuatie1, ecuatie2), (x, y))

# Afișăm rezultatul
print(sol)
