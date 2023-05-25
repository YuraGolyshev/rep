#include<iostream>
using namespace std;

struct queue{
int inf;
queue *next;
};

void push (queue *&h, queue *&t, int x) //вставка элемента в очередь
{ 
    queue *r = new queue; //создаем новый элемент
    r->inf = x;
    r->next = NULL; //всегда последний
    if (!h && !t)
    { //если очередь пуста
        h = t = r; //это и голова и хвост
    }
    else 
    {
        t->next = r; //r - следующий для хвоста
        t = r; //теперь r - хвост
    }
}

int pop (queue *&h, queue *&t)  //удаление элемента из очереди
{ 
queue *r = h; //создаем указатель на голову
int i = h->inf; //сохраняем значение головы
h = h->next; //сдвигаем указатель на следующий элемент
if (!h) //если удаляем последний элемент из очереди
t = NULL;
delete r; //удаляем первый элемент
return i;
}

queue *result (queue *&h, queue *&t)
{
    queue *h1 = h;  //инициализация
    queue *t1 = NULL;
    queue *rh = NULL;
    queue *rt = NULL;
    int max = 0;
    int first;
    int d = 0;
    while(h1) // ищем максимальное и запоминаем первый элемент
    {
        int x = h1->inf;
		h1 = h1->next;
        if(d == 0) first = x;
		if (x > max) max = x;
        d++;
    }
    while(h)
    {
    int x = pop(h, t);  // удаляем элемент и записываем его значение
    push(rt , rh, x);   // записываем в rt
    if(x == first)         // после элементов равных первому вставляем максимальный
        push(rt, rh, max);
    }
    return rt; // возвращаем rt
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    queue *head = NULL; //инициализация
    queue *tail = NULL;
    int x;
    for (int i = 0; i < n; i++) //создаем очередь
    { 
        cin >> x;
        push(head, tail, x);
    }
    queue *rt = result(head, tail); //результат
    while(rt)
        cout << pop(rt, tail) << " "; //выводим на экран
    cout << endl;
    system("pause");
    return 0;
}
