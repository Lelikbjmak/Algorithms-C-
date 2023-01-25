#include<iostream>
#include<iomanip>

// определить количество " особых эелементов" ( особый элемент больше суммы остальных в данном столбце )

using namespace std;

int main()
{
	int m, n;
	int k = 0;

	while (k != 1)
	{
		cout << "rows ";
		cin >> m;
		cout << "colls ";
		cin >> n;

		if ((n < 1 || m < 1) || (m < 1 && n < 1))
		{
			cout << "Error data. Try again ";
			fflush(stdin);
			system("pause");
			system("cls");


		}
		else k = 1;

	}

	int** a;
	a = new int*[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];

		}
	}


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << "\n";
	}

	int elem;
	int count = 0;
	int s;

	cout << "\n";

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			s = 0;
			elem = a[i][j];

			for (int p = 0; p < m; p++)
			{

				if (p != i)
					s += a[p][j];
			     
			}
			if (elem > s)
			{
				count++;
				cout << elem<<"  ";
			}
		}
		
	}

	cout << "count is " << count << "\n";

    system("pause");
	return 0;


}
