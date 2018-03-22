template<typename T>
class ShellSorter : public Sorter<T>
{
public:
	T* Sort(T*, T*);
	ShellSorter() : Sorter() {};
};

template<typename T>
T* ShellSorter<T>::Sort(T* nach, T* kon)
{


	startTime = clock();								//Фиксация времени входа в функцию (неп роверяется на 
														//повторный вход т.к. нет рекурсии)


	T *x1, *x2, *m;
	int length = (kon - nach) + 1;
	bool swapped = true;								//Признак произошедшего обмена
	int i, D, j, s;
	int d[8] = { 1, 4, 10, 23, 57, 132, 301, 701 };		//Массив шагов
	for (i = 0; i <= 7; i++)							//Выбор шага
	{
		if (length < d[i])
		{
			s = i - 1;
			break;
		}
	};
	for (j = s; j >= 0; j--)							//Счётчик шага
	{
		D = d[j];
		swapped = true;
		for (i = 0; i < (length - D); i++)				//Счётчик смещения
		{
			while (swapped == true)
			{
				swapped = false;
				for (m = nach; m <= (kon-D); m += D)
				{
					x1 = m + i;
					x2 = m + D + i;
					if (*x1 > *x2)
					{
						swap(*x1, *x2);
						numChanges++;
						numComp++;
						swapped = true;
					}
					else
						numComp++;

				}	//for (m = nach; m <= (kon-D); m += D)

			}	//while (swapped == true)

		}	//for (i = 0; i < (length - D); i++) – счётчик смещения

	}	//for (j = s; j >= 0; j--) – счёчик шага


	finishTime = clock();									//Фиксация времени выхода из функции


	return nach;
}