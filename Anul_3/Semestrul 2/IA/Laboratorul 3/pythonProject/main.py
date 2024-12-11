from sklearn.datasets import load_iris
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score
import matplotlib.pyplot as plt

# Încărcăm setul de date Iris
iris = load_iris()
X = iris.data

# Implementăm algoritmul k-Means
kmeans = KMeans(n_clusters=3, random_state=42)
kmeans.fit(X)

# Evaluăm rezultatele folosind Silhouette Score
kmeans_silhouette_score = silhouette_score(X, kmeans.labels_)
print("Silhouette Score for K-Means:", kmeans_silhouette_score)

# Vizualizarea rezultatelor pentru algoritmul k-Means
plt.scatter(X[:, 0], X[:, 1], c=kmeans.labels_, cmap='viridis')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.title('Clustering by K-Means')
plt.show()

from sklearn.cluster import AgglomerativeClustering
from sklearn.metrics import silhouette_score
import matplotlib.pyplot as plt

# Implementăm algoritmul Agglomerative Clustering
agglomerative = AgglomerativeClustering(n_clusters=3)
agglomerative.fit(X)

# Evaluăm rezultatele folosind Silhouette Score
agglomerative_silhouette_score = silhouette_score(X, agglomerative.labels_)
print("Silhouette Score for Agglomerative Clustering:", agglomerative_silhouette_score)

# Vizualizarea rezultatelor pentru algoritmul Agglomerative Clustering
plt.scatter(X[:, 0], X[:, 1], c=agglomerative.labels_, cmap='viridis')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.title('Clustering by Agglomerative Clustering')
plt.show()

from sklearn.cluster import DBSCAN
import matplotlib.pyplot as plt

# Implementăm algoritmul DBSCAN
dbscan = DBSCAN(eps=0.5, min_samples=5)
dbscan.fit(X)

# Evaluăm rezultatele folosind Silhouette Score
# Notă: DBSCAN nu întoarce etichetele clusterele, astfel că Silhouette Score nu poate fi calculat direct.
# Vom evalua numărul de clustere și folosirea rezultatelor pentru a face interpretări.
unique_labels = set(dbscan.labels_)
num_clusters_dbscan = len(unique_labels) - (1 if -1 in dbscan.labels_ else 0)
print("Number of clusters found by DBSCAN:", num_clusters_dbscan)

# Vizualizarea rezultatelor pentru algoritmul DBSCAN
plt.scatter(X[:, 0], X[:, 1], c=dbscan.labels_, cmap='viridis')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.title('Clustering by DBSCAN')
plt.show()


from sklearn.mixture import GaussianMixture
from sklearn.datasets import load_iris
import matplotlib.pyplot as plt

iris = load_iris()
X = iris.data


# Implementăm algoritmul GMM
gmm = GaussianMixture(n_components=3, random_state=42)
gmm.fit(X)

# Vizualizăm rezultatele clusteringului
plt.scatter(X[:, 0], X[:, 1], c=gmm.predict(X), cmap='viridis')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.title('Clustering by Gaussian Mixture Model')
plt.show()

# Afișarea numărului de clustere estimat de modelul GMM
num_clusters_gmm = gmm.n_components
print("Number of clusters found by GMM:", num_clusters_gmm)

