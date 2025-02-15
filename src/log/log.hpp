#ifndef LOG_HPP
#define LOG_HPP

namespace log
{
	template <typename T>
	void print(T arg);

	template <typename T>
	void println(T arg);

	template <typename T, typename... Args>
	void println(T first, Args... args);

	template <typename T, typename... Args>
	void print(T first, Args... args);

	template <typename T, typename... Args>
	void fatal(T first, Args... args);
}

#include "./log.cpp"

#endif