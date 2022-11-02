#include <iostream>
using namespace std;
int main() {
  int64_t n, m, a;
  cin >> n >> m >> a;
  cout << ((m+a-1)/a)*((n+a-1)/a);
}
