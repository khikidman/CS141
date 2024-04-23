#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double pi = 3.14;

double normal(double x, double mean = 0.0, double std = 1.0) {
    double part1 = 1.0 / (std * (sqrt(2 * pi)));
    double part2 = -pow((x - mean), 2) / (2.0 * pow(std, 2));
    double normal = part1 * exp(part2);
    return normal;
}

double log_normal(double x, double mean = 0.0, double std = 1.0) {
	return log(normal(x, mean, std));
}

double log_normal_better(double x, double mean = 0.0, double std = 1.0) {
    double part1 = -pow((x - mean), 2) / (2.0 * pow(std, 2));
    double part2 = (1.0 / 2.0) * log(2.0 * pi * std);
    double log_normal = part1 - part2;
    return log_normal;
}

bool is_equal(double x, double y, double esp = 0.001) {
    double difference = x - y;
    if (fabs(difference) < esp) {
        return true;
    } else {
        return false;
    }
}

int main() {

    for (int i = 0; i < 4000; i++){
        double x = i / 100.0;
        cout << fixed << setprecision(8) << x << " "<< log_normal(x) << " " << log_normal_better(x) << endl;
        if (!is_equal(log_normal(x), log_normal_better(x))) {
            break;
        }
    }

    cout << normal(2.0) << endl;
    cout << normal(0.0) << endl;
    cout << normal(1.0, 2.0, 2.0) << endl;

    cout << normal(30.0) << endl;
    cout << normal(40.0) << endl;

    cout << log_normal(1.0) << " " << log_normal_better(1.0) << endl;
    cout << log_normal(40.0) << " " << log_normal_better(40.0) << endl;


    return 0;
}