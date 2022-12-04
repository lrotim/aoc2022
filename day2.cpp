#include <cstdio>
#include <cstdlib>

inline int pts(char a) {
    switch (a) {
        case 'X': return 1;
        case 'Y': return 2;
        case 'Z': return 3;
    }
    std::exit(-1);
}

int ptsOutcome(char a, char x) {
    auto st = pts(x);
    if (a == 'A') { // opponet rock
        switch (x) {
            case 'X': return st + 3; // my rock
            case 'Y': return st + 6; // my paper
            case 'Z': return st; // my siz
        }
    } else if (a == 'B') { // opp paper
        switch (x) {
            case 'X': return st; // my rock
            case 'Y': return st + 3; // my paper
            case 'Z': return st + 6; // my siz
        }
    } else if (a == 'C') { // opp siz
        switch (x) {
            case 'X': return st + 6; // my rock
            case 'Y': return st; // my paper
            case 'Z': return st + 3; // my siz
        }
    }
    std::exit(-1);
}

int ptsOutcome2(char a, char x) {
    if (a == 'A') { // opponet rock
        switch (x) {
            case 'X': return pts('Z'); // loose - play siz
            case 'Y': return 3 + pts('X'); // draw - play rock
            case 'Z': return 6 + pts('Y'); // win - play paper
        }
    } else if (a == 'B') { // opp paper
        switch (x) {
            case 'X': return pts('X'); // loose - play rock
            case 'Y': return 3 + pts('Y'); // draw - play paper
            case 'Z': return 6 + pts('Z'); // win - play siz
        }
    } else if (a == 'C') { // opp siz
        switch (x) {
            case 'X': return pts('Y'); // loose - play paper 
            case 'Y': return 3 + pts('Z'); // draw - play siz
            case 'Z': return 6 + pts('X'); // win - play rock
        }
    }
    std::exit(-1);
}

int main() {
    char abc, xyz;
    
    long long tot = 0;
    while (scanf("%c %c\n", &abc, &xyz) == 2) {
        tot += ptsOutcome2(abc, xyz);
    }

    std::printf("%lld\n", tot);
    return 0;
}