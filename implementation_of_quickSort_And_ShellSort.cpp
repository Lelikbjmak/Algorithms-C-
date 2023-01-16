#include<iostream>                            // подключаем библиотеку iostream для ввода\вывода
#include<string.h>                            // string.h для работы со строками 
#include<iomanip>                             // iomanip для функций вывода 
#include<stdio.h>  
#include<string>
#include<Windows.h>




// Отсортировать по времени отправления   сортировка quicksort + Шелла


using namespace std;




struct POEZDA         // создаем структуру POEZDA
{
	int poezdnum;     // № поезда
	/*
	struct time
	{
		int hour;
		int minute;
	}a;
	*/
	               
	//char time[5];
	double time;        // время отправления 
	char place[50];     // место прибытия 
	int freeplaces;     // свободные места 

}*list;   // создаем указатель на нашу структуру, чтобы обращаться к элементам структуры 



void ShakerSort(POEZDA* , int);
void inptstr();
void out(int);
int menu();
void menu2();



int cont = -1;           // кол-во рейсов
int first, last;    // для quicksort


void out(int cont)          // вывод структуры 
{
	
	if (cont == -1)
	{
		cout << "Вы не ввели структуру! " << endl;
		cout << "Хотите ввести данные структуры? (1(да)/2(выход в меню)) ";
		int ans;
		cin >> ans;

		switch (ans)
		{

		case 1: inptstr(); break;
		case 2: return;
		default: cout << "Выберите верную операцию! " << endl;
		}
		
	}
	

	else
	{

		std::cout << std::setw(33) << "Расписание: ";
		std::cout << "\n";

		printf(" -------------------------------------------------------\n");
		printf("|№ Рейса   |    Место      |   Время   | Свободные места|\n");
		printf(" -------------------------------------------------------\n");

		for (int i = 0; i < cont; i++)   // выводим отсортированную структуру на экран 
		{

			std::cout << std::setw(6) << list[i].poezdnum << std::setw(15) << list[i].place << std::setw(14) << setprecision(4) << list[i].time << std::setw(16) << list[i].freeplaces;
			std::cout << std::endl;
			std::cout << std::endl;
			//printf(" %5d %14s %13.2f %15d", list[i].poezdnum, list[i].place, list[i].time, list[i].freeplaces);

		}

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		return;
	}

}




void ShakerSort(POEZDA* a, int n)      // Сортировка Шелла
{
	int left, right, i;
	left = 0;
	right = n - 1;
	while (left <= right) 
	{

		for (i = right; i >= left; i--) 
		{
			if (a[i - 1].time > a[i].time) 
			{
				swap(a[i - 1], a[i]);
			}
		}
		left++;


		for (i = left; i <= right; i++) 
		{
			if (a[i - 1].time > a[i].time) 
			{
				swap(a[i - 1], a[i]);
			}
		}
		right--;


	}

}







void QuickSort(int n, POEZDA* list, int first, int last)    // Быстрая сортировка 
{

	POEZDA tmp;
	double mid;
	int f = first, l = last;
	mid = list[(f + l) / 2].time;

	cout << "Опорный элемент - " << mid << endl;

	do
	{
		while (list[f].time < mid)
			f++;
		while (list[l].time > mid)
			l--;

		if (f <= l)
		{
			tmp = list[f];
			list[f] = list[l];
			list[l] = tmp;
			f++;
			l--;

		}
	} 
	while (f < l);

	if (first < l)
		QuickSort(n, list, first, l);

	if (f < last)
		QuickSort(n, list, f, last);


}





void ShellSort(int n, POEZDA* list)      // Сортировка Шелла
{
	
	int st = n / 2;
	POEZDA temp;
	while (st > 0)
	{
		for (int i = 0; i < n - st; i++)
		{
			int j = i;
			while (j >= 0 && list[j].time > list[j + st].time)
			{
				temp = list[j];
				list[j] = list[j + st];
				list[j + st] = temp;
				j--;

			}


		}
		st = st / 2;

	}
}




void inptstr()     // Ввод структуры
{

	cout << "Введите количество рейсов: ";
	
	
	
	do
	{
		cin >> cont;

		if (cont < 0)
		cout << "Некорректный ввод!" << endl;
		fflush(stdin);

	}
	while (cont < 0);


	list = new POEZDA[cont];   // создаем массив на структуру 


	for (int i = 0; i < cont; i++)
	{

		cout << "№ рейса: ";  // № поезда
		cin >> list[i].poezdnum;

		cout << "Свободные места: ";    // свободные места 
		cin >> list[i].freeplaces;

		cout << "Место прибытия: ";      // место прибытия 
		cin >> list[i].place;

		cout << "Время прибытия: ";       // время прибытия 
		cin >> list[i].time;

		cout << endl;

	}

	first = 0;
	last = cont - 1;

}




int menu()   // Главное меню 
{
	cout << "Выберите операцию: " << endl;
	cout << "1. Ввести данные структуры" << endl;
	cout << "2. Вывести структуру на экран" << endl;
	cout << "3. Произвести сортировку и вывести структуру" << endl;
	cout << "4. Очистка структуры и выход" << endl;


	int as;

	bool lp = true;

	while (lp)
	{
		cin >> as;

		if (cin.get() == (int)'\n' && (as >= 1 && as <= 4))
			lp = false;

		else
		{
			cout << "Неверная операция! Повторите попытку! " << endl;
			fflush(stdin);
		}

	}

	return as;

}



void menu2()     // Меню сортировок
{

	cout << ">>Сортировки<<" << endl;
	cout << "1. Сортировка Шелла " << endl;
	cout << "2. Сортировка QuickSort " << endl;
	cout << "3. Шейкерная сортировка " << endl;
	cout << "4. Выход " << endl;

	int c;
	cin >> c;
	
	switch (c)
	{
	case 1: ShellSort(cont, list); out(cont); break;
	case 2: QuickSort(cont, list, first, last); out(cont);  break;
	case 3: ShakerSort(list, cont); out(cont); break;
	case 4: return;
	default: cout << "Выберите корректную сортировку! " << endl;
	}


	cout << "Посмотреть еще? (1/2)" << endl;

	int ans = 0;
	cin >> ans;

	switch (ans)
	{
	case 1:system("cls"); menu2(); break;
	case 2: return;
	}

}




int main()                                    // главная функция main 
{
	
	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка 



	while (true)
	{
		switch (menu())
		{
		case 1: inptstr(); break;
		case 2: out(cont); break;
		case 3: menu2(); break;
		case 4: delete[]list;  return 0;   // заверашаем программу 
		default: cout << "выберите верную операцию! " << endl;
		}


		puts("Нажмите любую кнопку для продолжения...");


		system("pause");   // задержка экрана


		system("cls");  // очищаем экран консоли

	}


}


