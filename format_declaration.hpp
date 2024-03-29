
// algocpp/type/format_declaration.hpp
//
// This file is part of algocpp and is copyrighted by algocpp.
// If used, it must comply with the MIT License.

#ifndef ALGOCPP_TYPE_FORMAT_DECLARATION
#define ALGOCPP_TYPE_FORMAT_DECLARATION

#include <string>
#include <vector>
#include <array>
#include <list>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>

#if !defined(ALGOCPP_DONT_LIB) && __has_include(<boost/array.hpp>)
#include <boost/array.hpp>
#endif

namespace algocpp
{
	namespace type
	{
		template <typename T>
		inline std::string format(std::vector<T> x);

		template <typename T>
		inline std::string format(std::list<T> x);

		template <typename T, std::size_t n>
		inline std::string format(std::array<T, n> x);

		template <typename T1, typename T2>
		inline std::string format(std::pair<T1, T2> x);

		template <typename T>
		inline std::string format(std::set<T> x);

		template <typename T>
		inline std::string format(std::multiset<T> x);

		template <typename T>
		inline std::string format(std::unordered_set<T> x);

		template <typename T1, typename T2>
		inline std::string format(std::map<T1, T2> x);

		template <typename T1, typename T2>
		inline std::string format(std::unordered_map<T1, T2> x);

		template <typename T>
		inline std::string format(std::queue<T> x);

// Boost.Array
#ifdef BOOST_ARRAY_HPP

		template <typename T, std::size_t n>
		inline std::string format(boost::array<T, n> x);

#endif
	}
}

#endif // ALGOCPP_TYPE_FORMAT_DECLARATION
