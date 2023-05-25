#include <iostream>
#include<vector>

using namespace std;

struct stack{   //стек
int inf;
stack *next;
};

struct queue {	//очередь 
	int inf;
	queue* next;
};

void push(stack *&h, int x)
{//вставка в стек
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop (stack *&h)
{//удаление в стеке
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

void push(queue*& h, queue*& t, int x) 
{//вставка элемента в очередь
	queue* r = new queue;					
	r->inf = x;								
	r->next = NULL;							
	if (!h && !t) 
    {							
		h = t = r;							
	}
	else 
    {
		t->next = r;						
		t = r;								
	}
}

int pop(queue*& h, queue*& t) 
{	//удаление элемента из очереди
	queue* r = h;							
	int i = h->inf;							
	h = h->next;							
	if (!h)
		t = NULL;
	delete r;								
	return i;								
}

int main()
{
    // обход в глубину
	cout << "obhod v glubinu" << endl;
    stack* h = NULL;
    int n, x;
    cout << "n = "; cin >> n;
    cout << "x = "; cin >> x;
	int** Gr = new int*[n];
	int* Gr_razms = new int[n];
	for (int i = 0; i < n; i++) 
    {
		int Grirazm, el;
		cout << "razmerost i kontejnera: ";
		cin >> Grirazm;
		Gr[i] = new int[Grirazm];
		Gr_razms[i] = Grirazm;
		cout << "zapolnite: ";
		for (int j = 0; j < Grirazm; j++) 
        {
			cin >> el;
			Gr[i][j] = el;
		}
	}

	int* a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = 0;

	a[x] = 1;
	push(h, x);
    cout << "najdennaja vershina - " << x << endl;

	while (h) {
		bool fl = false;
		int x = h->inf;
		int y;
		for (int i = 0; i < Gr_razms[x]; i++) 
		{
			if (a[Gr[x][i]] == 0) 
			{
				y = Gr[x][i];
				fl = true;
				break;
			}
		}

		if (fl == true) 
		{
			a[y] = 1;
			push(h, y);
			cout << "najdennaja vershina - " << y << endl;
		}

		else 
			pop(h);
	}

	bool pr = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] == 0) 
		{
			cout << "ostalas neposeshhjonnaja vershina" << endl;
			pr = 1;
		}
	}
	if (pr == 0) 
		cout << "vse vershiny najdeny" << endl;

	cout << endl;

	
	//обход в ширину
	cout << "obhod v shirinu" << endl;	
	queue* h_q = NULL;										
	queue* t = NULL;
	for (int i = 0; i < n; i++)    //Уже созданный массив а нужно только обнулить
    {							
		a[i] = 0;
	}

	int x_q;
	cout << "x = "; cin >> x_q;
	a[x_q] = 1;
	push(h_q, t, x);
	cout << "najdennaja vershina - " << x << endl;

	while (h_q) 
    {
		int x = pop(h_q, t);
		for (int i = 0; i < Gr_razms[x]; i++) 
        {
			if (a[Gr[x][i]] == 0) 
            {
				int y = Gr[x][i];
				a[y] = 1;
				push(h_q, t, y);
				cout << "najdennaja vershina - " << y << endl;
			}
		}
	}

	pr = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == 0) 
        {
			cout << "ostalas neposeshhjonnaja vershina" << endl;
			pr = 1;
		}
	
	if (pr == 0) 
		cout << "vse vershiny najdeny" << endl;
	system("Pause");										
	return 0;												
}