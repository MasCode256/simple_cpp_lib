#ifndef PARSER_CPP
#define PARSER_CPP

#include <stdexcept>
#include <exception>
#include <string>

// Функции для обработки строк и работы с кодировками
namespace parser
{
	// Функции, которые не выбрасывают исключений
	namespace unsafe
	{
		// Возвращает подстроку после первого разделителя или пустую строку, если разделитель не найден
		std::string get_substring_after_delimiter(const std::string &str, char delimiter) noexcept
		{
			size_t pos = str.find(delimiter);
			if (pos == std::string::npos)
			{
				return ""; // Возвращаем пустую строку
			}
			return str.substr(pos + 1);
		}

		// Возвращает подстроку после последнего разделителя или пустую строку, если разделитель не найден
		std::string get_substring_after_last_delimiter(const std::string &str, char delimiter) noexcept
		{
			size_t pos = str.find_last_of(delimiter);
			if (pos == std::string::npos)
			{
				return ""; // Возвращаем пустую строку
			}
			return str.substr(pos + 1);
		}

		// Возвращает подстроку, находящуюся перед разделителем, или возвращает всю исходную строку, если разделитель не найден
		std::string get_substring_before_delimiter(const std::string &str, char delimiter) noexcept
		{
			size_t pos = str.find(delimiter);
			if (pos == std::string::npos)
			{
				return str;
			}
			return str.substr(0, pos);
		}
	}

	// Возвращает подстроку после первого разделителя или выбрасывает исключение, если разделитель не найден
	std::string get_substring_after_delimiter(const std::string &str, char delimiter)
	{
		size_t pos = str.find(delimiter);
		if (pos == std::string::npos)
		{
			throw std::runtime_error("delimiter not found"); // Выбрасываем исключение
		}
		return str.substr(pos + 1);
	}

	/**
	 * @brief Возвращает подстроку, находящуюся после последнего разделителя.
	 *
	 * Если разделитель не найден, выбрасывает исключение.
	 *
	 * @param str Исходная строка типа `std::string`, из которой нужно извлечь подстроку.
	 * @param delimiter Символ-разделитель типа `char` (по умолчанию ',').
	 * @throws std::runtime_error - если разделитель не обнаружен.
	 * @example
	 * Пример использования:
	 * <pre>
	 * std::string result = get_substring_before_delimiter("hello_world", '_'); // Вернёт "hello"
	 * </pre>
	 */
	std::string get_substring_after_last_delimiter(const std::string &str, char delimiter)
	{
		size_t pos = str.find_last_of(delimiter);
		if (pos == std::string::npos)
		{
			throw std::runtime_error("delimiter not found"); // Выбрасываем исключение
		}
		return str.substr(pos + 1);
	}

	/**
	 * @brief Возвращает подстроку, находящуюся перед первым разделителем.
	 *
	 * Если разделитель не найден, выбрасывает исключение.
	 *
	 *
	 * Пример использования:
	 * parser::get_substring_before_delimiter("hello_world", '_'); // "hello"
	 *
	 * @param str Исходная строка типа `std::string`, из которой нужно извлечь подстроку.
	 * @param delimiter Символ-разделитель типа `char` (по умолчанию ',').
	 * @throws std::runtime_error - если разделитель не обнаружен.
	 */
	std::string get_substring_before_delimiter(const std::string &str, char delimiter)
	{
		size_t pos = str.find(delimiter);
		if (pos == std::string::npos)
		{
			throw std::runtime_error("delimiter '" + std::string(1, delimiter) + "' not found in \"" + str + "\"");
		}
		return str.substr(0, pos);
	}
}

#endif