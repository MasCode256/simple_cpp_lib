#include <iostream>
#include <string>

#include "includes/log.hpp"

using namespace std;
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

int main()
{
	log::println(u8"Привет,", u8"мир!");
	log::print(u8"Всё работает!");
	return 0;
}
