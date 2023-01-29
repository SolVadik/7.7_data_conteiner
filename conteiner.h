#pragma once
#include <string>
#include <exception>

class Conteiner
{
private:
	int length_{};
	int* data_{};

public:
	Conteiner() = default;
	Conteiner(int length);
	Conteiner(Conteiner& a);

	~Conteiner();

	void erase();

	int& operator[](int index);
	Conteiner& operator=(Conteiner& a);

	const int& get_length();
	// изменить размер и очистить
	void reallocate(const int& new_length);
	
	void resize(const int& new_length);

	void insert_before(const int& value,const int& index);

	void remove(const int& index);

	void insert_beginning(const int& value);
	void insert_end(const int& value);

	int find(const int& value);
	
	void show();

	const int& get_data(const int& index);
};
