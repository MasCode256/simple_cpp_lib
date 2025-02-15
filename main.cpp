#include "includes/parser.hpp"
#include "includes/log.hpp"

using namespace std;

int main()
{
	try
	{
		log::println("substr =", parser::get_substring_before_delimiter("12345", '_'));
	}
	catch (const std::exception &e)
	{
		log::fatal("Error:", e.what());
	}

	log::println(u8"Программа завершена успешно.");
}