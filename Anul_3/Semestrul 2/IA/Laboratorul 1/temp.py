print("Pasul 1")
import numpy as np
import pandas as pd
import seaborn as sns
from matplotlib import pyplot as plt

print("Pasul 2")
# Citirea fișierului CSV într-un DataFrame
population = pd.read_csv('World Population Growth.csv')

# Afișarea primelor câteva rânduri ale DataFrame-ului pentru a verifica corectitudinea importului
print(population.head())

print("Pasul 3")
# Afișarea primelor câteva rânduri ale DataFrame-ului
print(population.head())

# Informații despre DataFrame
print(population.info())

# Statistici de bază despre coloanele numerice
print(population.describe())
# Eliminarea virgulelor din coloana 'Number' și convertirea în numere în virgulă mobilă
population['Number'] = population['Number'].str.replace(',', '').astype(float)
population['Population'] = population['Population'].str.replace(',', '').astype(float)
population['Yearly Growth %'] = population['Yearly Growth %'].str.replace('%', '').astype(float)
print("Pasul 4")

# pairplot este utilizat pentru a crea o grilă de diagrame de dispersie (scatter plots) și histograme pentru a investiga relațiile între perechi de variabile într-un set de date.
# jointplot este utilizat pentru a vizualiza distribuția conjunctă a două variabile și densitatea lor marginală pe axele x și y.
# Crearea diagramă comună (jointplot) utilizând seaborn
sns.jointplot(x='Density (Pop/km2)', y='Year', data=population, kind='scatter')

# Afișarea diagramei
plt.show()

print("Pasul 5")
# Crearea diagramei 2D (jointplot) utilizând seaborn
sns.jointplot(x='Population', y='Number', data=population, kind='scatter')

# Afișarea diagramei
plt.show()

print("Pasul 6")
# Crearea diagramei pairplot utilizând seaborn
sns.pairplot(population)

# Afișarea diagramei
plt.show()

print("Pasul 7")

import seaborn as sns
import matplotlib.pyplot as plt

# Crearea modelului liniar grafic (lmplot) utilizând seaborn
sns.lmplot(x='Population', y='Yearly Growth %', data=population)

# Afișarea modelului liniar grafic
plt.show()

print("Pasul 8")
# X reprezintă caracteristicile numerice ale populației
X = population[['Year', 'Number']]

# y reprezintă coloana pe care doriți să o preziceți
y = population['Population']

print("Pasul 9")
from sklearn.model_selection import train_test_split

# Împărțirea datelor în seturi de antrenament și testare
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=101)

print("Pasul 10")
from sklearn.linear_model import LinearRegression

print("Pasul 11")
# Crearea unei instanțe a modelului LinearRegression
lm = LinearRegression()
print("Pasul 12")
# Antrenarea modelului lm pe datele de antrenament
lm.fit(X_train, y_train)
print("Pasul 13")
# Afisarea coeficientilor modelului
print("Coeficienții modelului sunt:", lm.coef_)

print("Pasul 14")
# Prezicerea valorilor pentru setul X_test de date
predictions = lm.predict(X_test)

print("Pasul 15")
import matplotlib.pyplot as plt

# Crearea unei diagrame de dispersie pentru valorile reale de test față de valorile prezise
plt.scatter(y_test, predictions)
plt.xlabel("Valori reale de test")
plt.ylabel("Valori prezise")
plt.title("Diagramă de dispersie a valorilor reale de test vs. valorile prezise")
plt.show()

print("Pasul 16")
from sklearn.metrics import mean_absolute_error, mean_squared_error

# Calcularea eroarei medie absolute (MAE)
mae = mean_absolute_error(y_test, predictions)

# Calcularea eroarei medie pătratice (MSE)
mse = mean_squared_error(y_test, predictions)

# Calcularea rădăcinii eroarei medie pătratice (RMSE)
rmse = np.sqrt(mse)

# Afișarea rezultatelor
print("Eroarea medie absolută (MAE):", mae)
print("Eroarea medie pătratică (MSE):", mse)
print("Rădăcina eroarei medie pătratice (RMSE):", rmse)

print("Pasul 17")
import seaborn as sns
import matplotlib.pyplot as plt

# Calcularea reziduurilor
residuals = y_test - predictions

# Trasarea histogramă a reziduurilor folosind seaborn
sns.histplot(residuals, kde=True)
plt.xlabel("Reziduuri")
plt.ylabel("Frecvență")
plt.title("Histogramă a reziduurilor")
plt.show()

print("Pasul 18")
# Calcularea mediei pentru toate coloanele, cu excepția coloanei 'Year'
average_data = population.drop(columns=['Year']).mean(axis=0)

# Afișarea datelor medii
print(average_data)
