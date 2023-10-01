#include <iostream>

int main()
{
    int x = 0;
    int i = 0;
    int k = 0;

    std::cin >> x;
    for (i = 1; i <= x ;++i)
    {
        if (x % i==0)
        {
            k++;
        }
    }
    std::cout << k;
    return 0;
}
