#include <cstdio>

# define swap(x, y) (x ^= y); (y ^= x); (x ^= y);
void fst() {
    int a,b,c,d;
    long long tot = 0;
    while (std::scanf("%d-%d,%d-%d\n", &a, &b, &c, &d) == 4) {
        int l = a < c ? a : c;
        int u = b > d ? b : d; 
        tot += static_cast<int>(l == a && u == b || l == c && u == d);
    }    
    std::printf("%lld\n", tot);
}

int main() {
    int a,b,c,d;
    long long tot = 0;
    while (std::scanf("%d-%d,%d-%d\n", &a, &b, &c, &d) == 4) {
        if (a > c) {
            swap(a, c);
            swap(b, d);
        }
        tot += static_cast<int>(c <= b);
    }    
    std::printf("%lld\n", tot);
    return 0;
}