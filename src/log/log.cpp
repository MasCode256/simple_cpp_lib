#ifndef LOG_CPP
#define LOG_CPP

#include <iostream>
#include <cstdlib>
#include <ctime>

// Небольшая библиотека для работы с std::ostream
namespace log
{
	namespace local
	{
		void print_time()
		{
			std::time_t now = time(nullptr);
			std::tm *local_time = localtime(&now);
			char buffer[20];
			std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
			std::cout << buffer << " ";
		}
	}

	template <typename T>
	void print(T arg)
	{
		local::print_time();
		std::cout << arg;
	}

	template <typename T>
	void _print(T arg)
	{
		std::cout << arg;
	}

	template <typename T, typename... Args>
	void _print(T first, Args... args)
	{
		std::cout << first << " ";
		_print(args...);
	}

	template <typename T>
	void println(T arg)
	{
		local::print_time();
		std::cout << arg << std::endl;
	}

	template <typename T, typename... Args>
	void println(T first, Args... args)
	{
		local::print_time();
		std::cout << first << " ";
		_print(args...);
		std::cout << std::endl;
	}

	template <typename T, typename... Args>
	void print(T first, Args... args)
	{
		local::print_time();
		std::cout << first << " ";
		_print(args...);
	}

	template <typename T, typename... Args>
	void fatal(T first, Args... args)
	{
		local::print_time();
		std::cout << first << " ";
		_print(args...);
		exit(-1);
	}
}

#endif
