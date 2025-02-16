import csv

def extract_wanted_data_and_avg(input_file, output_file, column_name, target_value, selected_columns):
    """
    Extract rows from a CSV file where the specified column matches the target value.
    Writes only the selected columns to the output file and calculates the average of the 'percentage' column.
    """
    try:
        total_percentage = 0  # Initialize the sum of the percentage column
        matching_rows = 0     # Count of rows that match the condition

        # Open the input CSV file
        with open(input_file, mode='r', newline='', encoding='utf-8') as infile:
            reader = csv.DictReader(infile)
            
            # Check if the column exists in the file
            if column_name not in reader.fieldnames:
                raise ValueError(f"Column '{column_name}' not found in the input file.")

            # Check if the selected columns exist
            for col in selected_columns:
                if col not in reader.fieldnames:
                    raise ValueError(f"Selected column '{col}' not found in the input file.")

            # Filter rows and write to the output file
            with open(output_file, mode='w', newline='', encoding='utf-8') as outfile:
                writer = csv.DictWriter(outfile, fieldnames=selected_columns)

                # Write header for selected columns
                writer.writeheader()

                # Write rows where the column matches the target value
                for row in reader:
                    if row[column_name] == target_value:
                        # Create a filtered dictionary with only selected columns
                        filtered_row = {col: row[col] for col in selected_columns}
                        writer.writerow(filtered_row)

                        # Accumulate the percentage value and count the row
                        try:
                            total_percentage += float(row["percentage"])
                            matching_rows += 1
                        except ValueError:
                            raise ValueError(f"Invalid percentage value: {row['percentage']}")

        # Calculate average
        average_percentage = total_percentage / matching_rows if matching_rows > 0 else 0

        print(f"Filtered data saved to {output_file}")
        print(f"Average of 'percentage' column: {average_percentage:.2f}")

    except FileNotFoundError:
        print(f"Error: The file {input_file} was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Example usage
if __name__ == "__main__":
    input_csv = r"C:\Users\Dell\OneDrive - National University of Mongolia\Desktop\2nd Year 1st semester\Test Codes\learndash_reports_user_quizzes_40187754ec.csv"
    output_csv = r"C:\Users\Dell\OneDrive - National University of Mongolia\Desktop\2nd Year 1st semester\Test Codes\output.txt"
    column_to_filter = "name"  # Column to filter by
    value_to_match = "240121"  # Value to match
    columns_to_write = ["name", "percentage"]  # Columns to include in the output

    extract_wanted_data_and_avg(input_csv, output_csv, column_to_filter, value_to_match, columns_to_write)
