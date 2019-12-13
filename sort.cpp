#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "sort.h"
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;

Sort::Sort() 
{
	//empty
}

Sort::~Sort()
{
	delete[] quickSortArray;
	delete[] insertSortArray;
	delete[] gnomeSortArray;
}

void Sort::inputFile(string file) 
{
	int linenum = 1;
	double size;

	string line;
	string numstring;

	ifstream infile;
	infile.open(file.c_str());
	getline(infile, numstring);
	num = stoi(numstring);

	quickSortArray = new double[num];
	insertSortArray = new double[num];
	gnomeSortArray = new double[num];

	for (int i = 0; i < num; i++) 
	{
		linenum++;
		getline(infile, line);

		try 
		{
			size = stof(line);
		}
		catch (exception e) 
		{
			cout << "Incorrect file format. Please try again." << endl;
			return;
		}

		quickSortArray[i] = size;
		insertSortArray[i] = size;
		gnomeSortArray[i] = size;
	}

	infile.close();
	sortAll();
}

void Sort::quickSort(double array[], int left, int right) 
{
	int i = partition(array, left, right);

	if (left < i - 1) 
		quickSort(array, left, i - 1);

	if (right > i)
		quickSort(array, i, right);
}

int Sort::partition(double array[], int left, int right) 
{
	//middle value is the pivot
	int pivot = array[(left + right) / 2];

	while (left <= right)
	{
		//elements to the left of pivot
		while (array[left] < pivot)
			left++;

		//elements to the right
		while (array[right] > pivot) 
			right--;

		//swapping
		if (left <= right) 
		{
			swap(array, left, right);
			left++;
			right--;
		}
	}
	return left;
}

void Sort::insertionSort(double array[])
{
	//marker variable
	for (int j = 1; j < num; j++)
	{
		//storing variable here
		double t = array[j];
		
		//shifting starts here
		int x = j;

		while (x > 0 && array[x - 1] >= t)
		{
			array[x] = array[x - 1];
			x--;
		}

		array[x] = t;
	}
}

void Sort::gnomeSort(double array[])
{
	int x = 0;
	while (x < num) 
	{
		if (array[x - 1] <= array[x] || x == 0)
			x++;
		else 
		{
			double temp = array[x];
			array[x] = array[x - 1];
			array[x--] = temp;
		}
	}
}

void Sort::swap(double array[], int b, int c)
{
	double a = array[b];
	array[b] = array[c];
	array[c] = a;
}

void Sort::sortAll()
{
	clock_t begin;
	clock_t end;
	float totaltime;

	cout << endl << "------ SORTING ------" << endl;

	//quicksort
	begin = clock();
	quickSort(quickSortArray, 0, num - 1);
	end = clock();

	//calculates the total time it takes for the sorting algorithm to sort
	totaltime = (float(end - begin) / CLOCKS_PER_SEC) * 1000;

	cout << setprecision(5) << "Quick sort sorted " << num << " numbers in " << totaltime << "ms." << endl;

	//insertion sort
	begin = clock();
	insertionSort(insertSortArray);
	end = clock();

	totaltime = (float(end - begin) / CLOCKS_PER_SEC) * 1000;

	cout << setprecision(5) << "Insertion sort sorted " << num << " numbers in " << totaltime << "ms." << endl;

	//gnome sort
	begin = clock();
	gnomeSort(gnomeSortArray);
	end = clock();

	totaltime = (float(end - begin) / CLOCKS_PER_SEC) * 1000;

	cout << setprecision(5) << "Gnome sort sorted " << num << " numbers in " << totaltime << "ms." << endl;
}