#include "integer_set.h"

integer_set::integer_set()                                                      //конструктор по умолчанию
{
    pTop = nullptr;
}

integer_set::integer_set(const integer_set& l)                                  //конструктор копировання
{
    NodeStack* p1;                                              //дополнительные указатели
    NodeStack* p2;
    NodeStack* p3;
    
    pTop = nullptr;
    p3 = nullptr;
    
    p1 = l.pTop;                                                //указатель p1 движется по списку l.pTop->...
    while (p1 != nullptr)
    {
        try                                                     //1. Сформировать узел p2
        {
                p2 = new NodeStack;                             //попытка выделения памяти
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;                           //если память не выделена, то выход
            return;
        }
        
        p2->item = p1->item;
        p2->next = nullptr;
        
        if (pTop == nullptr)                                    //2. pTop = pTop + p2
        {
            pTop = p2;                                          //создать очередь
            p3 = p2;
        }
        else
        {
            p3->next = p2;
            p3 = p3->next;
        }
        
        p1 = p1->next;                                          //3. Перейти на следующий элемент
    }
}

integer_set::~integer_set()                                                     //деструктор
{
    empty();
}

void integer_set::push(int item)                                                //поместить элемент в список, элемент помещается на вершину списка
{
    NodeStack* p1;
    
    try                                                         //1. Сформировать элемент
    {
        p1 = new NodeStack;                                     //попытка выделить память
    }
    catch (bad_alloc e)
    {
        cout << e.what() << endl;                               //если память не выделилась, то выход
        return;
    }

    p1->item = item;
    p1->next = pTop;                                            //p1 указывает на 1-й элемент
    
    pTop = p1;                                                  //2. Перенаправить pTop на p1
}

