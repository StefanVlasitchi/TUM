from sympy import symbols, Function, Eq, dsolve, bernoulli, dsolve

# Definim simbolul
x = symbols('x')

# Definim funcția necunoscută
f = Function('f')(x)

# Definim ecuația diferențială
ecuatie = x*f.diff(x) + f - f**2

# Rezolvăm ecuația diferențială direct
sol_direct = dsolve(ecuatie)

# Rezolvăm ecuația diferențială cu hint-ul 'Bernoulli'
sol_bernoulli = dsolve(ecuatie, hint='Bernoulli')

# Afișăm rezultatele
print("Soluție directă:", sol_direct)
print("Soluție cu hint='Bernoulli':", sol_bernoulli)
