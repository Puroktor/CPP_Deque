#pragma once
#include "Deque.h"

namespace Colelctions
{
	template <typename T>
	class Node
	{
	private:
		Node(T _value) : value(_value) {};
		T value;
		Node<T>* prev = nullptr;
		Node<T>* next = nullptr;
	public:
		template<class T>
		friend class Deque;
	};
}