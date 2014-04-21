#pragma one

namespace slib{

	template <class Iterator>
	struct IteratorTraits {
		typedef typename Iterator::IteratorCategory IteratorCategory;
		typedef typename Iterator::ValueType        ValueType;
		typedef typename Iterator::DifferenceType   DifferenceType;
		typedef typename Iterator::Pointer          Pointer;
		typedef typename Iterator::Reference        Reference;
	};

	template <class _Tp>
	struct IteratorTraits<_Tp*> {
		//typedef random_access_iterator_tag iterator_category;
		typedef _Tp                         ValueType;
		typedef ptrdiff_t                   DifferenceType;
		typedef _Tp*                        Pointer;
		typedef _Tp&                        Reference;
	};

	template <class _Tp>
	struct IteratorTraits<const _Tp*> {
		//typedef random_access_iterator_tag iterator_category;
		typedef _Tp                         ValueType;
		typedef ptrdiff_t                   DifferenceType;
		typedef const _Tp*                  Pointer;
		typedef const _Tp&                  Reference;
	};
}