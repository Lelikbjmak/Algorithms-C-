#include<iostream>
#include<stdlib.h>

using namespace std;
                       // В массиве найти число, которое встречается чаще всего 
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

	for (int i = 0; i < m; i++)
		cout << a[i] << "  ";

	int count=0; int b = 0;
	for (int i = 0; i < m-1; i++)
		for (int j = i + 1; j < m; j++)
		{
			if (int p=(a[i] == a[j]))
			{
				cout <<"p=" << p << endl;
				b = p;
			}
	    }

	for (int i = 0; i < m; i++)
	{
		if (a[i] == b)
			count++;
	}

	cout << "\n\n";

	cout << "Most common element is " << b << endl;
	cout << "The amount of this element is " << count << endl;

	return 0;
}
