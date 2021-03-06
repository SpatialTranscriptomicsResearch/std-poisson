#include <algorithm>
#include <random>
#include "aux.hpp"
#include "entropy.hpp"

using namespace std;

string to_lower(string x) {
  transform(begin(x), end(x), begin(x), ::tolower);
  return x;
}

vector<string> form_factor_names(size_t n) {
  vector<string> factor_names;
  for (size_t i = 1; i <= n; ++i)
    factor_names.push_back("Factor " + std::to_string(i));
  return factor_names;
}

vector<size_t> random_order(size_t n) {
  vector<size_t> order(n);
  iota(begin(order), end(order), 0);
  shuffle(begin(order), end(order), EntropySource::rng);
  return order;
}
