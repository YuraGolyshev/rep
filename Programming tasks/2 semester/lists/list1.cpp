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

list *find ( list *h, list *t, int x, int f){ //поиск элементов списка в соответствии с их номером
    list *p = h; //укзатель на голову
    while (p){ //пока не дошли до конца списка
        if (p->inf == x)
            f--;
        if (p->inf == x && f == 0) 
            break; // если нашли, прекращаем цикл
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

int main()
{
    list *h = NULL; 
    list *t = NULL;
    int n, el, max, nech;
    cout << "n="; cin >> n;
    cout << "BBedite elemeti" << endl;
    for(int i=0;i<n;i++) // заполняем список
    {
        cin >> el;
        push(h,t,el);
    }
    list *h2 = h;
    list *h3 = h;
    max = h2->inf;
    int d = 0;
    while(h2) // ищем максимальный элемент и считаем сколько их
    {
        el = h2->inf;
        h2 = h2->next; 
        if(el == max)
            d++;
        if(el > max)
        {
            max = el;
            d=1;
        }
    }
    while(h3) // ищем последний нечетный элемент
    {
        el = h3->inf;
        h3 = h3->next;
        if(el % 2 != 0)
            nech = el;
    }
    for(int i=1;i<=d;i++) // вставляем последний нечетный элемент после всех чисел равных максимальному
        insert_after(h,t,find(h,t,max,i),nech);
    print(h,t);
    cout << endl;
    system("pause");
    return 0;
}