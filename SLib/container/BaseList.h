#pragma once
#include "../iterator/ListIterator.h"
#include "../alloc/Construct.h"
#include "../alloc/SimpleAlloc.h"

namespace slib{
	

	template <typename T
			, typename Alloc>
	class BaseList{
	public:
		BaseList(){
			node_ = getNode();
			node_->next = node_;
			node_->preview = node_;
		}


	protected:
		typedef SimpleAlloc<ListNode<T>, Alloc>	DataAllocator;
		typedef ListNode<T>	Node;
		
		Node*	getNode(){return DataAllocator::allocate(1);}
		void	putNode(ListNode<T>* node){DataAllocator::deallocate(node);}

		Node*	createNode(const T& value)
		{
			Node* node = getNode();
			construct(&node->data, value);
			return node;
		}

		Node*	createNode()
		{
			Node* node = getNode();
			construct(&node->data);
			return node;
		}

	
	protected:
		ListNode<T>*	node_;
	};
}