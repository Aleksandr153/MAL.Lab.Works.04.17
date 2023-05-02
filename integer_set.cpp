#include "integer_set.h"

integer_set::integer_set()                                                      //����������� �� ���������
{
    pTop = nullptr;
}

integer_set::integer_set(const integer_set& l)                                  //����������� �����������
{
    NodeStack* p1;                                              //�������������� ���������
    NodeStack* p2;
    NodeStack* p3;
    
    pTop = nullptr;
    p3 = nullptr;
    
    p1 = l.pTop;                                                //��������� p1 �������� �� ������ l.pTop->...
    while (p1 != nullptr)
    {
        try                                                     //1. ������������ ���� p2
        {
                p2 = new NodeStack;                             //������� ��������� ������
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;                           //���� ������ �� ��������, �� �����
            return;
        }
        
        p2->item = p1->item;
        p2->next = nullptr;
        
        if (pTop == nullptr)                                    //2. pTop = pTop + p2
        {
            pTop = p2;                                          //������� �������
            p3 = p2;
        }
        else
        {
            p3->next = p2;
            p3 = p3->next;
        }
        
        p1 = p1->next;                                          //3. ������� �� ��������� �������
    }
}

integer_set::~integer_set()                                                     //����������
{
    empty();
}

void integer_set::push(int item)                                                //��������� ������� � ������, ������� ���������� �� ������� ������
{
    NodeStack* p1;
    
    try                                                         //1. ������������ �������
    {
        p1 = new NodeStack;                                     //������� �������� ������
    }
    catch (bad_alloc e)
    {
        cout << e.what() << endl;                               //���� ������ �� ����������, �� �����
        return;
    }

    p1->item = item;
    p1->next = pTop;                                            //p1 ��������� �� 1-� �������
    
    pTop = p1;                                                  //2. ������������� pTop �� p1
}

void integer_set::pushNew(int new_element)                                      //��������� ������� � ������, ������� ���������� � ������� �����������
{
    integer_set lstTemp;
    int jCount = lstTemp.count();
    int iCount = this->count();

    //cout << endl << iCount << " iCount  " << endl;

    if (iCount == 0)
        this->push(new_element);                                  ////��������� ������� � ������, ���� ������ ����
    else
    {
        for (int i = 0; i < iCount; i++)
        {
            //cout << endl << i << " i  " << endl;
            //cout << endl << this->count() << " ����� ��������� �� ��������� " << endl;
            //cout << this->peek() << " �� ��������� " << endl;

            if (this->count() == 0)
            {
                this->push(new_element);                        //��������� ������� � ������, ���� ������ ���� ����� �������� ������ ��������
                //cout << endl << this->peek() << " 00 ��������� ������� �� ��������� 00" << new_element << endl;
                //this->print("lst");
                int jCount = lstTemp.count();
                for (int j = 0; j < jCount; j++)                //���������� �������� � ������    
                    this->push(lstTemp.pop());
                //this->print("lst 00");
                //lstTemp.print("lstTemp 00");
                i = iCount + 1;
            }
            else 
            {
                if (this->peek() == new_element)                //���������, ���� �� ������� �� ���������
                {
                    cout << "������� ���� �� ��������� " << endl;
                    jCount = lstTemp.count();
                    for (int j = 0; j < jCount; j++)            //���������� �������� � ������ 
                        this->push(lstTemp.pop());
                    i = i - 1;
                    cout << endl;
                    printf("������� ������ �������� ��������: ");
                    cin >> new_element;
                }
                else
                {
                    if (this->peek() > new_element)             //���������, ������ 
                    {
                        lstTemp.push(this->pop());              //�������� ������� �� ��������� ������
                        //this->print("lst >");
                        //lstTemp.print("lstTemp >");
                        i = i - 1;
                    }
                    else
                    {
                        if (this->peek() < new_element)         //���������, ������
                        {
                            this->push(new_element);            //��������� ������� � ������
                            //cout << endl << this->peek() << " ��������� ������� �� ��������� " << new_element << endl;
                            //this->print("lst");
                            jCount = lstTemp.count();
                            for (int j = 0; j < jCount; j++)    //���������� �������� � ������
                                this->push(lstTemp.pop());
                            //this->print("lst <");
                            //lstTemp.print("lstTemp <");
                            i = iCount + 1;
                        }
                    }
                }
            }
        };
    }
    return;
}

int integer_set::peek()                                                         //�������� ������� ������� �� ������, ������� ������� � ������
{
   if (pTop == nullptr)                                     //��������, ���� �� ������?
        return 0;

    int item;
    item = pTop->item;

    return item;                                                //������� item
}

