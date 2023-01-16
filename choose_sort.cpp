#include<iostream>


using namespace std;

void choose_sort(int*,int);

void view(int*, int);


int main()
{

	int* a;
	int m;

	cout << "Capacity of massiv " << endl;
	cin >> m;

	a = new int[m];

	for (int i = 0; i < m; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];

	}

	cout << "Massiv: " << endl;
	view(a, m);


	cout << "Choose_sort:" << endl;
	void (*sort)(int*, int);

	sort = choose_sort;

	sort(a, m);

	//choose_sort(a, m);

	view(a, m);


	return 0;
}



void choose_sort(int* a, int m)
{

	for (int i = 0; i < m-1; i++)
	{
		int imin = i;

		for (int j = i+1; j < m; j++)
		{
			if (a[imin] > a[j])
			{
				imin = j;
			}

		}
			
		int t = a[imin];
		a[imin] = a[i];
		a[i] = t;

			
	}


}


void view(int* a, int m)
{

	for (int i = 0; i < m; i++)
	{
		cout << a[i] << "  ";
	}

	cout << endl;
}