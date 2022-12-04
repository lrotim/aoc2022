#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

static const int MAX_CHARS = 1024;

inline int score(char a) {
    return a >= 'a' ? static_cast<int>(a - 'a') + 1 : static_cast<int>(a - 'A') + 27;
}

void fst() {
    char line[MAX_CHARS];
    long long tot = 0;
    char lookup[128];
    while(std::scanf("%s\n", line) == 1) {
        std::memset(lookup, 0, 128);
        auto len = std::strlen(line);
        auto mid = len / 2;
        for (int i = 0; i < mid; ++i) {
            lookup[line[i]] = 1;
        }
        for (int i = mid; i < len; ++i) {
            if (lookup[line[i]] == 1) {
                tot += score(line[i]);
                break;
            }
        }
    }

    std::printf("%lld\n", tot);
}

void snd() {
    char line[MAX_CHARS];
    long long tot = 0;
    char lookup[128];
    std::memset(lookup + static_cast<int>('A'), 0, static_cast<int>('z') + 1);
    int gc = 4;
    while(std::scanf("%s\n", line) == 1) {
        auto len = std::strlen(line);
        for (int i = 0; i < len; ++i) {
            lookup[line[i]] |= gc;
        }
        gc = gc >> 1;
        if (gc == 0) {
            gc = 4;
            for (int i = 'A'; i <= 'z'; ++i) {
                if (lookup[i] == 7) {
                    tot += score(i);
                    break;
                }
            }
            std::memset(lookup + static_cast<int>('A'), 0, static_cast<int>('z') + 1);
        } 
    }
    std::printf("%lld\n", tot);    
}

int main() {
    snd();
    return 0;
}