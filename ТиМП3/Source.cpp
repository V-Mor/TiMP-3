#include<iostream>
using namespace std;
void Qsort(int*, int*);
int* MergeSort(int*, int*);

int main()
{
	cout << sizeof(int) << endl;
	return 0;

}

void Qsort(int *nach, int *kon)
{
	int *l = nach, *r = kon, *opor;
	int length = (kon - nach) + 1;
	opor = nach + (abs(length / 2));
	while (l <= r)
	{
		while (*l < *opor)
			l++;
		while (*r > *opor)
			r--;
		if (l <= r)
		{
			swap(*l, *r);
			r--;
			l++;
		}

	}
	if (l < kon)
		Qsort(l, kon);
	if (r > nach)
		Qsort(nach, r);
}

int* MergeSort(int* nach, int* kon)
{
	int length = (kon - nach) + 1;
	int *opor = nach + (abs(length / 2));
	if (length == 1)
	{
		return nach;
	}
	if (length == 2)
	{
		if (*nach < *kon)
			swap(*nach, *kon);
		return nach;
	}
	int* tempMass = new int[length];
	int count = 0;
	for (int *i = MergeSort(nach, opor - 1); i <= opor; i++)
	{
		for (int *j = MergeSort((opor), kon); j <= kon; j++)
		{
			if (*i < *j)
			{
				tempMass[count] = *i;
				count++;
				if (i == opor)
					for (int *k = j; k <= kon; k++)
					{
						tempMass[count] = *k;
						count++;
					}
				break;
			}
			if (*j < *i)
			{
				tempMass[count] = *j;
				count++;
			}
			
		}
		if (count == length)
			break;
	}
	return tempMass;


}