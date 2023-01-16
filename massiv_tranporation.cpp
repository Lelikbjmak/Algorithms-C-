#include<iostream>

using namespace std;

int fun(int x, int y)
{
	int rez = x % y;
	return rez;
}

void out(int n, int **a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}

}



int main()
{
	// Протранспанировать матрицу (строки  -->  столбцы)
	

	cout << "Input the size of sqr matrix: ";
	int size;
	cin >> size;

	int** a;

	a = new int* [size];
	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];

		}
	}

	cout << endl;


	out(size, a);

	cout << endl;

	int temp = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}

	cout << "After transporation: " << endl;

	out(size, a);


	int arr[] = {-6,0,-6,-1,-2,-5,1,-3,0,8};
	int sz = 10;
	bool bl;
	int jk = 0;
	while (true)
	{
		bl = true;
		for (int i = jk; i < sz - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tp;
				bl = false;
				jk = i;
			}
			if (bl)
				break;

		}
	}

	for (int i = 0; i < sz; i++)
		cout << arr[i] << "  ";
	
	int x, y;

	cout << "x = ";
	cin >> x;
	cout << "y= ";
	cin >> y;

	fun(x, y);

	return 0;
}
