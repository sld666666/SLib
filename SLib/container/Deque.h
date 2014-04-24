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
		~Deque(){
			for (Vector<T*>::Iterator pos = map_.begin(); pos != map_.end(); ++pos){
				T* node = *pos;
				DataAllocator::deallocate(node, dequeBufSize(sizeof(T)));
			}
		}

		Reference operator[](SizeType n)
		{ return begin_[n]; }

	public:
		Iterator begin(){return begin_;}
		Iterator end(){return end_+1;}
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
	private:
		Iterator insertAux(Iterator position, const ValueType& value);
	};

	template <typename T, typename Alloc>
	void Deque<T, Alloc>::push_back(const ValueType& val)
	{
		if(end_.cur == end_.last){
			Base::allocateNodeAtBack();
		}
		construct(end_.cur, val);
		++end_.cur;
	}

	template <typename T, typename Alloc>
	void Deque<T, Alloc>::push_front(const ValueType& val)
	{
		if(begin_.cur == end_.first){
			Base::allocateNodeAtFront();
		}
		
		if(begin_.cur != end_.first)--begin_.cur;
		construct(begin_.cur, val);
	
	}

	template <typename T, typename Alloc>
	typename Deque<T, Alloc>::Iterator 
		Deque<T, Alloc>::insert(Iterator position
								, const ValueType& value)
	{
		if(position.cur == begin_->cur){
			push_front(value);
			return begin_;
		}else if(position.cur == end_->cur){
			push_back(value);
			Iterator tmp = end_;
			--tmp;
			return tmp;
		}else{
			return insertAux(position, value);
		}
	}

	template <typename T, typename Alloc>
	typename Deque<T, Alloc>::Iterator 
		Deque<T, Alloc>::insertAux(Iterator position
								, const ValueType& value)
	{
		if(end_.cur = end_.last){
			Base::allocateNodeAtBack();
		}
		
		++end_.cur;
		copy_backward(position, end_-1, end_);

		construct(position.cur, val);

		return position;
	}

}