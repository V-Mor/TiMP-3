template <typename T>
class Sorter
{
protected:
	bool started = false;
	int startTime, finishTime, numComp, numChanges;
public:
	virtual T* Sort(T*, T*) = 0;
	int getNumComp() { return numComp; }
	int getNumChanges() { return numChanges; }
	int getWorkTime() { return (finishTime - startTime); }

	void cancel()	//"Сброс" параметров статистики
	{
		started = false;
		startTime = 0;
		finishTime = 0;
		numComp = 0;
		numChanges = 0;
	}
	Sorter()
	{
		started = false;
		startTime = 0;
		finishTime = 0;
		numComp = 0;
		numChanges = 0;
	}
};
