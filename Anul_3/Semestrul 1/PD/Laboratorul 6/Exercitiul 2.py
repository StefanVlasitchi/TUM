import pandas as pd
import os


def load_and_process_data(file_path):
    df = pd.read_csv(file_path)
    df['Date'] = pd.to_datetime(df['Date'])
    df['Value'] = pd.to_numeric(df['Value'].astype(str).str.replace(' MDL', ''), errors='coerce')
    df = df.dropna(subset=['Value'])
    return df


def calculate_daily_statistics(df):
    return df.groupby('Date')['Value'].agg(['min', 'max', 'mean'])


def display_statistics_for_date(date, stats_dict):
    print(f"\nComparare pentru data: {date} 00:00:00")
    for stat_type in ['min', 'max', 'mean']:
        values = [stats_dict[file_key].loc[date, stat_type] for file_key in stats_dict]
        result = min(values) if stat_type == 'min' else max(values) if stat_type == 'max' else sum(values) / len(values)
        print(f"{stat_type}: {result}")


def calculate_and_display_statistics(file_names, file_type):
    daily_statistics_dict = {}

    for file_name in file_names:
        df = load_and_process_data(file_name)
        daily_statistics = calculate_daily_statistics(df)
        file_key = os.path.splitext(os.path.basename(file_name))[0]
        daily_statistics_dict[file_key] = daily_statistics

    all_dates = set().union(*[daily_statistics_dict[file_key].index for file_key in daily_statistics_dict])

    for date_to_check in sorted(all_dates):
        display_statistics_for_date(date_to_check, daily_statistics_dict)


def main():
    new_files = [f for f in os.listdir() if f.startswith("new")]
    specified_files = ['1_exchange_rates_october.csv', '2_exchange_rates_october.csv', '3_exchange_rates_october.csv']

    print("\nApelul funcției pentru calculul statisticilor pentru fișierele create anterior cu prefixul 'new'")
    calculate_and_display_statistics(new_files, "new")

    print("\n----------------------------------------------------------------------------")

    print("\nApelul funcției pentru calculul statisticilor pentru fișierele specificate")
    calculate_and_display_statistics(specified_files, "specified")


if __name__ == "__main__":
    main()
