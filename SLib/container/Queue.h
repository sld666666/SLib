#pragma once

#include "List.h"
#include "TypeDefinition.h"

namespace slib{
	template<typename T, typename Sequence = slib::List<T>>
	class Queue : public TypeDefinition<T>{
	public:
		Queue(){}
		~Queue(){}

	public:
		bool		empty();
		ValueType	size();

		void pop();
		void push(const T& value);

		Reference front();

	private:
		Sequence	sequence_;
	};

	template<typename T, typename Sequence>
	bool Queue<T, Sequence>::empty()
	{
		return sequence_.empty();
	}

	template<typename T, typename Sequence>
	typename Queue<T, Sequence>::ValueType Queue<T, Sequence>::size()
	{
		return sequence_.size();
	}

	template<typename T, typename Sequence>
	void Queue<T, Sequence>::pop()
	{
		sequence_.pop_front();
	}

	template<typename T, typename Sequence>
	void Queue<T, Sequence>::push(const T& value)
	{
		sequence_.push_back(value);
	}

	template<typename T, typename Sequence>
	typename Queue<T, Sequence>::Reference Queue<T, Sequence>::front()
	{
		return *(sequence_.begin());
	}
}