
// algocpp/type/format.hpp
//
// This file is part of algocpp and is copyrighted by algocpp.
// If used, it must comply with the MIT License.

#ifndef ALGOCPP_TYPE_FORMAT
#define ALGOCPP_TYPE_FORMAT

#include <string>
#include <vector>
#include <utility>
#include <tuple>
#include <set>
#include <locale>
#include <codecvt>
#include <map>

#if __has_include(<boost/multiprecision/cpp_int.hpp>)
#include <boost/multiprecision/cpp_int.hpp>
#endif
namespace algocpp
{
	namespace type
	{
		// Symple Type
		inline std::string format(std::string x)
		{
			return "\"" + x + "\"";
		}

		inline std::string format(int x)
		{
			return std::to_string(x);
		}

		inline std::string format(char x)
		{
			return std::string{'\'', x, '\''};
		}

		inline std::string format(std::u32string x)
		{
			std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf32conv;

			std::string result = utf32conv.to_bytes(x);
			return "\"" + result + "\"";
		}

		inline std::string format(char32_t x)
		{
			std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf32conv;

			std::string result = utf32conv.to_bytes(std::u32string{x});
			return "\'" + result + "\'";
		}

		inline std::string format(long long x)
		{
			return std::to_string(x);
		}

		inline std::string format(bool x)
		{
			return (x ? "true" : "false");
		}

// Boost.Multiprecision
#ifdef BOOST_MP_CPP_INT_HPP
		inline std::string format(boost::multiprecision::int1024_t x)
		{
			return x.str();
		}

		inline std::string format(boost::multiprecision::cpp_int x)
		{
			return x.str();
		}

		inline std::string format(boost::multiprecision::checked_int1024_t x)
		{
			return x.str();
		}

		inline std::string format(boost::multiprecision::checked_cpp_int x)
		{
			return x.str();
		}

		inline std::string format(boost::multiprecision::uint1024_t x)
		{
			return x.str();
		}

		inline std::string format(boost::multiprecision::checked_uint1024_t x)
		{
			return x.str();
		}
#endif

		// Class
		template <typename T>
		inline std::string format(std::vector<T> x)
		{
			std::string result = "[";
			for (int i = 0; i < x.size(); i++)
			{
				result += format(x[i]);
				if (i != x.size() - 1)
					result += ", ";
			}

			return result + "]";
		}

		template <typename T1, typename T2>
		inline std::string format(std::pair<T1, T2> x)
		{
			std::string result = "(" + format(x.first) + ", " + format(x.second) + ")";
			return result;
		}

		template <typename T>
		inline std::string format(std::set<T> x)
		{
			std::string result = "{";
			int i = 1;
			for (auto a : x)
			{
				result += format(a);
				if (i != x.size())
				{
					result += ", ";
				}
				i++;
			}
			return result + "}";
		}

		template <typename T1, typename T2>
		inline std::string format(std::map<T1, T2> x)
		{
			std::string result = "{";
			int i = 1;
			for (auto a : x)
			{
				result += format(a.first) + ":" + format(a.second);
				if (i != x.size())
				{
					result += ", ";
				}
				i++;
			}

			return result + "}";
		}
	}
}

#endif // ALGOCPP_TYPE_FORMAT