#include "../include/utils.hh"

static double getSharpRatio(const vector<double>& values, double rft, int count) {
  size_t n = values.size();
  if (n <= 2) {
    return 0;
  }
  double sum = 0;
  vector<double> rtns;
  for (size_t i = 1; i < n; ++i) {
    double r = (values[i] - values[i - 1]) / values[i - 1];
    sum += r;
    rtns.push_back(r);
  }
  n = rtns.size();

  double mean = sum / n;
  sum = 0;
  for (size_t i = 0; i < n; ++i) {
    sum += (rtns[i] - mean) * (rtns[i] - mean);
  }
  return (mean * count - rft) / sqrt(sum * count / (n - 1));
}

int main(int argc, char** argv) {
  vector<double> values = {100, 101, 102, 100, 101, 102, 103, 102, 103, 104, 101, 102, 103};
  cout << values << ": " << getSharpRatio(values, 0.03, 240) << endl;
  return 0;
}