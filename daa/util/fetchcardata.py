import pandas as pd
from scipy.io import arff
import os

def arff_to_csv_pandas(arff_filename, csv_filename):
    """
    Converts an ARFF file to a CSV file using pandas.

    Args:
        arff_filename (str): The path to the input .arff file.
        csv_filename (str): The path for the output .csv file.
    """
    try:
        # Load the ARFF file
        # arff.loadarff returns a tuple, the first element (index 0) is the data
        data, meta = arff.loadarff(arff_filename)

        # Convert the data to a pandas DataFrame
        df = pd.DataFrame(data)

        # Handle potential byte strings in categorical data (common in ARFF files)
        # Iterate over columns and decode byte strings if present
        for col in df.columns:
            if df[col].dtype == 'object':
                try:
                    df[col] = df[col].str.decode('utf-8')
                except AttributeError:
                    # Handle cases where some object columns might not be byte strings
                    pass

        # Save the DataFrame to a CSV file
        df.to_csv(csv_filename, index=False)

        print(f"Successfully converted '{arff_filename}' to '{csv_filename}'")

    except FileNotFoundError:
        print(f"Error: The file '{arff_filename}' was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Example usage:
# Replace 'your_input_file.arff' and 'your_output_file.csv' with your file names
input_file = 'data/Training Dataset.arff' # Example file name
output_file = 'data/phishingwebsites.csv' # Desired output file name

arff_to_csv_pandas(input_file, output_file)
