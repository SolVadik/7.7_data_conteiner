// Цельночисленный контейнер
#include "conteiner.h"


int main()
{
    setlocale(LC_ALL, "");

    Conteiner array(10);
    Conteiner b(0); //
    b.resize(10);

    for (int i{ 0 }; i < 10; ++i)
    {
        array[i] = i + 1;
        b[i] = i + 1;
    }
    
    b.remove(-5); //
    std::cout << b[15] << std::endl; //
    b.insert_before(10, 20); //

    array.resize(8);
    array.insert_before(20, 5);
    array.remove(3);
    array.insert_end(30);
    array.insert_beginning(40);
    std::cout << array.find(30) << std::endl;
    std::cout << array[5] << std::endl;

    Conteiner c{ array };
    c = array;
    c = c;
    array = array;

    array.show();
    std::cout << "\n";
    b.show();
    std::cout << '\n';
    c.show();
    std::cout << '\n';

	return 0;
}

