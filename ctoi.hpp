
// algocpp/type/ctoi.hpp
//
// This file is part of algocpp and is copyrighted by algocpp.
// If used, it must comply with the MIT License.

#include <assert.h>

#ifndef ALGOCPP_TYPE_CTOI
#define ALGOCPP_TYPE_CTOI

namespace algocpp
{
	namespace type
	{
		inline int ctoi(char c)
		{
			assert(c >= '0' && c <= '9');
			return (c - '0');
		}
	}
}

#endif
