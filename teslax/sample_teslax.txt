#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdint>
#include <math.h>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>

#define unsig                    unsigned
#define forIt(i, tmp)            for(auto i = tmp.begin();    i != tmp.end(); ++i)
#define fori(i, mx)              for(int_fast32_t i = 0;        i <= mx;        ++i)
#define forI(i, mn, mx)          for(int_fast32_t i = mn;    i <= mx;        ++i)
#define rall(tmp)                tmp.rbegin(), tmp.rend()
#define max3(n1, n2, n3)         std::max(std::max(n1, n2), n3)
#define min3(n1, n2, n3)         std::min(std::min(n1, n2), n3)
#define max4(n1, n2, n3, n4)     std::max(std::max(n1, n2), std::max(n3, n4))
#define min4(n1, n2, n3, n4)     std::min(std::min(n1, n2), std::min(n3, n4))
#define endl                     "\n"
#define all(tmp)                 tmp.begin(),  tmp.end()
#define sig                      signed
#define int                      int_fast32_t
#define PI                       3.1415926536

typedef int_fast64_t       LL;
typedef long double        LD;

// ╦╔═╗╦═╗╔╗ ╦ ╦╔═╗
// ║╠═╣╠╦╝╠╩╗║ ║╔═╝
//╚╝╩ ╩╩╚═╚═╝╚═╝╚═╝

namespace TeslaX {
    template<class T1>
    T1 abs(T1 n) {
        return (n < 0 ? -n : n);
    }
    template<class T1>
    T1 ceil(T1 n) {
        return (static_cast<int_fast64_t>(n) + (n - static_cast<int_fast64_t>(n) != 0));
    }
    template<class T1>
    T1 floor(T1 n) {
        return static_cast<int_fast64_t>(n);
    }
    template <class T1>
    T1 min(T1 n1, T1 n2) {
        return (n1 > n2 ? n2 : n1);
    }
    template <class T1>
    T1 max(T1 n1, T1 n2) {
        return (n1 < n2 ? n2 : n1);
    }
    void stop(void) {
        std::fflush(stdin); std::cout << "Press button to continue..."; _getch();
    }
    void start(void) {
    
        return;
    }
}
sig main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#ifdef  _DEBUG
    setlocale(LC_ALL, "ru");
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //  _DEBUG
 
    int t; std::cin >> t;

    while (t--) TeslaX::start();
 
    return 0;
}
