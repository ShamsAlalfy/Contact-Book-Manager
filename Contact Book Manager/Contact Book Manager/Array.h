#pragma once
#include <exception>
#include <iostream>
using namespace std;
template <class T>
class Array
{
private:
    T* data;
    size_t capacity;
    size_t size;
    void resize(size_t newCapacity)
    {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    void swap(size_t index1, size_t index2)
    {
        T temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
    }
public:
    Array() :capacity(2), size(0)
    {
        data = new T[capacity];
    }
    Array(size_t size) :size(size), capacity(size)
    {
        data = new T[capacity];
    }
    Array(size_t size, T initialVal) :size(size), capacity(size)
    {
        data = new T[capacity];
        for (int i = 0; i < size; i++)
            data[i] = initialVal;
    }
    Array(const Array<T>& other) :size(other.size), capacity(other.capacity)
    {
        data = new T[capacity];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    Array<T>& operator=(const Array<T>& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        }
        return *this;
    }
    bool operator==(const Array<T>& other)
    {
        if (size != other.size)
            return false;
        for (int i = 0; i < size; i++)
        {
            if (data[i] != other.data[i])
                return false;
        }
        return true;
    }
    T& operator[](size_t index)
    {
        if (index >= size)
            throw std::out_of_range("Index out of range...");
        return data[index];
    }
    size_t getSize()
    {
        return size;
    }
    size_t getCapacity()
    {
        return capacity;
    }
    T& front()
    {
        if (size == 0)
            throw std::out_of_range("Array is empty !");
        return data[0];
    }
    T& back()
    {
        if (size == 0)
            throw std::out_of_range("Array is empty !");
        return data[size - 1];
    }
    void Append(T element)
    {
        if (size >= capacity)
            resize(capacity * 2);
        data[size] = element;
        size++;
    }
    void Insert(T element, int index)
    {
        if (index > size)
            throw std::out_of_range("Index out of range...");
        if (size >= capacity)
            resize(capacity * 2);
        for (size_t i = size; i > index; i--)
            data[i] = data[i - 1];
        data[index] = element;
        size++;
    }
    void Remove()
    {
        size--;
        if (size <= capacity / 4 && capacity > 2)
            resize(capacity / 2);
    }
    void Delete(size_t index)
    {
        if (index > size)
            cout << index << ' ' << size << endl;
        for (size_t i = index; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;
        if (size <= capacity / 4 && capacity > 2)
            resize(capacity / 2);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void set(size_t index, T val)
    {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range...");
        data[index] = val;
    }
    void Reverse()
    {
        size_t start = 0;
        size_t end = size - 1;
        while (start < end)
        {
            swap(start, end);
            start++;
            end--;
        }
    }
    void sort()
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            for (size_t j = 0; j < size - 1; j++)
            {
                if (data[j] > data[j + 1])
                    swap(j, j + 1);
            }
        }
    }
    size_t search(T element)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (data[i] == element)
                return i;
        }
        return -1;
    }
    void Display()
    {
        for (size_t i = 0; i < size; i++)
            cout << data[i] << endl;
    }
    void Clear()
    {
        size = 0;
        resize(2);
    }
    ~Array()
    {
        delete[] data;
        data = nullptr;
    }
};
