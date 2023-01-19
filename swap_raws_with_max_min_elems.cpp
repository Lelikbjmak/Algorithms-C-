#include<iostream>        // подключение библиотеки iostream для ввода\вывода 
#include<iomanip>         // iomanip для для функций для вывода текста 
#include<stdlib.h>        // stdlib.h для работы функции rand() srand

int main(int argc, char* argv[]) // задаем главную функцию main

       //Задана матрица размером m*n; поменять местами строку, содержащую максимальный элемент, и строку,содержащую минимальный элемент

{

    //srand(time(0));               // всегда случайное заполнение 

    int** A;                      // массив указатель на указатель
    int m, n;                     // строки и столбцы
    
    int k = 0;

    while (k != 1)
    {

        std::cout << " Input size of raws(m) " << std::endl;  // ввод кол-ва строк
        std::cin >> m;
        std::cout << " Input size of cols (n) " << std::endl; // ввод кол-ва столбцов 
        std::cin >> n;

        if ((m < 1 || n < 1) || (m < 1 && n < 1))
        {
            std::cout << "Error data. Try again \n";
            fflush(stdin);
            system("pause");
            system("cls");

        }

        else
            k = 1;

    }

    


    A = new int* [m];               // создаем динамический массив


    
    for (int i = 0; i<m; i++) 
    {
       A[i]=new int[n];

          for (int j=0; j<n; j++)
          {
             std::cout<<"A["<<i<<"]["<<j<<"]= ";
             std::cin>>A[i][j];
          }
    }
    

    std::cout<<std::endl;
    std::cout<<std::endl;
    
    for (int i=0; i<m; i++){             // выводим динамически	 массив 
    for (int j=0; j<n; j++){
    std::cout<<std::setw(4)<<A[i][j]<<" "; 
    }
    std::cout<<std::endl;
    }
    

    /*
    for (int i = 0; i < m; i++) {   // цикл для задания столбцов, заполнение массива и вывода его на экран  
        A[i] = new int[n];
        for (int j = 0; j < n; j++) {

            A[i][j] = rand() % 100 - 21;
            std::cout <<std::setw(4)<<A[i][j]<<"  ";
        }
        std::cout << std::endl;              // вставляем пустую строку для удобства вывода 
    }
    */


    int imax = 0;               // вводим переменную imax, которая отвечает за за номер наибольшего элемента массива 
    int max;                // максимальный элемент массива 
    int jmax = 0;               // номер столбца, в котором находится данный максимальный элемент массива 
    max = A[0][0];          // считаем что max=A[0][0] --> переходим к сортировке и сравниваем каждый элемент каждой строки


    for (int i = 0; i < m; i++) {     // заводим цикл для такой переборки max

        for (int j = 0; j < n; j++) {   // проходим по строкам и столбцам, т.е всему массиву и исчем в строках max элемент, запоминаем строку и столбец, в которых он находится

            if (max < A[i][j]) { // т.к max=A[0][0], то смортим если последующие элементы < чем max, то  присваиваем им значение max
                max = A[i][j];
                imax = i;        // запоминаем номер строки с max
                jmax = j;        // запоминаем номер столбца с max
            }
        }

    }


    int min;          // минимальный элемент массива 
    int imin = 0;           // вводим переменную imin, которая отвечает за за номер наименьшего элемента массива
    int jmin = 0;           // номер столбца, в котором находится данный минимальный элемент массива
    min = A[0][0];     // преполагаю что A[0][0] - наименьший элемент в массиве


    for (int i = 0; i < m; i++) {       // цикл для поиска min
        for (int j = 0; j < n; j++) {   // 
            if (min > A[i][j]) {        // если находим элемент < A[0][0], то присваиваем значение min A[i][j]-ому
                min = A[i][j];
                imin = i;               // номер строки , в которой содержится min
                jmin = j;               // номер столбца, в котором содержится min 
            }
        }
    }


    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << " max numeric  in raw is " << max <<" It's raw number "<<imax<<std::endl; // выведем на экран номер строки и столбца с max, вместо с самим элементом max
    std::cout << " max number j in cals " << jmax << std::endl << std::endl;;

    std::cout << " min numeric  in raw is " << min << " It's raw number " << imin << std::endl; // выведем на экран номер сроки и столбца вместе с самим числом 
    std::cout << " min number j in cals  " << jmin << std::endl<< std::endl;


    std::cout << std::endl;
    std::cout << std::endl;


    if (imin == imax) {

        std::cout << " A[max] and A[min] are situated on the same line";   // если max и min элементы массива находятся в 1 строке
        std::cout << std::endl;                                            // завершаем программу 
        std::cout << std::endl;
        exit(0);
    }


    int t;      // вводим переменную t для перестановки строк местами 

for (int i = 0; i < n; i++) {      // вводим цикл для персестановки строк с max и min
    t = A[imax][i];                // берем t=строка с max --> присвиваем строке c max строку с min--> все элементы строки c max станут элементами строки с min -->
    A[imax][i] = A[imin][i];       // присваиваем строке с min строку переменную t --> а т.к t=строке с max, строка с min станет строкой с max
    A[imin][i] = t;                // 
    }


for (int i = 0; i<m; i++) {           // делаем цикл для вывода полученного массива с изменнеными строками 
    for (int j = 0; j < n; j++) {
        std::cout << std::setw(4) << A[i][j] << "  ";
    }
    std::cout << std::endl;
}

  for (int i=0; i<m; i++)       // очищаем память одномерных массивов 
  delete []A[i];

  delete[]A; // очищаем память массива-указателя 


    return 0;                         // завершаем программу 
}