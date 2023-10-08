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
        if(*(p + i) > *(p + p_max))
        {
            p_max = i;
        }
    }
    std::cout << *(p + p_max) << " ";

    free(p);
    return 0;
}
