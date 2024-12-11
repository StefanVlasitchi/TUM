import json

import requests
from bs4 import BeautifulSoup


def retrieve_books_with_two_stars():
    base_url = "http://books.toscrape.com/catalogue/page-{}.html"
    two_star_titles = []
    for n in range(1, 51):  # There are 50 pages in the catalogue
        scrape_url = base_url.format(n)
        res = requests.get(scrape_url)

        soup = BeautifulSoup(res.text, 'html.parser')
        books = soup.select(".product_pod")

        for book in books:
            if len(book.select('.star-rating.Two')) != 0:  # If the book has a 2-star rating
                two_star_titles.append(book.select('a')[1]['title'])  # Add the title to our list
    return two_star_titles


# Deschideți un fișier .txt în modul de scriere
with open('Final.txt', 'w', encoding='utf-8') as file:
    file.write(f"Rezultatul final este: ")
    # Scrieți titlul paginii
    file.write(json.dumps(retrieve_books_with_two_stars(), indent=4, ensure_ascii=False))
