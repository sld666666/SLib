#pragma 
#include "BaseDeque.h"
#include "alloc/DefaultAlloc.h"
#include "TypeDefinition.h"

namespace slib{

	template <typename T, typename Alloc = slib::DefaultAlloc<false, 0>>
	class Deque : public BaseDeque<T, Alloc>
			, public TypeDefinition<T>{

		typedef  BaseDeque<T, Alloc> Base;

	public:
		Deque():Base(){}

	public:
		Iterator begin(){return begin_;}
		Iterator end(){return end_;}
		SizeType size(){return end_-begin_;}
		bool empty(){return end_ == begin_;}

		void push_back(const ValueType& val);
		void push_front(const ValueType& val);
		void pop_back();
		void pop_front();
		

		Iterator insert(Iterator position, const ValueType& value);
		Iterator erase(Iterator position);
		Iterator erase(Iterator first, Iterator last);
		void clear();
	};

	template <typename T, typename Alloc>
	void Deque<T, Alloc>::push_back(const ValueType& val)
	{
		
	}

	template <typename T, typename Alloc>
	typename Deque<T, Alloc>::Iterator 
		Deque<T, Alloc>::insert(Iterator position
								, const ValueType& value)
	{
		if(end_.cur != (end_.last-1)){
			construct(end_.cur, val);
			++end_.cur;
		}else{

		}
	}

}