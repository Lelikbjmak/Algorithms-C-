#include<iostream>

using std::cin;
using std::cout;
using std::endl;



struct Hash
{
	int info;
	Hash* a;

}**H;



Hash** create(int m)
{
	H = new Hash * [m];   // Create array of stacks

	for (int i = 0; i < m; i++)
		H[i] = nullptr;    // fill our stack 

	return H;

}




void add(int key, int m)
{
	Hash* sp = new Hash;

	sp->info = key;

	int i = abs(key % m);
	if (H[i])          // if H[i] busy
	{
		sp->a = H[i];
		H[i] = sp;
	}
	else    // indicate that H[i] is hollow
	{
		H[i] = sp;
		sp->a = nullptr;

	}

}




Hash* search(int key, int m)
{
	int i = abs(key % m);

	Hash* sp = H[i];

	while (sp)   // while sp exist (untill sp != nullptr)
	{
		if (sp->info == key)
			return sp;
		sp = sp->a;

	}

}



void view_hash(int m)
{
	for (int i = 0; i < m; i++)
	{
		while (H[i])
		{
			cout << H[i]->info << "  ";
			H[i] = H[i]->a;

		}

		cout << "\n";

	}
}



void view_ARRAY(int m, int *a)
{
	for (int i = 0; i < m; i++)
	{
		cout << a[i] << "  ";

	}

	cout << "\n";

}


int main()
{
	cout << "Quantity of elements: ";
	int count;
	cin >> count;

	H = create(count);      // create hash table

	cout << "Elements: " << endl;

	int* A = new int[count];
	for (int i = 0; i < count; i++)
	{
		cin >> A[i];
		add(A[i], count);

	}
		

	cout << "\n";

	cout << "-------------------------------------------------" << endl;

	cout << "\nArray:\n";

	view_ARRAY(count, A);

	cout << "\nHash  table: \n";

	view_hash(count);

	
	return 0;
}