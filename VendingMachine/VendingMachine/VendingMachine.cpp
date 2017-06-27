// VendingMachine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

double customerMoney;


/*

1. sequantial access - while / for
2. binary search of array - binary_search()
3. insertion sort - insertion_order()
4. deletion - deletion()
5. random access - select item with array index

*/




void displayMenu()
{
	cout << "---------------------------\n";
	cout << "     Vending Machine \n";
	cout << "             Available $" << customerMoney << ". \n";
	cout << "---------------------------\n";
	cout << "   1. Water       $2.5 \n";
	cout << "   2. Coca Cola   $3.5 \n";
	cout << "   3. Bundaberg   $3.0 \n";
	cout << "   4. Sprite      $3.5 \n";
	cout << "   5. Doritos     $4.0 \n";
	cout << "   6. Twix        $2.0 \n";
	cout << "   7. Snikers     $2.0 \n";
	cout << "   8. M&M         $3.0 \n";
	cout << "   9. Chupa chups $1.0 \n";
	cout << "  10. Haribo      $3.5 \n";
	cout << "---------------------------\n";
	cout << "  0. Exit vending machine \n";
	cout << "  11. (Binary Search) Display the item details. \n";
	cout << "  12. (Insertion Sort) Display the items order by from lowest to highest \n";
	cout << "  13. (Deletion) Display the availabe items \n";
	cout << "---------------------------\n";
	
}

int binary_search(string items[10][3], int search_key, int first, int last) {

	int index;
	int mid = (first + last) / 2;
	int itemNum = atoi(items[mid][0].c_str());

	if (search_key == itemNum)
		index = mid;

	else
		if (search_key < itemNum)
			index = binary_search(items, search_key, first, mid - 1);
		else
			index = binary_search(items, search_key,  mid + 1, last);

	return index;
}

void insertion_order(string items[10][3]) {

	int current = 1;
	string temp[1][3] = {};//this was an int
	int i = 1;


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) {
			if (items[j+1][2] < items[j][2])
			{
				temp[0][0] = items[j+1][0];
				temp[0][1] = items[j+1][1];
				temp[0][2] = items[j+1][2];
				items[j+1][0] = items[j][0];
				items[j+1][1] = items[j][1];
				items[j+1][2] = items[j][2];
				items[j][0] = temp[0][0];
				items[j][1] = temp[0][1];
				items[j][2] = temp[0][2];
			}
		}
	}

	cout << "Display the items order by from chepeast. \n";
	for (i = 0; i < 10; i++)
	{
		cout << items[i][0] << ". " << items[i][1] << " $" << items[i][2] <<"\n";
	}
}


void deletion(string items[10][3]) {

	int position = 0, size=1;
	int currentSize = 10;
	double price;
	string temp[10][3] = {};
	
	for (int i = 0; i < 10; i++) {
		temp[i][0] = items[i][0];
		temp[i][1] = items[i][1];
		temp[i][2] = items[i][2];
	}


	if (customerMoney < 4)
	{
		while (size != 10) {

			price = stod(temp[position][2].c_str());
			if (price > customerMoney)
			{
				for (int i = position; i < currentSize - 1; i++)
				{
					temp[i][0] = temp[i + 1][0];
					temp[i][1] = temp[i + 1][1];
					temp[i][2] = temp[i + 1][2];
				}
				currentSize--;
			}
			else {
				position++;
			}
			size++;
		}
	}


	for (int i = 0; i < currentSize-1; i++)
	{
		cout << temp[i][0] << ". " << temp[i][1] << " $" << temp[i][2] << "\n";
	}
}



