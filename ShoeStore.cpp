// Cami Lacy
// Super Shoe Store program
// This program will take in shoe type, size, width, color, & quantity

#include<iostream>	
#include<iomanip>	
#include<string>	 
#include<vector>
#include<fstream>
using namespace std;

// Structure Definitions
struct Shoes
{
	string shoeType; 
	double shoeSize;
	char shoeWidth;
	string shoeColor;
	int shoeQuantity;
};
 
// Function Prototypes
void displayWelcome();
bool openFile(ifstream& inFile, string filename);
void readData(ifstream& inFile, vector<Shoes*>& sv);
void sortData(vector<Shoes*>& sv);
void swapShoes(Shoes*& s1, Shoes*& s2);
void displayData(vector<Shoes*> sv);
void deleteShoes(vector<Shoes*>& sv);

int main()
{
	// Local Variables
	vector<Shoes*> shoesData;
	string myFile;
	bool success;
	ifstream inputFile;

	// Display Welcome Message
	displayWelcome();

	// Ask User for File Name
	cout << "Please enter the name of the file: ";
	cin >> myFile;

	// Check for Successful Open
	success = openFile(inputFile, myFile);

	if (success == true)
	{
		// Read File into Vector
		readData(inputFile, shoesData);

		// Sort the Data in the Vector
		sortData(shoesData);


		// Close File
		inputFile.close();

		// Display Data to Screen
		displayData(shoesData); 


		// Delete Allocated Memory
		deleteShoes(shoesData);

	}
	else
	{
	cout << "There was an error, this file could not be opened.\n\n";
	}


	system("pause");
	return 0;
} // end main


/*******************************************************************/
/*                 Function Definitions Below                      */
/*******************************************************************/

void displayWelcome()
{
	cout << "**************************************************************************\n";
	cout << "*   Welcome to the Super Shoes Store Program! Here, the program          *\n";
	cout << "*   will read shoe type, size, width, color, and quantity data           *\n";
	cout << "*   from a file. Additionally, shoe size is sorted from low to high!     *\n";
	cout << "**************************************************************************\n\n";

} // end displayWelcome()

bool openFile(ifstream& inFile, string filename)
{
	// Local variables
	bool open = false;

	// Open File to Read
	inFile.open(filename);

	// Check for Success
	if (inFile)
	{
		// Set Open Flag to True
		open = true;
	}

	return open;

} // end openFile



void readData(ifstream& inFile, vector<Shoes*>& sv) // How to read each piece of data in the rows?
{
	// Local Variables
	Shoes* newShoes;

	while (!inFile.eof())
	{
		
		// Allocate Memory for the Shoe Data
		newShoes = new Shoes;


		// Copy Data into the Shoe Structure
		inFile >> newShoes->shoeType;
		inFile >> newShoes->shoeSize;
		inFile >> newShoes->shoeWidth;
		inFile >> newShoes->shoeColor;
		inFile >> newShoes->shoeQuantity;

		// Add the New Shoes to the Vector 
		sv.push_back(newShoes);
	
	}


} // end readData


void sortData(vector<Shoes*>& sv)
{
	//Local variables
	bool swap = true;
	int i, j;

	// Bubble Larges Number to Right
	for (i = sv.size() - 1; i > 0 && swap == true; i--)
	{
		swap = false;
		for (j = 0; j < i; j++)
		{
			// Compare the elements
			if (sv[j]->shoeSize > sv[j + 1]->shoeSize)
			{
				// Swap the Values
				swapShoes(sv[j], sv[j + 1]);

				swap = true;
			}
		} // end j for loop
	} // end i for loop



} // end sortData


void swapShoes(Shoes*& s1, Shoes*& s2)
{
	// Local Variables
	Shoes* temp;

	temp = s1;
	s1 = s2;
	s2 = temp;

} // end swapValue

void displayData(vector<Shoes*> sv)
{

	cout << "\n\n" << setw(50) << "Super Shoe Store Inventory Report\n\n";
	cout << "Shoe Type" << setw(12) << "Size" << setw(13) << "Width" << setw(13) << "Color" << setw(15) << "Quantity\n";
	cout << "-------------------------------------------------------------\n";

	// for loop diplays vector data
	for (Shoes* s : sv)
	{
		cout << left << setw(17) << s->shoeType;
		cout << setw(14) << s->shoeSize;
		cout << setw(11) << s->shoeWidth;
		cout << setw(13) << s->shoeColor;
		cout << right << setw(3) <<  s->shoeQuantity << endl;
	}
	

} // end displayData


void deleteShoes(vector<Shoes*>& sv)
{
	// Use a For Each Loop
	for (Shoes* s : sv)
	{
		// Delete the memory allocated
		delete s;
	}
	
	// Clear Vector Contents & Set Size to Zero
	sv.clear();

} // end deleteShoes