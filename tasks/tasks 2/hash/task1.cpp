#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("input.txt");

struct list 
{
int inf;
list *next;
list *prev;
};

struct date //дата
{
int dd, mm, yy;
};

struct people   //данные о человеке
{
string surn; // фамилия
string dolj; // должность 
date dob;    // дата рождения
int wex;     // опыт работы
int sal;     // зарплата
};

date Str_to_Date(string str )   //из строки в дату
{
date x;
string temp = str.substr(0, 2);//день
x.dd = atoi(temp.c_str() );
temp = str.substr(3, 2);//месяц
x.mm = atoi(temp.c_str());
temp = str.substr(6, 4);//год
x.yy = atoi(temp.c_str() );
return x;
}


vector <people> inFile() //ввод из файла
{
    vector<people> x;
    people temp;
    while (in.peek() != EOF) 
    {
        in >> temp.surn;//фамилия

        in >> temp.dolj; //должность

        string tmp;//дата рождения
        in >> tmp;

        temp.dob = Str_to_Date(tmp);

        in >> temp.wex; //опыт работы

        in >> temp.sal;//зарплата

        x.push_back(temp);
    }

    return x;
}

// void print(people x)    //вывод в файл
// {
//     out << setw(14) << left << x.surn;//по левому краю, 10 позиций для фамилии
//     out << setw(12) << left << x.dolj;//по левому краю, 10 позиций для должности

//     if (x.dob.dd < 10)
//         out << left << '0' << x.dob.dd << '.'; //добавляем 0
//     else
//         out << left << x.dob.dd << '.';

//     if (x.dob.mm < 10)
//         out << '0' << x.dob.mm << '.'; //добавляем 0
//     else
//         out << x.dob.mm << '.';

//     out << left << setw(10) << x.dob.yy;//год рождения

//     out << left << setw(6) << x.wex; //опыт работы

//     out << left << setw(10) << x.sal << endl;//зарплата

// }

// void pod_sort(vector<people> &x, int mxy)      // сортировка подсчетом
// { 
//     vector <int> count(mxy + 1, 0);

//     for(const auto& people : x)
//         count[people.dob.yy]++;
//     for(int i=1; i <= mxy; i++)
//         count[i] += count[i-1];
//     vector <people> result(x.size());

//     for(int i = x.size()-1; i>= 0; i--)
//         result[--count[x[i].dob.yy]] = x[i];
//     x = result;
// }

int main()
{
    vector <people> x;
    x = inFile();
    
    // int mxy = 2023;
    // pod_sort(x, mxy);
    // for(int i = 0; i < x.size(); i++) // вводим в файл
    // print(x[i]);
    // cout << "sorted!" << endl;
    system("pause");
    return 0;
}