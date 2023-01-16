#include<string>
#include<string.h>
#include<iostream>
#include<iomanip>

using namespace std;


// Вывести на экран порядковый номер слова max длины и номер позиции в строке, с которой оно начинается

int main()
{
	char a[255];
	char a1[255];
	char b[] = " ";

	
	puts("input the string");

	gets_s(a);

	strcpy_s(a1, a);

	cout << endl;


	char* pt = nullptr;
	char* ch;

	ch = strtok_s(a, b, &pt);

	int count = 0;

	while (ch != nullptr)
	{
		puts(ch);
		count++;
		ch = strtok_s(nullptr, b, &pt);
	}



	strcat_s(a1, b);

	int* s = new int[count];
	int* index = new int[count];

	int j = 0;
	int k = 0;

	for (int i = 0; a1[i] !='\0'; i++)
	{
		if (a1[i] != ' ')
			k++;
		else
		{
			index[j] = i - k;
			s[j] = k;
			j++;
			k = 0;
		}
		
	}

	cout << endl;

	cout << "count of symbols";

	for (int i = 0; i < j; i++)
	{
		cout <<setw(4)<< s[i];

	}

	cout << endl;

	cout << "index i of each element";

	for (int i = 0; i < j; i++)
	{
		cout <<setw(4)<< index[i];

	}

	int max = index[0];
	int delindex = 0;

	for (int i = 0; i < j; i++)
	{
		if (s[i] > max)
		{
			max = s[i];
			delindex = index[i];
		}
	}
	
	cout << "\n";

	cout << "Count of symbols in the vast word is " << max << "  It's index in the string is " << delindex;

	cout << "\n";

	for ( int l = 0; l<=max; l++)
	for (int i = delindex; i<delindex + max; i++)
	{
		
	    a1[i] = a1[i + 1];
			
	}

	for (int i = 0; a1[i] != '\0'; i++)
	{
		while (a1[i] == ' ' && a1[i + 1] == ' ')
		{
			for (int l = i; a1[l] != '\0'; l++)
				a1[l] = a1[l + 1];
		}
	}

	puts(a1);

	return 0;
}