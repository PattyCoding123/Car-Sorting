//==========================================================
//
// Title:      Lab 22
// Course:     CSC 1101
// Lab Number: 22
// Author:     Patrick Ducusin
// Date:       <04/19/2021>
// Description:
//   We will be making a program that manages car parts. 
// We will be utilizing arrays and several functions. 
// This code is added onto from Lab 22.
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// Declare global constants
const int G_ARRAY_SIZE = 10;

// This function takes the parts array, the size of the array, and the specific part
// and does a binary search
int binarySearchParts(string parts[], int arraySize, string key)
{

	// Declare variables
	int min = 0;
	int index;
	int max = arraySize - 1;

	// While loop to find the part - the key is the name of the part
	while (min <= max)
	{

		// Get to the midpoint of the array
		index = (min + max) / 2;

		// Test if key found
		if (parts[index] == key)  // Guess is correct
			return index;
		else if (parts[index] < key)  // Guess is too low
			min = index + 1;
		else // Guess is too high
			max = index - 1;

	}

	// If key isn't found, return -1
	index = -1;
	return index;
}

// This function loops through an array and addas all the scores of the quarters played
void listParts(string parts[], int arraySize, int &partCount)
{
	cout << "Parts List" << endl;
	cout << "-------------------" << endl;
	for (int i = 0; i <= arraySize - 1; i++)
	{
		if(parts[i] != "")
			cout << parts[i] << endl;
	}
	cout << "There are " << partCount << " parts in the list." << endl;
}

// This function will prompt for and gets a part from the user
// it will then call binarySearchParts
void searchParts(string parts[], int arraySize)
{
	string partKey;
	int finalIndex;
	cout << "Enter a part: ";
	cin >> partKey;
	finalIndex = binarySearchParts(parts, arraySize, partKey);
	
	if (finalIndex != -1)
		cout << "Part found at index " << finalIndex << endl;
	else
		cout << "Part not found" << endl;

}

// This function sorts the parts list using selection sort
void sortParts(string parts[], int arrSize)
{

	// Declare variables
	int minIndex;
	string placeHolder;

	// Loop to find min index within all groups
	for (int i = 0; i <= arrSize - 1; i++)
	{

		// Loop to find min index within one group - j is the alternate index
		minIndex = i;
		for (int j = i + 1; j < arrSize; j++)
		{
			if (parts[j] < parts[minIndex])
				minIndex = j;
		}

		// Test if we need switch the values of index i and j
		if (minIndex != i)
		{
			placeHolder = parts[minIndex];
			parts[minIndex] = parts[i];
			parts[i] = placeHolder;
			
		}

	}
	cout << "Parts sorted" << endl;

}

// This function will display the menu and prompt and get from the user an option
int menuOption()
{
	int userChoice;
	// display header plus options
	cout << "Part Pretenders Menu" << endl;
	cout << "1 - List car parts" << endl;
	cout << "2 - Sort car parts" << endl;
	cout << "3 - Search car parts" << endl;
	cout << "4 - Add car part" << endl;
	cout << "5 - Delete car part" << endl;
	cout << "9 - Exit" << endl << endl;

	cout << "Enter an option: ";
	cin >> userChoice;
	return userChoice;
}

void addPart(string parts[], int& partCount)
{
	// declare variables
	int emptySpaces = 0;
	string newPart;

	// checks to see if there are empty spaces
	for (int i = 0; i <= G_ARRAY_SIZE - 1; i++)
	{
		if (parts[i] == "")
			emptySpaces = emptySpaces + 1;
	}

	// if there are no spaces to add part, tell user
	if (emptySpaces == 0)
		cout << "Sorry, there are no empty slots" << endl;
	else
	{
		// Gets new part from user
		cout << "Enter a new part: ";
		cin >> newPart;
		for (int i = 0; i <= G_ARRAY_SIZE - 1; i++)
		{
			if (parts[i] == "")
			{
				// Increase part count
				partCount = partCount + 1;
				parts[i] = newPart;
				break;
			}
				
		}
		 
		
		// Notify user to sort list again
		cout << "New part was added." << endl;
		cout << "Please resort the list." << endl;
	}

}

void deletePart(string parts[], int& partCount)
{
	// declare variables
	int emptySpaces = 0;
	string deletePart;

	// checks to see if there are any spaces with a part
	for (int i = 0; i <= G_ARRAY_SIZE - 1; i++)
	{
		if (parts[i] == "")
			emptySpaces = emptySpaces + 1;
	}

	// if there are no parts to delete, tell user
	if (emptySpaces == 10)
		cout << "Sorry, there are no slots to delete" << endl;
	else
	{
		for (int i = G_ARRAY_SIZE - 1; i >= 0; i--)
		{
			if (parts[i] != "")
			{
				parts[i] = "";
				// decrease part count
				partCount = partCount - 1;
				break;
				
			}
		}
		

		// Notify user that part was removed to sort list again
		cout << "Last part was removed." << endl;
		cout << "Please resort the list." << endl;
	}

}

int main()
{
	// We will be managing a parts list with an array. The user can print out the list, sort it
	// and search for a part
	
	// Declare variables
	int currentOption;
	int partNum = 0;
	int &partCount = partNum;


	// initalize parts list
	string carParts[G_ARRAY_SIZE] = {"wheel", "mirror", "trunk", "steering", "AC", "engine", "door", "brake"};

	// Show application header
	cout << "Welcome to Part Pretenders!" << endl;
	cout << "----------------------------" << endl << endl;

	// get part count
	for (int i = 0; i < G_ARRAY_SIZE; i++)
	{
		if (carParts[i] != "")
			partCount = partCount + 1;
	}

	currentOption = menuOption();
	// Sentinel loop to check if user enters 9 which is the option to exit
	while (currentOption != 9)
	{
		// switch statement to check each case (option) that the user entered
		switch (currentOption)
		{
		  case 1:
			  cout << endl;
			  listParts(carParts, G_ARRAY_SIZE, partCount);
			  break;
		  case 2:
			  cout << endl;
			  sortParts(carParts, G_ARRAY_SIZE);
			  break;
		  case 3:
			  cout << endl;
			  searchParts(carParts, G_ARRAY_SIZE);
			  break;
		  case 4:
			  cout << endl;
			  addPart(carParts, partCount);
			  break;
		  case 5:
			  cout << endl;
			  deletePart(carParts, partCount);
			  break;
		}

		// Display the menu again to the user
		cout << endl;
		currentOption = menuOption();
	}

	// Show application close
	cout << "\nEnd of Part Pretenders!" << endl;

}
