import matplotlib
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Citirea fișierului CSV într-un DataFrame
customers = pd.read_csv('Ecommerce Customers.csv')

# Afișarea primelor câteva rânduri din DataFrame pentru a verifica încărcarea corectă a datelor
# print(customers.head())

# Afișarea primelor câteva rânduri din DataFrame
print("Primele câteva rânduri din DataFrame:")
print(customers.head())

# Informații despre DataFrame
print("\nInformații despre DataFrame:")
print(customers.info())

# Statistici de bază despre coloanele numerice din DataFrame
print("\nStatistici de bază despre coloanele numerice:")
print(customers.describe())

# Importarea Seaborn și crearea unei diagrame comune (jointplot) pentru a compara coloanele "Time on Website" și "Yearly Amount Spent"
sns.jointplot(x='Time on Website', y='Yearly Amount Spent', data=customers)
plt.show()

# Crearea unei diagrame comune (jointplot) pentru a compara coloanele "Time on App" și "Yearly Amount Spent"
sns.jointplot(x='Time on App', y='Yearly Amount Spent', data=customers)
plt.show()

# Crearea unei diagrame comune (jointplot) pentru a compara coloanele "Time on App" și "Length of Membership"
sns.jointplot(x='Time on App', y='Length of Membership', data=customers, kind='hex')
plt.show()

# Crearea unui pairplot pentru a explora relațiile între toate combinațiile de coloane numerice
sns.pairplot(customers)
plt.show()

# Crearea unui model liniar grafic între coloanele "Yearly Amount Spent" și "Length of Membership"
sns.lmplot(x='Length of Membership', y='Yearly Amount Spent', data=customers)
plt.xlabel('Length of Membership')
plt.ylabel('Yearly Amount Spent')
plt.title('Linear Model Plot of Yearly Amount Spent vs Length of Membership')
plt.show()

# Setați variabila X pentru caracteristicile numerice
X = customers[['Avg. Session Length', 'Time on App', 'Time on Website', 'Length of Membership']]

# Setați variabila y pentru coloana "Yearly Amount Spent"
y = customers['Yearly Amount Spent']

from sklearn.model_selection import train_test_split

# Împărțiți datele în seturi de antrenament și de testare
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=101)

from sklearn.linear_model import LinearRegression

# Crearea unei instanțe a modelului LinearRegression
lm = LinearRegression()

# Antrenarea modelului pe datele de antrenament
lm.fit(X_train, y_train)

# Imprimarea coeficienților modelului
print('Coeficienții modelului sunt:', lm.coef_)

# Prezicerea valorilor pentru setul de test
predictions = lm.predict(X_test)

# Crearea unei diagrame de dispersie pentru valorile reale de test vs. valorile prezise
plt.scatter(y_test, predictions)
plt.xlabel('Valori reale de test')
plt.ylabel('Valori prezise')
plt.title('Diagramă de dispersie a valorilor reale de test vs. valorile prezise')
plt.show()

from sklearn import metrics

# Calcularea erorii medie absolute (MAE)
mae = metrics.mean_absolute_error(y_test, predictions)

# Calcularea erorii medie pătratice (MSE)
mse = metrics.mean_squared_error(y_test, predictions)

# Calcularea erorii medie pătratice rădăcinată (RMSE)
rmse = np.sqrt(mse)

print('MAE:', mae)
print('MSE:', mse)
print('RMSE:', rmse)

# Calcularea reziduurilor
residuals = y_test - predictions

# Trasarea histogramă a reziduurilor
sns.histplot(residuals, kde=True)
plt.xlabel('Reziduuri')
plt.ylabel('Frecvență')
plt.title('Histograma reziduurilor')
plt.show()

# Recrearea setului de date cu valorile date
new_data = {'Avg. Session Length': [25.981550],
            'Time on App': [38.590159],
            'Time on Website': [0.190405],
            'Length of Membership': [61.279097]}

# Transformarea setului de date într-un DataFrame
new_customer = pd.DataFrame(new_data)

# Prezicerea sumei cheltuite anual pentru noul set de date folosind modelul nostru antrenat
predicted_spending = lm.predict(new_customer)

print('Suma cheltuită anual (Yearly Amount Spent) pentru noul set de date este:', predicted_spending[0])
