#include<iostream>
using namespace std;

struct stack{
int inf;
stack *next;
};

void push(stack *&h, int x) //вставка
{
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop (stack *&h) //удаление
{ 
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(stack *&h) //"обращение"стека
{ 
    stack *head1 = NULL; //инициализация буферного стека
    while (h) //пока стек не пуст
    push(head1, pop(h)); //переписываем из одного стека в другой
    h = head1; //переобозначаем указатели
}

stack *result (stack *&h)
{
    stack *res = NULL; //инициализация
    stack *h1 = h;
    stack *h2 = h;
    int max = 0;
    int min = 999;
    int d = 0;
    while(h1) // ищем максимальное и минимальное
    {
        int x = h1->inf;
		h1 = h1->next;
		if (x > max) max = x;
        if (x < min) min = x;
    }
    int count=0;
    while(h2) // считаем сколько максимальных
    {
        int x = h2->inf;
		h2 = h2->next;
		if (x == max) count++;
    }
    while(h)
    {
        int x = pop(h);     // удаляем и запоминаем 
        if(x == max) d++;   // считаем кол-во вхождений максимального 
        push(res, x); //записываем в res
        if(x == max && (d == 1 || d == count))  push(res, min); // если первое или последнее вставляем min

    }
    reverse(res);   // развернули
    return res;
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    stack *head = NULL; //инициализация
    int x;
    for (int i = 0; i < n; i++)
    { //создаем стек
        cin >> x;
        push(head, x);
    }
    reverse(head); //переворачиваем стек
    stack *res = result(head); //результат
    while(res)
    cout << pop(res) << " "; //выводим на экран
    cout << endl;
    system("pause");
    return 0;
}
