#pragma once
#include "BaseList.h"
#include "TypeDefinition.h"
#include "../alloc/DefaultAlloc.h"

namespace slib{

	template <typename T
		, typename Alloc = slib::DefaultAlloc<false, 0>>
	class List : public BaseList<T, Alloc>
		, public TypeDefinition<T>{
	public:
		typedef BaseList<T, Alloc>	Base;
		typedef ListIterator<T>		Iterator;

		List(): Base(){}
		~List()
		{
			clear();
			Base::putNode(node_);
		}

	public:
		Iterator	begin();
		Iterator	end();

		bool		empty() const;
		SizeType	size();

		Iterator	insert(Iterator position, const T& value);
		void		push_back(const T& value);
		void		push_front(const T& value);
		void		pop_back();
		void		pop_front();
		Iterator	erase(Iterator position);
		Iterator	erase(Iterator first, Iterator last);
		void		clear();
	};

	template<typename T, typename Alloc>
	typename List<T, Alloc>::Iterator List<T, Alloc>::begin()
	{
		return (Node*)node_->next;
	}

	template<typename T, typename Alloc>
	typename List<T, Alloc>::Iterator List<T, Alloc>::end()
	{
		return node_;
	}

	template<typename T, typename Alloc> 
	bool List<T, Alloc>::empty() const 
	{
		return node_->next == node_;
	}

	template<typename T, typename Alloc>
	typename List<T, Alloc>::SizeType List<T, Alloc>::size()  
	{
		SizeType result =  0;
		distance(begin(), end(), result);
		return result;
	}

	template<typename T, typename Alloc>
	typename List<T, Alloc>::Iterator List<T, Alloc>::insert(Iterator position
		, const T& value)
	{
		Node* tmp = Base::createNode(value);
		tmp->next = position.node;
		tmp->preview = position.node->preview;
		position.node->preview->next = tmp;
		position.node->preview = tmp;
		return tmp;
	}

	template<typename T, typename Alloc>
	void List<T, Alloc>::push_back(const T& value)
	{
		insert(end(), value);
	}


	template<typename T, typename Alloc>
	void List<T, Alloc>::push_front(const T& value)
	{
		insert(begin(), value);
	}

	template<typename T, typename Alloc>
	typename List<T, Alloc>::Iterator List<T, Alloc>::erase(Iterator position)
	{
		BaseListNode* nextNode = position.node->next;
		BaseListNode* previewNode = position.node->preview;
		Node* node = (Node*)position.node;
		previewNode->next = nextNode;
		nextNode->preview = previewNode;
		destroy(&node->data);
		putNode(node);

		return Iterator((Node*) nextNode);
	}

	template<typename T, typename Alloc>
	typename List<T, Alloc>::Iterator List<T, Alloc>::erase(Iterator first
															, Iterator last)
	{
		while (first != last){
			Iterator tmp = first;
			++tmp;
			erase(first);
			first = tmp;
		}
		return last;
	}

	template<typename T, typename Alloc>
	void List<T, Alloc>::clear()
	{
		erase(begin(), end());
	}

	template<typename T, typename Alloc>
	void List<T, Alloc>::pop_back()
	{
		erase(--end());
	}

	template<typename T, typename Alloc>
	void List<T, Alloc>::pop_front()
	{
		erase(begin());
	}
}