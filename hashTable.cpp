#include<iostream>
#include<clocale>
#include<Windows.h>
#include<string>
#include<string.h>
#include<cmath>



using namespace std;



struct competition
{
	char surname[10];
	int place;
	int score;

}*rating;




int cont = -1;
int* H;
int cont2 = 0;





int menu();
void input();
void view();
void sv_add(int, int, int*);
int sv_search(int, int*);
void create_hash();
void view_hash();
void view_participant(int);






void input()
{
	cout << "Введите кол-во участников (9)";
	cin >> cont;


	rating = new competition[cont];



	for (int i = 0; i < cont; i++)
	{
		cout << "Фамилия: ";
		cin >> rating[i].surname;

		cout << "Место: ";
		cin >> rating[i].place;

		cout << "Кол-во очков: ";
		cin >> rating[i].score;


		cout << endl;


	}

}








void view()
{
	if (cont < 0)
	{
		cout << "Структура не введена! \n Хотите ввести? (1/2) ";

		int k;
		cin >> k;

		switch (k)
		{
		case 1: input(); return;
		case 2: return;
		}
	}

	else
		for (int i = 0; i < cont; i++)
		{

			cout << "Участник " << i + 1 << endl;
			cout << "Фамилия - " << rating[i].surname << endl;
			cout << "Кол-во очков - " << rating[i].score << endl;
			cout << "Место - " << rating[i].place << endl;

			cout << "\n\n";

		}


}







int main()
{

	setlocale(LC_ALL, "ru");

	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка


	while (true)
	{                                   // цикл для выбора операции
		switch (menu())
		{
		case 1: input(); break;
		case 2: view(); break;
		case 3: create_hash(); break;
		case 4: view_hash(); break;
		case 5: sv_search(cont2, H); break;
		default: cout << "Выберите корректную операцию! \n";
		}

		puts("Нажмите любую кнопку для продолжения...");


		system("pause");   // задержка экрана


		system("cls");  // очищаем экран консоли
	}

	return 0;

}






int menu()
{

	cout << "1. Ввести данные сруктуры " << endl;
	cout << "2. Вывести структуру на экран " << endl;
	cout << "3. Создание и заполнение Хеш-таблицы " << endl;
	cout << "4. Вывести Хеш-таблицу и структуру " << endl;
	cout << "5. Произвести поиск по Хеш-таблице " << endl;
	cout << "6. Выход " << endl;


	int answer;   // переменная ответа для передачи в функцию main()
	int pl = 0;

	while (pl != 1)   // проверка ввода данных
	{
		cin >> answer;


		if (cin.get() == (int)'\n' && (answer >= 1 && answer <= 9))
		{
			pl = 1;  // если наше число int выходим из while и передаем с в main()

		}

		else
		{
			cout << "Неверная операция. Повторите попытку!" << endl;
			fflush(stdin);  // очищаем буфер ввода, при неверных данных
			break;
		}

	}

	return answer;   // возвращаем значение с в main()

}






void sv_add(int key, int m, int* H)
{

	int p = 1;
	int i = abs(key % m);    // квадратичная адресация

	while (H[i] != -1)   // ячейка уже занята
	{
		i = i + (p * p);

		p++;

		if (i >= cont2)   // Если мы дольши до конца и не нашли место повторяем
			i = 0;
	}

	H[i] = key;

}







int sv_search(int m, int* H)
{
	int key;
	int answer;

	cout << "Введите какое кол-во очков нужно - ";
	cin >> key;


	int p = 1;
	int i = abs(key % m);


	while (H[i] != -1)
	{

		if (H[i] == key)
		{
			cout << "Элемент найден его номер в Хеш-таблице " << i << "\n\n";
			cout << "Показать данные этого участника? (1/2) " << endl;

			cin >> answer;
			switch (answer)
			{
			case 1: view_participant(key); system("Pause"); return i;
			case 2: break;
			}

			return i;


		}
		else
			i = i + p * p;


		if (i >= m)
			i = 0;


	}

	cout << "Такого элемента нет! " << endl;

	return -1;
}








void create_hash()
{

	cont2 = 15;

	H = new int[cont2];

	for (int i = 0; i < cont2; i++)
	{
		H[i] = -1;

	}


	for (int i = 0; i < cont; i++)
	{
		sv_add(rating[i].score, cont2, H);
	}


}






void view_hash()
{
	for (int i = 0; i < cont2; i++)
		cout << "H[" << i << "] = " << H[i] << endl;

}






void view_participant(int cod)
{
	for (int i = 0; i < cont; i++)
	{
		if (rating[i].score == cod)
		{

			cout << "Участник " << i + 1 << endl;
			cout << "Фамилия - " << rating[i].surname << endl;
			cout << "Кол-во очков - " << rating[i].score << endl;
			cout << "Место - " << rating[i].place << endl;

			cout << "\n\n";
		}
	}
}