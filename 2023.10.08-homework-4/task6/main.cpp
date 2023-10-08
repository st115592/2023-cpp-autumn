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
    int p_max = 0;
    for (int i = 0; i < n; ++i)
    {
        if(*(p + i) >= *(p + p_max))
        {
            p_max = i;
        }
    }
    int p_min = 0;
    for (int i = 0; i < n; ++i)
    {
        if(*(p + i) < *(p + p_min))
        {
            p_min = i;
        }
    }
    int k = 0;
    k = *(p + p_max);
    *(p + p_max) = *(p + p_min);
    *(p + p_min) = k;
    for (int i = 0; i < n; ++i)
    {
        std::cout << *(p + i) << " ";
    }

    free(p);
    return 0;
}
