#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
    std::string line;
    long long top[4] = {0, 0, 0, 0};
    long long total = 0;
    while (!std::cin.eof()) {
        std::getline(std::cin, line);
        int val;
        if (std::sscanf(line.c_str(), "%d", &val) == 1) {
            total += val;
        } else {
            top[0]= total;
            std::sort(top, top+4);
            total = 0;
        }
    }
    top[0]= total;
    std::sort(top, top+4);
    long long max = 0;
    for (int i = 1; i < 4; ++i) {
        max += top[i];
    }
    std::printf("top 1: %lld\n", top[3]);
    std::printf("top 3 sum: %lld\n", max);

    return 0;
}