#include<iostream>
#include<string>

using namespace std;

struct hotel // структура hotel
{
    int dayin;
    int monthin;
    int yearin;
    int dayout;
    int monthout;
    int yearout;
    string fio;
};

hotel STR_datein(string str)    //перевод из строки в дату для первой даты
{
    hotel datain;
    //—–day———————-
    string str1 = str.substr (0, 2);
    const char *sd = str1.c_str();
    int dd = atoi(sd);
    datain.dayin = dd;
    //———month—————-
    str1 = str.substr (3, 2);
    sd = str1.c_str () ;
    dd = atoi(sd);
    datain.monthin = dd;
    //———year—————–
    str1 = str.substr (6, 4);
    sd = str1.c_str () ;
    dd = atoi(sd);
    datain.yearin = dd;
    
    return datain;
}
hotel STR_dateout(string str)   //перевод из строки в дату для второй даты
{
    hotel dataout;
    //—–day———————-
    string str1 = str.substr (11, 2);
    const char *sd = str1.c_str();
    int dd = atoi(sd);
    dataout.dayout = dd;
    //———month—————-
    str1 = str.substr (14, 2);
    sd = str1.c_str () ;
    dd = atoi(sd);
    dataout.monthout = dd;
    //———year—————–
    str1 = str.substr (17, 4);
    sd = str1.c_str () ;
    dd = atoi(sd);
    dataout.yearout = dd;

    return dataout;
}


bool vis(int year)  //високосный год
{
    return (year%4 == 0 && year%100 != 0) || year%400 == 0;
}


int EndOfMonth(int month, int year) //конец месяца
{
    switch (month) 
    {
        case 1: case 3: case 5:
        case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: if(vis(year)) return 29;
        else return 28;
    }
}

int days(int day, int month, int year) // перевод дат в дни
{
    static int days_before_month[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int y = year - 1;
    return day + days_before_month[month] + (vis(year) && month > 2) + y * 365 + y/4 - y/100 + y/400;
}

int correct(string str )    //проверка корректности данных для двух дат
{
    for(string::size_type i = 0; i <= 9 ; i++)
        if (i != 2 && i != 5)
            if (!isdigit (str[i])) 
                return 0;
    for(string::size_type i = 11; i <= 20 ; i++)
        if(i != 13 && i != 16)
            if (!isdigit (str[i]))
                return 0;

    hotel datain = STR_datein(str);
    if (datain.dayin <= 0 || datain.dayin > EndOfMonth(datain.monthin, datain.yearin)) return 0;
    if (datain.monthin <= 0 || datain.monthin > 12) return 0;
    if (datain.yearin == 0) return 0;
    hotel dataout = STR_dateout(str);
    if (dataout.dayout <= 0 || dataout.dayout > EndOfMonth(dataout.monthout, dataout.yearout)) return 0;
    if (dataout.monthout <= 0 || dataout.monthout > 12) return 0;
    if (dataout.yearout == 0) return 0;
    return 1;
}

int main()
{
    string str ;
    int n; 
    cout << "Input the number of tourists\n";
    cin >> n;       // Ввод количества туристов
    cin.get();
    for(int i = 0; i < n; i++)
    {
        cout << "Input datein and dateout as dd.mm.yyyy, FIO\n";
        getline (cin, str);
        int f = correct(str);
        if (f == 0) cout << "Error data\n";
        else 
        {
            hotel datain = STR_datein(str);
            hotel dataout = STR_dateout(str);
            int day = (days(dataout.dayout, dataout.monthout, dataout.yearout) - days(datain.dayin, datain.monthin, datain.yearin)) + 1; // количество дней в отеле 
            cout << "days in hotel: " << day << "\n";
        }
    }
    system("pause");
    return 0;
}

