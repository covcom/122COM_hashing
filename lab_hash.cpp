#include "hash.h"

#include <iostream>
using namespace std;

int main()
{
	cout << crc32("buckeroo") << endl;
	cout << crc32("plumless") << endl;
	cout << crc32("wibble") << endl;

	return 0;
}