int main()
{
	int selectedItem = -1;
	double price;

	string items[10][3] = {
		{ "1", "Water", "2.5" } , 
		{ "2", "Coca Cola", "3.5" }, 
		{ "3", "Bundaberg", "3.0" },
		{ "4", "Sprite", "3.5" },
		{ "5", "Doritos", "4.0" },
		{ "6", "Twix", "2.0" },
		{ "7", "Snikers", "2.0" },
		{ "8", "m&m", "1.0" },
		{ "9", "Chupa Chups", "3.0" },
		{ "10", "Haribo", "3.5" }
	};

	string itemDetails[10][3] = {
		{ "1", "Water", "Evian is a brand of mineral water coming from several sources near Évian-les-Bains, on the south shore of Lake Geneva" } ,
		{ "2", "Coca Cola", "Coca-Cola is a carbonated soft drink produced by The Coca-Cola Company. Originally intended as a patent medicine, it was invented in the late 19th century by John Pemberton." },
		{ "3", "Bundaberg", "Bundaberg Brewed Drinks Pty Ltd is a very large brewer of non-alcoholic beverages (soft drink) located in Bundaberg, Queensland. The business is owned by an Australian family." },
		{ "4", "Sprite", "Sprite is a colorless, caffeine-free, lemon and lime-flavoured soft drink created by The Coca-Cola Company." },
		{ "5", "Doritos", "The plain chips are made of ground corn (maize), vegetable oil, and salt. Other ingredients vary across the flavored chip varieties. Doritos made for the US market generally do not use pork-derived animal rennet in the making of the cheese flavorings used on the chip" },
		{ "6", "Twix", "Twix is a chocolate bar made by Mars, Inc., consisting of biscuit applied with other confectionery toppings and coatings (most frequently caramel and milk chocolate).[1] Twix bars are packaged with two or four bars in a package. Miniature and bite-size Twix are also available." },
		{ "7", "Snickers", "Snickers is a brand name chocolate bar made by the American company Mars, Incorporated. Consisting of nougat topped with caramel and peanuts, enrobed in milk chocolate,[2] Snickers has annual global sales of $2 billion." },
		{ "8", "m&m", "M&M are colorful button - shaped chocolates produced by Mars, Incorporated. The candy shell, each of which has the letter m printed in lower case on one side, surrounds a filling which varies depending upon the variety of M&M's." },
		{ "9", "Chupa Chups", "Chupa Chups (Spanish pronunciation: Spanish: [ˈtʃupa ˈtʃups];) is a popular Spanish brand of lollipop and other confectionery sold in over 150 countries around the world. " },
		{ "10", "Haribo", "Haribo is a German confectionery company, founded in 1920 by Johannes Hans Riegel, Sr. It is headquartered in Bonn and the name comes from an abbreviation of Hans Riegel, Bonn." }
	};

	
	cout << "---------------------------\n";
	cout << "     Vending Machine \n";
	cout << "---------------------------\n";
	cout << "How much you want to put into the machine? ";

	if (!(cin >> customerMoney))
	{
		cout << "Sorry, It's not valid number. bye bye. \n ";
	}
	else {

		/* 1. While loop - Sequential Access  */
		while (selectedItem != 0 && customerMoney >= 1)
		{
			//display menu and get the item number from user
			displayMenu();
			cout << "Which product would you like to buy? ";
			
			if (!(cin >> selectedItem))
			{
				cout << "Sorry, It's not valid number. Good bye. \n";
				break;
			}
			else {
				//if user want to exit the system, show the message.
				if (selectedItem == 0)
				{
					cout << "Thank you! Good bye. \n";
					break;
				}
				else if (selectedItem == 11)
				{
					cout << "---------------------------\n";
					cout << "Which product do you want to know in details? \n";
					cout << "---------------------------\n";
					int search_key;
					cin >> search_key;

					int index = binary_search(items, search_key, 1, 10);
					cout << itemDetails[index][2] << "\n";
				}
				else if (selectedItem == 12)
				{
					insertion_order(items);
				}
				else if (selectedItem == 13)
				{
					deletion(items);
				}
				else if (selectedItem > 13 || selectedItem < 0) {
					cout << "Please enter the number between 1 and 10. \n";
				}
				else
				{
					cout << "You have selected '" << items[selectedItem - 1][1] << "'. \n";
					price = stod(items[selectedItem - 1][2].c_str());
					if ((customerMoney - price) < 0) {
						cout << "You don't have enough money to buy this item. \n";
					}

					else {
						customerMoney = customerMoney - price;
						cout << "You have $" << customerMoney << " left\n";
					}
				}
			}
		}

		if (customerMoney < 1)
		{
			cout << "Sorry, you don't have enough money. bye bye. \n ";
		}
	}
   
}

