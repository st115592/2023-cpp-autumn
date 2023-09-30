#include <iostream>
#include <cmath>

int main()
{
    int x = 0;
    int i = 0;
    int k = 0;

    std::cin >> x;
    for (i = 1; i <= sqrt(x) ;++i)
    {
        if (x % i==0)
        {
            k += 2;
        }
    }
    if (double(sqrt(x)) == int(sqrt(x)))
        {
            std::cout << k -1;
        }
    else
        {
            std::cout << k;
        }

    return 0;
}
