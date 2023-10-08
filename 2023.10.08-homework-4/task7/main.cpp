#include <iostream>
#include <cstdlib>

int main(int, char**)
{
    int n;
    std::cin >> n;
    int* p = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >>*(p + i);
    }
    for (int i = 0; i < n; ++i)
    {
        if (*(p + i) <= 0)
        {
            for (int j = i; j < n - 1; ++j)
            {
                *(p + j) = *(p + 1 + j);
            }
            --n;
            --i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        std::cout << *(p + i) << " ";
    }

    free(p);
    return 0;
}
