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

int notpop (queue *&h, queue *&t)  // возвращает значение элемента
{ 
queue *r = h; //создаем указатель на голову
int i = h->inf; //сохраняем значение головы
return i;
}

queue *result (queue *&h, queue *&t)
{
    int d = 0;
    while(h && d<1)
    {
        int x = notpop(h, t); // узнаем с каким элементом работаем
        if(x % 2 != 0) d++;  // чтобы дойти до первого нечетного
        if(d < 1)   // если четное
        {
            pop(h, t);   // удаляем
            push(h, t, x);  // вставляем в конец
        }
    }
    return h; // возвращаем h
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
    queue *h = result(head, tail); //результат
    while(h)
        cout << pop(h, tail) << " "; //выводим на экран
    cout << endl;
    system("pause");
    return 0;
}
