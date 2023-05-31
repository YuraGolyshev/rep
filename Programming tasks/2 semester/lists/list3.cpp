#include <iostream>
#include <vector>

using namespace std;

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

void insert_after ( list *&h, list *&t, list *r, int y){ //вставляем после r
    list *p = new list; //создаем новый элемент
    p->inf = y;
    if (r == t){ //если вставляем после хвоста
        p->next = NULL; //вставляемый эл-т - последний
        p->prev = r; //вставляем после r
        r->next = p;
        t = p; //теперь хвост - p
    }
    else{ //вставляем в середину списка
        r->next->prev = p; //для следующего за r эл-та предыдущий - p
        p->next = r->next; //следующий за p - следующий за r
        p->prev = r; //p вставляем после r
        r->next = p;
}
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

void del_list( list *&h, list *&t){ //удаляем список
while (h){ //пока список не пуст
list *p = h; //указатель на голову
h = h->next; //переносим голову
h->prev = NULL; //обнуляем
delete p; //удаляем p
}
}

int findcount( list *h, list *t, int x)
{
    int c = 0;
    list *p = h; //укзатель на голову
    while (p){ //пока не дошли до конца списка
        if (p->inf == x) c++; // если нашли, прекращаем цикл
        p = p->next; //переход к следующему элементу
    }
    return c; //возвращаем указатель
}

int main()
{
list *h = NULL;
list *t = NULL;
int n, el, sum, j, c;
cout << "n="; cin >> n;
cout << "BBedite elemeti" << endl;
for(int i=0;i<n;i++)    // заполняем список
{
    cin >> el;
    push(h,t,el);
}
for(int i=n;i>0;i--)    // цикл, чтобы пройтись по всем элементам
{
    list *h2 = h;
    list *t2 = t;
    c = 0;
    sum = 0;
    j = 0;
    for(int m=0;m<=n-i;m++) // проходимся справа налево
    {
        el = t2->inf;
        if(m != n-i)    // если за элементом, который проверяем на соответствие условию
        {
            t2 = t2->prev;
            sum += el;  // считаем сумму
            c++;    // считаем кол-во
        }
        if(m == n-i)    // запоминаем элемент, который проверяем
            j = el;
    }
    
    if(sum != 0 && c != 0)
        if(j>sum/c) // удаляем если не соответствует условию
        {
            del_node(h,t,find(h,t,j));
            n--;    // уменьшаем кол-во элементов 
        }
}
print(h,t);
cout << endl;
system("pause");
return 0;
}