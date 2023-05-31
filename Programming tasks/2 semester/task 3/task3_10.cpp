#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

ifstream in("input.txt");
ofstream out("output2.txt");

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


vector<people> inFile() //ввод из файла
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

void print(people x)    //вывод в файл
{
    out << setw(14) << left << x.surn;//по левому краю, 10 позиций для фамилии
    out << setw(12) << left << x.dolj;//по левому краю, 10 позиций для должности

    if (x.dob.dd < 10)
        out << left << '0' << x.dob.dd << '.'; //добавляем 0
    else
        out << left << x.dob.dd << '.';

    if (x.dob.mm < 10)
        out << '0' << x.dob.mm << '.'; //добавляем 0
    else
        out << x.dob.mm << '.';

    out << left << setw(10) << x.dob.yy;//год рождения

    out << left << setw(6) << x.wex; //опыт работы

    out << left << setw(10) << x.sal << endl;//зарплата

}

bool operator <= (people a, people b)   //переопределяем оператор < в соотвествии с условием
{
	map <string,int> order = {{"Student", 0}, {"Junior", 1}, {"Middle", 2}, {"Senior", 3}};
    if (order[a.dolj] < order[b.dolj]) return true;
	if (order[a.dolj] == order[b.dolj] && a.sal <= b.sal) return true;
	return false;
}

void gnom_sort(vector<people> &x)      // гномья сортировка
{ 
    int i = 1;
    while(i < x.size())
    {
        if(i == 0)
            i++;
        if(x[i-1] <= x[i])
            i++;
        else
        {
            swap(x[i], x[i-1]);
            i--;
        }
    }
}

int main()
{
    vector <people> x;
    x = inFile();
    gnom_sort(x);
    for(int i = 0; i < x.size(); i++)   // вводим в файл
    print(x[i]);
    cout << "sorted!" << endl;
    system("pause");
    return 0;
}