#include <iostream>

int main()
{
    int k = 0;
    int m = 0;
    int n = 0;
    int t = 0;
    std::cin >> k;
    std::cin >> m;
    std::cin >> n;
    t = (n / k) * 2 * m;
    if ((n % k > 0) && (k / 2 < n % k)) {
        t += m * 2;
    }
    else if(n % k > 0) {
        t += m;
    }
    if (n <= k){
        t = 2 * m;
    }
    std::cout << t;

    return 0;
}
