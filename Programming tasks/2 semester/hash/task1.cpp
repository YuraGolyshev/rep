#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
//#include <list>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("input.txt");

struct list {
int inf;
list *next;
list *prev;
};

void push (list *&h, list *&t, int x){ //вставка элемента в конец списка
    list *r = new list; //создаем новый элемент
    r->inf = x;
    r->next = NULL; //всегда последний
    if (!h && !t){ //если список пуст
        r->prev = NULL; //первый элемент
        h = r; //это голова
    }
    else{
        t->next = r; //r - следующий для хвоста
        r->prev = t; //хвост - предыдущий для r
    }
    t = r; //r теперь хвост
}

void print ( list *h, list *t){ //печать элементов списка
    list *p = h; //укзатель на голову
    while (p){ //пока не дошли до конца списка
        cout << p->inf << " ";
        p = p->next; //переход к следующему элементу
}
}

list *find ( list *h, list *t, int x){ //поиск элементов списка
    list *p = h; //укзатель на голову
    while (p){ //пока не дошли до конца списка
        if (p->inf == x) break; // если нашли, прекращаем цикл
        p = p->next; //переход к следующему элементу
    }
    return p; //возвращаем указатель
}

void del_node (list *&h, list *&t, list *r){ //удаляем после r
if (r == h && r == t) //единственный элемент списка
h = t = NULL;
else if (r == h){ //удаляем голову списка
h = h->next; //сдвигаем голову
h->prev = NULL;

}
else if (r == t){ //удаляем хвост списка
t = t->prev; //сдвигаем хвост
t->next = NULL;
}
else{
r->next->prev = r->prev; //для следующего от r предыдущим становится r->prev
r->prev->next = r->next; //для предыдущего от r следующим становится r->next
}
delete r; //удаляем r
}

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

int h(people x) // хэш-функция
{
    return x.dob.mm % 47; // берем остаток от деления месяца рождения на 47
}

void create(vector <people> x, vector<list*> &tabl) // 
{
  tabl.resize(x.size());
  for (int i = 0; i < x.size() - 1; i++) 
  {
    int k = h(x[i]);    // вычисляем хэш
    tabl[k].push_back(x[i]);
  }
}

void print(people x) // вывод на экран данных о человеке
{
    cout << setw(15) << right << x.surn << " " << x.dolj 
    << " " << x.dob.dd << "." << x.dob.mm << "." << x.dob.yy 
    << " " << x.wex << " " << x.sal;
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

void add_people(vector<list*>& tabl) // функция добавления человека
{
    people newp = inputinf();
    int k = h(newp); // вычисляем хэш
    tabl[k].push()
  tabl[k].push_back(newp);
  cout << "Person added successfully!" << endl;
}

void find_in_hash(vector <list*> tabl, int month) // функция поиска человека по месяцу в таблице
{
    int hash = month % 47;  // находим хэш заданного числа
    bool flag = false;
    cout << "hash: " << hash << " ";
    for (auto it = tabl[hash].begin(); it != tabl[hash].end(); it++) // просматриваем в соответствующей строке таблицы
    {
        people fp = *it;
        if (fp.dob.mm == month) // если нашили, то выводим на экран
        {
            cout << "information about a person: "; print(fp);
            flag = true;
            cout << endl;
        }
    }
    if (!flag) // если не нашли, выводим сообщение об этом
        cout << "No such person";
    cout << endl;
}

void delp(vector <list*> tabl, int month) // функция удаления человека по месяцу в таблице
{
    int hash = month % 47;  // находим хэш заданного числа
    bool flag = false;
    for (auto it = tabl[hash].begin(); it != tabl[hash].end(); it++) // просматриваем в соответствующей строке таблицы
    {
        people dp = *it;
        if (dp.dob.mm == month) // если нашили, то удаляем
        {
            cout << "Deleted!" << endl;
            flag = true;
            tabl[hash].erase(it--);
        }
    }
    if (!flag)  // если не нашли, выводим сообщение об этом
        cout << "No such person";
    cout << endl;
}

int main()
{
    vector <list*> tabl; // создаем таблицу
    vector <people> x;
    x = inFile();   // считываем из файла
    create(x, tabl); // заполняем хэш-таблицу
    for (int i = 0; i < tabl.size(); i++) // выводим хэш-таблицу
    {
		cout << i << ": ";
		for (auto it = tabl[i].begin(); it != tabl[i].end(); it++) 
        {
			people p = *it;
			print(p);
		}
		cout << endl;
	}

    cout << "Enter information about the new person: " << endl;
    add_people(tabl);   // добавление человка
    cout << endl;

    int month;
    cout << "Enter the month of birth of the person you want to find: ";
    cin >> month;
    find_in_hash(tabl, month);  // поиск человка

    cout << "Enter the month of birth of the person you want to delete: " << endl;
    cin >> month;
    delp(tabl, month); // удаление человка

    for (int i = 0; i < tabl.size(); i++)   // выводим хэш-таблицу
    {
		cout << i << ": ";
		for (auto it = tabl[i].begin(); it != tabl[i].end(); it++) 
        {
			people p = *it;
			print(p);
		}
		cout << endl;
	}
    system("pause");
    return 0;
}