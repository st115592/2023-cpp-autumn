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

    int c = 0;
    for (int i = 0; i < n; i++)
        {
            if(*(p + i) > 0)
            {
                c += 1;
            }
        }

    std::cout << c;

    free(p);
    return 0;
}
