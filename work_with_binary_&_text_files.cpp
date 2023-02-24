#include <stdio.h>                  
#include<iostream>                // ввод\вывод            
#include<string.h>                // для строк            
#include<iomanip>                 //  для setw            
#include<io.h>                    // для работы с низкоуровневыми функциями ввода\вывода
#include<stdlib.h>                // для system() + работа со строками
#include<clocale>
#include<Windows.h>               // Для работы с русским языком 
#include<cstdlib>                   


//#define _CRT_SECURE_NO_WARNING


using namespace std;           // пространство имен std


FILE* fl;                      // создаем 2 файла, один из них бинарный (fl), второй текстовый (ft) 
FILE* ft;


struct POEZDA         // создаем структуру POEZDA
{                     
	int poezdnum;     // № рейса
	char time[10];    // время прибытия 
	char place[50];   // место прибытия
	int freeplaces;   // свободные места

}*list, train;   // создаем указатель на нашу структуру, чтобы обращаться к элементам структуры + переменную, для работы со структурой и файлом


int cont1 = 0;        // кол-во элементов структуры 
char fname[20];       // имя бинарного файла
int s = 0;            // длина файла
char punkt[10];       // место прибытия для записи в файл
char fnamet[20];      // имя текстового файла для сохранения инфы 
char delname[20];     // удаления файла



void inputlist();     // Заполнить структуру и записать в бинарный файл
void redlist();       // прочитать данные из файла и вывести в консоль
void consolerez();    // вывести результат в консоль до определенного города
void filerez();       // Записать определнный рейс в файл ( текстовый )
int menu();           // меню
char* fnam();         // ввод имени бинарного файла 
void deletFile();     // удаление файла
void openfile();      // открытие проводника для просмотра файлов
char* fnam1();        // ввод имени текстового файла 
void sorted(); //вывод отсортированной структуры на экран и переписываем в файл


int main()       // Главная функция main
{
	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка

	while (true)
	{                                   // цикл для выбора операции
		switch (menu())
		{
		case 1 : case 8: inputlist(); break;
		case 2: redlist(); break;
		case 3: consolerez(); break;
		case 4: filerez(); break;
		case 5: deletFile(); break;
		case 6: openfile(); break;
		case 7: sorted(); break;
		case 9: return 0;
		default: cout << "Выберите корректную операцию! \n";
		}

		puts("Нажмите любую кнопку для продолжения...");


		system("pause");   // задержка экрана


		system("cls");  // очищаем экран консоли
	}
}






