#include <cmath> 
#include<iostream> 

using namespace std; 

int main(){ 
int o, i, n, c = 1;
cout << "nomer op \n"; 
cin >> o;

//1
if (o == 1){ 
cout << "i = "; 
cin >> i; 
cout << (c<<i) << endl;
}
//выводит 2^i

//2
if (o == 2){
cout << "i = ";
cin >> i;
cout << "n = ";
cin >> n;
cout << ((c << i) | n) << endl;
}
/*пример:
i = 2  n = 8
установим i-ый бит 1 в переменной c, тогда c = 4(100)
остальне биты должны совпадать с битами n = 8(1000), тогда  c = 12(1100)*/

//3
if (o == 3){
cout << "i = ";
cin >> i;
cout << "n = ";
cin >> n;
cout << ((~(c << i)) & n) << endl;   
}
/*пример:
i = 3  n = 27(11011)
установим i-ый бит в 1, тогда c = 8(1000)
если применить отрицание, тогда получим i-ый бит в 0, с = 1(0001)
остальные биты(кроме i-ого) должны совпадать с числом n, для этого применим операцию логического умножения &
Получим c = 19(10011)*/

//4
if (o == 4){
cout << "i = ";
cin >> i;
cout << "n = ";
cin >> n;
cout << (((c << i)) ^ n) << endl;    
}
/*пример:
i = 2  n = 12(1100)
i-ый бит в данном случае равен 1, значит в c i-ый бит равен 0
остальные биты должны сопадать с числом n
Получим c = 8(1000)*/

//5
if (o == 5){
cout << "n = ";
cin >> n;
i = c & n;
if (i == 1){
cout << "nechetnoe" << endl;
}
else{
cout << "chetnoe" << endl;    
}}
/*бит четности - нулевой бит
с = 1, поэтому при логическом умножении на n в результате получим значение бита четности
1 - нечетное, 0 - четное*/

system("pause"); 
return 0; 
}