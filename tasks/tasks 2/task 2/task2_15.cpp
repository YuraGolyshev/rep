#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main()
{
    multiset <string> chisla;   // создаем множество строк, которые могут повторяться 
    string str;
    ifstream file("C:\\Users\\79370\\Desktop\\fortask\\FORTASK.txt"); // записываем в str строку из файла
    getline(file, str);
    cout << str << "\n";
    int k, a;
    cout << "k=";   cin >> k;   // вводим k
    int pos = 0;
    while(pos <= str.length())  // цикл пока pos меньше длины строки
    {
        if(isdigit(str[pos]))   // если элемент число
        {
            a = pos;    // запоминаем начало числа
            while(isdigit(str[pos]))    // идем до конца числа
                pos++;

            string chislo = "";     // пустая строка для числа
            for(int i = a;i <= pos-1; i++)  // записываем число в строку chislo
                chislo += str[i];
            chisla.insert(chislo);  // вводим в chisla chislo 
        }
        else pos++;     // если элемент не число идем дальше
    }
    string c;
    int count;
    for(auto it = chisla.begin(); it != chisla.end(); it++) 
    {
        count = chisla.count(*it);  // считаем количество повторений числа в chisla
        if(count == k)  // проверием равно ли количество повторений числа k
        {
            cout << *it << "\n";    // выводим число которе удовлетворяет условию 
            for(int i = 0; i < k-1;i++) // пропускаем повторяющиеся элементы
                it++;
        }
    }
    system("pause");
    return 0;
}
