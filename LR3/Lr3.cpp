﻿#include <iostream>
#include<vector>
#define MAXINT 32767

using namespace std;
class MyObj
{
public:
    int val;

    MyObj(int value = 0)
    {
        this->val = value;
    }

    friend bool operator>(const MyObj a, const MyObj b)
    {
        return a.val > b.val;
    }
    friend ostream& operator<<(ostream& os, const MyObj& obj)
    {
        return os << obj.val;
    }
    friend bool operator < (const MyObj a, const MyObj b)
    {
        return a.val < b.val;
    }
    friend bool operator>=(const MyObj& lh, const MyObj& rh)
    {
        return std::rel_ops::operator>=(lh, rh);
    }
    MyObj operator=(MyObj obj)
    {
        val = obj.val;
        return *this; // возвращает объект, который сгенерировал вызов
    }
    friend bool operator<=(const MyObj& lh, const MyObj& rh)
    {
        return std::rel_ops::operator<=(lh, rh);
    }
};




template < typename ElementType >
void combSort(ElementType* array, int _length) //comb sort for arrays
{
    ElementType temp;
    int length = _length;
    bool flag = true;

    while (length != 1 || flag == true)
    {
        length = (length) / 1.247;
        if (length < 1)
            length = 1;
        flag = false;

        for (int i = 0; i < _length - length; i++)
        {
            if (array[i] > array[i + length])
            {
                temp = array[i];
                array[i] = array[i + length];
                array[i + length] = temp;

                flag = true;
            }
        }
    }
}

template < typename ElementType >
vector<ElementType>combSort(vector<ElementType>vec, int _length) // comb sort for vectors
{
    ElementType temp;
    int length = _length;
    bool flag = true;

    while (length != 1 || flag == true)
    {
        length = (length) / 1.247;
        if (length < 1)
            length = 1;
        flag = false;

        for (int i = 0; i < _length - length; i++)
        {
            if (vec[i] > vec[i + length])
            {
                temp = vec[i];
                vec[i] = vec[i + length];
                vec[i + length] = temp;

                flag = true;
            }
        }
    }
    return vec;
}

template <typename Type>
Type* TournamentSort(Type* Arr, const int size) //Tournament sort for arrays
{
    Type* sortedArray = new Type[size];
    Type* m1 = new Type[2 * size];
    int* m2 = new int[2 * size];
    int i, j, index;
    for (i = size; i <= 2 * size - 1; i++)
    {
        m1[i] = Arr[i - size];
        m2[i] = i;
    }
    for (i = size - 1; i > 0; i--)
    {
        if (m1[2 * i] <= m1[2 * i + 1])
        {
            m1[i] = m1[2 * i];  m2[i] = m2[2 * i];
        }
        else
        {
            m1[i] = m1[2 * i + 1]; m2[i] = m2[2 * i + 1];
        }
    }
    for (j = 0; j < size; j++)
    {
        sortedArray[j] = m1[1];
        index = m2[1];
        m1[index] = MAXINT;
        index = index / 2;
        while (index > 0)
        {
            if (m1[2 * index] <= m1[2 * index + 1])
            {
                m1[index] = m1[2 * index];  m2[index] = m2[2 * index];
            }
            else
            {
                m1[index] = m1[2 * index + 1]; m2[index] = m2[2 * index + 1];
            }
            index = index / 2;
        }
    }
    return sortedArray;
}


