#pragma once
#include "TypeTraits.h"
#include "Construct.h"
#include "../iterator/BaseIterator.h"

namespace slib{

	inline void fill(signed char* first
		, size_t n
		, signed char& c)
	{
		memset(first, static_cast<unsigned char>(c), n);
	}

	template<typename InputIter, typename OutputIter>
	inline OutputIter copy(InputIter first
		, InputIter last
		, OutputIter result)
	{
		for (; first != last; ++result, ++first){
			*result = *first;
		}
		return result;
	}

	template<typename InputIter, typename OutputIter>
	inline void copy_backward(InputIter first
		, InputIter last
		, OutputIter result)
	{
		for (; last != first; --last, --result){
			*result = *last;
		}
	}

	template<typename ForwardIter,typename Size, typename T>
	inline ForwardIter uninitialized_fill_n(ForwardIter first
		, Size n
		, T val
		, TrueType)
	{
		fill(first, n, val); 
		return first + n;
	}

	template<typename ForwardIter,typename Size, typename T>
	inline ForwardIter uninitialized_fill_n(ForwardIter first
		, Size n
		, T val
		, FalseType)
	{
		ForwardIter cur = first;
		for(; n > 0; --n, ++cur){
			construct(&*cur, val);
		}

		return cur;
	}


	template<typename ForwardIter,typename Size, typename T>
	inline ForwardIter uninitialized_fill_n(ForwardIter first
		, Size n
		, T val)
	{
		typedef typename TypeTraits<T>::is_POD_type IsPod;
		uninitialized_fill_n(first, n, val, IsPod());

		return first+n;
	}


	template <typename InputIter, typename ForwordIter>
	inline ForwordIter uninitialiezed_copy_aux(InputIter fisrt
		, InputIter last
		, ForwordIter result
		, FalseType)
	{
		ForwordIter cur = result;
		for (; fisrt != last; ++fisrt, ++cur){
			construct(&*cur, *fisrt);
		}

		return cur;
	}

	template <typename InputIter, typename ForwordIter>
	inline ForwordIter uninitialiezed_copy_aux(InputIter fist
		, InputIter last
		, ForwordIter result
		, TrueType)
	{
		return copy(fist, last, result);
	}


	template <typename InputIter, typename ForwordIter, typename T>
	inline ForwordIter uninitialized_copy(InputIter first
										, InputIter last
										, ForwordIter result
										, T*)
	{
		typedef typename TypeTraits<T>::is_POD_type IsPod;
		return uninitialiezed_copy_aux(first, last, result, IsPod());
	}


	template <typename InputIter, typename ForwordIter>
	inline ForwordIter uninitialized_copy(InputIter first
										, InputIter last
										, ForwordIter result)
	{
		return uninitialized_copy(first, last, result, valueType(result));
	}


}
