import requests
from bs4 import BeautifulSoup
import csv
from datetime import datetime, timedelta

# URL of the website
url = "https://www.curs.md/ro/ajax/block?block_name=curs_box&referer=curs_valutar/oficial"

# Start date for October
start_date = datetime(2023, 10, 1)

# Initialize lists to store EUR data
eur_data = []

# Session to handle cookies and maintain state
session = requests.Session()

# Iterate through each day in October
current_date = start_date
while current_date.month == 10:
    # Send a POST request to the website and get the HTML content
    response = session.post(url, data={'CursDate': current_date.strftime("%Y-%m-%d")})
    html_content = response.text

    # Parse the HTML content using BeautifulSoup
    soup = BeautifulSoup(html_content, 'html.parser')

    # Find the updated table element
    updated_table = soup.find('table', class_='table')

    # Check if the table is found
    if updated_table:
        # Extract data for the current date and filter for EUR currency
        for row in updated_table.find_all('tr'):
            columns = row.find_all('td')
            if len(columns) >= 4:
                currency = columns[1].text.strip()
                rate_str = columns[2].text.strip()

                if currency == 'EUR':
                    # Extract numeric part of the rate string
                    rate_str_numeric = ''.join(filter(str.isdigit, rate_str))

                    # Convert to a float
                    try:
                        rate = float(rate_str_numeric) / 10000  # Assuming the rate is in MDL, divide by 10000
                        # Append EUR data to the list
                        eur_data.append({
                            'Date': current_date.strftime("%d %B %Y"),
                            'Value': '{:.4f} MDL'.format(rate)  # Append 'MDL' after the value
                        })
                    except ValueError as e:
                        print(f"Error converting rate for {current_date.strftime('%Y-%m-%d')}: {e}")




    else:
        print(f"Table not found for {current_date.strftime('%Y-%m-%d')}")

    # Move to the next day
    current_date += timedelta(days=1)

# Create a CSV file and write formatted EUR data
csv_filename = "3_exchange_rates_october.csv"
with open(csv_filename, 'w', newline='', encoding='utf-8') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(['Date', 'Value'])

    # Write data row by row
    for entry in eur_data:
        csv_writer.writerow([entry['Date'], entry['Value']])

print(f"Formatted EUR data for October has been extracted and saved to {csv_filename}")
