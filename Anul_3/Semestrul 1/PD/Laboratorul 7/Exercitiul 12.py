import numpy as np
from scipy.optimize import fmin
import matplotlib.pyplot as plt

# Definirea funcției de minimizat
def f(x):
    return np.cos(x) - 3 * np.exp(-(x - 0.2)**2)

# Apelarea funcției de optimizare pentru x0 = 1.0
x_min_1 = fmin(f, 1.0, disp=False)
y_min_1 = f(x_min_1)

# Apelarea funcției de optimizare pentru x0 = 2.0
x_min_2 = fmin(f, 2.0, disp=False)
y_min_2 = f(x_min_2)

# Apelarea funcției de optimizare pentru x0 = 0.0
x_min_0 = fmin(f, 0.0, disp=False)
y_min_0 = f(x_min_0)

# Valoarea funcției pentru x = 1 și x = 2
y_at_x1 = f(1)
y_at_x2 = f(2)
y_at_x0 = f(0)

# Afișarea rezultatelor
print("Valoarea minimă a lui x pentru x0 = 1.0:", x_min_1)
print("Valoarea funcției pentru x = 1:", y_at_x1)

print("Valoarea minimă a lui x pentru x0 = 2.0:", x_min_2)
print("Valoarea funcției pentru x = 2:", y_at_x2)

print("Valoarea minimă a lui x pentru x0 = 0.0:", x_min_0)
print("Valoarea funcției pentru x = 0:", y_at_x0)

# Crearea unui grafic pentru funcția dată
x_values = np.linspace(-2, 4, 100)
y_values = f(x_values)

plt.plot(x_values, y_values, label='f(x)')

plt.scatter(x_min_0, y_min_0, color='green', marker='^', label='Minimizare pentru x0=0.0')
plt.scatter(x_min_1, y_min_1, color='red', marker='^', label='Minimizare pentru x0=1.0')
plt.scatter(x_min_2, y_min_2, color='blue', marker='^', label='Minimizare pentru x0=2.0')
plt.scatter(0, y_at_x0, color='green', marker='o', label='f(0)')
plt.scatter(1, y_at_x1, color='red', marker='o', label='f(1)')
plt.scatter(2, y_at_x2, color='blue', marker='o', label='f(2)')
plt.title('Graficul funcției și punctele de minimizare')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()

# Adăugarea unui grid
plt.grid(True)

plt.show()
