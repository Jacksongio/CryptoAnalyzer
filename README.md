# Cryptocurrency Data Analyzer

This project is a C-based application designed to read, parse, and analyze historical cryptocurrency data from a CSV file. The program calculates and outputs key statistics such as the average, minimum, and maximum values of cryptocurrency prices over time. This tool is especially useful for understanding trends and making data-driven decisions in cryptocurrency trading.

## Features

- **Data Parsing:** Reads and parses large CSV files, skipping rows with missing data (NaN values).
- **Statistical Analysis:** Calculates statistics like average, minimum, and maximum values for Open, High, Low, and Close prices.
- **Modular Design:** Uses a clean and modular design with separate header and source files for easy maintenance and extension.
- **Dynamic Memory Allocation:** Efficiently handles large datasets by dynamically allocating memory.

## Directory Structure

### CryptoAnalyzer
- **crypto_stats.c:** Main source code file for data processing and analysis
- **crypto_stats.h:** Header file containing structure and function declarations
- **Makefile:** Makefile to automate the build process
- **README.md:** Project documentation
- **sampleCSV.csv:** Sample CSV file for testing purposes -- CSV files compatible are downloadable from Kaggle!


## Getting Started

### Prerequisites

Ensure you have the following installed on your system:

- **GCC**: The GNU Compiler Collection for compiling the C program.
- **Make**: For building the project using the provided Makefile.

### Installation

1. **Clone the Repository**:

   ```bash
   git clone [https://github.com/YourUsername/CryptoAnalyzer.git](https://github.com/jacksongio/CryptoAnalyzer.git)
   cd CryptoAnalyzer
2. **Compile the Program**:\
Use the provided Makefile to compile the program.
   ```Bash
      make

3. **Run the Program**:\
After compilation, run the program with:

   ```Bash
    ./crypto_stats
4. **Clean Up**:\
To remove the compiled executable, use:

    ```Bash
    make clean


## Usage
The program reads a CSV file named bitstampUSD_1-min_data_2012-01-01_to_2021-03-31.csv by default. You can modify the source code to specify a different file if needed.

Once the program is run, it will output statistical information such as the average, minimum, and maximum prices for the cryptocurrency data contained in the CSV file.

Example Output
  ```Bash
Statistics for Cryptocurrency Data:
-----------------------------------
Average Open Price: 5000.23
Average High Price: 5100.87
Average Low Price: 4950.14
Average Close Price: 5050.55
Minimum Open Price: 0.01
Maximum Open Price: 20000.00
Minimum Close Price: 0.01
Maximum Close Price: 19995.00
```

## Project Structure
- **crypto_stats.c:** Contains the main logic for parsing the CSV file and computing statistics.
- **crypto_stats.h:** Header file with declarations of the CryptoData structure and the function prototypes.
- **Makefile:** Automates the build process, ensuring that all necessary files are compiled correctly.
- **sample_data.csv:** A smaller CSV file for quick testing and demonstration.
- **run.sh:** A shell script that compiles and runs the program.
## How It Works
- **CSV Parsing:** The program reads the CSV file line by line, parsing each row into a CryptoData structure. Lines with missing data (NaN) are skipped.
- **Dynamic Memory Management:** The program uses dynamic memory allocation to handle datasets of arbitrary size efficiently.
- **Statistical Calculation:** After parsing the data, the program computes and displays various statistics such as average, minimum, and maximum values.
## Future Improvements
- **Command-Line Arguments:** Allow the user to specify the CSV file path and analysis options via command-line arguments.
- **Additional Analysis:** Implement more advanced statistical analysis, such as moving averages, volatility, and trend detection.
- **Data Visualization:** Integrate with a library or tool to generate graphs and charts for better data visualization.
## Contributing
Contributions are welcome! Please feel free to submit a pull request or open an issue if you have any suggestions or improvements.   

## License
This project is licensed under the MIT License. See the LICENSE file for more details.

## Contact
For any inquiries or support, you can reach me at jackson@giordano.us.   
