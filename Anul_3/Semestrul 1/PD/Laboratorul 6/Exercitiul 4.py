import pandas as pd

# Încarcă fișierul CSV obținut după concatinare
try:
    concatenated_df = pd.read_csv("fisier_concatenat.csv")
except FileNotFoundError:
    print("Fișierul fisier_concatenat.csv nu a fost găsit.")
    concatenated_df = None


def filter_data_by_date(df, target_date):
    if df is not None and 'Date' in df.columns:
        try:
            formatted_target_date = target_date.strftime('%d %B %Y')
            filtered_rows = df[df['Date'] == formatted_target_date]

            if not filtered_rows.empty:
                return filtered_rows
            else:
                print(f'Nu există date pentru data: {target_date}')
                return None
        except ValueError as e:
            print(f"Eroare la filtrarea datelor: {e}")
            return None
    else:
        print("DataFrame invalid pentru filtrare.")
        return None


# Exemplu de utilizare:
try:
    day_input = input("Introdu ziua (DD): ")
    target_date = pd.to_datetime(f'2023-10-{day_input}', format='%Y-%m-%d')
except ValueError as e:
    print(f"Eroare: {e}")
    target_date = None

if target_date is not None:
    result = filter_data_by_date(concatenated_df, target_date)

    if result is not None:
        print(f"\nDatele pentru data {target_date} sunt:")
        print(result)
