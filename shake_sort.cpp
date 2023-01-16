#include<iostream>


using namespace std;

void ShakerSort(int* a, int n) 
{
    int left, right, i;
    left = 0;
    right = n - 1;
    while (left <= right) 
    {
        for (i = right; i >= left; i--) 
        {
            if (a[i - 1] > a[i]) 
            {
                swap(a[i - 1], a[i]);
            }
        }
        left++;

        for (i = left; i <= right; i++) 
        {
            if (a[i - 1] > a[i]) 
            {
                swap(a[i - 1], a[i]);
            }
        }
        right--;
    }

}

int main()
{
    int n; 
    cout << "enter the size"<<endl;
    cin >> n;

    int* a;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }

    cout << endl;

    ShakerSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }


}