#include <iostream>
#include "ExpenseTracker.h"

void showMenu() {
    std::cout << "1. Add Expense\n";
    std::cout << "2. View Expenses\n";
    std::cout << "3. Delete Expense\n";
    std::cout << "4. Exit\n";
}

int main() {
    ExpenseTracker tracker("expenses.txt");
    int choice;
    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string date, category, description;
            double amount;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::getline(std::cin, date);
            std::cout << "Enter amount: ";
            std::cin >> amount;
            std::cin.ignore();
            std::cout << "Enter category: ";
            std::getline(std::cin, category);
            std::cout << "Enter description: ";
            std::getline(std::cin, description);
            tracker.addExpense(date, amount, category, description);
            break;
        }
        case 2:
            tracker.viewExpenses();
            break;
        case 3: {
            int id;
            std::cout << "Enter expense ID to delete: ";
            std::cin >> id;
            tracker.deleteExpense(id);
            break;
        }
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
