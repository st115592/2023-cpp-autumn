#include <iostream>
#include <cstdlib>

int main(int, char**)
{
    int n;
    std::cin >> n;
    int* p = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        {
            std::cin >>*(p + i);
        }
    for (int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                std::cout << *(p + i) << " ";
            }
        }

    free(p);
    return 0;
}
