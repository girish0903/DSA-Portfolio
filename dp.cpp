//Fare Calculation

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

const int MAX_DISTANCE = 100;
const int MAX_TIME = 100;
const double BASE_FARE = 2.0; 
const double TIME_FARE = 0.5; 
const double SURGE_MULTIPLIER = 1.5; 

double calculateFare(int distance, int time, bool surge) {
    return (BASE_FARE * distance + TIME_FARE * time) * (surge ? SURGE_MULTIPLIER : 1.0);
}

double fareDP(int maxDistance, int maxTime, bool surge) {
    std::vector<std::vector<double>> dp(maxDistance + 1, std::vector<double>(maxTime + 1, INT_MAX));
    dp[0][0] = 0.0;

    for (int d = 0; d <= maxDistance; ++d) {
        for (int t = 0; t <= maxTime; ++t) {
            if (d > 0) {
                dp[d][t] = std::min(dp[d][t], dp[d - 1][t] + calculateFare(1, 0, surge));
            }
            if (t > 0) {
                dp[d][t] = std::min(dp[d][t], dp[d][t - 1] + calculateFare(0, 1, surge));
            }
        }
    }

    return dp[maxDistance][maxTime];
}

int main() {
    int distance = 50;
    int time = 30;
    bool surge = true; 

    double minimumFare = fareDP(distance, time, surge);
    std::cout << "Minimum fare for " << distance << " distance units and " << time << " time units with surge pricing "
              << (surge ? "enabled" : "disabled") << " is: " << minimumFare << std::endl;

    return 0;
}
