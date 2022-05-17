#include<iostream>
#include<string>
#include"MyArray.hpp"
using namespace std;
//自定义类放入数组中测试
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
//输出int数组数据
void printIntArray(MyArray<int>& p) {
    for (int i = 0; i < p.getSize(); i++)
        cout << p[i] << endl;
}
//输出Person数组数据
void printPersonArray(MyArray<Person>& p) {
    for (int i = 0; i < p.getSize(); i++)
        cout << p[i].m_Name << ' ' << p[i].m_Age << endl;
}


void test() {  //构造函数测试
    MyArray<int>p1(2);
    MyArray<int>p2(p1);
    MyArray<int>p3;
}

void test2() { //尾插法和尾删法测试
    MyArray<int>p1(5);

    for (int i = 0; i < 5; i++)
        p1.Push_Back(i);

    cout << "p1打印输出为" << endl;
    printIntArray(p1);

    cout << "p1的容量为" << p1.getCapacity() << endl;
    cout << "p1的大小为" << p1.getSize() << endl;

    MyArray<int>p2(5);

    for (int i = 0; i < 5; i++)
        p2.Push_Back(i);
    cout << "p2打印输出为" << endl;
    printIntArray(p2);

    for (int i = 0; i < 5; i++)
        p2.Pop_Back();
    cout << "p2尾删后：" << endl;
    printIntArray(p2);

    cout << "p2的容量为" << p2.getCapacity() << endl;
    cout << "p2的大小为" << p2.getSize() << endl;

}
//自定义类放进数组中测试
void test3() {
    MyArray<Person>p(10);

    Person p1("孙悟空", 999);
    Person p2("韩信", 30);
    Person p3("妲己", 20);
    Person p4("赵云", 25);
    Person p5("安其拉", 27);

    //将数据插入到数组中
    p.Push_Back(p1);
    p.Push_Back(p2);
    p.Push_Back(p3);
    p.Push_Back(p4);
    p.Push_Back(p5);

    printPersonArray(p);

    cout << "p的容量为" << p.getCapacity() << endl;
    cout << "p的大小为" << p.getSize() << endl;
}
int main() {
    test();
    test2();
    test3();

    system("pause");
    return 0;
}