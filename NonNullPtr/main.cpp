#include <iostream>
#include "NonNullObserverPtr.h"


int main()
{
	int x = 1;
	int* pX = &x;

	NonNullObserverPtr<int> xWrap(pX);
	*xWrap = 2;
	std::cout << *xWrap;

	int* NULLPTR = nullptr;

	NonNullObserverPtr<int> nullWrap(NULLPTR);

	try
	{
		NonNullObserverPtr<int> qwe(NULLPTR);
	}
	catch (std::invalid_argument& ip)
	{
		std::cout << ip.what();
	}

	return 0;
}