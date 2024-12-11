import csv

import requests
from bs4 import BeautifulSoup


def scrape_exchange_rates(url):
    # Send a GET request to the URL
    response = requests.get(url)

    # Check if the request was successful (status code 200)
    if response.status_code == 200:
        # Parse the HTML content of the page
        soup = BeautifulSoup(response.content, 'html.parser')

        # Find the table containing exchange rate data
        table = soup.find('table', {'class': 'table'})

        # Check if the table is found
        if table:
            # Initialize a list to store data
            data = []

            # Extract data from each row in the table
            for row in table.find_all('tr'):
                columns = row.find_all('td')
                if len(columns) == 2:
                    date = columns[0].text.strip()
                    value = columns[1].text.strip().split("=")[1].strip()
                    # Append data to the list
                    data.append([date, value])

            return data
        else:
            print("Table not found on the webpage.")
            return None
    else:
        # Print an error message if the request was not successful
        print(f"Error: {response.status_code}")
        return None


def save_to_csv(data, filename):
    # Specify the CSV file header
    header = ["Date", "Value"]

    # Write data to CSV file
    with open(filename, 'w', newline='') as csv_file:
        writer = csv.writer(csv_file)
        writer.writerow(header)
        writer.writerows(data)


if __name__ == "__main__":
    # URL of the website to scrape
    url = "https://currencies.zone/historic/euro/moldovan-leu?startdate=2023-10-01&enddate=2023-10-31&p=1"

    # Perform web scraping
    exchange_rate_data = scrape_exchange_rates(url)

    # Check if data is successfully obtained
    if exchange_rate_data:
        # Specify the filename for the CSV file
        csv_filename = "2_exchange_rates_october.csv"

        # Save data to CSV file
        save_to_csv(exchange_rate_data, csv_filename)

        print(f"Data for October successfully scraped and saved to {csv_filename}")
    else:
        print("Web scraping failed.")
