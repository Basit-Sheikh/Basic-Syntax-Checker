#include "utilities.h"

int main()
{
	// Prompt the user to enter a file name
	string file_name;
	cout << "Enter file name (or use predefined one: \'balanced.txt\' \'unbalanced1.txt\' \'unbalanced2.txt\'): ";
	cin >> file_name;

	//Checks for file
	ifstream infile(file_name.c_str());
	if (!infile)
		cerr << "Error: Cannot open " << file_name << ".txt!" << endl;

	PrintLines(infile);
	BalanceCheck(file_name, infile);
	//system("PAUSE") //uncomment if you are on windows OS and the program ends too quickly for you to read the results
	return 0;
}