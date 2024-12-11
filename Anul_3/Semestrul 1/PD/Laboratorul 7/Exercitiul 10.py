from scipy.integrate import quad
import numpy as np

# Definim funcția integrată
def f(x):
    return np.cos(2 * np.pi * x)

# Aplicăm funcția quad pentru a rezolva integrala
rezultat, eroare = quad(f, 0, 1)

# Afișăm rezultatele
print("Rezultatul integrală:", rezultat)
print("Eroarea estimată:", eroare)
