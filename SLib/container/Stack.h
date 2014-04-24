#pragma once
#include "List.h"
#include "TypeDefinition.h"

namespace slib{
	template<typename T, typename Sequence = slib::List<T>>
	class Stack : public TypeDefinition<T>{
	public:
		Stack(){}
		~Stack(){}

	public:
		bool		empty();
		ValueType	size();

		void pop();
		void push(const T& value);

		Reference top();

	private:
		Sequence	sequence_;
	};

	template<typename T, typename Sequence>
	bool Stack<T, Sequence>::empty()
	{
		return sequence_.empty();
	}

	template<typename T, typename Sequence>
	typename Stack<T, Sequence>::ValueType Stack<T, Sequence>::size()
	{
		return sequence_.size();
	}

	template<typename T, typename Sequence>
	void Stack<T, Sequence>::pop()
	{
		sequence_.pop_back();
	}

	template<typename T, typename Sequence>
	void Stack<T, Sequence>::push(const T& value)
	{
		sequence_.push_back(value);
	}

	template<typename T, typename Sequence>
	typename Stack<T, Sequence>::Reference Stack<T, Sequence>::top()
	{
		return *(--sequence_.end());
	}
}