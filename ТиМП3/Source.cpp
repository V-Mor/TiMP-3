#include<iostream>
using namespace std;
void Qsort(int*, int*);

int main()
{
	int mass[10];
	for (int i = 0; i <= 9; i++)
		mass[i] = 9 - i;
	Qsort(mass, &(mass[9]));
	for (int i = 0; i <= 9; i++)
		cout << mass[i] << " ";
	cout << endl;
	return 0;

}

void Qsort(int *nach, int *kon)
{
	int *l = nach, *r = kon, *opor;
	int length = (kon - nach) / sizeof(int);
	opor = nach + sizeof(int) * (abs(length / 2));
	while (l <= r)
	{
		while (*l < *opor)
			l++;
		while (*r > *opor)
			r--;
		if (l < r)
			swap(*l, *r);
	}
	if (l < kon)
		Qsort(l, kon);
	if (r > nach)
		Qsort(nach, r);
}