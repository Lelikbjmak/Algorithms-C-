#include<iostream>

// упорядочить столбцы по возрастанию наименьших элементов 

using namespace std;

int main()
{
	int m; 
	int n;
	int k = 0;

	while (k != 1)
	{
		cout << "rows ";
		cin >> m;
		cout << "cols ";
		cin >> n;

		if (n < 1 && m < 1)
		{
			cout << "error data ";
			fflush(stdin);

		}

		else
			k = 1;

	}

	cout << "\n";

	// creat dynamic massiv 

	int** a;
	 a = new int* [m];
	for (int i = 0; i < m; i++)
	{
		 a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "]["<<j<<"]= ";
			cin >> a[i][j];
		}
	}

	//

	cout << "\n";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << "\n";
	}

	int min = a[0][0];
	int s = 0;

	for (int j = 0; j < n; j++)
	{
		for (int p = 0; p < m; p++)
		{
			min = a[p][j];

			for (int i = p; i < m; i++)
			{

				if (a[i][j] < min)
				{
					min = a[i][j];

				}
			}
		}

	}
	

	for (int i = 0; i < m; i++)
		delete[]a[i];

	delete[]a;

	return 0;
}



