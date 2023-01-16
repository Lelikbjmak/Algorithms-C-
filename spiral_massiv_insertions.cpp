#include<iostream>

using namespace std;

// Заполнения массива по спирали


void vvod(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];

		}

	}

}


void vivod(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}

}
	


int main()
{
	int m, n;
	cout << "Enter the size ";
	cin >> m >> n;

	int** a = new int* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}

	cout << endl;

	vvod(a, m, n);

	cout << endl;

	vivod(a, m, n);

	cout << endl;

	int k;
	int j;
	int i=1;
	int p = n / 2;

	for ( k = 1; k <= p; k++)
	{
		for (j = k - 1; j < n - k + 1; j++)
			a[k - 1][j] = i++;
		for (j = k; j < n - k + 1; j++)
			a[j][n - k] = i++;
		for (j = n - k - 1; j >= k - 1; --j)
			a[n - k][j]= i++;
		for (j = n - k - 1; j >= k; j--)
			a[j][k - 1] = i++;

	}

	if (n % 2 == 1)
		a[p][n] = n * n;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j]<<"  ";

		}
		cout << "\n";
	}

	return 0;
}


