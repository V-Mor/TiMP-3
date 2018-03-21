#include<iostream>
#include<time.h>
#include<stdlib.h>
#include"Sorter.h"
#include"ShellSort.h"
#include"QuickSort.h"
#include"MergeSort.h"
using namespace std;

int main()
{
	int mass[1000], mass1[1000];
	MergeSorter<int> sort1;
	for (int i = 0, j = 0; i <= 499, j <= 998; i++, j += 2)
	{
		mass[j] = 999 - i;
		mass[j + 1] = i;
	}
	for (int i = 0; i <= 999; i++)
		mass1[i] = 999 - i;

	sort1.Sort(mass, &(mass[999]));
	cout << sort1.getWorkTime() << "	" << sort1.getNumChanges() << "	" << sort1.getNumComp() << endl;
	sort1.cancel();
	sort1.Sort(mass1, &(mass1[999]));
	cout << sort1.getWorkTime() << "	" << sort1.getNumChanges() << "	" << sort1.getNumComp() << endl;

	/*srand(time(NULL));


	int arr1[1], arr2[2], arr3[3], arr4[4], arr5[5], arr6[10], arr7[15], arr8[20], arr9[25], 
		arr10[30], arr11[50], arr12[75], arr13[100], arr14[250], arr15[500];


	cout << "#	time	chang	comp\n\n";
	int results[15][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	MergeSorter<int> sort1;
	for (int i = 0; i <= 99; ++i)
	{
		for (int i = 0; i <= 0; i++)
			arr1[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 1; i++)
			arr2[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 2; i++)
			arr3[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 3; i++)
			arr4[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 4; i++)
			arr5[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 9; i++)
			arr6[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 14; i++)
			arr7[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 19; i++)
			arr8[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 24; i++)
			arr9[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 29; i++)
			arr10[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 49; i++)
			arr11[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 74; i++)
			arr12[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 99; i++)
			arr13[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 249; i++)
			arr14[i] = (rand() % 1001) - 500;
		for (int i = 0; i <= 499; i++)
			arr15[i] = (rand() % 1001) - 500;

		sort1.Sort(arr1, &arr1[0]);
		results[0][0] += sort1.getWorkTime(); results[0][1] += sort1.getNumChanges(); results[0][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr2, &arr2[1]);
		results[1][0] += sort1.getWorkTime(); results[1][1] += sort1.getNumChanges(); results[1][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr3, &arr3[2]);
		results[2][0] += sort1.getWorkTime(); results[2][1] += sort1.getNumChanges(); results[2][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr4, &arr4[3]);
		results[3][0] += sort1.getWorkTime(); results[3][1] += sort1.getNumChanges(); results[3][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr5, &arr5[4]);
		results[4][0] += sort1.getWorkTime(); results[4][1] += sort1.getNumChanges(); results[4][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr6, &arr6[9]);
		results[5][0] += sort1.getWorkTime(); results[5][1] += sort1.getNumChanges(); results[5][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr7, &arr7[14]);
		results[6][0] += sort1.getWorkTime(); results[6][1] += sort1.getNumChanges(); results[6][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr8, &arr8[19]);
		results[7][0] += sort1.getWorkTime(); results[7][1] += sort1.getNumChanges(); results[7][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr9, &arr9[24]);
		results[8][0] += sort1.getWorkTime(); results[8][1] += sort1.getNumChanges(); results[8][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr10, &arr10[29]);
		results[9][0] += sort1.getWorkTime(); results[9][1] += sort1.getNumChanges(); results[9][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr11, &arr11[49]);
		results[10][0] += sort1.getWorkTime(); results[10][1] += sort1.getNumChanges(); results[10][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr12, &arr12[74]);
		results[11][0] += sort1.getWorkTime(); results[11][1] += sort1.getNumChanges(); results[11][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr13, &arr13[99]);
		results[12][0] += sort1.getWorkTime(); results[12][1] += sort1.getNumChanges(); results[12][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr14, &arr14[249]);
		results[13][0] += sort1.getWorkTime(); results[13][1] += sort1.getNumChanges(); results[13][2] += sort1.getNumComp();
		sort1.cancel();

		sort1.Sort(arr15, &arr15[499]);
		results[14][0] += sort1.getWorkTime(); results[14][1] += sort1.getNumChanges(); results[14][2] += sort1.getNumComp();
		sort1.cancel();
	}


	for (int i = 0; i <= 14; ++i)
	{
		cout << i + 1 << "	";
		cout << (((double)results[i][0]) / 100) << "	";
		cout << (((double)results[i][1]) / 100) << "	";
		cout << (((double)results[i][2]) / 100) << "	";
		cout << endl;
	}*/


}
