#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    char s[20];
    fread(s, 1, 20, stdin);
    printf("%s\n", s);
}

int main() {
    int T = 1;
    // cin >> T;
    // std::ifstream inputFile("./1.txt");
    // std::cin.rdbuf(inputFile.rdbuf());
    // FILE *fp = fopen("./1.txt", "r");
    int fp = open("./1.txt", O_RDWR);
    dup2(fp, STDIN_FILENO);
    // stdin = fp;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (T--) {
        sol();
    }
}