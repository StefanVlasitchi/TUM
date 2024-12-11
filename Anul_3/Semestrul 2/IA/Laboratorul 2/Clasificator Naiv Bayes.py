# Importăm bibliotecile necesare
from sklearn.naive_bayes import GaussianNB
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
# Importăm biblioteca pentru evaluare
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score

# Generăm un set de date sintetic pentru scopuri de demonstrație
X, y = make_classification(n_samples=1000, n_features=20, n_classes=2, random_state=42)

# Împărțim setul de date în set de antrenare și set de testare
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Inițializăm clasificatorul Clasificator Naiv Bayes
naive_bayes_clf = GaussianNB()

# Antrenăm clasificatorul Clasificator Naiv Bayes pe setul de antrenare
naive_bayes_clf.fit(X_train, y_train)

# Facem predicții pe setul de testare
y_pred = naive_bayes_clf.predict(X_test)

# Calculăm acuratețea predicțiilor
accuracy = accuracy_score(y_test, y_pred)
print("Acuratețea clasificatorului Naiv Bayes:", accuracy)

# Calculăm alte metrici de evaluare
print("\nMatricea de Confuzie:")
print(confusion_matrix(y_test, y_pred))

print("\nRaportul de Clasificare:")
print(classification_report(y_test, y_pred))
