#pragma once
#include "except.h"


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

	int& operator[](int index);
	Conteiner& operator=(Conteiner& a);

	void show();
	//const int& get_data(const int& index);
	const int& get_length();

	// изменить размер и очистить
	void reallocate(const int& new_length);
	void resize(const int& new_length);
	void erase();
	void remove(const int& index);
	int find(const int& value);

	void insert_end(const int& value);
	void insert_beginning(const int& value);
	void insert_before(const int& value, const int& index);

	void bad_range(const int& index);
	void bad_length(const int& length);
};
