# Pasul 1
import pandas as pd
import seaborn as sns



# Pasul 2
population = pd.read_csv('World Population Growth.csv')

# Pasul 4
sns.jointplot(x='Year', y='Number', data=population, kind='scatter')

sns.jointplot(x='Population', y='Number', data=population, kind='scatter')

