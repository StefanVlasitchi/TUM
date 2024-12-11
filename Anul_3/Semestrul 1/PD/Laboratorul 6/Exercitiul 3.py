import pandas as pd

END_DATE = pd.to_datetime('2023-10-31')

files_to_concat = ['1_exchange_rates_october.csv', '2_exchange_rates_october.csv', '3_exchange_rates_october.csv']

# List Comprehension for loading data
dataframes = [pd.read_csv(file) for file in files_to_concat]

concatenated_df = pd.concat(dataframes, ignore_index=True)
concatenated_df.to_csv('fisier_concatenat.csv', index=False)
print("Fișierul concatenat a fost creat cu succes.")

# Date parsing with error handling
concatenated_df['Date'] = pd.to_datetime(concatenated_df['Date'], format='%d %B %Y', errors='coerce')

if concatenated_df['Date'].isna().any():
    print("Warning: Some dates could not be parsed.")

# Sorting by date
concatenated_df = concatenated_df.sort_values(by='Date')

# Using a fixed interval for weeks
distinct_weeks = pd.date_range(start=concatenated_df['Date'].min(), end=concatenated_df['Date'].max(), freq='7D')

for start_date in distinct_weeks:
    end_date = start_date + pd.DateOffset(days=6)
    end_date = min(end_date, END_DATE)  # Adjust end date to END_DATE constant

    week_df = concatenated_df[(concatenated_df['Date'] >= start_date) & (concatenated_df['Date'] <= end_date)]

    if not week_df.empty:
        weekly_output_file = f"{start_date.strftime('%Y%m%d')}_{end_date.strftime('%Y%m%d')}.csv"
        week_df.to_csv(weekly_output_file, index=False)
        print(f"Created file: {weekly_output_file}")
    else:
        print("Could not create file: no valid data.")
