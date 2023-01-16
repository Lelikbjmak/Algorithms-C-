#include<iostream>

using namespace std;

// Найьти S на 


void vivod(int **a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j]<<"   ";
		}
		cout << endl;
	}

}

void dell(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
		delete[]a[i];

	delete[]a;
		
}


int main()
{
	cout << "Enter the size, rows, calls"<<endl;
	int n;
	cin >>n;

	int** a;
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

	vivod(a, n, n);

	cout << endl;

	int s = 0;

	
	for (int i = 0; i < n; i++)
	{                              // Сумма на главной диагонали
		s += a[i][i];
	}

	cout << "Summ on main diag is " << s << endl;

	int p = 0;
	for (int i = 0; i <n; i++)
	{                              // сумма на побочной диаогонали 
			p += a[i][n-i-1];
	}

	cout << "Summ on dop diag is " << p<< endl;
	

	/*
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s1 += a[i][i] + a[i][n - i - 1];   //  Сумма на двух диагоналях
		}
	}
	*/

	int s1 = 0;
	int s2 = 0;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i < n; j++)
		{         // если надо вместе с элементами диагонали то >= везде вместо >
			if ((j > i) && (i + j + 1 < n))
				s1 += a[i][j];
			if ((i > j) && (i + j + i > n))
				s2 += a[i][j];


		}
	}

	sum = s1 + s2;

	cout << "Summ om uper amd bottom triangle " << sum << endl;


	dell(a, n, n);

	return 0;
}