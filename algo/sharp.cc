#include "../include/utils.hh"

class SharpRatio {
public:
  SharpRatio(double rfRtn, int days) : mRiskFreeRtn(rfRtn), mTradingDays(days) {}

  double get(const vector<double>& values) const { return calc(values, mRiskFreeRtn, mTradingDays); }

private:
  static double calc(const vector<double>& values, double rft, int count) {
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

private:
  double mRiskFreeRtn;
  size_t mTradingDays; // for daily sharp ratio.
};

int main(int argc, char** argv) {
  SharpRatio sharp(0.03, 240);
  vector<double> values = {100, 101, 102, 100, 101, 102, 103, 102, 103, 104, 101, 102, 103};
  cout << values << ": " << sharp.get(values) << endl;
  return 0;
}
