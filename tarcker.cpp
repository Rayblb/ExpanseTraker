#include "tarcker.h"


Expense::Expense(int id, const std::string& Description, int quantity, double amount)
	: id(id), Description(Description), quantity(quantity), amount(amount) {
}

void Expense::ViewAllExpenses(const std::vector<Expense>& expenses) {
	if (expenses.empty()) {
		std::cout << "Your expenses are empty." << std::endl;
	}
	else {
		for (const auto& expense : expenses) {
			std::cout << "ID: " << expense.id
				<< ", Description: " << expense.Description
				<< ", Quantity: " << expense.quantity
				<< ", Amount: $" << expense.amount
				<< std::endl;
		}
	}
}

bool ExpenseManager::AddExpense(std::string& Description, int& quantity, double& amount) {
	if (amount < 0 || quantity < 0) {
		std::cout << "The amount/quantity should be positive." << std::endl;
		return false;
	}

	Expense newExpense(nextID++, Description, quantity, amount); // Create new expense with unique ID
	expenses.push_back(newExpense);

	std::cout << "Expense added: " << Description << " Q: " << quantity << " - $ " << amount << std::endl;
	return true;
}


bool ExpenseManager::EditExpense(int ID, std::string& NewDescription, int& quantity, double& amount){
	
	for (auto& expense : expenses) { // Loop through expenses
		if (expense.id == ID) { // Check if ID matches

			char userInput;
			std::cout << "What do you want to change:for Description press D for Quantity press Q for amount press A" << std::endl;
			std::cin >> userInput;

			userInput = toupper(userInput);

			if (userInput == 'D' || userInput == 'Q' || userInput == 'A') {


				switch (userInput)
				{
				case 'D':
					std::cout << "Enter a new Description : " << std::endl;
					std::cin >> NewDescription;
					expense.Description = NewDescription;
					break;
				case 'Q':
					std::cout << "Enter a new Quantity : " << std::endl;
					std::cin >> quantity;
					expense.quantity = quantity;
					break;
				case 'A':
					std::cout << "how much did it cost you: " << std::endl;
					std::cin >> amount;
					expense.amount = amount;
					break;
				default:
					return false;
					break;
				}
				return true;

			}
			else {
				return false;
			}
			return true;

		}
	}

	std::cout << "NO Expanse found with this ID" << ID;
	return false;
};

bool ExpenseManager::DeleteExpense(int ID) {
	int userID;
	std::cout << "Enter the ID of the expense that you want to delete: " << std::endl;
	std::cin >> userID;

	auto it = expenses.begin();
	while (it != expenses.end()) {
		if (it->id == userID) { // Check if ID matches
			it = expenses.erase(it); // Remove expense from vector
			std::cout << "Expense deleted successfully." << std::endl;
			return true;
		}
		else {
			++it; // Move to next expense
		}
	}
	std::cout << "No expense found with ID: " << userID << "." << std::endl;
	return false; 
}

int main() {
	ExpenseManager manager; // Create an instance of ExpenseManager
	int choice;

	do {
		std::cout << "\nExpense Manager Menu:\n";
		std::cout << "1. Add Expense\n";
		std::cout << "2. View All Expenses\n";
		std::cout << "3. Edit Expense\n";
		std::cout << "4. Delete Expense\n";
		std::cout << "5. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			// Add Expense
			std::string description;
			int quantity;
			double useramount;
			

			std::cout << "Enter Description: ";
			std::cin >> description;
			std::cout << "Enter Quantity: ";
			std::cin >> quantity;
			std::cout << "How much did it cost you ? " << std::endl;
			std::cin >> useramount;

			if (manager.AddExpense(description, quantity, useramount)) {
				std::cout << "Expense added successfully." << std::endl;
			}
			else {
				std::cout << "Failed to add expense." << std::endl;
			}
			break;
		}
		case 2:
			// View All Expenses
			Expense::ViewAllExpenses(manager.GetExpenses());
			break;

		case 3: {
			// Edit Expense
			int id;
			std::string newDescription;
			int newQuantity;
			double newAmount;

			std::cout << "Enter ID of the expense to edit: ";
			std::cin >> id;

			// Assuming you have a method to edit expenses
			if (manager.EditExpense(id, newDescription, newQuantity, newAmount)) {
				std::cout << "Expense edited successfully." << std::endl;
			}
			else {
				std::cout << "Failed to edit expense." << std::endl;
			}
			break;
		}
		case 4: {
			int id{};

			if (manager.DeleteExpense(id)) {
				std::cout << "Expense deleted successfully." << std::endl;
			}
			else {
				std::cout << "Failed to delete expense." << std::endl;
			}
			break;
		}
		case 5:
			std::cout << "Exiting program." << std::endl;
			break;

		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	} while (choice != 5);

	return 0; 
;
}