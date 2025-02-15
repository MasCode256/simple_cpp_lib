#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

namespace parser
{
	namespace unsafe
	{
		std::string get_substring_after_delimiter(const std::string &str, char delimiter = ',') noexcept;
		std::string get_substring_after_last_delimiter(const std::string &str, char delimiter = ',') noexcept;
	}

	std::string get_substring_after_delimiter(const std::string &str, char delimiter = ',');
	std::string get_substring_after_last_delimiter(const std::string &str, char delimiter = ',');
}

#include "./parser.cpp"

#endif