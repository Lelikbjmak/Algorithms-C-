#include<iostream>
#include<iomanip>

using namespace std;


// Найти кол-во особых элементов ( особый > суммы оставшихся в строке ) 

int main()
{
	int m, n;
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
		for (int j = 0; j < n; j++)
		{
			cout <<setw(3) <<a[i][j];
		}
		cout << endl;
	}


	cout << "\n";


	int h = n * m;
	int* b = new int[h];


	int s;
	int c = 0;
	int count = 0; 

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s = 0;
			int p = a[i][j];

			for (int k = 0; k < n; k++)
			{
				if (k == j)
					continue;

					s += a[i][k];
				
			}

			if (p > s)
			{
				b[c] = p;
				c++;
				count++;
			}
		
		}
	}

	cout << endl;

	for (int i = 0; i < count; i++)
		cout << setw(3) << b[i];



	for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[]a;



	delete[]b;



	return 0;
}

