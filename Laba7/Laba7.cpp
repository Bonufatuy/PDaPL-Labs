#include <iostream>

class Death_Stranding {
public:
    Death_Stranding(int id = 0, int time = 0, int level = 0) :
        m_id(id), m_time(time), m_level(level) {}
    ~Death_Stranding() {}

    int getId() {
        return m_id;
    }
    int getTime() {
        return m_time;
    }
    int getLevel() {
        return m_level;
    }

private:
    int m_id;
    int m_time;
    int m_level;
};


class Exception
{
private:
    int error;

public:
    Exception()
    {
        error = 0;
    }
    Exception(int error)
    {
        this->error = error;
    }
    void what()
    {
        if (error == 0) {
            std::cout << "exception" << std::endl;
        }
        if (error == 1)
        {
            std::cout << "Cant insert Dublicate!" << std::endl;
        }
        if (error == 2)
        {
            std::cout << "No such value!" << std::endl;
        }
        if (error == 3)
        {
            std::cout << "pointer is empty" << std::endl;
        }
    }
};

template <class T>
class Iterator;
template <class T>
class List;

template <class T>
class Node {
private:
    T data;
    Node* prev;
    Node* next;
    Node* head;

    friend Iterator<T>;
    friend List<T>;
};

template <class T>
class Iterator {
public:
    Iterator() {
        nodePointer = nullptr;
    }
    Iterator(Node<T>* nodePointer) {
        this->nodePointer = nodePointer;
    }
    ~Iterator() {
        nodePointer = nullptr;
    }
    bool operator == (Iterator other) {
        if (nodePointer == other.nodePointer) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator != (Iterator other) {
        return !operator==(other);
    }

    T GetValue() {
        if (nodePointer == nullptr) {
            throw 3;
        }
        return nodePointer->data;
    }
    void Next() {
        if (nodePointer->next != nullptr) {
            nodePointer = nodePointer->next;
        }
    }
    void Prev() {
        if (nodePointer->prev != nullptr) {
            nodePointer = nodePointer->prev;
        }
    }
private:
    Node<T>* nodePointer;
};

template <class T>
class List {
public:
    List() {
        head = nullptr;
        size = 0;
    }

    Iterator<T> Begin() {
        Node<T>* temp = head;
        while (temp->prev) {
            temp = temp->prev;
        }
        return temp;
    }

    Iterator<T> End() {
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        return temp;
    }

    Node<T>* GetNodeByValue(T value) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data != value) {
                temp = temp->next;
                continue;
            }
            else {
                return temp;
            }
        }
        throw 2;
    }

    void InsertNode(T l_data) {
        if (!head) {
            head = GetFreeNode(l_data, nullptr);
            size++;
        }
        else {
            Node<T>* iterator = head;
            while (iterator) {
                if (iterator->next) {
                    iterator = iterator->next;
                    continue;
                } /*else if (iterator->data == l_data){
                     throw 1;
                }*/
                else {
                    iterator->next = GetFreeNode(l_data, iterator);
                    size++;
                    return;
                }
            }
        }
    }

    void EraseNodeByValue(T l_value) {
        Node<T>* target = GetNodeByValue(l_value);
        RawEraseNode(target);
    }

    void bubble_sort() {
        Node<T>* ptr;

        for (int i = 0; i < size; i++) {

            Node<T>* elem_1 = head;
            Node<T>* elem_2 = head->next;

            for (int j = 0; j < size - 1; j++) {

                if (elem_1->data > elem_2->data) {

                    if (elem_1->prev) {
                        ptr = elem_1->prev;
                    }
                    else {
                        ptr = nullptr;
                    }

                    if (elem_1 == head) {
                        head = elem_2;
                        head->prev = nullptr;
                    }
                    if (elem_1->prev) {
                        elem_1->prev->next = elem_2;
                    }
                    if (elem_2->next) {
                        elem_2->next->prev = elem_1;
                        elem_1->next = elem_2->next;
                    }
                    else {
                        elem_1->next = nullptr;
                    }

                    elem_1->prev = elem_2;
                    elem_2->next = elem_1;

                    if (ptr) {
                        elem_2->prev = ptr;
                    }

                    ptr = elem_1;
                    elem_1 = elem_2;
                    elem_2 = ptr;

                }
                elem_1 = elem_1->next;
                elem_2 = elem_2->next;
            }
        }
    }

    void print() {
        Iterator<T> it = this->Begin();
        while (true) {
            if (it == this->End()) {
                std::cout << it.GetValue() << "; ";
                break;
            }
            std::cout << it.GetValue() << "; ";
            try {
                it.Next();
            }
            catch (int exIndex) {
                Exception ex(exIndex);
                ex.what();
            }
        }
        std::cout << std::endl;
    }
private:
    Node<T>* head;
    int size;

    void RawEraseNode(Node<T>* target) {
        if (target->prev && target->next) {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
        else if (target->next == nullptr) {
            target->prev->next = nullptr;
        }
        else if (target->prev == nullptr) {
            head->next->prev = nullptr;
            head = head->next;
        }
        delete target;
        size--;
    }

    Node<T>* GetFreeNode(T l_data, Node<T>* iterator) {
        Node<T>* temp = new Node<T>;
        temp->data = l_data;
        temp->next = nullptr;
        temp->prev = iterator;
        return temp;
    }
};

int main() {
    Death_Stranding death_1{ 3,2,10 };
    Death_Stranding death_2{ 1,5,15 };
    Death_Stranding death_3{ 10,15,20 };

    List<Death_Stranding> list;
    list.InsertNode(death_1);
    list.InsertNode(death_2);
    list.InsertNode(death_3);

    Iterator<Death_Stranding> it = list.Begin();
    while (true) {
        if (it == list.End()) {
            std::cout << it.GetValue().getId() << "; ";
            std::cout << it.GetValue().getLevel() << "; ";
            std::cout << it.GetValue().getTime() << "; ";
            std::cout << std::endl;
            break;
        }
        std::cout << it.GetValue().getId() << "; ";
        std::cout << it.GetValue().getLevel() << "; ";
        std::cout << it.GetValue().getTime() << "; ";
        std::cout << std::endl;
        try {
            it.Next();
        }
        catch (int exIndex) {
            Exception ex(exIndex);
            ex.what();
        }
    }
    std::cout << std::endl;


    List<int> list_int;

    list_int.InsertNode(10);
    list_int.InsertNode(5);
    list_int.InsertNode(3);
    list_int.InsertNode(11);

    list_int.bubble_sort();
    list_int.print();

    list_int.EraseNodeByValue(3);
    list_int.print();
    std::cout << std::endl;

    List<double> list_double;

    list_double.InsertNode(10.5);
    list_double.InsertNode(5.2);
    list_double.InsertNode(3.3);
    list_double.InsertNode(11.9);

    list_double.bubble_sort();
    list_double.print();

    list_double.EraseNodeByValue(3.3);
    list_double.print();
    std::cout << std::endl;

    List<char> list_char;

    list_char.InsertNode('g');
    list_char.InsertNode('y');
    list_char.InsertNode('z');
    list_char.InsertNode('a');

    list_char.bubble_sort();
    list_char.print();

    list_char.EraseNodeByValue('z');
    list_char.print();

    return 0;
}
