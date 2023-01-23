#include<iostream>

using namespace std;

// Найти наименьший положительный элемент массива с четнам индексом 

int main()
{
	int m;
	cout << "enter the amount of elements in massiv ";
	cin >> m;

	int* a = new int[m];

	for (int i = 0; i < m; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}

	cout << "\n\n";

	for (int i = 0; i < m; i++)
		cout << a[i] << "  ";
	
	cout << "\n\n";

	int min = a[0];
	int imin = 0;
	for (int i = 0; i < m; i += 2)
	{
		if (a[i] < min && a[i] > 0 )
		{
			
			min = a[i];
			imin = i;
		}
		
	}

	cout << "Min element is " << min << "   " << "Min element index is " << imin << endl;

	system("pause");
	return 0;
}