int menu()              // функция menu
{
	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка 

	cout << "Выберите операцию: " << endl;
	cout << "1. Вести данные в новый файл  " << endl;
	cout << "2. Прочитать данные из файла  " << endl;
	cout << "3. Вывести данные в консоль " << endl;
	cout << "4. Записать данные в текстовый файл " << endl;
	cout << "5. Удалить файл " << endl;
	cout << "6. Открыть текстовый файл " << endl;
	cout << "7. Вывод отсортированной структуры" << endl;
	cout << "8. Дополнить данными существующий файл " << endl;
	cout << "9. Выход " << endl;
	cout << endl;
	
	int c;   // переменная ответа для передачи в функцию main()
	int pl = 0;

	while (pl != 1)   // проверка ввода данных
	{
		cin >> c;
		 
		
		if (cin.get() == (int)'\n' && (c>=1 && c<=9 ))   
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

	return c;   // возвращаем значение с в main()

}






char* fnam()          //  Функция для ввода имени бинарного файла и проверки введено ли оно вообще
{ 
	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка

	if (strlen(fname)) return fname;     // если имя файла уже введено возвращаем имя файла и передает его в вызванную вами функцию
	cout << "Введите имя бинарного файла " << endl;   // ввод имени бинарного файла со структурой
	cin >> fname;
	return fname;
}





void inputlist()         // Функция для заполнения структуры
{
	
	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка

	errno_t err;         // Специальная переменная для работы с файлом ( определения ошибки при открытии файла ) 
	  if((err = fopen_s(&fl, fnam(), "ab") != 0 && (err = fopen_s(&fl, fnam(), "wb")) != 0))
		{
			cout << "Ошибка в создании файла! " << endl;
			return;
		}

	  cout << "Введите количество рейсов ";
	  cin >> cont1;

	  list = new POEZDA[cont1];

	  for (int i = 0; i < cont1; i++)      // Заполняем структуру
	  {
		  std::cout << "Номер рейса: ";  // № рейса
		  std::cin >> list[i].poezdnum;

		  std::cout << "Количество свободных мест: ";    // свободные места
		  std::cin >> list[i].freeplaces;

		  std::cout << "Место прибытия: ";      // место прибытия
		  std::cin >> list[i].place;

		  std::cout << "Время прибытия: ";      // время прибытия
		  std::cin >> list[i].time;
		  cout << "\n";

		  fwrite(&list[i], sizeof(POEZDA), 1, fl);       // записываем структуру в файл
		  cout << "\n";
		
	  }

	
	fclose(fl);        // закрываем файл

}


void sorted()
{

	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка


	errno_t err;   // Специальная переменная для работы с файлом ( определения ошибки при открытии файла )
	if (err = fopen_s(&fl, fnam(), "rb") != 0)    // ошибка при открытии файла
	{
		cout << "Ошибка в открытии бинарного файла! " << endl;
		return;

	}


	s = _filelength(_fileno(fl)) / sizeof(POEZDA);    // считаем длину файла для записи в структуру ( в байтах )


	list = new POEZDA[s];    // создаем массив на структуру для записи в консоль

	fread(list, sizeof(POEZDA), s, fl); // считавыем данные из файла

	cout << endl << endl;

	POEZDA tp;                            // Сортировка структуры по убывания кол-ва свободных мест

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s - 1; j++)
		{
			if (list[j].freeplaces < list[j + 1].freeplaces)
			{
				tp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tp;

			}
		}
	}



	fclose(fl);                   // закрываем файл



	if (err = fopen_s(&fl, fnam(), "wb") != 0)    // ошибка при открытии файла
	{
		cout << "Ошибка в открытии бинарного файла! " << endl;
		return;

	}

	for (int i = 0; i < s; i++)                     // перезапишем стурктуру в файл
	{
		cout << "Рейс № " << list[i].poezdnum << "\n" << setw(2) << "Место прибытия - " << list[i].place << setw(2) << ".Свободные места - " << list[i].freeplaces << setw(2) << ".Время прибытия " << list[i].time << endl;
		cout << endl;
		fwrite(&list[i], sizeof(POEZDA), 1, fl);
	}

	delete[]list;


	fclose(fl);



}



void redlist()           // функция для вывода структуры из файла на экран в консоль 
{                
	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка


	errno_t err;   // Специальная переменная для работы с файлом ( определения ошибки при открытии файла )
	if (err = fopen_s(&fl, fnam(), "rb") != 0)    // ошибка при открытии файла
	{
		cout << "Ошибка в открытии бинарного файла! " << endl;
		return;

	}

	s = _filelength(_fileno(fl)) / sizeof(POEZDA);    // считаем длину файла для записи в структуру ( в байтах )


	list = new POEZDA[s];    // создаем массив на структуру для записи в консоль

	fread(list, sizeof(POEZDA), s, fl); // считавыем данные из файла


	cout << endl << endl;
	

	for (int i = 0; i < s; i++)           // записываем данные в консоль
	{
		cout <<"Рейс № "<< list[i].poezdnum<< "\n" << setw(2) << "Место прибытия - " << list[i].place << setw(2) << ".Свободные места - " << list[i].freeplaces << setw(2) << ".Время прибытия " << list[i].time<<endl;
		cout << endl;
	}

	delete[]list;     // очищаем память под массив

	fclose(fl);    // закрываем файл

}




void consolerez()             // Вывести результат на экран в консоли
{
	
	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка


	errno_t err;
	if (err = fopen_s(&fl, fnam(), "rb") != 0)            // при ошибке открвтия файла
	{
		cout << "Ошибка в открытии бинарного файла! " << endl;
		return;
	}

	s = _filelength(_fileno(fl)) / sizeof(POEZDA);         // Вычисляем длину файла для вывода в консоль
	
	int ss = 0;
	int pp = 0;

			cout << "Введите место куда вам нужно ";   // вводим место, которое нам надо
			cin >> punkt;
			cout << "\n";

			
			

			
				for (int i = 0; i < s; i++)
				{
					fread(&train, sizeof(POEZDA), 1, fl);     // считываем данные из файла

					if (strcmp(train.place, punkt) == 0)      // если место прибытия из структуры равно тому что ввели, то выводим
					{     
						pp++;   // считаем кол-во pp для исключения, что поездов в это место нет
						cout << "Номер рейса " << train.poezdnum << "\n" << "Время прибытия " << train.time << ".Место прибытия " << train.place << ".Количество свободных мест " << train.freeplaces << endl << endl;
						// записываем данные в консоль
					}
				}
			

			if (pp == 0)
			{
				cout << "Нет поездов до " << punkt << endl;   // если пункт и данныес структуры не совпали -> поездов туда нет
			}

			cout << "Хотите посмотреть рейсы до других городов? (да(1)/нет(2)\nЗаписать данный рейс в файл? (да(3))" << endl;
			cin >> ss;
			switch (ss)
			{

			case 1: return consolerez();  // если да то  вызываем еще раз эту функцию 
			case 2: return;               // если нет вызвращаемся в меню
			case 3: return filerez();     // если захотим записать данный рейс в файл  

			}
	
	
	fclose(fl);   // закрываем файл
}




