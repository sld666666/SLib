#pragma once

#include "BaseIterator.h"

namespace slib{
	struct BaseListNode{
		BaseListNode* next;
		BaseListNode* preview;
	};

	template<typename T>
	struct ListNode : public BaseListNode{
		T data;
	};


	struct BaseListIterator {
		BaseListIterator(){}
		BaseListIterator(BaseListNode* _node): node(_node){}
		BaseListNode*	node;

		void incr(){ node = node->next;}
		void decr(){ node = node->preview;}

		bool operator==(const BaseListIterator& value) const{
			return node == value.node;
		}

		bool operator!=(const BaseListIterator& value) const{
			return node != value.node;
		}
	};

	template< typename T>
	struct ListIterator : public BaseListIterator{

		typedef ListIterator<T>		Iterator;
		typedef ListIterator<T>		Self;

		typedef T	ValueType;
		typedef T*	Pointer;
		typedef T&	reference;
		typedef ListNode<T>	Node;

		ListIterator(){}
		ListIterator(Node* node) : BaseListIterator(node){}
		ListIterator(const Iterator& iter): BaseListIterator(iter.node){}

		reference operator*() const {return ((Node*) node)->data;}
		Pointer	operator->() const {return &(operator*());}

		Self& operator++(){
			BaseListIterator::incr();
			return *this;
		}

		Self& operator--(){
			BaseListIterator::decr();
			return *this;
		}
	};
}