#include<iostream>
#include<stdio.h>

using namespace std;



// << Удалить каждый 3ий элемент >>




struct steck1    // Структура для создания 1 элемента стека (состоит из 2ух частей (инфы + адрес(указыввает на некст элемент)))
{
	int info;   // info       
	steck1* a;  // Указатель на следующий элемент элемент

}*sp, p;




steck1* add(steck1* sp, int info)       // добавляем элемент в стек 
{
	steck1* spt = new steck1;  // выделяес память под новый элемент
	spt->info = info;          // заполняем информационную часть (заранее ввеленные данные info)
	spt->a = sp;               // Присоединяем элемент к вершин

	return spt;

}




void view(steck1* p)  // вывести стек на экран
{
	steck1* t = p;
	while (t != nullptr)
	{
		cout << t->info << "   ";
		t = t->a;
	}
}





void removeallst(steck1** p)    // Очистка памяти под стек
{
	while (*p != nullptr)
	{
		steck1* t = *p;
		//cout << "Удаляем:" << t->info << endl;
		*p = (*p)->a;


		delete t;
	}

}





void  dellel(steck1** p, int &size)    // Удаление элемента
{

	steck1* t = *p;
	*p = (*p)->a;
	printf("Удаляем: %d\n", t->info);

	size--;   //Уменьшаем размер стека после удаление элемента

	delete t;

}




void viewsize(int& size)
{
printf("Размер стека равен - %d элементов\n", size );
}




int main()
{
	setlocale(LC_ALL, "ru");

	int m;

	bool b = true;
	while (b)
	{
		printf("Кол-во элементов стека - ");
		scanf_s("%d", &m);
		if (m > 0)
			b = false;
		else
		{
			printf("Неверные данные! Повторите попытку!\n");
			fflush(stdin);
		}
	}

	if (m == 0)
	{
		printf("Стек пуст!\n ");
		system("pause");
		exit(0);
	}



	int bf;

	printf("Введите элементы стека: \n");
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &bf);
		sp = add(sp, bf);

	}

	printf("\nВаш стек: \n");
	view(sp);
	viewsize(m);



	printf("\nУДАЛЕНИЕ:\n");
	printf("Сколько элементов удалить? \n");
	int ans = 0;
	scanf_s("%d", &ans);


	for (int i = 0; i < ans; i++)
		dellel(&sp, m);

	
	printf("\nПосле удаления: \n");

	view(sp);
	viewsize(m);

	removeallst(&sp);  // Очищаем память, выделенную под стек и завершаем программу

	return 0;
}