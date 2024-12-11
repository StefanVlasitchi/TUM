def suma_primelor_N_naturale(N):
    if N <= 0:
        return 0
    else:
        return N + suma_primelor_N_naturale(N - 1)

# Exemplu de utilizare a funcției
N = 20
rezultat = suma_primelor_N_naturale(N)
print(f"Suma primelor {N} numere naturale este: {rezultat}")
