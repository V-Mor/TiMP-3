template<typename T>
class QuickSorter : public Sorter<T>
{
public:
	T* Sort(T*, T*);
	QuickSorter() : Sorter() {};
};

template<typename T>
T* QuickSorter<T>::Sort(T* nach, T* kon)
{
	if (!started)
	{
		started = true;
		startTime = clock();
	}
	T *l = nach, *r = kon, *opor;
	int length = (kon - nach) + 1;
	opor = nach + (abs(length / 2));
	//cout << *opor << endl;
	while (l <= r)
	{
		while (*l < *opor)
		{
			l++;
			numComp++;
		}
		numComp++;
		while (*r > *opor)
		{
			r--;
			numComp++;
		}
		numComp++;
		if (l <= r)
		{
			swap(*l, *r);
			numChanges++;
			r--;
			l++;
		}

	}
	if (l < kon)
		Sort(l, kon);
	if (r > nach)
		Sort(nach, r);
	finishTime = clock();
	return nach;
}
