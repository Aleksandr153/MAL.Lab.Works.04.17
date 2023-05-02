#pragma once

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include<iostream>

using namespace std;

#include "NodeStack.h"

class integer_set                                                       //��������� �� ������ ������ (������ �������� ��������), �������� �� ��������� ������ ���������� � ������� �����������
{
private:
    NodeStack* pTop;                                                    //��������� �� ������� ������

    void push(int item);                                                //��������� ������� � ������, ������� ���������� �� ������� ������

public:
    integer_set();                                                      //����������� �� ���������

    integer_set(const integer_set& l);                                  //����������� �����������

    ~integer_set();                                                     //����������

    void pushNew(int new_element);                                      //��������� ������� � ������, ������� ���������� � ������� �����������

    int peek();                                                         //�������� ������� ������� �� ������, ������� ������� � ������

    int pop();                                                          //�������� ������� ������� �� ������, ������� ��������� �� ������

    int count();                                                        //���������� ��������� � ������

    void empty();                                                       //������� ������ - ������� ��� �������� �� ������
 
    integer_set& operator=(const integer_set& l);                       //�������� �����������

    void print(const char* l);                                          //����� ������

    int getValueOfElement(int& number_element);                         //�������� �������� �������� ������ ������

    void setValueOfElement(int& number_element, int& value_element);    //�������� ������� � ������ �� ���������� �������, ������� ���������� � ������� �����������!

    void addValueOfElement(int& new_element);                           //��������� ������� � ������, ������� ���������� � ������� �����������

    void searchValueOfElement(int& value_element);                      //����� �������� �� �������� � ������. ����� ������������� � ������� ��������� ��������� ������
};