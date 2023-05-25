#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int n, d = 3;
float ym1 = 0.4, ym2 = 0.5;
cout << "n = ";
cin >> n;
cout << "1 " << ym2 << "\n";
cout << "2 " << ym1 << "\n";

while(d <= n)
{
    cout << d << " ";
    float y = ym1 / 2 + ym2 / 3;
    cout << y << "\n";
    d++;
    ym2 = ym1;
    ym1 = y;
}
system ("pause");
return 0;
}