#include<iostream>

// Удалить из массива все числа, встречающиеся более одного раза

using namespace std;

int main()
{

	int m;
	int i;
	cout << "Input the amount of elements ";
	cin >> m;

	int* a = new int[m];
	for (int i = 0; i < m; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];

	}

	cout << endl<<endl;

	for (int i = 0; i < m; i++)
		cout << a[i] << "  ";

	cout << endl << endl;


	int j;
	for ( int i = 1; i < m; i++)
	{

		 int buff = a[i]; // запомним обрабатываемый элемент
		// и начнем перемещение элементов слева от него
		// пока запомненный не окажется меньше чем перемещаемый
		for (  j = i - 1; j >= 0 && a[j] > buff; j--)
			a[j + 1] = a[j];

		a[j + 1] = buff; // и поставим запомненный на его новое место 

	}


	cout << endl << endl;

	for (int i = 0; i < m; i++)
		cout << a[i] << "  ";

	cout << endl;


	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			int t = a[i];
			if (a[i] == a[j])
				count++;
		}
	}

	cout << endl << endl;
	cout <<"number of repeat elements is "<< count<<endl;
	cout << endl;


	for (int i = 0; i < m; i++)
	{
		if (a[i] == a[i + 1])
		{
			for (int j = i; j < m; j++)
				a[j] = a[j + 1];
			--i;
			m--;
	    }
		
	}

	cout << endl<<endl;
	for (int i = 0; i < m; i++)
		cout << a[i] << "  ";

	return 0;
}