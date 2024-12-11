def concateneaza_stringuri(*args):
    """
    Concatenează o listă de șiruri.

    Args:
    *args: Argumente variabile reprezentând șiruri.

    Returns:
    Șirul rezultat din concatenarea șirurilor primite ca argumente.
    """
    rezultat = ""
    for s in args:
        rezultat += s
    return rezultat


# Exemplu de utilizare a funcției
string1 = "Veni, "
string2 = "Vedi,"
string3 = " Vici!"
rezultat = concateneaza_stringuri(string1, string2, string3)
print(rezultat)
