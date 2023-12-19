#include<iostream>

int n[4] { 0 };
int** d = new int* [4] {nullptr, new int[10], new int[10], new int[10]};

void shift(int from = 1, int to = 3)
{
	std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
	d[to][n[to]++] = d[from][--n[from]];
}

void hanoy(int count, int from = 1, int to = 3)
{
	if (count == 0)
	{
		return;
	}

	int res = 6 - from - to;

	hanoy(count - 1, from, res);
	shift(from, to);
	hanoy(count - 1, res, to);
}

void swap(int& a, int& b)
{
	int k = 0;
	k = a;
	a = b;
	b = k;
}

int top(int a)
{
	if (n[a] > 0)
	{
		return d[a][n[a] - 1];
	}
	else
	{
		return 11;
	}
}

void sort(int from = 1, int to = 3)
{
	int res = 6 - from - to;

	while (n[from] > 0)
	{
		while (top(to) < top(from))
		{
		    int count = 0;

			for (int i = 0; i < n[res]; ++i)
			{
				if (d[res][i] > top(to))
				{
					++count;
				}
			}
			hanoy(n[res] - count, res, to);
			swap(res, to);
		}
		shift(from, to);
	}

	while (n[to] > 0)
	{
		int count = 0;
		for (int i = 0; i < n[res]; ++i)
		{
			if (d[res][i] > top(to))
			{
				count++;
			}
		}
		hanoy(n[res] - count, res, to);
		swap(res, to);
	}
}

int main(int argc, char* argv[])
{
	std::cin >> n[1];
	for (int i = n[1] - 1; i >= 0; --i)
	{
		std::cin >> d[1][i];
	}
	sort();

	return EXIT_SUCCESS;
}
