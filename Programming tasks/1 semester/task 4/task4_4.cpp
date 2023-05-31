#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int n, d = 2;
bool dp = false; // делать ++ или нет
cout << "n = ";
cin >> n;           //ввод n
cout << "prostie mnozhiteli chisla " << n << ": ";

while (n > 1)     // цикл пока n больше 1
{
    
    if (n % d == 0)            // если n делится нацело на d 
        {
            cout << d << " ";  // вывод множителя
            n = n / d;         // веление n на множитель d
        }
    if (n % d != 0) dp = true; // если n больше не делится нацело на d
    if (dp) d++;               // увеличивать d на 1
}

cout << "\n";
system ("pause");   
return 0;
}