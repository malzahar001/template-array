#include<iostream>
#include<string>
#include"MyArray.hpp"
using namespace std;
//�Զ�������������в���
class Person {
public:
    Person() {}
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }
    string m_Name;
    int m_Age;
};
//���int��������
void printIntArray(MyArray<int>& p) {
    for (int i = 0; i < p.getSize(); i++)
        cout << p[i] << endl;
}
//���Person��������
void printPersonArray(MyArray<Person>& p) {
    for (int i = 0; i < p.getSize(); i++)
        cout << p[i].m_Name << ' ' << p[i].m_Age << endl;
}


void test() {  //���캯������
    MyArray<int>p1(2);
    MyArray<int>p2(p1);
    MyArray<int>p3;
}

void test2() { //β�巨��βɾ������
    MyArray<int>p1(5);

    for (int i = 0; i < 5; i++)
        p1.Push_Back(i);

    cout << "p1��ӡ���Ϊ" << endl;
    printIntArray(p1);

    cout << "p1������Ϊ" << p1.getCapacity() << endl;
    cout << "p1�Ĵ�СΪ" << p1.getSize() << endl;

    MyArray<int>p2(5);

    for (int i = 0; i < 5; i++)
        p2.Push_Back(i);
    cout << "p2��ӡ���Ϊ" << endl;
    printIntArray(p2);

    for (int i = 0; i < 5; i++)
        p2.Pop_Back();
    cout << "p2βɾ��" << endl;
    printIntArray(p2);

    cout << "p2������Ϊ" << p2.getCapacity() << endl;
    cout << "p2�Ĵ�СΪ" << p2.getSize() << endl;

}
//�Զ�����Ž������в���
void test3() {
    MyArray<Person>p(10);

    Person p1("�����", 999);
    Person p2("����", 30);
    Person p3("槼�", 20);
    Person p4("����", 25);
    Person p5("������", 27);

    //�����ݲ��뵽������
    p.Push_Back(p1);
    p.Push_Back(p2);
    p.Push_Back(p3);
    p.Push_Back(p4);
    p.Push_Back(p5);

    printPersonArray(p);

    cout << "p������Ϊ" << p.getCapacity() << endl;
    cout << "p�Ĵ�СΪ" << p.getSize() << endl;
}
int main() {
    test();
    test2();
    test3();

    system("pause");
    return 0;
}