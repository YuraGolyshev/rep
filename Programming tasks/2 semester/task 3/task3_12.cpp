#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("input.txt");
ofstream out("output3.txt");

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

bool operator > (people a, people b) //переопределяем оператор < в соотвествии с условием
{
	if (a.surn > b.surn) return true;
	if (a.surn == b.surn && a.wex > b.wex) return true;
    if (a.surn == b.surn && a.wex == b.wex && a.sal > b.sal) return true;
	return false;
}

void chnech_sort(vector<people> &x)      // чет-нечет сортировка
{ 
    for(int i=0; i < x.size();i++)
    {
        if(i % 2 == 0)
            for(int j=2; j < x.size();j+=2)
                if(x[j-1] > x[j])
                    swap(x[j-1], x[j]);
        else
            for(int j=1; j < x.size();j+=2)
                if(x[j-1] > x[j])
                    swap(x[j-1], x[j]);
    }
}

int main()
{
    vector <people> x;
    x = inFile();
    chnech_sort(x);
    for(int i = 0; i < x.size(); i++)   // вводим в файл
    print(x[i]);
    cout << "sorted!" << endl;
    system("pause");
    return 0;
}