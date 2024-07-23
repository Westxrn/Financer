#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

struct Expense {
    int id;
    std::string date;
    double amount;
    std::string category;
    std::string description;
};

class ExpenseTracker {
private:
    std::vector<Expense> expenses;
    int nextId;
    std::string filename;

    void loadExpenses();
    void saveExpenses();
public:
    ExpenseTracker(const std::string& file);
    void addExpense(const std::string& date, double amount, const std::string& category, const std::string& description);
    void viewExpenses() const;
    void deleteExpense(int id);
};
