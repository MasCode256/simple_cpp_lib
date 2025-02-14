#include "includes/log.hpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "65001");
	log::out << u8"Привет, мир! Размер out: " << sizeof(log::out) << "\n";
	log::out << u8"Всё работает!";
}