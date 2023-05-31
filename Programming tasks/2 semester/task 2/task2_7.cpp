#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>

using namespace std;

int main()
{
    set <string> vopr, vosk, pov; // создаем множества
    string str, razd;   
    string::size_type pos = 0;
    razd = ".?!";       // разделители
    cout << "Vvedite stroku" << "\n";
    getline(cin, str);  // вводим строку
    
    string::size_type k = str.find_first_of(razd, pos); // ищем конец 1 предложения
    while(k != string::npos)// цикл пока не дошли до конца текста
    {
        char tmp = str[k];  // запоминаем знак 
        string temp = str.substr(pos, k - pos);     // записываем предложение
        temp += ' ';        // в конце добавляем пробел
        string::size_type pos1 = 0; // обнуляем pos1
        string::size_type k1 = temp.find(' ', pos1);// ищем конец 1 слова
        while(k1 != string::npos)   // цикл пока не дошли до конца предложения 
        {
            string word = temp.substr(pos1 ,k1 - pos1); // записываем слово
            for(int i = 0; i < word.size(); i++)        // приводим к одному регистру
                word[i] = tolower(word[i]); 
            switch(tmp)     // в зависимости от знака записываем в соответствующее множество
            {
                case '?':   vopr.insert(word);  break;
                case '!':   vosk.insert(word);  break;
                case '.':   pov.insert(word);   break;
            }
            pos1 = k1 + 1; // увеличиваем pos1
            k1 = temp.find(' ', pos1);  // ищем следующее слово
        }
        k1 = 0;     // обнуляем k1
		pos1 = 0;   // обнуляем pos1 
		pos = k + 2;  // увел pos на 2 так как след предложение начнется после пробела
		k = str.find_first_of(razd, pos);   // ищем след предложение
    }
    set <string> res;   // создаем множество res
    set_difference(vopr.begin(), vopr.end(), pov.begin(), pov.end(), inserter(res, res.begin())); // записываем в res слова, которые есть в vopr, но нет в pov
    set_difference(vosk.begin(), vosk.end(), pov.begin(), pov.end(), inserter(res, res.begin())); // записываем в res слова, которые есть в vosk, но нет в pov

    cout << res.size() << "\n";     // вывродим кол-во слов
    for(auto s : res)   //выводим слова
    {
        cout << s << " ";
    }
    cout << "\n";
    system("pause");
    return 0;
}
