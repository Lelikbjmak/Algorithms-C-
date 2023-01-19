#include<iostream>

using namespace std;

// найти элементы которые максимальные в строке и минимальные в столбце 


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
			cout << a[i][j] << "  ";

		}
		cout << endl;

	}

	cout << "\n";


	int* b = new int[m + n];

	int max;

	int count = 0;
	int c = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			max = a[i][j];

			for (int p = 0; p < m; p++)
			{
				if (a[p][j] > max)
				{
					max = a[p][j];
				}

			} 
			while (p!=i)

			
				

				
				
					
				

		}
	}

	for (int i = 0; i < count; i++)
		cout << b[i] << "   ";

	return 0;

}



