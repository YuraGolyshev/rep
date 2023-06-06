#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("input.txt");

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

int aux_h(int x) // вспомогательная квадратичная хэш-функция
{
    float aux_mult = x * 0.61803;
	int aux_int = int(aux_mult);
	float aux = aux_mult - aux_int;
	aux *= 64;
	return int(aux);
}

int h(int aux_x, int j) // линейная хэш-функция
{
    return ((aux_x + j)) % 64; // берем остаток от деления aux_x на 64
}

void create(vector <people> x, vector <people> &tabl) {
  tabl.resize(64);
  for (int i = 0; i < x.size(); i++) {
    int k = aux_h(x[i].dob.yy); // считаем вспомогательный хэш от года рождения
    int j = 0;
    while (true) {
        int p = h(k, j); // считаем основной хэш данного элемента
        if (tabl[p].wex == 0) // если ячейка пуста, записываем туда элемент
        { 
            tabl[p] = x[i];
            break;
        }
      else
        j++; // иначе идём дальше
    }
  }
}

void print(people x) // вывод на экран данных о человеке
{   
    if (x.dob.dd == 0)  // дня 0 быть не может, отсекаем пустые ячейки
        cout << " ";
    else
    {
    cout << x.surn << " " << x.dolj 
    << " " << x.dob.dd << "." << x.dob.mm << "." << x.dob.yy 
    << " " << x.wex << " " << x.sal;
    }
}

people inputinf() // ввод данных о человеке 
{
  people newp;
  string dob;
  cout << "Enter surn: ";    cin >> newp.surn;
  cout << "Enter dolj: ";   cin >> newp.dolj;
  cout << "Enter dob: ";    cin >> dob;
  newp.dob = Str_to_Date(dob);
  cout << "Enter exp: ";    cin >> newp.wex;
  cout << "Enter salary: "; cin >> newp.sal;
  return newp;
}

void add_people(vector <people> &tabl) // функция добавления человека
{
    people newp = inputinf();
    int k = aux_h(newp.dob.yy); // считаем вспомогательный хэш от года рождения
    int j = 0;
    while (true) {
        int p = h(k, j); // считаем основной хэш данного элемента
        if (tabl[p].wex == 0) // если ячейка пуста, записываем туда элемент
        { 
            tabl[p] = newp;
            break;
        }
        else
        j++; // иначе идём дальше
    }
    cout << "Person added successfully!" << endl;
}

void find_in_hash(vector <people> tabl, int year)
{
    int k = aux_h(year);  // находим aux_x для искомого значения 
    //bool flag = false;
    //cout << "hash: " << hash << " ";
    int j = 0;
    while (true) 
    {
        int p = h(k, j); // считаем основной хэш данного элемента
        if (tabl[p].dob.yy == year)    // если ячейка не пуста, выводим информацию о человеке
        { 
            cout << "Information about the employee: " << endl; print(tabl[p]);
            cout << endl;
        }
        if (tabl[p].dob.dd == 0 && j == 0) // если ячейка пуста, искомого человка в таблице нет
        { 
            cout << "No such element";
            break;
        }
        if (tabl[p].dob.dd == 0) // если ячейка пуста, искомого человка в таблице нет
            break;
        j++; // идём дальше на случай, если людей с таким годом рождения больше одного
    }
}

int main()
{
    vector <people> tabl; // создаем таблицу
    vector <people> x;
    x = inFile();   // считываем из файла
    create(x, tabl); // заполняем хэш-таблицу
    
    for (int i = 0; i <tabl.size(); i++) // выводим таблицу
    {
		cout << i << ": "; print(tabl[i]);
		cout << endl;
	}
    
    cout << "Enter information about the new person: " << endl;
    add_people(tabl);   // добавление человка
    cout << endl;

    int year;
    cout << "Enter the year of birth of the person you want to find: ";
    cin >> year;
    find_in_hash(tabl, year);  // поиск человка
    
    cout << endl;
    for (int i = 0; i <tabl.size(); i++) // выводим таблицу
    {
		cout << i << ": "; print(tabl[i]);
		cout << endl;
	}
    system("pause");
    return 0;
}