#include<iostream>
#include"Sorter.h"
#include"ShellSort.h"
#include"QuickSort.h"
#include"MergeSort.h"
using namespace std;

int main()
{
	int *mass = new int[5];
	for (int i = 0; i <= 4; i++)
		cin >> mass[i];
	ShellSorter<int> sorter1;
	sorter1.Sort(mass, &(mass[4]));
	for (int i = 0; i <= 4; i++)
		cout << mass[i] << " ";
	cout << endl;
	return 0;

}
