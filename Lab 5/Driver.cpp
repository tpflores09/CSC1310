//LOOK!! ---------------------put your comment block here with title, author, date, & purpose
/* Title: Driver.cpp
	Author: Tania Perdomo Flores
	Date: 03/02/2023
	Purpose: inventory program that will alow user to enter inventory, take part of inventory, or quit	
*/

#include <iostream>
#include "InvItem.h"
#include "DynStack.h"
using namespace std;

int main()
{
	//LOOK!!  -------------------create your InventoryItem stack on the line below and name it "stack"
	DynamicStack<InvItem> stack;
	//LOOK!! ---------------------create an inventory item object and name it "item"
	InvItem item;

	int choice;						// Menu choice
	long serial;					// Serial number
	string mDate;					// Manufacture date

	do
	{
		// Display the menu.
		cout << "\n------ Inventory Menu --------\n\n";
		cout << "1.  Enter a part into the inventory.\n";
		cout << "2.  Take a part from the inventory.\n";
		cout << "3.  Quit.\n\n";
		cout << "Please make a choice (1, 2, or 3):  ";
		cin >> choice;

		// Validate choice
		while (choice < 1 || choice > 3)
		{
			cout << "Please enter 1, 2, or 3: ";
			cin >> choice;
		}

		// Act on the user's choice.
		switch(choice)
		{

		case 1:
			// Enter a part into inventory.
			cout << "\nYou have chosen to add an item to the inventory bin.\n\n";
			cout << "Enter the item's serial number: ";
			cin >> serial;
			item.setSerialNum(serial);
			cout << "Enter the item's manufacture date: ";
			cin >> mDate;
			item.setManufactDate(mDate);
			stack.push(item);
			break;

		case 2:
			// Take a part out of inventory.
			cout << "\nYou have chosen to remove an item from the inventory bin.\n\n";
			if (stack.isEmpty())
				cout << "No parts to remove.\n";
			else
			{
				stack.pop(item);
				cout << "\nThe part you removed was:\n";
				cout << "\tSerial number: " << item.getSerialNum() << endl;
				cout << "\tManufacture date: " << item.getManufactDate() << endl;
				cout << endl;
			}
			break;

		case 3:
			cout << "\nGoodbye!\n\n";
			break;
		}
	} while (choice  != 3);

	return 0;
}