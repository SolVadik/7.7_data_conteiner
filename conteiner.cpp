#pragma once
#include "conteiner.h"


Conteiner::Conteiner(int length) : length_(length)
{	
    try
    {
        bad_length(length);
        data_ = new int [length] {};
    }
    catch (Except& exc)
    {
        std::cout << "An array exception occurred (" << exc.what() << " " << length << " )" << std::endl;
    }
}

Conteiner::Conteiner(Conteiner& a)
{
    reallocate(a.get_length());
    for (int index{ 0 }; index < length_; ++index)
        data_[index] = a.data_[index];
}

Conteiner::~Conteiner()
{
    delete[] data_;
}

int& Conteiner::operator[](int index)
{
    try
    {
        bad_range(index);
        
    }
    catch (Except& exc)
    {
        std::cout << "An array exception occurred (" << exc.what() << " " << index << " )" << std::endl;
        index = 0;
    }
    return data_[index];
}

Conteiner& Conteiner::operator=(Conteiner& a)
{
    if (&a == this)
        return *this;
    reallocate(a.get_length());
    for (int index{ 0 }; index < length_; ++index)
        data_[index] = a.data_[index];

    return *this;
}

void Conteiner::show()
{
    if (length_ != 0)
    {
        for (int i{ 0 }; i < length_; i++)
        {
            std::cout << data_[i] << " ";
        }
    }
    else
    {
        std::cout << 0;
    }
}

//const int& Conteiner::get_data(const int& index){return data_[index];}


const int& Conteiner::get_length()
{
    return length_;
}

void Conteiner::reallocate(const int& new_length)
{

    erase();
    if (new_length <= 0)
        return;
    data_ = new int[new_length];
    length_ = new_length;
}

void Conteiner::resize(const int& new_length)
{
    if (new_length == length_)
        return;

    if (new_length <= 0)
    {
        erase();
        return;
    }

    int* data{ new int[new_length] };

    if (length_ > 0)
    {
        int elementsToCopy{ (new_length > length_) ? length_ : new_length };
        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = data_[index];
    }
    delete[] data_;

    data_ = data;
    length_ = new_length;
}

void Conteiner::erase()
{
    delete[] data_;
    data_ = nullptr;
    length_ = 0;
}

void Conteiner::remove(const int& index)
{
    try
    {
        bad_range(index);



        if (length_ == 1)
        {
            erase();
            return;
        }
        int* data{ new int[length_ - 1] };

        for (int before{ 0 }; before < index; ++before)
            data[before] = data_[before];

        for (int after{ index + 1 }; after < length_; ++after)
            data[after - 1] = data_[after];

        delete[] data_;
        data_ = data;
        --length_;
    }
    catch (Except& exc)
    {
        std::cout << "An array exception occurred (" << exc.what() << " " << index << " )" << std::endl;
    }

}

int Conteiner::find(const int& value)
{
    for (int i{ 0 }; i < length_; i++)
    {
        if (value == data_[i]) return i;
    }
    return -1;
}

void Conteiner::insert_end(const int& value) { insert_before(value, length_); }

void Conteiner::insert_beginning(const int& value) { insert_before(value, 0); }

void Conteiner::insert_before(const int& value, const int& index)
{
    try
    {
        bad_range(index);


        int* data{ new int[length_ + 1] };
        for (int before{ 0 }; before < index; ++before)
            data[before] = data_[before];
        data[index] = value;
        for (int after{ index }; after < length_; ++after)
            data[after + 1] = data_[after];
        delete[] data_;
        data_ = data;
        ++length_;
    }
    catch (Except& exc)
    {
        std::cout << "An array exception occurred (" << exc.what() << " " << index << " )" << std::endl;
    }
}

void Conteiner::bad_range(const int& index)
{
    if ((index < 0) || (index > length_)) throw Except(" Invalid index");
}

void Conteiner::bad_length(const int& length)
{
    if (length < 1) throw Except(" Invalid index");
}





