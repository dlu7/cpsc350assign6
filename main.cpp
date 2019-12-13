#include <iostream>
#include "sort.h"
using namespace std;

int main(int argc, char** argv) 
{
	Sort s;

	if (argc >= 2)
	{
		string file = argv[1];
		s.inputFile(file);
	}
	else
		cout << "Error: Invalid file. Please try again." << endl;

	return 0;
}