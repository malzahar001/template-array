#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray {
private:
	T* m_Address;//����ĵ�һ����ַ��ָ��
	int m_Capacity;//��������
	int m_Size;//���鵱ǰԪ�ظ���
public:
	//���캯��
	MyArray() {
		m_Capacity = 0;
		m_Size = 0;
		m_Address = NULL;
		cout << "�޲ι������" << endl;
	}
	//���캯����������MyArray<T>p1(10);
	MyArray(int capacity) {
		m_Capacity = capacity;
		m_Size = 0;
		m_Address = new T[m_Capacity];
		cout << "�вι������" << endl;
	}

	//����
	~MyArray() {
		if (m_Address != NULL)
			delete[] m_Address; //�ͷ�����ָ��
		cout << "��������" << endl;
	}

	//��������MyArray<T>p1(p2);
	MyArray(const MyArray& arr) {
		this->m_Size = arr.m_Size;
		this->m_Capacity = arr.m_Capacity;
		//ָ�벻��ֱ�Ӹ�ֵ���������
		//this->m_Address = arr.m_Address;
		this->m_Address = new T[arr.m_Capacity];
		//�����е�ֵ����
		for (int i = 0; i < this->m_Size; i++)
			this->m_Address[i] = arr.m_Address[i];
		cout << "�����������" << endl;
	}

	//operator=���ط�ֹǳ�������� MyArray<T>p1=p2;
	MyArray& operator=(const MyArray& arr) {
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if (this->m_Address != NULL) {
			delete[] this->m_Address;
			this->m_Address = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Address = new T[arr.m_Capacity];
		//�����е�ֵ����
		for (int i = 0; i < this->m_Size; i++)
			this->m_Address[i] = arr.m_Address[i];
		return *this;
		cout << "=������" << endl;
	}

	//�����±귽ʽ����������Ԫ�� p[10]
	T& operator[](int index) {
		return m_Address[index];
	}


	//β�巨
	void Push_Back(const T& val) {
		//�ж�������С��������
		if (m_Size == m_Capacity) {
			return;
		}
		m_Address[m_Size] = val;//������ĩβ��������
		m_Size++;//���������С
	}
	//βɾ��
	void Pop_Back() {
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if (m_Size == 0) {
			return;
		}
		//����Ҫ�ͷŸ�Ԫ�ص��ڴ�ռ䣬delete m_Adress[m_Size];��Ϊ�������Ŀռ�����new�ڶ��д�����
		// ��Ԫ��ֵֻ�Ƕ��й̶���ַ�ڴ�Ŀɱ�ֵ�����������б�ɾ��Ԫ�ص�λ�õ�ָ�뻹��ָ�����ԭ�����ڴ�ĵ�ַ��ֻ���ڴ��е���ֵ���ˡ�
		//����������Ĵ�С�ǹ̶��ģ��������Ԫ�ض��Ǳ�new�����ģ���ɾ��ʱ��Ҫdelete�ͷţ���ΪԪ�ر��滻ʱ������������ʱ���Ǹ��ڴ�û�б��ͷţ���
		//���Ӿ���ְ������ϵͳ��Address[i]=new worker*(a,b,c);

		m_Size--;//���������С
	}
	//��ȡ��������
	int getCapacity() {
		return this->m_Capacity;
	}
	//��ȡ�����С
	int getSize() {
		return this->m_Size;
	}
};