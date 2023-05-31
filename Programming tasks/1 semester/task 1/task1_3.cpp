#include <cmath> //библиотека математических функций
#include<iostream> //библиотека для потока ввода-вывода

using namespace std; //сообщает компилятору, что мы хотим использовать всё, что находится в пространстве имен std   

int main(){ //выражение, показывающее, что в программе присутствует главная функция main(), которая вернет в качестве значения целое число
float x, y; //объявление двух переменных с плавающей точкой

cout << "x = "; //обозначение ввода числа x
cin >> x; //ввод числа x

cout << "y = "; //обозначение ввода числа y
cin >> y; //ввод числа y

float c = (2.0 / 3) * sin(sqrt(((x*x - y*y) / exp(x + y)) + (x*x * y*y))) + ((cos(x) + sin(y)) / 2); //выражение

cout << c << endl; ; //вывод
system("pause"); //задержка консоли
return 0; //возврат значения 0 из функции `main` говорит об успешном завершении программы
}