﻿#include<iostream>
#include<iomanip>
#include<ctime>

using namespace std;

void insertionSort(int*, int);    // прототип функции вставками

int main()

{
    srand(time(NULL));

    setlocale(LC_ALL, "rus");

    cout << "Введите размер массива: ";
    int m;      // длинна массива
    cin >> m;
    cout << "\n\n";

    int* a = new int[m];   // создаем динамический массив 

    for (int i = 0; i < m; i++)
    {
        a[i] = rand() % 100 - 21;       // заполняем динамический массив
        cout << setw(4) << a[i] << "  ";
    }

    cout << "\n\n";

    insertionSort(a, m);       // вызываем функцию на сортировку массива 

    for (int i = 0; i < m; i++)
    {
        cout << setw(4) << a[i] << "  ";    // выводим отсортиоованный массив 
    }

    cout << "\n\n";

    delete[]a;      // очищаем динамическую память 

    return 0;

}


void insertionSort(int* aPtr, int length)     // функция для сортировки вставками ( принимает указатель на массив, длину массива )

{

    int temp,      // временная переменная для хранения значения элемента сортируемого массива
        index;     // индекс предыдущего элемента

    for (int i = 1; i < length; i++)
    {
        temp = aPtr[i];       // инициализируем временную переменную текущим значением элемента массива
        index = i - 1;        // запоминаем индекс предыдущего элемента массива

        while (index >= 0 && aPtr[index] > temp)    // пока индекс не равен 0 и предыдущий элемент массива больше текущего

        {
            aPtr[index + 1] = aPtr[index];     // перестановка элементов массива
            aPtr[index] = temp;
            index--;
        }

    }

}



void insertionSort()
{
    const int N = 10;
    int a[N] = { 12, 5, 3, 2, 45, 96, 6, 8, 11, 24 };

    int buff = 0; // для хранения перемещаемого значения
    int i, j; // для циклов 


    /************* Начало сортировки *******************/

    for (i = 1; i < N; i++)
    {

        buff = a[i]; // запомним обрабатываемый элемент
        // и начнем перемещение элементов слева от него
        // пока запомненный не окажется меньше чем перемещаемый
        for (j = i - 1; j >= 0 && a[j] > buff; j--)
            a[j + 1] = a[j];

        a[j + 1] = buff; // и поставим запомненный на его новое место 

    }
    /************* Конец сортировки *******************/


    for (int i = 0; i < N; i++) // вывод отсортированного массива
        cout << a[i] << '\t';
    cout << endl;

 }