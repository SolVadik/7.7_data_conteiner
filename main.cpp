// Цельночисленный контейнер
#include <iostream>
#include "conteiner.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "");

    Conteiner array(10);
     
    for (int i{ 0 }; i < 10; ++i)
        array[i] = i + 1;

    array.resize(8);
    array.insert_before(20, 5);
    array.remove(3);
    array.insert_end(30);
    array.insert_beginning(40);

    Conteiner b{ array };
    b = array;
    b = b;
    array = array;
    
    array.show();
    cout << "\n";
    b.show();
    cout << '\n';
    cout << array.find(30) << endl;
    

    cout << array.get_data(5) << endl;

	return 0;
}

