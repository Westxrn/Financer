#include "ExpenseTracker.h"

ExpenseTracker::ExpenseTracker(const std::string& file) : nextId(1), filename(file) {
    loadExpenses();
}

void ExpenseTracker::loadExpenses() {
    std::ifstream file(filename);
    if (!file.is_open()) return;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Expense exp;
        iss >> exp.id >> exp.date >> exp.amount >> exp.category >> std::ws;
        std::getline(iss, exp.description);
        expenses.push_back(exp);
        if (exp.id >= nextId) nextId = exp.id + 1;
    }
    file.close();
}

void ExpenseTracker::saveExpenses() {
    std::ofstream file(filename, std::ios::trunc);
    for (const auto& exp : expenses) {
        file << exp.id << " " << exp.date << " " << exp.amount << " " << exp.category << " " << exp.description << "\n";
    }
    file.close();
}

void ExpenseTracker::addExpense(const std::string& date, double amount, const std::string& category, const std::string& description) {
    Expense exp = { nextId++, date, amount, category, description };
    expenses.push_back(exp);
    saveExpenses();
    std::cout << "Expense added successfully.\n";
}

void ExpenseTracker::viewExpenses() const {
    std::cout << "ID  Date       Amount  Category    Description\n";
    for (const auto& exp : expenses) {
        std::cout << exp.id << " " << exp.date << " " << exp.amount << " " << exp.category << " " << exp.description << "\n";
    }
}

void ExpenseTracker::deleteExpense(int id) {
    auto it = std::remove_if(expenses.begin(), expenses.end(), [id](const Expense& exp) { return exp.id == id; });
    if (it != expenses.end()) {
        expenses.erase(it, expenses.end());
        saveExpenses();
        std::cout << "Expense deleted successfully.\n";
    } else {
        std::cout << "Expense not found.\n";
    }
}
