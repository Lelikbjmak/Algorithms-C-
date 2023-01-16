/*
вводятся указатели first и last для обозначения начального и конечного элементов последовательности, 
а также опорный элемент mid;

вычисляется значение опорного элемента(first + last) / 2, и заноситься в переменную mid;

указатель first смещается с шагом в 1 элемент к концу массива до тех пор, пока Mas[first] > mid.
А указатель last смещается от конца массива к его началу, пока Mas[last] < mid;

каждые два найденных элемента меняются местами;
пункты 3 и 4 выполняются до тех пор, пока first < last.
*/

#include <iostream>
#include <ctime>

using namespace std;
int first, last;

//функция сортировки

void quicksort(int* mas, int first, int last)
{
	int mid;
	int f = first, l = last;

	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	cout << "Mid is " << mid << endl;

	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;

		if (f <= l) //перестановка элементов
		{
			int count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}

	} while (f < l);

	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}

//главная функция

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time_t(NULL));

	int n;
	cout << "enter the size ";
	cin >> n;

	int* A = new int[n];

	

	cout << "Исходный массив: ";

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		//cout << A[i] << " ";
	}

	first = 0; last = n - 1;

	quicksort(A, first, last);
	cout << endl << "Результирующий массив: ";

	for (int i = 0; i < n; i++) cout << A[i] << " ";
	delete[]A;
	system("pause>>void");

	return 228;
}
