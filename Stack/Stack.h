#pragma once
#include"IConteiner.h"

	template<typename T>
	class Stack : IContainer<T>
	{
	private:

		using Node = IContainer<T>::Node;

		T& get(int index)
		{
			Node* temp = this->Head;
			for (size_t i = 0; i < index; i++)
			{
				temp = temp->nextvalue;
			}
			return temp->value;
		}

		//проверка на пустоту СТЕКА
		bool isEmpty() override
		{
			if (!this->size)
			{
				return true;
			}
			return false;
		}
	public:

		//Stack(std::initializer_list<T> list) : IConteiner<T>(list) {}
		Stack() {};
		//добавление элемента в СТЕК
		Node* push(T _value) override
		{
			Node* new_node = new Node(_value);
			new_node->nextvalue = this->Head;
			this->Head = new_node;
			this->size++;
			return new_node;
		}

		//удаление элемента в СТЕКЕ
		void pop() override
		{
			try
			{
				if (isEmpty())
				{
					throw(std::out_of_range("Out of range"));
				}
				this->Head = this->Head->nextvalue;
				this->size--;
			}
			catch (const std::out_of_range e)
			{
				std::cout << e.what() << "   ";
			}
		}

		//взятие верхнего элемента из СТЕКА
		T top() override
		{
			try
			{
				if (isEmpty())
				{
					throw(std::out_of_range("This Stack is Empty"));
				}
				return this->Head->value;
			}
			catch (const std::out_of_range e)
			{
				std::cout << e.what() << "    ";
				//return nullptr;
			}
		}

		////делаем тут свой Свап))
		void swap(size_t index_left, size_t index_right) override
		{
			try
			{
				if (index_right >= this->size || index_left<0 || index_left>this->size || index_right < 0)
				{
					throw(std::out_of_range("OUT OF RANGE"));
				}

				T& left = get(index_left);
				T& right = get(index_right);


				T& temp=get(index_left);
				temp = left;
				left = right;
				right = temp;
				//left ^= right ^= left ^= right;

			}
			catch (const std::out_of_range e)
			{
				std::cout << e.what() << " ";
			}
		}

		

		friend std::ostream& operator<<(std::ostream& tech, Stack& list)
		{
			for (size_t i = 0; i < list.size; i++)
			{
				tech << list.get(i) << " ";
			}
			return tech;
		}
	};

