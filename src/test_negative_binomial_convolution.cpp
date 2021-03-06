#include <iostream>
#include "pdist.hpp"

using namespace std;

int main(int argc, char **argv) {
  init_logging("foo.txt");

  size_t N = 1000;

  size_t K = 20;

  size_t n = 50;
  vector<double> shapes(n, 1);
  vector<double> scales(n, 0.5);
  verbosity=Verbosity::warning;
  for(size_t t = 0; t < N; ++t) {
    double x = t;
    double foo = convolved_negative_binomial(x, K, shapes, scales);
    cout << x << "\t" << foo << endl;
  }
}
