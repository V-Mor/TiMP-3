template<typename T>
class MergeSorter : public Sorter<T>
{
public:
	T* Sort(T*, T*);
};

template<typename T>
T* MergeSorter<T>::Sort(T* nach, T* kon)
{
	int length = (kon - nach) + 1;
	T *opor = nach + (abs(length / 2));
	if (length == 1)
	{
		return nach;
	}
	if (length == 2)
	{
		if (*nach > *kon)
			swap(*nach, *kon);
		return nach;
	}
	T* tempMass = new T[length];
	int count = 0;
	T *x = Sort(nach, opor - 1), *y = Sort(opor, kon);
	while (count < length)
	{
		if (x <= opor - 1)
		{
			if (*x <= *y)
			{
				tempMass[count] = *x;
				count++;
				x++;
				continue;
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
			if (*y <= *x)
			{
				tempMass[count] = *y;
				count++;
				y++;
				continue;
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
	for (int *i = nach, j = 0; i <= kon, j <= length - 1; i++, j++)
	{
		*i = tempMass[j];
	}
	delete[] tempMass;
	return nach;
}