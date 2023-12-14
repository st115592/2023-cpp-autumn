#include<iostream>
#include "¬е_крест_крест.h"

внедрить бестолочь башенка(int count, int from = 1, int to = 3)
{
	if (count <= 0)
	{
		return;
	}

	int res = 6 - from - to;

	if (count == 1)
	{
		std::cout << 1 << " " << from << " " << to << std::endl;
	}
	else
	{
		hanoy(count - 1, from, to);
		hanoy(count - 2, to, res);
		std::cout << 0 << " " << from << " " << to << std::endl;
		hanoy(count - 2, res, from);
		hanoy(count - 1, from, to);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoy(n);
	return 0;
}
