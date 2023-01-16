#include<string>
#include<iostream>
#include<string.h>
#include<clocale>
#include<Windows.h>


using namespace std;

// Заменить все слова Си на C++  

int length(char *a)
{
	int i = 0;
	while (a[i] != '\0')
		i++;

	return i;
}


int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");

	char a[255];

	puts("Input the string");
	gets_s(a);

	//char b[255];


	int j = 0;
	int l = length(a);


	for (int i = 0, j = i+1; a[i] != '\0'; i++, j++)
	{
		if ( a[i] == 'и' || a[i] == 'И')
		{
			
			for (int p = l; p > i; p--)
			{
				a[p] = a[p - 1];
			}
			
			a[i] = '+';
			a[j] = '+';

			l++;
			
		}
		a[l] = '\0';
	}
	 

	

	cout << endl;
   
	puts(a);

	return 0;
}
