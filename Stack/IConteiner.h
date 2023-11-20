#pragma once
#include<iostream>
template<typename T>
class IContainer
{
public:
	class Node
	{
	public:
		T value;
		Node* nextvalue;
		Node()
		{

		}
		// Создание нового узла
		Node(T _value, Node* _nextvalue = nullptr)
		{
			this->value = _value;
			this->nextvalue = _nextvalue;
		}
	};
	Node* Head;
	Node* Tail;
	size_t size;

	//конструктов по умолчанию для создания 
	IContainer()
	{
		Head = nullptr;
		Tail = nullptr;
		size = 0;
	}

	//Список инициализации
	IContainer(std::initializer_list<int> array)
	{
		for (auto x = array.begin(); x != array.end(); x++)
		{
			push(x);
		}
	}

	//вертуальный десткруктор
	virtual ~IContainer()
	{
		Node* del;
		for (size_t i = 0; i < size; i++)
		{
			del = this->Head->nextvalue;
			delete this->Head;
			this->Head = del;
		}
	}

	virtual Node* push(T _value) = 0;
	virtual void pop() = 0;
	virtual T top() = 0;
	virtual bool isEmpty() = 0;
	virtual void swap(size_t index_left, size_t index_right)=0;

};

