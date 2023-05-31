#include <iostream>
using namespace std;
int main()
{
int day, month, year;
cout << "enter day: "; // ввод дня
cin >> day;
cout << "enter month: "; // ввод месяца
cin >> month;
cout << "enter year: "; // ввод года
cin >> year;
int a = 0;
bool leapyear = false; // високосный год
if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) leapyear = true; // условие високосного года

switch (month) // оператор switch
{              // позволяет выбирать между несколькими разделами кода в зависимости от значения целочисленного выражения
  case 1: case 3: case 5: case 7: case 8: case 10: case 12: // Январь, Март, Май, Июль, Август, Октябрь и Декабрь
  if (day <= 0 || day > 31)
  {
    cout << "wrong day\n"; // неподходящее кол-во дней в месяце
    system("pause");
    return 0; 
  }
  else
  {
    a = 31 - day;
  }
  break;
  case 4: case 6 : case 9: case 11: // Апрель, Июнь, Сентябрь и Ноябрь
  if (day <= 0 || day > 30)
  {
    cout << "wrong day\n"; // неподходящее кол-во дней в месяце
    system("pause");
    return 0;
  }  
  else
  {
    a = 30 - day;   
  }
  break;
  case 2: // февраль
    if (leapyear) // если високосный год
    {
        if (day <= 0 || day > 29)
        {
            cout << "wrong day\n"; // неподходящее кол-во дней в месяце
            system("pause");
            return 0; 
        }  
        else
        {
            a = 29 - day;   
        }
    }
    else // если не високосный год
    {
        if (day <= 0 || day > 28)
        {
            cout << "wrong day\n"; // неподходящее кол-во дней в месяце
            system("pause");
            return 0; 
        }  
        else
        {
            a = 28 - day;   
        }      
           
    }   
}
if (month > 12 || month < 1)
{
    cout << "wrong month\n"; // неправильный месяц
    system("pause");
    return 0; 
}
cout << day << " "; // вывод дня

switch (month) // вывод месяца
{
    case 1:
    cout << "January";
    break;
    case 2:
    cout << "February";
    break;
    case 3:
    cout << "March";
    break;
    case 4:
    cout << "April";
    break;
    case 5:
    cout << "May";
    break;
    case 6:
    cout << "June";
    break;
    case 7:
    cout << "July";
    break;
    case 8:
    cout << "August";
    break;
    case 9:
    cout << "September";
    break;
    case 10:
    cout << "October";
    break;
    case 11:
    cout << "November";
    break;
    case 12:
    cout << "December";
    break;
}
cout << " " << year << " Year" << "\n" << a << "\n"; // вывод года и кол-ва дней оставшихся до конца месяца
system("pause");
return 0;
}







