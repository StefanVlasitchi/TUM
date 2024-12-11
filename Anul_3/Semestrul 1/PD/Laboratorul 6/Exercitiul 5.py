import pandas as pd

try:
    # Încarcă fișierul CSV obținut după concatinare
    concatenated_df = pd.read_csv("fisier_concatenat.csv")
except FileNotFoundError:
    print("Fișierul fisier_concatenat.csv nu a fost găsit.")
    concatenated_df = None

def get_data_for_time_interval(dataframe, start_date, end_date):
    try:
        # Asigură-te că coloana 'Date' este de tipul datetime
        dataframe['Date'] = pd.to_datetime(dataframe['Date'], errors='coerce')

        # Construiește datele de start și final cu luna și anul fixate la 2023-10
        start_date = pd.to_datetime(f'2023-10-{start_date:02}', format='%Y-%m-%d')
        end_date = pd.to_datetime(f'2023-10-{end_date:02}', format='%Y-%m-%d')

        # Filtrarea dataframe-ului pentru intervalul specificat
        time_interval_data = dataframe[(dataframe['Date'] >= start_date) & (dataframe['Date'] <= end_date)]

        # Verificare dacă există date pentru intervalul specificat
        if time_interval_data.empty:
            print(f"Nu există date pentru intervalul de la {start_date} la {end_date}")
            return None
        else:
            return time_interval_data

    except ValueError as e:
        print(f"Eroare la conversia datelor sau filtrarea datelor: {e}")
        return None

# Exemplu de utilizare
try:
    start_date_input = int(input("Introdu data inițială (format: DD): "))
    end_date_input = int(input("Introdu data finală (format: DD): "))

    # Verifică dacă datele introduse sunt în formatul corect și sunt valide
    if 1 <= start_date_input <= 31 and 1 <= end_date_input <= 31:
        result = get_data_for_time_interval(concatenated_df, start_date_input, end_date_input)

        if result is not None:
            print(result)
    else:
        print("Ați introdus o dată greșită.")

except ValueError:
    print("Datele introduse nu sunt valide.")
