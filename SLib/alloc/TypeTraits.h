#pragma once

struct TrueType{};
struct FalseType{};

template<typename T>
struct TypeTraits{
	typedef FalseType	is_POD_type;
};

template<typename T>
struct TypeTraits<T*>{
	typedef TrueType	is_POD_type;
};


template<>
struct TypeTraits<bool>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<char>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<signed char>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<unsigned char>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<wchar_t>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<short>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<unsigned short>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<int>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<unsigned int>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<long>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<float>{
	typedef TrueType	is_POD_type;
};

template<>
struct TypeTraits<double>{
	typedef TrueType	is_POD_type;
};