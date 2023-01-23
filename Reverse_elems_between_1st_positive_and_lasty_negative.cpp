#include<iostream>

// переставить в обратном порядке элементы между 1ым (+) и последним (-)

using namespace std;

int main()
{

	int m;
	int k = 0;

	while (k != 1)
	{
		cout << "Input the amount m ";
		cin >> m;

		if (m < 1)
		{
			cout << "error data " << "\n";
			fflush(stdin);
		}

		else
			(k = 1);

	}

	cout << "\n";

	int* a = new int[m];

	for (int i = 0; i < m; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];

	}

	
	for (int i = 0; i < m; i++)
		cout << a[i] << "  ";

	cout << "\n\n";

	int firstpos = 0;
	int ipos = 0;

	for (int i = 0; i < m; i++)
	{
		if (a[i] > 0)
		{
			firstpos = a[i];
			ipos = i;
			break;

		}

		
	}

	cout << "1st pos is " << firstpos << "    \t" << "number is " << ipos << endl;

	int lastmin = 0;
	int lasti = 0;

	for (int i = m - 1; i >= 0; i--)
	{
		if (a[i] < 0)
		{
			lastmin = a[i];
			lasti = i;
			break;
		}
	}

	cout << "last otric is " << lastmin << "\t" << "number is " << lasti << endl;

	for (int i = ipos + 1, j = lasti - 1 ;i<j; i++,j--)
	{
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	cout << "New massiv\n";

	for (int i = 0; i < m; i++)
		cout << a[i] << "  ";
		
	system("PAUSE");

	return 0;
}
 
