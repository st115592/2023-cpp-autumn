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

void sort(int from = 1, int to = 3)
{
    int res = 6 - from - to;
    shift(from, to);

    while(d[from][n[from] - 1] < d[to][n[to] - 1])
    {
        shift(from, to);
    }

    if(d[from][n[from] - 1] < d[to][n[1]])
    {
        hanoy(n[to] - 1, 3, 2);
    }
    else
    {
        hanoy(n[to], 3, 2);
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
