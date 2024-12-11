from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split

# Generăm setul de date sintetic
X, y= make_classification(n_samples=10, n_features=5, n_classes=2, random_state=42)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)


# Afișăm setul de date
print("Setul de date X:")
print(X)
print("\nEtichetele y:")
print(y)
print("\nEtichetele x_test")
print(X_test)
print("\nEtichetele y_test")
print(y_test)
print("\nEtichetele x_train")
print(X_train)
print("\nEtichetele y_train")
print(y_train)