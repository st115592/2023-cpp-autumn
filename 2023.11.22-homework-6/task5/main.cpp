#include<iostream>

void hanoi(int n, int from, int to)
{
	if (n > 0)
	{
		int res = 6 - from - to;
		hanoi(n - 1, from, res);
		std::cout<< n << " " << from << " " << to << std::endl;
		hanoi(n - 1, res, to);
	}
}
int main()
{
	int n = 0;
	std::cin >> n;

	if (n >= 2)
    {
        if (n % 2 == 0)
        {
            hanoi(n, 1, 3);
            --n;
        }
		else
		{
			hanoi(n, 1, 2);
			--n;
			hanoi(n, 2, 3);
			--n;
		}
		while (n > 0)
		{
			hanoi(n, n % 2 + 2, (n + 1) % 2 + 2);
			--n;
		}
    }
	else if (n == 1)
	{
		hanoi(n, 1, 2);
	}
	return EXIT_SUCCESS;
}
