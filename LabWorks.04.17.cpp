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

����������������� (��� �����������) ����� �������������� ���������.

����������� ��������� �� ������ ������ (������ �������� ��������) ����� �������,
����� �������� �� ��������� ������ ����������� � ������� �����������.

����������� �����, ������� ��������� ��������� �� �������� ������� �� ���������.
���� ����� ������ ���� ������������� � ������� ��������� ��������� ������.

������������� ��������� - integer_set

*/

#include "NodeStack.h"
#include "integer_set.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    int valueNew = NULL;
    bool number_element_Bool;

    //������������� ��������� �� ����������� - ��������� ������

    integer_set lst;
    int sizeSLL;

    cout << "������� ������ �������������� ���������: ";
    cin >> sizeSLL;                                             //��������� �� ������������ ������� ���������

    valueNew = NULL;
    for (int i = 0; i < sizeSLL; i++)
    {
        cout << endl;
        printf("������� �������� �%d: ", i);
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
        cout << "������� ������ �������� ���������, �������� �������� �� ������ ��������: ";
        cin >> number_element_GVOE;                             //��������� �� ������������ ������� �������� �������� ���������

        if (number_element_GVOE < lst.count())
        {
            value_element_GVOE = lst.getValueOfElement(number_element_GVOE);
            cout << endl;
            cout << "�������� �������� ���������: ";
            cout << value_element_GVOE << endl;
            number_element_Bool = false;
        }
        else
        {
            cout << "������ �������� ��������� ������ ������� ��������� " << lst.count() << endl;
            number_element_Bool = true;
        }
    }

    int number_element_SVOE;
    int value_element_SVOE;

    number_element_Bool = true;
    while (number_element_Bool)
    {
        cout << endl;
        cout << "������� ������ �������� ���������, �������� �������� �� ������ ��������: ";
        cin >> number_element_SVOE;                             //��������� �� ������������ ������� ����������� �������� ���������

        if (number_element_SVOE < lst.count())
        {
            value_element_GVOE = lst.getValueOfElement(number_element_GVOE);
            cout << endl;
            cout << "�������� �������� ���������: ";
            cout << value_element_GVOE << endl; 
            cout << endl;
            cout << "������� ����� �������� �������� ���������: ";
            cin >> value_element_SVOE;                          //��������� �� ������������ �������� ����������� �������� ��������� 

            lst.setValueOfElement(number_element_SVOE, value_element_SVOE);

            cout << endl;
            lst.print("lst");
            number_element_Bool = false;
        }
        else
        {
            cout << "������ �������� ��������� ������ ������� ���������" << endl;
            number_element_Bool = true;
        }
    }

    int value_element_AVOE;

    cout << endl;
    cout << "������� �������� �������� ��������� ������� �� ������ �������� �� ���������: ";
    cin >> value_element_AVOE;                                  //��������� �� ������������ �������� ������������ �� ���������

    lst.addValueOfElement(value_element_AVOE);

    cout << endl;
    lst.print("lst");

    int value_element_srhVOE;

    cout << endl;
    cout << "������� �������� �������� ���������, ������� �� ������ ����� �� ���������: ";
    cin >> value_element_srhVOE;                                //��������� �� ������������ �������� �������� ���������, ������� ����� ����� �� ���������

    lst.searchValueOfElement(value_element_srhVOE);

    cout << endl;
    lst.print("lst");

    return 0;
}