template <typename Type>
vector<Type>TournamentSort(vector<Type>Arr, int size) // Tournament sort for vectors
{
    vector<Type>sortedVector(size);
    vector<Type>m1(2 * size);
    vector<int>m2(2 * size);
    int i, j;

    for (i = size; i <= 2 * size - 1; i++)
    {
        m1[i] = Arr[i - size];
        m2[i] = i;
    }
    for (i = size - 1; i > 0; i--)
    {
        if (m1[2 * i] <= m1[2 * i + 1])
        {
            m1[i] = m1[2 * i];  m2[i] = m2[2 * i];
        }
        else
        {
            m1[i] = m1[2 * i + 1]; m2[i] = m2[2 * i + 1];
        }
    }
    for (j = 0; j < size; j++)
    {
        sortedVector[j] = m1[1]; i = m2[1]; m1[i] = MAXINT;
        i = i / 2;

        while (i > 0)
        {
            if (m1[2 * i] <= m1[2 * i + 1])
            {
                m1[i] = m1[2 * i];  m2[i] = m2[2 * i];
            }
            else
            {
                m1[i] = m1[2 * i + 1]; m2[i] = m2[2 * i + 1];
            }
            i = i / 2;
        }
    }
    return sortedVector;
}

template < typename ElementType >
void out_array(const ElementType* arr, size_t arrSize)
{
    for (size_t i = 0; i < arrSize; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

template < typename ElementType >
void out_vector(vector<ElementType>arr, size_t arrSize)
{
    for (size_t i = 0; i < arrSize; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

int main()
{

    const size_t n = 5;
    int arr1[n] = { 10 , 5 , 7 , 3 , 4 };
    double arr2[n] = { 7.62 , 5.56 , 38.0 , 56.0 , 9.0 };
    vector<int>vec1 = { 6 , 5 , 2 , 3 , 4 };
    vector<double>vec2 = { 7.0 , 6.76 , 83.0 , 6.0 , 10.345 };

    vector<MyObj>vec3 = { MyObj(7), MyObj(2), MyObj(1), MyObj(9), MyObj(11) };
    MyObj arr3[n] = { MyObj(0), MyObj(7), MyObj(2), MyObj(1), MyObj(9) };
    cout << "Arrays and vectors for Comb sort:\n";
    out_array(arr1, n); //Компилятор сам выведет параметр шаблона исходя из первого аргумента функции
    out_array(arr2, n);
    out_vector(vec1, n);
    out_vector(vec2, n);
    out_vector(vec3, n);
    out_array(arr3, n);


    combSort(arr1, n);
    combSort(arr2, n);
    vec1 = combSort(vec1, n);
    vec2 = combSort(vec2, n);
    combSort(arr3, n);
    vec3 = combSort(vec3, n);


    std::cout << "\n\nComb sort:\n";
    out_array(arr1, n);
    out_array(arr2, n);
    out_vector(vec1, n);
    out_vector(vec2, n);
    out_vector(vec3, n);
    out_array(arr3, n);

    int m = 8, k = 6, p = 7, l = 4;
    int* mass1 = new int[l] { 10, 5, 7, 3};
    double* mass = new double[m] {7.62, 7.0, 5.56, 38.0, 56.0, 9.0, 56.9876, -23.123678 };
    vector<int>X = { 6, 5, 2, 0, 7, -1 };
    vector<double>x = { 6.872 , 3.0, 9.89 , 83.0 , 7.45 , 1.0, 45.7653,  -12.343 };
    MyObj* arr = new MyObj[k]{ MyObj(7), MyObj(2), MyObj(1), MyObj(9), MyObj(11), MyObj(8) };
    vector<MyObj>vec = { MyObj(2), MyObj(15), MyObj(6), MyObj(-4), MyObj(10), MyObj(8), MyObj(1) };
    cout << "\n\n";
    cout << "Arrays and vectors for Tournament sort:\n";
    out_array(mass1, l);
    out_array(mass, m);
    out_vector(X, k);
    out_vector(x, m);
    out_array(arr, k);
    out_vector(vec, p);

    mass1 = TournamentSort(mass1, l);
    mass = TournamentSort(mass, m);
    X = TournamentSort(X, k);
    x = TournamentSort(x, m);
    arr = TournamentSort(arr, k);
    vec = TournamentSort(vec, p);

    cout << "\n\nTournament Sort:\n";
    out_array(mass1, l);
    out_array(mass, m);
    out_vector(X, k);
    out_vector(x, m);
    out_array(arr, k);
    out_vector(vec, p);
    return 0;
}