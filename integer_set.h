#pragma once

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include<iostream>

using namespace std;

#include "NodeStack.h"

class integer_set                                                       //множество на основе списка (любого наиболее удобного), элементы во множестве всегда содержатся в порядке возрастания
{
private:
    NodeStack* pTop;                                                    //указатель на вершину списка

    void push(int item);                                                //поместить элемент в список, элемент помещается на вершину списка

public:
    integer_set();                                                      //конструктор по умолчанию

    integer_set(const integer_set& l);                                  //конструктор копировання

    ~integer_set();                                                     //деструктор

    void pushNew(int new_element);                                      //поместить элемент в список, элемент помещается в порядке возрастания

    int peek();                                                         //получить элемент вершины из списка, элемент остаётся в списке

    int pop();                                                          //получить элемент вершины из списка, элемент удаляется из списка

    int count();                                                        //количество элементов в списке

    void empty();                                                       //очищает список - удаляет все элементы из списка
 
    integer_set& operator=(const integer_set& l);                       //оператор копирования

    void print(const char* l);                                          //вывод списка

    int getValueOfElement(int& number_element);                         //получить значение элемента указав индекс

    void setValueOfElement(int& number_element, int& value_element);    //заменяет элемент в списка по указанному индексу, элемент помещается в порядке возрастания!

    void addValueOfElement(int& new_element);                           //поместить элемент в список, элемент помещается в порядке возрастания

    void searchValueOfElement(int& value_element);                      //поиск элемента по значению в списке. Метод оптимизирован с помощью алгоритма двоичного поиска
};