int integer_set::pop()                                                          //�������� ������� ������� �� ������, ������� ��������� �� ������
{
    if (pTop == nullptr)                                        //��������, ���� �� ������?
        return 0;

    NodeStack* p2;                                              //�������������� ���������
    int item;
    item = pTop->item;
    
    p2 = pTop;                                                  //������������� ��������� pTop, p2
    pTop = pTop->next;
    
    delete p2;                                                  //���������� ������, ���������� ��� 1-� �������
    
    return item;                                                //������� item
}

int integer_set::count()                                                        //���������� ��������� � ������
{
    if (pTop == nullptr)
        return 0;
    else
    {
        NodeStack* p1 = pTop;
        int c = 0;
        
        while (p1 != nullptr)
        {
            c++;
            p1 = p1->next;
        }
        return c;
    }
}

void integer_set::empty()                                                       //������� ������ - ������� ��� �������� �� ������
{
    NodeStack* p1;                                              //�������������� ���������
    NodeStack* p2;

    p1 = pTop;
    
    while (p1 != nullptr)
    {
        p2 = p1;                                                //������� ����� �� p1
        p1 = p1->next;                                          //������� �� ��������� ������� ������
        delete p2;                                              //������� ������, ���������� ��� ����������� ��������
    }
    pTop = nullptr;                                             //��������� ������� ������
}

integer_set& integer_set::operator=(const integer_set& l)                       //�������� �����������
{
    if (pTop != nullptr)                                        //���� �� �������� � ������?
        empty();
    
    NodeStack* p1;                                              //�������������� ���������
    NodeStack* p2;
    NodeStack* p3;
    
    pTop = nullptr;                                             //����������������� pTop
    p3 = nullptr;
    
    p1 = l.pTop;                                                //��������� p1 ��������� �� ������ l.pTop->...
    while (p1 != nullptr)
    {
        try                                                     //1. ������������ ���� p2
        {
            p2 = new NodeStack;                                 //������� �������� ������   
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;                           //���� ������ �� ��������, �� �����
            return *this;
        }

        p2->item = p1->item;
        p2->next = nullptr;

        if (pTop == nullptr)                                    //2. pTop = pTop + p2
        {
            pTop = p2;                                          //������� ������
            p3 = p2;
        }
        else
        {
            p3->next = p2;
            p3 = p3->next;
        }
        
        p1 = p1->next;                                          //3. ������� �� ��������� �������
    }
    return *this;
}

void integer_set::print(const char* l)                                          //����� ������
{
    cout << "������������� ���������: " << l << endl;
    if (pTop == nullptr)
        cout << "��������� �����." << endl;
    else
    {
        NodeStack* p1;                                          //�������������� ���������
        p1 = pTop;
        while (p1 != nullptr)
        {
            cout << p1->item << " ";
            p1 = p1->next;
        }
        cout << endl;
    }
}

int integer_set::getValueOfElement(int& number_element)                         //�������� �������� �������� ������ ������
{
    integer_set lstTemp = *this;
    int number_element_from_top;
    number_element_from_top = this->count() - number_element;
    for (int i = 0; i < number_element_from_top - 1; i++)
        lstTemp.pop();
    return lstTemp.pop();
}

void integer_set::setValueOfElement(int& number_element, int& value_element)    //�������� ������� � ������ �� ���������� �������, ������� ���������� � ������� �����������!
{
    integer_set lstTemp;
    int number_element_from_top;
    number_element_from_top = this->count() - number_element;
    for (int i = 0; i < number_element_from_top - 1; i++)
        lstTemp.push(this->pop());
    this->pop();
    for (int i = 0; i < number_element_from_top - 1; i++)
        this->push(lstTemp.pop());
    this->pushNew(value_element);
    return;
}

void integer_set::addValueOfElement(int& new_element)                           //��������� ������� � ������, ������� ���������� � ������� �����������
{
    this->pushNew(new_element);
    cout << "����� ��������: " << new_element << " ��������� �� ���������" << endl;
    return;
}

void integer_set::searchValueOfElement(int& value_element)                      //����� �������� �� �������� � ������. ����� ������������� � ������� ��������� ��������� ������
{
    int l = 0;
    int r = this->count();
    int mid;
    while (l < r)
    {
        mid = (l + r) / 2;                                      //��������� ��������� ������ ������� [l,r]
        if (this->getValueOfElement(mid) > value_element)       //���������, ����� ����� ����� ��������� � ������
            r = mid;  
        else
            l = mid + 1;
    }
    r--;                                                        //��������� �� ���� 
    if (this->getValueOfElement(r) == value_element)
    {
        cout << "������ �������� " << value_element << " �� ��������� �����: " << r;
        cout << endl;
    }
    else 
    {
        cout << "�������� �� ��������� ���";
        cout << endl;
    }
    return ;
}