import random

# Generați un număr aleator între 0 și 10000 reprezentând secunde
numar_secunde = random.randint(0, 10000)

# Calculați orele, minutele și secundele
ore = numar_secunde // 3600
minute = (numar_secunde % 3600) // 60
secunde = numar_secunde % 60

# Formatarea rezultatului sub forma hh:mm:ss
timp_formatat = f"{ore:02d}:{minute:02d}:{secunde:02d}"
print(f"Numărul de secunde: {numar_secunde}")
print(f"Reprezentarea în format hh:mm:ss: {timp_formatat}")
