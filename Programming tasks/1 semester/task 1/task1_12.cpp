#include <cmath> //библиотека математических функций
#include<iostream> //библиотека для потока ввода-вывода

using namespace std; //сообщает компилятору, что мы хотим использовать всё, что находится в пространстве имен std

int main(){ //выражение, показывающее, что в программе присутствует главная функция main(), которая вернет в качестве значения целое число
int x; //объявление переменной целочисленного типа

cout << "x ="; //обозначение ввода числа x
cin >> x; //ввод числа x

int a, b, c; //объявление переменной целочисленного типа

a = x / 100; //отделение первой цифры числа x
b = (x % 100) / 10; //отделение второй цифры числа x
c = x % 10; //отделение третьей цифры числа x

a = 25 % a; //нахождение остатка от деления 25-ти на первую цифру числа x
b = 25 % b; //нахождение остатка от деления 25-ти на вторую цифру числа x
c = 25 % c; //нахождение остатка от деления 25-ти на третью цифру числа x

int y = a * 100 + b * 10 + c; //расчет числа y и выполнение условия "Должно быть выведено именно число y"

cout << y << endl; //вывод числа y
system("pause"); //задержка консоли
return 0; //возврат значения 0 из функции `main` говорит об успешном завершении программы
}