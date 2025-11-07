#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>


struct DynamicArray 
{
    int* data;      
    size_t capacity;  
    size_t size;       
};
void allocate(DynamicArray& arr, size_t new_capacity) 
{
    if (new_capacity > arr.capacity) 
    { 
        int* temp = new int[new_capacity]; 

        for (size_t i = 0; i < arr.size; ++i) 
        {
            temp[i] = arr.data[i]; 
        }

        delete[] arr.data; 
        arr.data = temp; 
        arr.capacity = new_capacity; 
    }
}
void initDynamicArray(DynamicArray& arr, size_t initialCapacity) 
{
    arr.data = new int[initialCapacity];
    arr.capacity = initialCapacity;
    arr.size = 0;
}
void printDynamicArray(const DynamicArray& arr) 
{
    std::cout << "Размер массива: " << arr.size << '\n';
    std::cout << "Емкость массива: " << arr.capacity << '\n';
    std::cout << "Элементы массива: ";
    for (size_t i = 0; i < arr.size; ++i) 
    {
        std::cout << arr.data[i] << ' ';
    }
    std::cout << '\n';
}
void deleteDynamicArray(DynamicArray& arr) 
{
    delete[] arr.data;
    arr.data = nullptr;
    arr.capacity = 0;
    arr.size = 0;
}
void addElement(DynamicArray& arr, int value) 
{
    if (arr.size >= arr.capacity) 
    {
        allocate(arr, arr.capacity * 2); 
    }
    arr.data[arr.size++] = value; 
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));


    DynamicArray myArray;
    initDynamicArray(myArray, 5);

    addElement(myArray, 10);
    addElement(myArray, 20);
    addElement(myArray, 30);
    addElement(myArray, 40);
    addElement(myArray, 50);
    addElement(myArray, 60); 

    printDynamicArray(myArray);

    deleteDynamicArray(myArray);

    return 0;
}