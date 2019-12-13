#include <iostream>
using namespace std;

class Sort 
{
private:
	int num;

	double *quickSortArray;
	double *insertSortArray;
	double *gnomeSortArray;

public:
	Sort();
	~Sort();

	void inputFile(string file);

	void quickSort(double array[], int left, int right);
	int partition(double array[], int left, int right);

	void insertionSort(double array[]);

	void gnomeSort(double array[]);

	void swap(double array[], int a, int b);
	void sortAll();
};
