#include<iostream>
#include<clocale>


using namespace std;


struct elem
{
	int info;
	elem* next;
	elem* prev;

};




void view(elem*sp)   // sp - begin of list
{
	while (sp != nullptr)
	{
		cout << sp->info<<" ";
		sp = sp->prev;

	}

}



elem* create(elem* begin, elem *end, int inf)   // создание очереди из 1 элемента
{
	elem* sp = new elem;
	sp->info = inf;
	sp->next = nullptr;
	sp->prev = nullptr;
	begin = end = sp;

	return sp;

}




void add(elem* end, int inf)  // добавление элемента (в конец очереди)
{
	elem *sp = new elem;
	sp->info = inf;
	sp->next = nullptr;
	sp->prev = end;
	end->next = sp;

	end = sp;
	return;
}



void remove(elem*sp)
{
	cout << sp->info << " ";
	sp->prev->next = sp->next;
	sp->next->prev = sp->prev;

	delete sp;
	
}




int main()
{
	setlocale(LC_ALL, "ru");


	int count = 0;
	bool b = true;


	while (b)
	{
		cout << "Введите количество элементов: ";
		cin >> count;

		if (count == 0)
		{
			cout << "Очередь пуста!" << endl;
			cout << "Желаете повторить ввод числа элементов? (1/2)" << endl;
			int ans;
			cin >> ans;
			switch (ans)
			{
			case 1: main(); break;
			case 2: system("pause"); exit(0);
			}
		}


		if (count < 1)
		{
			cout << "Неверный ввод данных! Повторите попытку!  " << endl;
			fflush(stdin);

		}

		else
			b = false;


	}

	elem* begin, * end, * now;   // 1ый последний и текущий элементы

	begin = end = nullptr; 


	cout << "Заполнение очереди: " << endl;

	int buff;

	cin >> buff;
	now = create(begin, end, buff);  // создание очереди из 1 элемента
	begin = end = now;

	for (int i = 1; i < count; i++)
	{
		cin >> buff;
		add(end, buff);

	}


	cout << "\nВаша очередь: " << endl;
	view(end);
	//cout << end->info<<"  "<<begin->info;
	

	

	return 0;

}