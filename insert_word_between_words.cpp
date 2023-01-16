#include<iostream>
#include<string>
#include<string>

using namespace std;

// Между 2ым и 3им словом вставить Visual

int main()
{
	char a[255];
	char vs[255];
	int k = 0;

	puts("Input the string");

	gets_s(a);

	int count = 0;
	for (int i = 1; a[i] != '\0'; i++)
	{
		if (a[i] == ' ' )
			count++;

		if (count == 2)
		{
			k = i + 1;
			break;
		}
	}



	cout << "Index is " << k;

	


	

	return 0;
}

