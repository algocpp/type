
// algocpp/type/format.hpp
//
// This file is part of algocpp and is copyrighted by algocpp.
// If used, it must comply with the MIT License.

#include <string>
#include <vector>
#include <utility>
#include <set>

#ifndef ALGOCPP_TYPE_FORMAT
#define ALGOCPP_TYPE_FORMAT

namespace algocpp
{
	namespace type
	{
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
					result += ", ";
				i++;
			}
			return result + "}";
		}
	}
}

#endif // ALGOCPP_TYPE_FORMAT
