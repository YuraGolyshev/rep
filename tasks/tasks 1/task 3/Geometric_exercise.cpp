#include <iostream>
#include <cmath>
using namespace std;
int main()
{

float a1, a2, b1, b2, c1, c2, x, y;
cout << "a1, b1, c1\n"; // ввод данных первой прямой 
cin >> a1 >> b1 >> c1;
cout << "a2, b2, c2\n"; // ввод данных второй прямой
cin >> a2 >> b2 >> c2;

float det = a1 * b2 - a2 * b1; // определитель | a1 b1 |
                               //              | a2 b2 |
if (a1 == 0 && b1 == 0 && a2 == 0 && b2 == 0) // если a1, b1, a2, b2 = 0, тогда это не прямые
{
    cout << "ne pryamie\n";
    system("pause"); 
    return 0;
}
else if (a1 == 0 && b1 == 0)                  // если a1, b1 = 0, тогда 1 уравнение это не прямая
{
    cout << "1 yr-ie - ne pryamaya\n";
    system("pause"); 
    return 0;
}
else if (a2 == 0 && b2 == 0)                  // если a2, b2 = 0, тогда 2 уравнение это не прямая
{
    cout << "2 yr-ie - ne pryamaya\n";
    system("pause"); 
    return 0;
}

else
{
    if ((a1 * b2) == (a2 * b1)) // проверка на параллельность/совпадение  
    {                           // две прямые параллельны, если a1/a2 = b1/b2, но на ноль делить нельзя, поэтому (a1 * b2) = (a2 * b1)
        if ((a2 * c1) == (a1 * c2) && (b2 * c1) == (b1 * c2)) // с условием совпадения то же самое, но добавляется с1/c2
        {                                                     // a1/a2 = b1/b2 = c1/c2    (a2 * c1) = (a1 * c2) и (b2 * c1) = (b1 * c2)      
            cout << "sovpadaut\n";
            system("pause"); 
            return 0;
        } 
        else
        {
            cout << "parallelni\n"; 
            system("pause"); 
            return 0;
        }
    }
    if (det == 0) // проверка не равно ли det нулю, на 0 делить нельзя
    {
        cout << "delenie na 0\n";
        system("pause"); 
        return 0;
    }
    else    
    {                               // если все прошлые варианты не подходят, остается только один
        cout << "peresekayutsya\n"; // пересечение прямых
        // метод Крамера
        x = (b1 * c2 - b2 * c1) / det; //   x = | b1 c1 | / | a1 b1 |               
                                       //       | b2 c2 |   | a2 b2 | 
        y = (a2 * c1 - a1 * c2) / det; //   y = | c1 a1 | / | a1 b1 |
                                       //       | c2 a2 |   | a2 b2 | 
        cout << x << ", " << y << "\n"; // вывод координат пересечения прямых
        system("pause"); 
        return 0;
    }
}
system("pause"); 
return 0; 
}