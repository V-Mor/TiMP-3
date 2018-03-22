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


	if (!started)									//Фиксация времени входа в функцию
	{
		started = true;
		startTime = clock();
	}


	int length = (kon - nach) + 1;
	T *opor = nach + (abs(length / 2));
	if (length == 1)								//Если в массиве один элемент, возвратить его неизменным и 
													//зафиксировать время
	{
		finishTime = clock();
		return nach;
	}
	if (length == 2)								//Пару элементо проще обменять местами, чем перезаписать в 
													//новый массив
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
	T* tempMass = new T[length];					//Временный массив для хранения новой последовательности
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
			if (y <= kon)							//Дописываются остальные элементы без сравнения, т.к. второй массив
													//закончился
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
			if (x <= opor - 1)						//Дописываются остальные элементы без сравнения, т.к. первый массив
													//закончился
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
	delete[] tempMass;								//Освобождение памяти


	finishTime = clock();							//Фиксация времени выхода из функции


	return nach;
}