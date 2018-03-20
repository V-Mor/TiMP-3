template<typename T>
class ShellSorter : public Sorter<T>
{
public:
	T* Sort(T*, T*);
};

template<typename T>
T* ShellSorter<T>::Sort(T* nach, T* kon)
{
	T *x1, *x2;
	int length = (kon - nach) + 1;
	int i = 1, D, j, s;
	int d[8] = { 1, 4, 10, 23, 57, 132, 301, 701 };
	for (i = 0; i <= 7; i++)
	{
		if (length < d[i])
		{
			s = i - 1;
			break;
		}
	};
	for (j = s; j >= 0; j--)
	{
		D = d[j];
		for (i = 0; i < (length - D); i++)
		{
			x1 = nach + i;
			x2 = nach + D + i - 1;
			if (*x1 > *x2)
				swap(*x1, *x2);
		};
	}
	return nach;
}