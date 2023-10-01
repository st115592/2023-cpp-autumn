#include <iostream>

int main()
{
    int n = 0;
    int a = 1;
    int k = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cout << a << " " ;
        k++;
        if (a == k)
            {
                a++;
                k = 0;
            }
    }
    return 0;
}
