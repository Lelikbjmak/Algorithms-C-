#include<iostream>
#include<iomanip>

// упорядочить строки по возрастанию суммы их элементов 

using namespace std;

int main()
{

	int m, n;
	cout << "rows ";
	cin >> m;
	cout << "colls ";
	cin >> n;

	cout << "\n";

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
			cout << setw(4) << a[i][j];
		}
		cout << "\n";

	}

	int k = 0; 
	int* b = new int[m];

	int s = 0;
	

	

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s += a[i][j];

		}
		b[i] = s;

		s = 0;
	}

	

	cout << "\n";

	for (int i = 0; i < m; i++)
		cout << b[i] << "  ";


	for (int i = 0; i <m-1 ; i++)
	{
		
		for (int j = i+1; j < n; j++)
		{
			
		    if (b[i] > b[j])
		    {
		
				int t = b[i];
				b[i] = b[j];
				b[j] = t;

				 
					for (int p = 0; p<m; p++)
					{
						   int temp = a[i][p];
						   a[i][p] = a[j][p];
						   a[j][p] = temp;
						
					}

				
				
			}
		}
	}
	
	
	cout << "\n\n";


	for (int i = 0; i < m; i++)
		cout << b[i] << "  ";


	cout << "\n\n";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << "\n";

	}

	return 0;

}