void integer_set::pushNew(int new_element)                                      //поместить элемент в список, элемент помещается в порядке возрастания
{
    integer_set lstTemp;
    int jCount = lstTemp.count();
    int iCount = this->count();

    //cout << endl << iCount << " iCount  " << endl;

    if (iCount == 0)
        this->push(new_element);                                  ////добавляем элемент в список, если список пуст
    else
    {
        for (int i = 0; i < iCount; i++)
        {
            //cout << endl << i << " i  " << endl;
            //cout << endl << this->count() << " всего элементов во множестве " << endl;
            //cout << this->peek() << " во множестве " << endl;

            if (this->count() == 0)
            {
                this->push(new_element);                        //добавляем элемент в список, если список пуст после проверок нового элемента
                //cout << endl << this->peek() << " 00 добавляем элемент во множество 00" << new_element << endl;
                //this->print("lst");
                int jCount = lstTemp.count();
                for (int j = 0; j < jCount; j++)                //возвращаем элементы в список    
                    this->push(lstTemp.pop());
                //this->print("lst 00");
                //lstTemp.print("lstTemp 00");
                i = iCount + 1;
            }
            else 
            {
                if (this->peek() == new_element)                //проверяем, есть ли элемент во множестве
                {
                    cout << "Элемент есть во множестве " << endl;
                    jCount = lstTemp.count();
                    for (int j = 0; j < jCount; j++)            //возвращаем элементы в список 
                        this->push(lstTemp.pop());
                    i = i - 1;
                    cout << endl;
                    printf("Введите другое значение элемента: ");
                    cin >> new_element;
                }
                else
                {
                    if (this->peek() > new_element)             //проверяем, больше 
                    {
                        lstTemp.push(this->pop());              //помещаем элемент во временный список
                        //this->print("lst >");
                        //lstTemp.print("lstTemp >");
                        i = i - 1;
                    }
                    else
                    {
                        if (this->peek() < new_element)         //проверяем, меньше
                        {
                            this->push(new_element);            //добавляем элемент в список
                            //cout << endl << this->peek() << " добавляем элемент во множество " << new_element << endl;
                            //this->print("lst");
                            jCount = lstTemp.count();
                            for (int j = 0; j < jCount; j++)    //возвращаем элементы в список
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

int integer_set::peek()                                                         //получить элемент вершины из списка, элемент остаётся в списке
{
   if (pTop == nullptr)                                     //проверка, пуст ли список?
        return 0;

    int item;
    item = pTop->item;

    return item;                                                //вернуть item
}

int integer_set::pop()                                                          //получить элемент вершины из списка, элемент удаляется из списка
{
    if (pTop == nullptr)                                        //проверка, пуст ли список?
        return 0;

    NodeStack* p2;                                              //дополнительный указатель
    int item;
    item = pTop->item;
    
    p2 = pTop;                                                  //перенаправить указатели pTop, p2
    pTop = pTop->next;
    
    delete p2;                                                  //освободить память, выделенную под 1-й элемент
    
    return item;                                                //вернуть item
}

int integer_set::count()                                                        //количество элементов в списке
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

void integer_set::empty()                                                       //очищает список - удаляет все элементы из списка
{
    NodeStack* p1;                                              //дополнительный указатель
    NodeStack* p2;

    p1 = pTop;
    
    while (p1 != nullptr)
    {
        p2 = p1;                                                //сделать копию из p1
        p1 = p1->next;                                          //перейти на следующий элемент списка
        delete p2;                                              //удалить память, выделенную для предыдущего элемента
    }
    pTop = nullptr;                                             //поправить вершину списка
}

integer_set& integer_set::operator=(const integer_set& l)                       //оператор копирования
{
    if (pTop != nullptr)                                        //есть ли элементы в списке?
        empty();
    
    NodeStack* p1;                                              //дополнительный указатель
    NodeStack* p2;
    NodeStack* p3;
    
    pTop = nullptr;                                             //иИнициализировать pTop
    p3 = nullptr;
    
    p1 = l.pTop;                                                //указатель p1 двигается по списку l.pTop->...
    while (p1 != nullptr)
    {
        try                                                     //1. Сформировать узел p2
        {
            p2 = new NodeStack;                                 //попытка выделить память   
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;                           //если память не выделена, то выход
            return *this;
        }

        p2->item = p1->item;
        p2->next = nullptr;

        if (pTop == nullptr)                                    //2. pTop = pTop + p2
        {
            pTop = p2;                                          //создать список
            p3 = p2;
        }
        else
        {
            p3->next = p2;
            p3 = p3->next;
        }
        
        p1 = p1->next;                                          //3. Перейти на следующий элемент
    }
    return *this;
}

void integer_set::print(const char* l)                                          //вывод списка
{
    cout << "Целочисленное множество: " << l << endl;
    if (pTop == nullptr)
        cout << "Множество пусто." << endl;
    else
    {
        NodeStack* p1;                                          //дополнительный указатель
        p1 = pTop;
        while (p1 != nullptr)
        {
            cout << p1->item << " ";
            p1 = p1->next;
        }
        cout << endl;
    }
}

int integer_set::getValueOfElement(int& number_element)                         //получить значение элемента указав индекс
{
    integer_set lstTemp = *this;
    int number_element_from_top;
    number_element_from_top = this->count() - number_element;
    for (int i = 0; i < number_element_from_top - 1; i++)
        lstTemp.pop();
    return lstTemp.pop();
}

void integer_set::setValueOfElement(int& number_element, int& value_element)    //заменяет элемент в списка по указанному индексу, элемент помещается в порядке возрастания!
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

void integer_set::addValueOfElement(int& new_element)                           //поместить элемент в список, элемент помещается в порядке возрастания
{
    this->pushNew(new_element);
    cout << "Новое значение: " << new_element << " добавлено во множество" << endl;
    return;
}

void integer_set::searchValueOfElement(int& value_element)                      //поиск элемента по значению в списке. Метод оптимизирован с помощью алгоритма двоичного поиска
{
    int l = 0;
    int r = this->count();
    int mid;
    while (l < r)
    {
        mid = (l + r) / 2;                                      //считываем срединный индекс отрезка [l,r]
        if (this->getValueOfElement(mid) > value_element)       //проверяем, какую часть нужно отбросить с поиска
            r = mid;  
        else
            l = mid + 1;
    }
    r--;                                                        //уменьшаем на один 
    if (this->getValueOfElement(r) == value_element)
    {
        cout << "Индекс элемента " << value_element << " во множестве равен: " << r;
        cout << endl;
    }
    else 
    {
        cout << "Элемента во множестве нет";
        cout << endl;
    }
    return ;
}