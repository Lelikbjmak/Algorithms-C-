#include<iostream>
#include<clocale>

using namespace std;



int rezult(int,int);    // Прототипы функции 
int rek(int);  




int rek(int n)    // Функция на вычисления факториала (Рекурсия)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n*rek(n-1);
}


int main()
{
	setlocale(LC_ALL, "ru");

	int n, k;
	int l = 0;

	while (l != 1)
	{
		
		cout << "Введите данные: n,k (n > 0,  0< k <n) \n";   // Ввод данных
		cin >> n >> k;
		if (n > 0 && k > 0 && k < n)
			l = 1;
		else
		{
			cout << "Введите корректые данные!";
			fflush(stdin);
			system("pause");
			system("cls");
		}

	}
	

	

	cout << "n! = " << rek(n) << endl;   // Вычисляем факториал n через рекурсию
	cout << "k! = " << rek(k)<<endl;     // Вычисляем факториал k через рекурсию

	
	cout << endl;

	// C = n! / k!*(n-k)! - формула рекурсии

	int c;
	c = rek(n) /( rek(k) * rek(n - k));
	cout << "Число сочетаний (рекурсия) - "<<c<<endl;

	cout << "Число сочетаний (циклы) - " << rezult(n-1, k) + rezult(n - 1,k-1);
		
	return 0;
}



int rezult(int n, int k)   // Функция для вычисления факторила через циклы
{
	if (k == 0 || k == n)
		return 1;

	int summ;

	int n1 = 1;
	int k1 = 1;
	int p1 = 1;


	for (int i = 1; i <= n; i++)
		n1 *= i;

	for ( int j = 1; j <= k; j++)
	    k1 *= j;
	
	for (int i = 1; i <= (n - k) ; i++)
		p1 *= i;

	summ = n1 / (k1 * p1);

	return summ;
}
