#include<iostream>
#include"Sorter.h"
#include"ShellSort.h"
#include"QuickSort.h"
#include"MergeSort.h"
using namespace std;

int main()
{
	char *mass = new char[10];
	for (int i = 0; i <= 9; i++)
		cin >> mass[i];
	ShellSorter<char> sorter1;
	sorter1.Sort(mass, &(mass[9]));
	for (int i = 0; i <= 9; i++)
		cout << mass[i] << " ";
	cout << endl;
	return 0;

}
