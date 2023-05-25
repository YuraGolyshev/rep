#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int n = 1, i = 1;
float x, sum = 0, eps;
eps = 0.00001;
cout << "x = ";
cin >> x;
float a = x;

cout << "leavaya chast ravenstva = " << atan(x) << "\n";
cout << "sum" << i << " = " << sum << "\n";
while (abs(sum - atan(x)) >= eps)
{
    sum += a/n;
    a *= x * x * (-1);
    n += 2;
    i++;
    cout << "sum" << i << " = " << sum << "\n";
    if (i >= 1000) break;
    if (abs(sum) > 10000) 
    {
        cout << "ryad rashoditsya" << "\n";
        break;
    }
}
system ("pause");
return 0;
}