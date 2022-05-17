#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray {
private:
	T* m_Address;//数组的第一个地址的指针
	int m_Capacity;//数组容量
	int m_Size;//数组当前元素个数
public:
	//构造函数
	MyArray() {
		m_Capacity = 0;
		m_Size = 0;
		m_Address = NULL;
		cout << "无参构造调用" << endl;
	}
	//构造函数（容量）MyArray<T>p1(10);
	MyArray(int capacity) {
		m_Capacity = capacity;
		m_Size = 0;
		m_Address = new T[m_Capacity];
		cout << "有参构造调用" << endl;
	}

	//析构
	~MyArray() {
		if (m_Address != NULL)
			delete[] m_Address; //释放数组指针
		cout << "析构调用" << endl;
	}

	//拷贝构造MyArray<T>p1(p2);
	MyArray(const MyArray& arr) {
		this->m_Size = arr.m_Size;
		this->m_Capacity = arr.m_Capacity;
		//指针不能直接赋值，必须深拷贝
		//this->m_Address = arr.m_Address;
		this->m_Address = new T[arr.m_Capacity];
		//数组中的值拷贝
		for (int i = 0; i < this->m_Size; i++)
			this->m_Address[i] = arr.m_Address[i];
		cout << "拷贝构造调用" << endl;
	}

	//operator=重载防止浅拷贝问题 MyArray<T>p1=p2;
	MyArray& operator=(const MyArray& arr) {
		//先判断原来堆区是否有数据，如果有先释放
		if (this->m_Address != NULL) {
			delete[] this->m_Address;
			this->m_Address = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Address = new T[arr.m_Capacity];
		//数组中的值拷贝
		for (int i = 0; i < this->m_Size; i++)
			this->m_Address[i] = arr.m_Address[i];
		return *this;
		cout << "=号重载" << endl;
	}

	//利用下标方式访问数组中元素 p[10]
	T& operator[](int index) {
		return m_Address[index];
	}


	//尾插法
	void Push_Back(const T& val) {
		//判断容量大小超出容量
		if (m_Size == m_Capacity) {
			return;
		}
		m_Address[m_Size] = val;//在数组末尾插入数据
		m_Size++;//更新数组大小
	}
	//尾删法
	void Pop_Back() {
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (m_Size == 0) {
			return;
		}
		//不需要释放该元素的内存空间，delete m_Adress[m_Size];因为这个数组的空间是由new在堆中创建，
		// 而元素值只是堆中固定地址内存的可变值，所以数组中被删除元素的位置的指针还是指向堆中原来的内存的地址，只是内存中的数值变了。
		//如果这个数组的大小是固定的，但里面的元素都是被new出来的，则删除时需要delete释放，因为元素被替换时或留在数组内时，那个内存没有被释放，。
		//例子就是职工管理系统：Address[i]=new worker*(a,b,c);

		m_Size--;//更新数组大小
	}
	//获取数组容量
	int getCapacity() {
		return this->m_Capacity;
	}
	//获取数组大小
	int getSize() {
		return this->m_Size;
	}
};