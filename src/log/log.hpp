#ifndef LOG_SRC
#define LOG_SRC

#include <type_traits>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

namespace log
{
	namespace local
	{
		void print_time()
		{
			std::time_t now = std::time(nullptr);
			std::tm *local_time = std::localtime(&now);
			char buffer[20];
			std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
			std::cout << buffer << " ";
		}
	}

	/*
	template <typename T>
	void print(T arg)
	{
		cout << arg << endl;
	}

	template <typename T, typename... Args>
	void print(T first, Args... args)
	{
		cout << first << " "; // Печатаем первый аргумент
		print(args...);		  // Рекурсивно вызываем print для остальных аргументов
	}

	template <typename T, typename... Args>
	void println(T first, Args... args)
	{
		cout << first << " "; // Печатаем первый аргумент
		print(args...);		  // Рекурсивно вызываем print для остальных аргументов
		cout << endl;
	}*/

	template <typename T>
	void print(T arg)
	{
		local::print_time();
		cout << arg;
	}

	template <typename T>
	void println(T arg)
	{
		local::print_time();
		cout << arg << endl;
	}

	template <typename T>
	void _print(T arg)
	{
		cout << arg;
	}

	template <typename T>
	void _println(T arg)
	{
		cout << arg << endl;
	}

	template <typename T, typename... Args>
	void print(T first, Args... args)
	{
		local::print_time();
		cout << first << " "; // Печатаем первый аргумент
		_print(args...);	  // Рекурсивно вызываем print для остальных аргументов
	}

	template <typename T, typename... Args>
	void _print(T first, Args... args)
	{
		cout << first << " "; // Печатаем первый аргумент
		_print(args...);	  // Рекурсивно вызываем print для остальных аргументов
	}

	template <typename T, typename... Args>
	void println(T first, Args... args)
	{
		local::print_time();
		cout << first << " "; // Печатаем первый аргумент
		_println(args...);	  // Рекурсивно вызываем print для остальных аргументов
	}
}

#endif
