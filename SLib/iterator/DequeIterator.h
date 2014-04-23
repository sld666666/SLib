#pragma  once

namespace slib{

	inline size_t dequeBufSize(size_t size){
		return (size < 512)?size_t(512 / size):size_t(1);
	}

	template<typename T>
	struct DequeIterator
	{
		typedef DequeIterator<T>	Iterator;
		typedef T					ValueType;
		typedef T*					Pointer;
		typedef T&					Reference;
		typedef size_t				SizeType;
		typedef T**					MapPointer;
		typedef Iterator			Self;
		
		Pointer		cur;
		Pointer		first;
		Pointer		last;
		MapPointer	node;

		DequeIterator():cur(0), first(0), last(0), node(0){}
		DequeIterator(T* value, MapPointer map)
			: cur (value)
			, first (*map)
			, last (*map+bufferSize())
			, node (map)
		{}

		DequeIterator(const Iterator& iter)
			: cur(iter.cur)
			, first(iter.first)
			, last(iter.last)
			, node(iter.node)
		{

		}

		static size_t bufferSize(){return dequeBufSize(sizeof(T));}

		Reference operator*() const {return *cur;}
		Pointer operator->() const {return cur;}
		Self& operator+=(size_t n)
		{
			this->advance(n);
			return *this;
		}
		Self operator+(size_t n) const 
		{
			Self tmp = *this;
			return tmp += n;
		}
		Self& operator++()
		{
			++cur;
			if( cur == last){
				setNode(node + 1);
				cur = first;
			}

			return *this;
		}
		Self& operator--()
		{
			if(cur == first){
				setNode(node -1);
				cur = last;
			}

			--cur;
			return *this;
		}
		
		Reference operator[](size_t n) const {return *(*this + n);}

		void setNode(MapPointer newNode)
		{
			node = newNode;
			first = *newNode;
			last = first + bufferSize();
		}

		void advance(size_t n)
		{
			const size_t bufferSize = bufferSize();
			cur += n;
		}
	};
}