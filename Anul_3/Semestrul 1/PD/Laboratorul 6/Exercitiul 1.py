from pathlib import Path
import pandas as pd


def filter_and_save(input_file, output_file=None, start_date='2023-10-24', end_date='2023-10-31'):
    # Load data from the CSV file
    df = pd.read_csv(input_file)

    # Convert the 'Date' column to the datetime data type
    df['Date'] = pd.to_datetime(df['Date'])

    # Select only the data between the specified date range
    filtered_df = df[df['Date'].between(start_date, end_date)]

    # Extract the file name without extension using pathlib
    input_path = Path(input_file)
    file_name = input_path.stem
    file_extension = input_path.suffix

    # Construct the name of the new output file
    new_output_file = Path(output_file) if output_file else input_path.parent / f"new_{file_name}{file_extension}"

    # Save the sorted and filtered DataFrame to a new CSV file
    filtered_df.to_csv(new_output_file, index=False)

    print(
        f"Data from {input_file} has been sorted and filtered for the period {start_date} - {end_date} and saved in {new_output_file}.")


# List of CSV file names
files = ['1_exchange_rates_october.csv', '2_exchange_rates_october.csv', '3_exchange_rates_october.csv']

# Iterate through each file and apply the sorting function
for file in files:
    filter_and_save(file)
