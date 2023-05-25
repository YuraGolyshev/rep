#include <iostream>
#include <set>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n;
    cout << "n="; cin >> n;
 
    set <int> input, output, buff; //создаем

    int elem;
    for(int i = 0; i < n; i++)   // заполняем
    {
        cin >> elem;
        input.insert(elem);
    }
 
    for(auto i : input)
    {
        if(i >= 10 && i<100) // проверяем на двузначность 
        {
            elem = i;
            while(elem)    // записываем в buff последнюю цифру, а потом получаем первую и её тоже записываем
            {
                buff.insert(elem % 10); 
                elem /= 10;
            }
        }
        else
        {
            elem = i;
            while(elem)
            {
                if(buff.find(elem%10) != buff.end())    // ищем и удаляем цифры которые есть в трехзначных и больше
                    buff.erase(buff.find(elem%10));
                elem /= 10;
            }
        }
    }

    set_difference(buff.begin(), buff.end(), input.begin(), input.end(), inserter(output, output.begin())); // переносим из buff в output цифры, которых нет в input(тем самым удалив однозначные)
    
    for(auto item : output) // вывод
    {
        cout << item << ' ';
    }
    cout << "\n";
    system("pause");
    return 0;
}

