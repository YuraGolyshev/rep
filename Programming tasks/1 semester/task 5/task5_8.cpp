#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int n = 1;
float x, cx, eps, sum = 1;
eps = 0.00001;
cout << "x = ";
cin >> x;
float a = x;
if (x != -1)
    {
    cout << "levaya chast ravnenstva = " << 1 / (x + 1) << "\n";
    }

cout << "sum" << n << " = " << sum << "\n";
while (abs(sum - 1 / (x + 1)) >= eps)
{
    if (x == -1)
    {
        cout << "levaya chast delitsa na 0" << "\n";
        break;
    }
    sum -= a;
    n++;
    cout << "sum" << n << " = " << sum << "\n";
    if (sum > 10000)
    {
        cout << "ryad rashoditsya" << "\n";
        break;
    }
    a *= (-1) * x;
    if (n >= 1000) break;
}
system("pause");
return 0;
}