#include<iostream>
#include<string.h>
#include<string>
#include<clocale>
#include<cmath>



using namespace std;


// x^w - y^w +(a+y)/(a-x)



struct steck
{
	double info;        // инфа
	steck* a;           // адресс

}*top, *point;       



double A[122];                  // массив для результата
char str[100], strp[100];          // инфиксная и постфиксная строка




steck* add(steck* , double);       
steck* read(steck*, double&);   // Прототипы
double ras(char* , double* );
void addafter(char*, char*);
int priority(char);



int main()
{
	setlocale(LC_ALL, "ru");

	cout << "Ведите x " << endl;
	cin >> A[int('x')];

	cout << "Ведите y " << endl;
	cin >> A[int('y')];

	cout << "Ведите a " << endl;
	cin >> A[int('a')];

	cout << "Ведите w " << endl;
	cin >> A[int('w')];


	cout << "Введите выражение: " << endl;
	cin>>str;

	addafter(str, strp);

	cout << "\n\n" << strp << endl;

	double rez = ras(strp, A);

	cout << "Результат - " << rez << endl;


	return 0;

}




steck* add(steck* sp, double info)       // добавляем элемент в стек 
{
	steck* spt = new steck;  // выделяес память под новый элемент
	spt->info = info;          // заполняем информационную часть (заранее ввеленные данные info)
	spt->a = sp;               // Присоединяем элемент к вершине

	return spt;

}




steck* read(steck* sp, double &inf)
{
	                       // Чтение элемента из стека
	steck* p = sp;
	inf = sp->info;
	sp = sp->a;

	delete p;
	return sp;

}




int priority(char symbol)
{ 
	                          // вычисление приритета операции 
	switch (symbol)
	{

	case '(':case')': return 0;
	case '+': case '-': return 1;
	case '^': case '*':case'/': return 2;
	//case '^': return 3;
	default: return -1;
		 
	}


}




void addafter(char* strin, char* strout)
{

	steck* sp = nullptr;

	int n = 0;

	char ch;

	double inf;

	for (unsigned int i = 0; i < strlen(strin); i++)
	{
		ch = strin[i];
		// If operand

		if (ch >= 'A' && ch!='^')
		{
			strout[n++] = ch; 
			continue;
		}

		if (sp == nullptr || ch == '(')
		{
			sp = add(sp, ch);
			continue;
		}

		if (ch == ')' )
		{
			while (sp->info != '(')
			{
				sp = read(sp, inf);
				strout[n++] = (char)inf;

			}
			
			sp = read(sp, inf);   // Удаление  открывающ скобки

			continue;
		}
	

		int pr = priority(ch);


		while (sp != nullptr && priority((char)sp->info) >= pr)
		{
			sp = read(sp, inf);
			strout[n++] = char(inf);

		}

		sp = add(sp, ch);
	}




	while (sp != nullptr)
	{
		sp = read(sp, inf);
		strout[n++] = (char)inf;

	}

	strout[n++] = '\0';


}





double ras(char* str, double* mz)
{
	steck* sp = nullptr;

	char ch;

	double inf, inf1, inf2;

	for (unsigned int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		// if operand
		if (ch >= 'A' && ch!='^')
		{
			sp = add(sp, mz[int(ch)]);
			continue;
		}

		sp = read(sp, inf2);
		sp = read(sp, inf1);


		switch (ch)
		{

		case '+': sp = add(sp, inf1 + inf2); break;
		case '-': sp = add(sp, inf1 - inf2); break;
		case '*': sp = add(sp, inf1 * inf2);  break;
		case'/': 
		{
			if (inf2 == 0)
			{
				cout << "Ошибка деления на 0"; exit(0);

			}
			sp = add(sp, inf1 / inf2); break;
			
		}
		case '^': sp = add(sp, pow(inf1, inf2)); break;

		}

	}

	sp = read(sp, inf);


	return inf;


}


