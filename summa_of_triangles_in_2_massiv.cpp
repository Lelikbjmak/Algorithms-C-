#include<iostream>

using namespace std;


void vivod(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "  ";

		}
		cout << "\n";
	}

}


int main()
{

	setlocale(LC_ALL, "ru");

	int** a;
	int n;

	cout << "Size: ";
	cin >> n;
	

	a = new int* [n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];

		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];

		}
	}

	cout << endl;

	vivod(a, n);

	cout << endl;


	//#1
	int s1 = 0;
	int s2 = 0;
	int trsum = 0;
	// верхний и нижний треугольники (если с диагоналями > меняем на >=)
	cout << "#1 - верхний и нижний треугольники " << endl << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i < j) && (i + j + 1 < n))
				s1 += a[i][j];

			if ((i > j) && (i + j + 1 > n))
				s2 += a[i][j];
		}
	}

	trsum = s1 + s2;
	cout << "Summ is " << trsum << endl;
	cout << "\n";

	//#2
	cout << "#1 - левый и правый треугольники " << endl << endl;


	s1 = 0;
	s2 = 0;
	trsum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i > j) && (i + j + 1 < n))
				s1 += a[i][j];

			if ((i < j) && (i + j + 1 > n))
				s2 += a[i][j];
		}
	}

	trsum = s1 + s2;

	cout << "Summ is " << trsum << endl;

	system("PAUSE");

	return 0;
}