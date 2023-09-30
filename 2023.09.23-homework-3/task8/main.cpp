#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    int n = 0;
    int m = 0;
    int nod = 0;
    char a_name = 'A';
    char b_name = 'B';
    std::cin >> a;
    std::cin >> b;
    std::cin >> n;
    int av = a;
    int bv = b;
    if (a > b)
    {
        nod = a;
        a = b;
        b = nod;
        a_name = 'B';
        b_name = 'A';
    }
    if (n == b)
    {
        std::cout << ">" << b_name << std::endl;
        return 0;
    }
    while (bv != 0)
    {
        nod = av % bv;
        av = bv;
        bv = nod;
    }
    if ((n % av != 0) || ((n > a) && (n > b)))
    {
        std::cout << "Impossible";
    }
    else
    {
        while (1)
        {
            m += a;
            std::cout << ">" << a_name << std::endl;
            std::cout << a_name << ">" << b_name << std::endl;
            if (m >= b)
            {
                std::cout << b_name << ">" << std::endl;
                std::cout << a_name << ">" << b_name << std::endl;
                m %= b;
            }
            if ((m == n) || (m == 0))
            {
                break;
            }
        }
    }
    return 0;
}
