#ifndef LOG_SRC
#define LOG_SRC

#include <iostream>
#include <type_traits>
#include <ctime>

namespace log
{
	class _out
	{
	private:
		bool timePrinted;

		inline void print_time()
		{
			if (!timePrinted)
			{
				std::time_t now = std::time(nullptr);
				std::tm *local_time = std::localtime(&now);
				char buffer[20];
				std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
				std::cout << buffer << " ";
			}
		}

		void print_str(const std::string &str)
		{
			print_time();
			if (str == "\n")
			{
				timePrinted = false;
			}
			else
			{
				timePrinted = true;
			}
			std::cout << str;
		}

		void print_str(const char c)
		{
			print_time();
			if (c == '\n')
			{
				timePrinted = false;
			}
			else
			{
				timePrinted = true;
			}
			std::cout << c;
		}

	public:
		_out() : timePrinted(false)
		{
		}

		inline _out &operator<<(const std::string &str)
		{
			print_str(str);
			return *this;
		}

		inline _out &operator<<(const char *c)
		{
			print_str(c);
			return *this;
		}

		inline _out &operator<<(const char c)
		{
			print_str(c);
			return *this;
		}

		template <typename Type>
		_out &operator<<(const Type &val)
		{
			print_time();
			std::cout << val;
			return *this;
		}

	} out;
}

#endif