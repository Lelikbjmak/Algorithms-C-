#include<iostream>

using namespace std;

      //    Найти числа, входящие в массив не более 1 раза 

int main()
{
	int m;

	cout << "Enter the amount of elements ";
	cin >> m;

	int* a = new int[m];


	for (int i = 0; i < m; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}


	cout << "\n\n";

	int count = 0;
	for (int i = 0; i < m; i++)
	{
		int t = a[i];
		
		for (int j = 0; j < m; j++)
			if (t == a[j])
				count++;

		if (count == 1)
			cout << t << "  ";

		count = 0;

	}

	cout << "\n";

	return 0;
	
}
