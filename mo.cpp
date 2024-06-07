// Trip History

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct Trip {
    int startLocation;
    int endLocation;

    Trip(int start, int end) : startLocation(start), endLocation(end) {}
};

struct Query {
    int left;
    int right;
    int result;

    Query(int l, int r) : left(l), right(r), result(0) {}
};

class TripAnalyzer {
private:
    std::vector<Trip> trips;
    std::vector<Query> queries;
    std::vector<int> frequency;
    int blockSize;

    void processQuery(const Query& query) {
    std::unordered_map<int, int> count;
    int maxCount = 0;
    int mostFrequentRoute = -1;

    for (int i = query.left; i <= query.right; ++i) {
        int route = trips[i].startLocation * 1000 + trips[i].endLocation; 
        count[route]++;
        if (count[route] > maxCount) {
            maxCount = count[route];
            mostFrequentRoute = route;
        }
    }

    queries[query.right].result = mostFrequentRoute;
    std::cout << "Result of query " << query.left << " " << query.right << ": " << mostFrequentRoute << std::endl;
}


public:
    TripAnalyzer(const std::vector<Trip>& tripData, const std::vector<Query>& queryData) : trips(tripData), queries(queryData) {
        int n = trips.size();
        blockSize = static_cast<int>(sqrt(n));
        std::cout << "Block size: " << blockSize << std::endl;

        frequency.resize(1000000); 

        std::sort(queries.begin(), queries.end(), [this](const Query& q1, const Query& q2) {
            int block1 = q1.left / blockSize;
            int block2 = q2.left / blockSize;
            if (block1 != block2) {
                return block1 < block2;
            }
            return q1.right < q2.right;
        });

        int currentLeft = 0;
        int currentRight = -1;

        for (const auto& query : queries) {
            std::cout << "Processing query: " << query.left << " " << query.right << std::endl;
            int left = query.left;
            int right = query.right;

            while (currentRight < right) {
                currentRight++;
                frequency[trips[currentRight].startLocation]++;
                frequency[trips[currentRight].endLocation]++;
            }
            while (currentRight > right) {
                frequency[trips[currentRight].startLocation]--;
                frequency[trips[currentRight].endLocation]--;
                currentRight--;
            }
            while (currentLeft < left) {
                frequency[trips[currentLeft].startLocation]--;
                frequency[trips[currentLeft].endLocation]--;
                currentLeft++;
            }
            while (currentLeft > left) {
                currentLeft--;
                frequency[trips[currentLeft].startLocation]++;
                frequency[trips[currentLeft].endLocation]++;
            }

            processQuery(query);
        }
    }

    std::vector<int> getResult() {
        std::vector<int> results;
        for (const auto& query : queries) {
            results.push_back(query.result);
        }
        return results;
    }
};

int main() {
    std::vector<Trip> tripData = {{1, 2}, {2, 3}, {1, 2}, {3, 4}, {2, 3}};
    std::vector<Query> queryData = {{0, 2}, {1, 4}};

    TripAnalyzer analyzer(tripData, queryData);
    std::vector<int> frequentRoutes = analyzer.getResult();

    std::cout << "Most frequent routes for each query:" << std::endl;
    for (int i = 0; i < queryData.size(); ++i) {
        int route = frequentRoutes[i];
        int startLocation = route / 1000;
        int endLocation = route % 1000;
        std::cout << "Start: " << startLocation << ", End: " << endLocation << std::endl;
    }

    return 0;
}
