#include<iostream>
#include<string>

using namespace std;

struct drob //структура дробь
{
    int chisl;
    int znam;
};

drob strdrob(string str) //перводим из строки в значения для первой дроби
{
    drob drob1;
    int i = 0;
    while(str[i] != '/') // цикл для считывания числителя
        i++;
    string str1 = str.substr(0, i);
    const char *sd = str1.c_str() ;
    int dd = atoi(sd);
    drob1.chisl = dd;
    int j = i+1;
    while(isdigit(str[j]))  // цикл для считывания знаменателя
        j++;
    str1 = str.substr(i+1, j+1);
    sd = str1.c_str() ;
    dd = atoi(sd);
    drob1.znam = dd;
    return drob1;
}
drob strdrob2(string str2)  //перводим из строки в значения для второй дроби
{    
    drob drob2;
    int i = 0;
    while(str2[i] != '/')   // цикл для считывания числителя
        i++;
    string str1 = str2.substr(0, i);
    const char *sd = str1.c_str() ;
    int dd = atoi(sd);
    drob2.chisl = dd;
    int j = i+1;
    while(isdigit(str2[j])) // цикл для считывания знаменателя
        j++;
    str1 = str2.substr(i+1, j+1);
    sd = str1.c_str() ;
    dd = atoi(sd);
    drob2.znam = dd;
    return drob2;
}

int proverka(int ch, int zn) // проверка на нули
{
    if(ch == 0 || zn == 0)
    {
        cout << "error input\n";
        return 0;
    }
    return 1;
}

drob slozhenie(int ch1, int zn1, int ch2, int zn2) // функция сложения
{
    if(zn1 == zn2)
    {
        int ch = ch1 + ch2;
        cout << ch << "/" << zn1 << "\n";
        return drob{ ch, zn1 }; // возвращаем результат для дальнейших дейстивий
    }

    int ch = ch1 * zn2 + zn1 * ch2;
    int zn = zn1 * zn2;
    cout << ch << "/" << zn << "\n";
    return drob{ ch, zn };  // возвращаем результат для дальнейших дейстивий
}

drob vychitanie(int ch1, int zn1, int ch2, int zn2) // функция вычитания
{
    if(zn1 == zn2)
    {
        int ch = ch1 - ch2;
        cout << ch << "/" << zn1 << "\n";
        return drob{ ch, zn1 }; // возвращаем результат для дальнейших дейстивий
    }
    else
    {
        int ch = ch1 * zn2 - zn1 * ch2;
        int zn = zn1 * zn2;
        cout << ch << "/" << zn << "\n";
        return drob{ ch, zn };  // возвращаем результат для дальнейших дейстивий
    }
}

drob umnozhenie(int ch1, int zn1, int ch2, int zn2) // функция умножения
{
    int ch = ch1 * ch2;
    int zn = zn1 * zn2;
    cout << ch << "/" << zn << "\n";
    return drob{ ch, zn };  // возвращаем результат для дальнейших дейстивий
}

drob delenie(int ch1, int zn1, int ch2, int zn2)    // функция деления
{
    int ch = ch1 * zn2;
    int zn = zn1 * ch2;
    cout << ch << "/" << zn << "\n";
    return drob{ ch, zn };  // возвращаем результат для дальнейших дейстивий
}

int sokrashchenie(int ch, int zn)   // функция сокращения
{
    int min;
    if(ch < zn) min = ch;
    else min = zn;
    for(int i = min; i > 0; i--)
        if(ch % i == 0 && zn % i == 0)
        {
            cout << ch/i << "/" << zn/i << "\n";
            return 0;
        }
}

int desyatichnaya(double ch, double zn) // функция приведения к десятичной дроби
{
    cout << ch/zn << "\n";
}

int pravilnaya(int ch, int zn)  // функция приведения к правильной дроби
{
    int pr = ch/zn;
    ch -= pr*zn;
    if(ch == 0)
        cout << pr << "\n";
    else cout << pr << " " << ch << "/" << zn << "\n";
}

int main()
{
    string str, str2;
    int op; // 0 - сложение, 1 - вычитание, 2 - умножение, 3 - деление, 4 - сокращение, 5 - приведение к десятичной дроби, 6 - приведение к правильной дроби
    cout << "kakuyu operaciyu nuzhno budet sdelat'?\n" << "0 - slozhenie, 1 - vychitanie, 2 - umnozhenie, 3 - delenie, 4 - sokrashchenie, 5 - privedenie k desyatichnoj drobi, 6 - privedenie k pravil'noj drobi\n";
    cin >> op;
    if(op == 0 || op == 1 || op == 2 || op == 3) 
    {
        cout << "vvedite drob'\n";  // ввод первой дроби
        cin >> str; 
        cout << "vvedite drob'\n";  // ввод второй дроби
        cin >> str2; 
        drob drob1 = strdrob(str);
        drob drob2 = strdrob2(str2);
        int a = proverka(drob1.chisl, drob1.znam);
        int b = proverka(drob2.chisl, drob2.znam);
        if(a != 0 && b != 0)
        {
            int chisl, znam;
            drob result; // в result сохраним значения после выполнения функций
            if(op == 0)                                                                 // сложение
                result = slozhenie(drob1.chisl, drob1.znam, drob2.chisl, drob2.znam);
            if(op == 1)                                                                 // вычитание
                result = vychitanie(drob1.chisl, drob1.znam, drob2.chisl, drob2.znam);
            if(op == 2)                                                                 // умножение
                result = umnozhenie(drob1.chisl, drob1.znam, drob2.chisl, drob2.znam);
            if(op == 3)                                                                 // деление
                result = delenie(drob1.chisl, drob1.znam, drob2.chisl, drob2.znam);
            int opr;
            cout << "chto sdelat' s drob'yu?\n" << "0 - nichego, 1 - sokratit', 2 - privesti k desyatichnoj, 3 - privesti k pravil'noj\n";
            cin >> opr; 
            if(opr == 1)                                    // сокращение
                sokrashchenie(result.chisl, result.znam);
            if(opr == 2)                                    // приведение к десятичной дроби
                desyatichnaya(result.chisl, result.znam);
            if(opr == 3)                                    // приведение к правильной дроби
                pravilnaya(result.chisl, result.znam);
        }
    }
    if(op == 4) // сокращение
    {
        cout << "vvedite drob'\n";  // ввод дроби
        cin >> str; 
        drob drob1 = strdrob(str);
        if(proverka(drob1.chisl, drob1.znam) != 0)
            sokrashchenie(drob1.chisl, drob1.znam);
    }
    if(op == 5) // приведение к десятичной дроби
    {
        cout << "vvedite drob'\n";  // ввод дроби
        cin >> str; 
        drob drob1 = strdrob(str);
        if(proverka(drob1.chisl, drob1.znam) != 0)
            desyatichnaya(drob1.chisl, drob1.znam);
    }
    if(op == 6) // приведение к правильной дроби
    {
        cout << "vvedite drob'\n";  // ввод дроби
        cin >> str; 
        drob drob1 = strdrob(str);
        if(proverka(drob1.chisl, drob1.znam) != 0)
            pravilnaya(drob1.chisl, drob1.znam);
    }
    system("pause");
    return 0;
}

