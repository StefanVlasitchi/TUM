from urllib.parse import urljoin

import requests
from bs4 import BeautifulSoup

# URL-ul paginii Wikipedia
url = "https://en.wikipedia.org/wiki/World_War_II"

# Faceți o cerere GET la URL
response = requests.get(url)

# Analizați răspunsul cu BeautifulSoup
soup = BeautifulSoup(response.text, 'html.parser')

# Capturați titlul paginii
page_title = soup.find('h1').text

# Capturați toate titlurile secțiunilor
section_titles = [header.text for header in soup.find_all(['h2', 'h3', 'h4', 'h5', 'h6'])]

# Găsiți toate elementele de imagine pe pagină
img_tags = soup.find_all('img')

# Creați o listă pentru a stoca URL-urile imaginilor
image_urls = []

# Parcurgeți toate elementele de imagine și adăugați URL-urile lor la listă
for img in img_tags:
    image_url = img.get('src')
    if image_url:
        # Construiți un URL absolut folosind urljoin
        absolute_image_url = urljoin(url, image_url)
        image_urls.append(absolute_image_url)

# Salvare într-un fișier text
with open("informatii_wikipedia.txt", "w", encoding="utf-8") as file:
    file.write(f"Titlul paginii: {page_title}\n\n")
    file.write("Titlurile secțiunilor:\n")
    for section_title in section_titles:
        file.write(f"- {section_title}\n")
    file.write("\nURL-urile imaginilor:\n")
    for image_url in image_urls:
        file.write(f"- {image_url}\n")

print("Informațiile au fost salvate în fișierul 'informatii_wikipedia.txt'.")
