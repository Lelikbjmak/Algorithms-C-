#include<iostream>

using namespace std;

// Определить количество различных элементов матрицы повторяющиеся элементы считать 1 раз


int main()
{
	int m, n;
	cout << "rows  colls \n";
	cin >> m >> n;

	int** a;

	a = new int* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}

	cout << "\n";

	

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j< n; j++)
		{
			cout << a[i][j]<<"   ";
		}
		cout << endl;
	}

	cout << "\n";



	int** b;
	b = new int* [m];
	for (int i = 0; i < m; i++)
	{
		b[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			b[i][j] = 1;
		}
	}
	cout << "\n";

	for (int i = 0; i< m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j] << "  ";

		}
		cout << endl;
	}

	cout << "\n";



	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] == 1)
			{
				for (int k = 0; k < m; k++)
				{
					for (int p = 0; p < n; p++)
					{

						if ((a[i][j] == a[k][p]) && (b[k][p] == 1) && !(i==k && j==p ))
						{
							b[k][p] = 0;

						}

					}
				}
			}

		
	    }

	}

	
	cout << "\n";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j] << "  ";

		}
		cout << endl;
	}

	cout << "\n";

	int count = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] == 1)
			{
				count++;
				cout << a[i][j] << "  ";

			}

		}
	}

	cout << endl;

	cout << "Count is " << count;

		
	

	system("pause");
	return 0;

}
