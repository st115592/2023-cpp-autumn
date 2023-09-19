#include <iostream>
#include <cmath>

int main(){
    int a = 0;
    int b = 0;
   std::cin >> a >> b;
   std::cout << (a + b + abs(a - b)) / 2;
    return 0;
}
