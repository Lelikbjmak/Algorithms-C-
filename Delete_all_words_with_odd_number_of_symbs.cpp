#include<iostream>
#include<string>
#include<string.h>
#include<ctype.h>

// удалить из строки слова в которых четное кол-во символов

using namespace std;

int main()
{
	char a[255];   // создаем строку 
	char b[] = " ";
	char a1[255];


	puts("Input the string");

	gets_s(a);

	strcpy_s(a1, a);

	cout << endl;

	


	char* pt = nullptr;
	char* ch;

	ch = strtok_s(a, b, &pt);

	while (ch != nullptr)
	{
		puts(ch);
		ch = strtok_s(nullptr, b, &pt);

	}

	int k = 0;

	cout << endl;

	puts(a1);

	strcat_s(a1,b);

	
	for (int i = 0; a1[i] != '\0'; i++)
	{
		if (a1[i] != ' ' )
			k++;
		else
		{
			cout << k<<"     ";
			int j = i;
			int p = i - k; 
			

			if (k % 2 == 0)
			{
				for (int s = 0; s <= k; s++)
				{
					for (int z = p; z < j; z++)
						a1[z] = a1[z + 1];
				}
			}
			k = 0;
		}
	
	}


	for (int i = 0; a1[i] != '\0'; i++)
	{

		while (a1[i] == ' ' && a1[i + 1] == ' ')
		{
			for ( int j = i; a1[j] !='\0'; j++)
			a1[j] = a1[j + 1];
		}
	}
		
	cout << endl<<endl;

	puts(a1);

	system("pause");
	
}

