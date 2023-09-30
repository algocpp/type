
// algocpp/type/format.hpp
//
// This file is part of algocpp and is copyrighted by algocpp.
// If used, it must comply with the MIT License.

#ifndef ALGOCPP_TYPE_FORMAT
#define ALGOCPP_TYPE_FORMAT

#include <string>
#include <vector>
#include <array>
#include <list>
#include <utility>
#include <tuple>
#include <locale>
#include <codecvt>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algocpp/string/wconvert.hpp>
#include <algocpp/type/format_declaration.hpp>

#if !defined(ALGOCPP_DONT_LIB) && __has_include(<boost/multiprecision/cpp_int.hpp>)
#include <boost/multiprecision/cpp_int.hpp>
#endif

#if !defined(ALGOCPP_DONT_LIB) && __has_include(<boost/array.hpp>)
#include <boost/array.hpp>
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
			std::string result = algocpp::string::utf32conv.to_bytes(x);
			return "\"" + result + "\"";
		}

		inline std::string format(char32_t x)
		{
			std::string result = algocpp::string::utf32conv.to_bytes(std::u32string{x});
			return "\'" + result + "\'";
		}

		inline std::string format(std::u16string x)
		{
			std::string result = algocpp::string::utf16conv.to_bytes(x);
			return "\"" + result + "\"";
		}

		inline std::string format(char16_t x)
		{
			std::string result = algocpp::string::utf16conv.to_bytes(std::u16string{x});
			return "\'" + result + "\'";
		}

		inline std::string format(std::wstring x)
		{
			std::string result = algocpp::string::wstrconv.to_bytes(x);
			return "\"" + result + "\"";
		}

		inline std::string format(wchar_t x)
		{
			std::string result = algocpp::string::wstrconv.to_bytes(std::wstring{x});
			return "\'" + result + "\'";
		}

// C++20
#if __cplusplus >= 202002LL

		inline std::string format(std::u8string x)
		{
			std::string result = std::string(x.begin(), x.end());
			return "\"" + result + "\"";
		}

		inline std::string format(char8_t x)
		{
			std::u8string tmp = {x};
			std::string result = std::string(tmp.begin(), tmp.end());
			return "\'" + result + "\'";
		}

#endif

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
			for (unsigned long long i = 0; i < x.size(); i++)
			{
				result += format(x[i]);
				if (i != x.size() - 1)
					result += ", ";
			}

			return result + "]";
		}

		template <typename T, std::size_t n>
		inline std::string format(std::array<T, n> x)
		{
			std::string result = "[";
			for (unsigned long long i = 0; i < x.size(); i++)
			{
				result += format(x[i]);

				if (i != x.size() - 1)
					result += ", ";
			}

			return result + "]";
		}

		template <typename T>
		inline std::string format(std::list<T> x)
		{
			std::string result = "[";
			unsigned long long i = 0;
			for (auto a : x)
			{
				result += format(a);

				if (i != x.size() - 1)
					result += ", ";
				i++;
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
			unsigned long long i = 1;
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

		template <typename T>
		inline std::string format(std::multiset<T> x)
		{
			std::string result = "{";
			unsigned long long i = 1;
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

		template <typename T>
		inline std::string format(std::unordered_set<T> x)
		{
			std::string result = "{";
			unsigned long long i = 1;
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
			unsigned long long i = 1;
			for (auto a : x)
			{
				result += format(a.first) + ": " + format(a.second);
				if (i != x.size())
				{
					result += ", ";
				}
				i++;
			}

			return result + "}";
		}

		template <typename T1, typename T2>
		inline std::string format(std::unordered_map<T1, T2> x)
		{
			std::string result = "{";
			unsigned long long i = 1;
			for (auto a : x)
			{
				result += format(a.first) + ": " + format(a.second);
				if (i != x.size())
				{
					result += ", ";
				}
				i++;
			}

			return result + "}";
		}

		template <typename T>
		inline std::string format(std::queue<T> x)
		{
			std::string result = "{";
			while (!x.empty())
			{
				result += format(x.front());

				if (x.size() != 1)
					result += ", ";

				x.pop();
			}

			return result + "}";
		}

#ifdef BOOST_ARRAY_HPP

		template <typename T, std::size_t n>
		inline std::string format(boost::array<T, n> x)
		{
			std::string result = "[";
			for (unsigned long long i = 0; i < x.size(); i++)
			{
				result += format(x[i]);

				if (i != x.size() - 1)
					result += ", ";
			}

			return result + "]";
		}

#endif
	}
}

#endif // ALGOCPP_TYPE_FORMAT