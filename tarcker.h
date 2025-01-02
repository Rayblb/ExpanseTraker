#pragma once
#include <iostream>
#include <string>
#include<vector>



class Expense {//to view and store
	public:
		int id;
		std::string Description;
		int quantity;
		double amount;
		Expense() {};
		Expense(int id, const std::string& Description, int quantity, double amount);
		static void ViewAllExpenses(const std::vector<Expense>& expenses);
		//void ViewMonthlySummary(int MonthNumber) {};
		//void ViewWeaklySummary(int WeekNumber ) {};


};

class ExpenseManager :public Expense {// to manage
	private:
		int nextID = 1; // To keep track of the next available ID
		std::vector<Expense> expenses; // Vector to store expenses

	public:
		ExpenseManager() {};

		bool AddExpense(std::string &Description , int &quantity ,double &amount); //add Expense 
		bool EditExpense(int ID ,std::string& NewDescription, int &quantity, double &amount);//edit the Expense
		bool DeleteExpense(int ID); // delete or quantity or the who;e Expense by ID 
		const std::vector<Expense>& GetExpenses() const { return expenses; } // Getter for expenses


};