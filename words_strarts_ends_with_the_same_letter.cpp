#include<iostream>
#include<string>
#include<string.h>

using namespace std;

// вывести слова которые начинаютися и заканчиваются одной и той же буквой

int main()
{
	char a[255];
	char a1[255];

	puts("Input the string ");

	gets_s(a);

	cout << endl;

	strcat_s(a, " ");

	int n = strlen(a);

	int p = 0;
	int k = 0;
	a1[0] = '\0';
	for (int i = 0; i < n; i++)
	{
		if (a[i] != ' ')
		{
			a1[k] = a[i];
			a1[k + 1] = '\0';
			k++;
		}
		else
		{
			if (strlen(a1) > 0 && a1[0] == a1[k - 1])
			{
				puts(a1);
				p++;
			}
			a1[0] = '\0';
			k = 0;
		}
	}

	cout << endl;

	if (p == 0)
		puts("No such words");
	else
		cout << "count is " << p << endl;


	system("pause");
	return 0;
}
	
