#pragma  once

template <typename T>
class TypeDefinition{
public:
	typedef T					ValueType;
	typedef ValueType*			Pointer;
	typedef const ValueType*	ConstPointer;
	typedef ValueType*			Iterator;
	typedef const ValueType*	ConstIterator;
	typedef ValueType&			Reference;
	typedef const ValueType&	ConstReference;
	typedef size_t				SizeType;
};