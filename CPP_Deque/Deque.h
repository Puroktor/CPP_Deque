#pragma once
#include "Node.h"
#include <stdexcept>

namespace Colelctions
{
	typedef unsigned int size_t;

	template <class T>
	class Deque
	{
	private:
		Node<T>* head = nullptr;
		Node<T>* tail = nullptr;
		size_t _size = 0;
	public:
		Deque();
		~Deque();
		const T& at(size_t n) const;
		void push_front(const T& val);
		void pop_front();
		const T& front() const;
		void push_back(const T& val);
		void pop_back();
		const T& back() const;
		bool empty() const;
		size_t size() const;
	};

	template <class T>
	Deque<T>::Deque()
	{
	}

	template <class T>
	Deque<T>::~Deque()
	{
		auto curr = head;
		while (curr != nullptr)
		{
			auto next = curr->next;
			delete curr;
			curr = next;
		}
	}

	template <class T>
	const T& Deque<T>::at(size_t n) const
	{
		if (n < 0 || n >= _size) 
		{
			throw std::out_of_range("Index is out of deque size");
		}
		auto curr = head;
		for (auto i = 0; i < n; i++, curr = curr->next);
		return curr->value;
	}

	template <class T>
	void Deque<T>::push_front(const T& val)
	{
		auto node = new Node<T>(val);
		if (head != nullptr)
		{
			node->next = head;
			head->prev = node;
		}
		else
		{
			tail = node;
		}
		head = node;
		_size++;
	}

	template <class T>
	void Deque<T>::pop_front()
	{
		if (head != nullptr)
		{
			auto node = head;
			head = head->next;
			if (_size == 1)
				tail = nullptr;
			else
				head->prev = nullptr;
			_size--;
			delete node;
		}
		else
		{
			throw std::out_of_range("Deque is empty");
		}
	}

	template <class T>
	const T& Deque<T>::front() const
	{
		if (head != nullptr)
			return head->value;	
		else
			throw std::out_of_range("Deque is empty");
	}

	template <class T>
	void Deque<T>::push_back(const T& val)
	{
		auto node = new Node<T>(val);
		if (tail != nullptr)
		{
			tail->next = node;
			node->prev = tail;
		}
		else
		{
			head = node;
		}
		tail = node;
		_size++;
	}

	template <class T>
	void Deque<T>::pop_back()
	{
		if (tail != nullptr)
		{
			auto node = tail;
			tail = tail->prev;
			if (_size == 1)
				head = nullptr;
			else
				tail->next = nullptr;
			_size--;
			delete node;
		}
		else
		{
			throw std::out_of_range("Deque is empty");
		}
	}

	template <class T>
	const T& Deque<T>::back() const
	{
		if (tail != nullptr)		
			return tail->value;
		else		
			throw std::out_of_range("Deque is empty");
	
	}

	template <class T>
	bool Deque<T>::empty() const
	{
		return _size == 0;
	}

	template <class T>
	size_t Deque<T>::size() const
	{
		return _size;
	}
}


