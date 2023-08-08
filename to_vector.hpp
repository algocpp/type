
// algocpp/type/to_vector.hpp
//
// This file is part of algocpp and is copyrighted by algocpp.
// If used, it must comply with the MIT License.

#ifndef ALGOCPP_TYPE_TO_VECTOR
#define ALGOCPP_TYPE_TO_VECTOR

#include <vector>
#include <array>
#include <list>

namespace algocpp
{
	namespace type
	{
		template <typename T, std::size_t n>
		inline std::vector<T> to_vector(std::array<T, n> v)
		{
			std::vector<T> result(v.size());
			for (unsigned long long i = 0; i < v.size(); i++)
			{
				result[i] = v[i];
			}

			return result;
		}

		template <typename T>
		inline std::vector<T> to_vector(std::list<T> v)
		{
			std::vector<T> result(v.size());
			unsigned long long i = 0;
			for (T x : v)
			{
				result[i] = x;
				i++;
			}

			return result;
		}
	}
}

#endif // ALGOCPP_TYPE_TO_VECTOR
