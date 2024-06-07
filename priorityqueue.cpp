// Requesting a Ride

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

struct Driver {
    int id;
    double distance;

    Driver(int id, double distance) : id(id), distance(distance) {}

    bool operator>(const Driver& other) const {
        return distance > other.distance;
    }
};

std::priority_queue<Driver, std::vector<Driver>, std::greater<Driver>> availableDrivers;

void addDriver(int id, double distance) {
    availableDrivers.push(Driver(id, distance));
}

int findNearestDriver() {
    if (availableDrivers.empty()) {
        return -1;
    }
    Driver nearestDriver = availableDrivers.top();
    availableDrivers.pop();
    return nearestDriver.id;
}

int main() {
    
    addDriver(1, 5.0);
    addDriver(2, 3.2);
    addDriver(3, 7.1);

    
    int nearestDriverId = findNearestDriver();
    if (nearestDriverId != -1) {
        std::cout << "Nearest driver ID: " << nearestDriverId << std::endl;
    } else {
        std::cout << "No available drivers." << std::endl;
    }

    return 0;
}
