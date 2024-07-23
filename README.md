# Expense Tracker

A simple console-based expense tracker application written in C++ to help manage and track your expenses.

## Features

- Add expenses with date, amount, category, and description
- View a list of all expenses
- Delete expenses by ID
- Save expenses to a file for persistence
- Load expenses from a file on startup

## Requirements

- C++11 or later
- g++ compiler (or any C++ compiler that supports C++11)

## Installation

1. Clone the repository or download the source files (`ExpenseTracker.h`, `ExpenseTracker.cpp`, and `main.cpp`).

2. Navigate to the directory containing the source files.

3. Compile the program using g++:

    ```sh
    g++ -std=c++11 -o expense_tracker main.cpp ExpenseTracker.cpp
    ```

4. Run the compiled program:

    ```sh
    ./expense_tracker
    ```

## Usage

Upon running the program, you will see a menu with the following options:

1. **Add Expense**: Add a new expense by entering the date, amount, category, and description.
2. **View Expenses**: Display a list of all expenses.
3. **Delete Expense**: Delete an expense by entering its ID.
4. **Exit**: Exit the program.

### Example

1. **Add an Expense**:

    ```
    Enter date (YYYY-MM-DD): 2024-07-23
    Enter amount: 50.0
    Enter category: Food
    Enter description: Dinner at a restaurant
    Expense added successfully.
    ```

2. **View Expenses**:

    ```
    ID  Date       Amount  Category    Description
    1  2024-07-23  50.0    Food        Dinner at a restaurant
    ```

3. **Delete an Expense**:

    ```
    Enter expense ID to delete: 1
    Expense deleted successfully.
    ```

4. **Exit**:

    ```
    Exiting...
    ```

## File Structure

- `ExpenseTracker.h`: Header file containing the `Expense` struct and `ExpenseTracker` class definition.
- `ExpenseTracker.cpp`: Implementation of the `ExpenseTracker` class methods.
- `main.cpp`: Contains the main function and user interface for interacting with the expense tracker.

## Contributing

If you wish to contribute to the project, please fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
