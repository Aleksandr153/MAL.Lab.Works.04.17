#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include<iostream>

using namespace std;

struct Leaks
{
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

/*

17.

Усовершенствовать (или разработать) класс «целочисленное множество».

Реализовать множество на основе списка (любого наиболее удобного) таким образом,
чтобы элементы во множестве всегда содержались в порядке возрастания.

Реализовать метод, который проверяет находится ли заданный элемент во множестве.
Этот метод должен быть оптимизирован с помощью алгоритма двоичного поиска.

целочисленное множество - integer_set

*/

#include "NodeStack.h"
#include "integer_set.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    int valueNew = NULL;
    bool number_element_Bool;

    //целочисленное множество по возрастанию - связанный список

    integer_set lst;
    int sizeSLL;

    cout << "Введите размер целочисленного множества: ";
    cin >> sizeSLL;                                             //получение от пользователя размера множества

    valueNew = NULL;
    for (int i = 0; i < sizeSLL; i++)
    {
        cout << endl;
        printf("Введите значение №%d: ", i);
        cin >> valueNew;
        lst.pushNew(valueNew);
    }
    cout << endl;
    lst.print("lst");

    int number_element_GVOE;
    int value_element_GVOE;

    number_element_Bool = true;
    while (number_element_Bool)
    {
        cout << endl;
        cout << "Введите индекс элемента множества, значение которого вы хотите получить: ";
        cin >> number_element_GVOE;                             //получение от пользователя индекса искомого элемента множества

        if (number_element_GVOE < lst.count())
        {
            value_element_GVOE = lst.getValueOfElement(number_element_GVOE);
            cout << endl;
            cout << "Значение элемента множества: ";
            cout << value_element_GVOE << endl;
            number_element_Bool = false;
        }
        else
        {
            cout << "Индекс элемента множества больше размера множества " << lst.count() << endl;
            number_element_Bool = true;
        }
    }

    int number_element_SVOE;
    int value_element_SVOE;

    number_element_Bool = true;
    while (number_element_Bool)
    {
        cout << endl;
        cout << "Введите индекс элемента множества, значение которого вы хотите изменить: ";
        cin >> number_element_SVOE;                             //получение от пользователя индекса заменяемого элемента множества

        if (number_element_SVOE < lst.count())
        {
            value_element_GVOE = lst.getValueOfElement(number_element_GVOE);
            cout << endl;
            cout << "Значение элемента множества: ";
            cout << value_element_GVOE << endl; 
            cout << endl;
            cout << "Введите новое значение элемента множества: ";
            cin >> value_element_SVOE;                          //получение от пользователя значения заменяемого элемента множества 

            lst.setValueOfElement(number_element_SVOE, value_element_SVOE);

            cout << endl;
            lst.print("lst");
            number_element_Bool = false;
        }
        else
        {
            cout << "Индекс элемента множества больше размера множества" << endl;
            number_element_Bool = true;
        }
    }

    int value_element_AVOE;

    cout << endl;
    cout << "Введите значение элемента множества которое вы хотите добавить во множество: ";
    cin >> value_element_AVOE;                                  //получение от пользователя значения добавляемого во множество

    lst.addValueOfElement(value_element_AVOE);

    cout << endl;
    lst.print("lst");

    int value_element_srhVOE;

    cout << endl;
    cout << "Введите значение элемента множества, которое вы хотите найти во множестве: ";
    cin >> value_element_srhVOE;                                //получение от пользователя значения элемента множества, которое нужно найти во множестве

    lst.searchValueOfElement(value_element_srhVOE);

    cout << endl;
    lst.print("lst");

    return 0;
}