#include<iostream>
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

void reverse(stack *&h)
{ //"обращение"стека
    stack *head1 = NULL; //инициализация буферного стека
    while (h) //пока стек не пуст
    push(head1, pop(h)); //переписываем из одного стека в другой
    h = head1; //переобозначаем указатели
}

stack *result (stack *&h)
{
    stack *res = NULL; //инициализация
    stack *h1 = NULL;
    stack *h2 = NULL;
    while(h)
    {
        int x = pop(h);
        if(x % 2 != 0)push(h1, x); //записываем в h1
        if(x % 2 == 0)push(h2, x); //записываем в h2
    }
    while(h2)// переписываем h2 в res
        {
        int x = pop(h2);
        push(res, x);
        }
    while(h1)// переписываем h1 в res
        {
        int x = pop(h1);
        push(res, x);
        }
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
