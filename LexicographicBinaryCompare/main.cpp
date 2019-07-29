#include <iostream>
#include "LexicographicBinaryCompare.h"

using namespace std;

int main()
{
	std::cout << "Testing...\n";

	const char* p1 = "hello";
	const char* p2 = "hello world";

	int v = LexicographicBinaryCompare32(p1, (int)strlen(p1), p2, (int)strlen(p2));
	if (v < 0)
		cout << "Test 1 ok.\n";
	else
		cout << "Test 1 failed.\n";

	p1 = "a hello";
	p2 = "hello";

	v = LexicographicBinaryCompare32(p1, (int)strlen(p1), p2, (int)strlen(p2));
	if (v < 0)
		cout << "Test 2 ok.\n";
	else
		cout << "Test 2 failed.\n";

	p1 = "abc123";
	p2 = "abc133";

	v = LexicographicBinaryCompare32(p1, (int)strlen(p1), p2, (int)strlen(p2));
	if (v < 0)
		cout << "Test 3 ok.\n";
	else
		cout << "Test 3 failed.\n";

	p1 = "abc123 ";
	p2 = "abc133";

	v = LexicographicBinaryCompare32(p1, (int)strlen(p1), p2, (int)strlen(p2));
	if (v < 0)
		cout << "Test 4 ok.\n";
	else
		cout << "Test 4 failed.\n";

	p1 = "abc123";
	p2 = "abc123 ";

	v = LexicographicBinaryCompare32(p1, (int)strlen(p1), p2, (int)strlen(p2));
	if (v < 0)
		cout << "Test 5 ok.\n";
	else
		cout << "Test 5 failed.\n";

	p1 = "abc123";
	p2 = "abc123";

	v = LexicographicBinaryCompare32(p1, (int)strlen(p1), p2, (int)strlen(p2));
	if (v == 0)
		cout << "Test 6 ok.\n";
	else
		cout << "Test 6 failed.\n";

	std::cout << "Finished.\n";
}
