#include <iostream>
#include "locale.h"
#include <math.h>
#include <iomanip>

using namespace std;

void method_simple_implications()                //    Метод простых итераций
{
	int n = 0;
	float x = -4.5, y, z, с = 0.5, mod1, mod2, eps = 0.001, d = 0.01;
	do
	{
		z = x;                                                // z - это Xn
		y = x + с * (exp(x) + sin(x) - 1);              // y - это Xn + 1
		mod1 = fabs(y - z);
		mod2 = fabs(exp(y) + sin(y) - 1);
		x = y;
		cout << "|" << setw(5) << n << setw(5) << "|" << setw(12) << z << setw(5) << "|" << setw(12) << y << setw(5) << "|"
			<< setw(14) << mod1 << setw(8) << "|" << setw(14) << mod2 << setw(8) << "|" << endl;
		n += 1;
	} while ((mod1 > eps) || (mod2 > d));
}

void method_Newton()                            //    Метод Ньютона
{
	int n = 0;
	float x = -4.5, y, z, mod1, mod2, eps = 0.001, d = 0.01;

	do
	{
		z = x;                                                                        // z - это Xn
		y = x - (exp(x) + sin(x) - 1) / (exp(x) + cos(x));              // y - это Xn + 1
		mod1 = fabs(y - z);
		mod2 = fabs(exp(y) + sin(y) - 1);
		x = y;
		cout << "|" << setw(5) << n << setw(5) << "|" << setw(12) << z << setw(5) << "|" << setw(12) << y << setw(5) << "|"
			<< setw(14) << mod1 << setw(8) << "|" << setw(14) << mod2 << setw(8) << "|" << endl;
		n += 1;
	} while ((mod1 > eps) || (mod2 > d));
}

void modification_method_Newton()                //    Модифицированный Метод Ньютона
{
	int n = 0;
	float x0 = -4.5, x = x0, y, z, mod1, mod2, eps = 0.001, d = 0.01;
	do
	{
		z = x;                                                                        // z - это Xn
		y = x - (exp(x) + sin(x) - 1) / (exp(x0) + cos(x0));            // y - это Xn + 1
		mod1 = fabs(y - z);
		mod2 = fabs(exp(y) + sin(y) - 1);
		x = y;
		cout << "|" << setw(5) << n << setw(5) << "|" << setw(12) << z << setw(5) << "|" << setw(12) << y << setw(5) << "|"
			<< setw(14) << mod1 << setw(8) << "|" << setw(14) << mod2 << setw(8) << "|" << endl;
		n += 1;
	} while ((mod1 > eps) || (mod2 > d));
}

void show_table()
{
	cout << "-----------------------------------------------------------------------------------------\n";
	cout << "|    n    |       Xn       |     Xn + 1     |    |(Xn+1 - Xn)|    |     |f(Xn + 1)|     |\n";
	cout << "-----------------------------------------------------------------------------------------\n";
}

void func()
{
	int n;

	while (true)
	{
		cout << "Если хотите:" << endl;
		cout << "Произвести поиск корня на отрезке по Методу простых итераций - Нажмите 1" << endl;
		cout << "Произвести поиск корня на отрезке по Методу Ньютона - Нажмите 2" << endl;
		cout << "Произвести поиск корня на отрезке по Модифицированному Методу Ньютона - Нажмите 3" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "\nМетод простых итераций" << endl;
			show_table();
			method_simple_implications();
			cout << "\nПроцесс поиска корня на отрезке прошел успешно !" << endl;
			break;
		case 2:
			cout << "\nМетод Ньютона" << endl;
			show_table();
			method_Newton();
			cout << "\nПроцесс поиска корня на отрезке прошел успешно !" << endl;
			break;
		case 3:
			cout << "\nМодифицированный Метод Ньютона" << endl;
			show_table();
			modification_method_Newton();
			cout << "\nПроцесс поиска корня на отрезке прошел успешно !" << endl;
			break;
		default:
			cout << "Ошибка ввода !";
			break;
		}
		cout << "\n";
		//        system("pause");
		//        system("cls");
	}
}

int main()
{
	setlocale(0, "");
	cout << "Лабораторная работа по Вычислительной математике №1-2\n" << endl;
	cout << "Выполнили студенты группы 4310 Кутдусов Ильшат и Мулюков Роберт\n" << endl;
	cout << "Вариант №11(16)\nНелинейное уравнение: e^x + sin(x) - 1 = 0\nОтрезок: [-4,7; -3,5]\n" << endl;

	func();
	system("pause");
	return 0;
}
