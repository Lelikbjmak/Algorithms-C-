#include<iostream>
#include<string.h>
#include<string>

using namespace std;

// Вывести группы единиц с макс и мин кол-вом  ( строка из 0\1 )


void vivod(int *a, int j)
{
	for (int i = 0; i < j; i++)
	{
		cout << a[i] << "  ";
	}
}


int main()
{
	char a[255];
	
	puts("Input the string ");

	gets_s(a);

	
	int indexmax = 0;
	int indexmin = 0;

	int n = strlen(a);

	cout <<"Length of the string is "<< n << endl;

	int* k = new int[n];
	int j = 0;

	int count = 0;

	int onec = 0;
	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == '1')
			onec++;

	}

	if (onec == 0)
	{
		cout << "There are no '1' in the string!" << endl;
		exit(0);

	}

	for (int i = 0; a[i] != '\0'; i++)
	{


		if (a[i] == '1')
		{
			count++;
			if (a[i + 1] != '1')
			{

				k[j] = count;
				j++;
				count = 0;
				
			}

		}
		
			
	}

	cout << endl;

	vivod(k,j);


	cout << endl;

	int max = k[0];
		int min = k[0];

	for (int i = 1; i < j; i++)
	{
		if (k[i] > max)
		max = k[i];

	    if (k[i] < min)
		min = k[i];
	}

	cout << "\n Max is " << max << "\tMin is " << min << endl;

	for ( int i = 0; a[i] !='\0'; i++)
		while (a[i] == '0' && a[i+1] == '0')
		{
			for (int j = i; a[j] != '\0'; j++)
				a[j] = a[j + 1];
	    }

	cout << endl;

	puts(a);

	cout << endl;


	char* cmin, * cmax;
	char* pt = nullptr;
	char* ch;
	ch = strtok_s(a, "0", &pt);
	cmin=cmax=ch;

		while (ch != nullptr)
		{
			if (strlen(ch) > strlen(cmax))
				cmax = ch;
			else
				if (strlen(ch) < strlen(cmin))
					cmin = ch;
			ch = strtok_s(nullptr, "0", &pt);
		}

		cout << endl;

		cout<<cmax<<"\n";
		cout << min << "\n";
	

	return 0;
}

/*char* pt = nullptr;
char* ch;

ch = strtok_s(a, b, &pt);

int count = 0;

while (ch != nullptr)
{
	puts(ch);
	count++;
	ch = strtok_s(nullptr, b, &pt);
}
*/