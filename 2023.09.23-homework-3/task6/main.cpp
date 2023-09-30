#include <iostream>

int main()
{
    int n = 0;
    int f1 = 0;
    int f2 = 1;
    int f = 0;
    int i = 1;
    std::cin >> n;
    while(i < n)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        i++;
    }
    if(n == 1)
    {
        f = 1;
    }
    std::cout << f;

    return 0;
}
