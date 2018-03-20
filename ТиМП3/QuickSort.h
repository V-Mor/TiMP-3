template<typename T>
class QuickSorter : public Sorter<T>
{
public:
	T* Sort(T*, T*);
};

template<typename T>
T* QuickSorter<T>::Sort(T* nach, T* kon)
{
	T *l = nach, *r = kon, *opor;
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
	return nach;
}
