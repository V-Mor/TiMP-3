template<typename T>
class MergeSorter : public Sorter<T>
{
public:
	T* Sort(T*, T*);
	MergeSorter() : Sorter() {};
};

template<typename T>
T* MergeSorter<T>::Sort(T* nach, T* kon)
{
	if (!started)
	{
		started = true;
		startTime = clock();
	}
	int length = (kon - nach) + 1;
	T *opor = nach + (abs(length / 2));
	if (length == 1)
	{
		finishTime = clock();
		return nach;
	}
	if (length == 2)
	{
		if (*nach > *kon)
		{
			swap(*nach, *kon);
			numComp++;
			numChanges++;
		}
		else
			numComp++;
		finishTime = clock();
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
				numComp++;
				numChanges++;
				continue;
			}
			else
				numComp++;
		}
		else
			if (y <= kon)
			{
				tempMass[count] = *y;
				count++;
				y++;
				numChanges++;
				continue;
			}
		if (y <= kon)
		{
			if (*y <= *x)
			{
				tempMass[count] = *y;
				count++;
				y++;
				numComp++;
				numChanges++;
				continue;
			}
			else
				numComp++;
		}
		else
			if (x <= opor - 1)
			{
				tempMass[count] = *x;
				count++;
				x++;
				numChanges++;
				continue;
			}
	}
	for (T *i = nach, j = 0; i <= kon, j <= length - 1; i++, j++)
	{
		*i = tempMass[j];
	}
	delete[] tempMass;
	finishTime = clock();
	return nach;
}