import time

from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.chrome.options import Options

# Set the URL of the website
url = 'https://www.moneyratestoday.com/exchange-rate-history-euro-to-moldovan-leu.html?date=2023-10'

# Set the path to the Opera WebDriver executable
# Replace 'path/to/chromedriver' with the actual path to the chromedriver executable
chromedriver_path = r'C:\Users\Steve\Downloads\chromedriver_win32'

# Configure Opera options
opera_options = Options()
opera_options.binary_location = r'C:\Users\Steve\Downloads\chromedriver_win32'  # Adjust this path based on your Opera GX installation directory

# Create a WebDriver with Chrome options
driver = webdriver.Chrome(executable_path=chromedriver_path, options=opera_options)

# Load the webpage
driver.get(url)

# Wait for dynamic content to load (you might need to adjust the sleep duration)
time.sleep(5)

# Get the HTML content after dynamic content is loaded
html_content = driver.page_source

# Close the browser
driver.quit()

# Parse the HTML content
soup = BeautifulSoup(html_content, 'html.parser')

# Find the table with the class 'result_table'
result_table = soup.find('table', class_='result_table')

# Extract only the body of the table
table_body = result_table.find('tbody')

# Write the body of the table to a CSV file
if table_body:
    csv_filename = 'result_table_body_moneyratestoday.csv'
    with open(csv_filename, 'w', newline='', encoding='utf-8') as csv_file:
        csv_file.write(str(table_body))

    print(f'The body of the result_table has been successfully written to {csv_filename}')
else:
    print('No table body found on the page.')
