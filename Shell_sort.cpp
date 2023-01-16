#include<iostream> 
#include<ctime>
#include<cmath>

using namespace std;

void vivod(int* a, int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << a[i]<<"  ";
    }
}

void Shell1(int *arr, int n)             //Обычная последовательность Шилла
{
    int d = n / 2;                        //Длина промежутков между элементами


    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i;
            while (j >= 0 && arr[j] > arr[j + d])
            {
                int temp = arr[j];
                arr[j] = arr[j + d];
                arr[j + d] = temp;

                j--;
            }
        }
        d = d / 2;
    }

    cout << "runtime = " << clock() / 1000.0 <<"c"<< endl; // время работы программы
}

int main()
{
    int m;

    cout << "enter the size " << endl;
    cin >> m;

    int* a;
    a = new int[m];
    for (int i = 0; i < m; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    cout << endl;


    vivod(a, m);

    cout << endl;

    Shell1(a, m);

    cout << endl;

    vivod(a, m);

    return 0;

}