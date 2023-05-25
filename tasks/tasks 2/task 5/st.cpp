#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct stack{
int inf;
stack *next;
};

void push(stack *&h, int x)
{//вставка
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop (stack *&h)
{ //удаление
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

int op(char p, int a, int b) // функция для вычислений 
{
    if(p == '+')
        return a+b;
    if(p == '-')
        return a-b;
    if(p == '*')
        return a*b;
    if(p == '/')
        return a/b;
}

int main()
{
    string str;
    getline(cin, str);
    stack *head = NULL; //инициализация
    for(int i=0;i<str.size();i++) // цикл до конца строки
    {
        if(isdigit(str[i])) // если элемент число
        {
            int x = str[i]-'0'; // получаем это число
            push(head, x);  // записываем в стек
        }
        else    // если элемент это знак
        {
            int b = pop(head);  // ивлекаем элементы
            int a = pop(head);
            int res = op(str[i], a, b); // вычисляем
            push(head, res);    // записываем в стек
        }
    }
    cout << pop(head); // выводим ответ
}