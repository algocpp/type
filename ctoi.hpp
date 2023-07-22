
// algocpp/type/ctoi.hpp
//
// This file is part of algocpp and is copyrighted by algocpp.
// If used, it must comply with the MIT License.

#ifndef ALGOCPP_TYPE_CTOI
#define ALGOCPP_TYPE_CTOI

#include <algocpp/exception/invaid_str.hpp>

namespace algocpp
{
	namespace type
	{
		inline int ctoi(char c)
		{
			if (c >= '0' && c <= '9')
				return (c - '0');
			else
				throw algocpp::exception::invaid_string("The character must be a one-byte number between 0 and 9.");
		}
	}
}

#endif
