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
	int *x = MergeSort(nach, opor - 1), *y = MergeSort(opor, kon);
	while (count < length)
	{
		if (x <= opor - 1)
		{
			if (*x <= *y)
			{
				tempMass[count] = *x;
				count++;
				x++;
			}
		}
		else
			if (y <= kon)
			{
				tempMass[count] = *y;
				count++;
				y++;
				continue;
			}
		if (y <= kon)
		{
			if(*y <= *x)
			{
				tempMass[count] = *y;
				count++;
				y++;
			}
		}
		else
			if (x <= opor - 1)
			{
				tempMass[count] = *x;
				count++;
				x++;
				continue;
			}
	}
	for (int *i = nach; i <= kon; i++)
	{
		*i = *tempMass;
		tempMass++;
	}
	return nach;


}