char* fnam1()          //  Функция для ввода имени файла и проверки введено ли оно вообще
{
	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка

	if (strlen(fnamet)) return fnamet;    // функция для задания имени текстового файла и проверки на его наличие 
	cout << "Введите имя текстового файла для сохранения информации по (последнему) рейсу " << endl;
	cin >> fnamet;
	return fnamet;
	
}




void filerez()        // запись результата в текстовый файл
{
		
	
	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка

	

	//fopen_s(&ft, fnamet, "wt");      // открываем текстовый файл для записи


	errno_t err;   // Специальная переменная для работы с файлом ( определения ошибки при открытии файла )
	if ((err = fopen_s(&ft, fnam1(), "wt") != NULL))
	{
		cout << "Ошибка при открытии открытии текстового файла! " << endl;        // ошибка при открытии файла
			return;
	}

	// fopen_s(&fl, fnam(), "rb");            // открываем бинарный файл для чтения данных

	if ((err = fopen_s(&fl, fnam(), "rb")) != NULL)
	{
		cout << "Ошибка при открытии бинарного файла! " << endl;        // ошибка при открытии файла
		return;
	}

	s = _filelength(_fileno(fl)) / sizeof(POEZDA);        // длина файла ( в байтах )

	for (int i = 0; i < s; i++)
	{
		fread(&train, sizeof(POEZDA), 1, fl);            // чтение из бинарного файла и запись в текстовый
		if (strcmp(train.place, punkt) == 0)
			fprintf(ft," Номер рейса - %d. Место прибытия - %s. Время прибытия - %s. Свободные места - %d \n", train.poezdnum, train.place, train.time, train.freeplaces);
	}   

	fclose (fl);  // закрываем бинарный файл

	fclose(ft);   // закрываем текстовый файл 

	cout << "Операция прошла успешно!"<<endl;  // если ошибок не возникло выводим сообщение на экран 
}



void deletFile()   // функция удаления файла
{

	SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");  // подключение русского языка

	int k; // переменная для switch

	cout << "Удалить файл, созданный во время текущего сеанса программы (1) "<<endl;
	cout << "Введите имя существующнго файла, который хотите удалить (2) "<<endl;

	cout << fname << endl;
	cout << fnamet << endl;

	int pp = 0;  
	cin >> k;
	switch (k)   // Выберем нужное нам действие 
	{
	case 1: 
	{
		while (pp != 1)
		{
			cout << "Введите имя файла ";
			cin >> delname;       
			if ((strcmp(fname, delname) == 0) || (strcmp(fnamet, delname) == 0))
			{
				remove(delname);
				cout << "Файл успешно удален! " << endl;
				return;
			}
			else
			{
				cout << "Неверное имя файла. Повторите попытку ";
				fflush(stdin);

			}
			
		}
	}

	case 2: 
	{
		cout << "Введите имя файла ";
		cin >> delname;
		remove(delname);   // удаляем файл с введенным именем
		cout << "\nФайл успешно удален! ";
		return;  // выходим в меню 
	}

	default: cout << "Выберите корректную операцию! " << endl;
	}

}



void openfile()    // функция открытия папки в проводнике с проектом и файлами 
{
	int a;    

	cout << "Открыть папку для просмотра фалов? да(1)/нет(2) " << endl;
	
	cin >> a;    // выбираем действие 

	switch (a)
	{
		// открываем проводник 
	case 1: system("explorer C:\\Users\\denis\\source\\repos\\LABA8(fileeee)№9 examen\\LABA8(fileeee)№9 examen");
	case 2: return;

	}

}