// Driver Management:

#include <iostream>
#include <map>
#include <string>

enum class Availability { AVAILABLE, BUSY, OFFLINE };

struct Driver {
    std::string name;
    double latitude;
    double longitude;
    Availability availability;

    Driver(const std::string& name, double latitude, double longitude, Availability availability)
        : name(name), latitude(latitude), longitude(longitude), availability(availability) {}
};

class DriverManager {
private:
    std::map<double, Driver*> availableDrivers;

public:
    void addDriver(Driver* driver) {
        if (driver->availability == Availability::AVAILABLE) {
            availableDrivers[driver->latitude] = driver;
        }
    }

    void removeDriver(Driver* driver) {
        if (driver->availability == Availability::AVAILABLE) {
            auto it = availableDrivers.find(driver->latitude);
            if (it != availableDrivers.end() && it->second == driver) {
                availableDrivers.erase(it);
            }
        }
    }

    Driver* findNearestDriver(double userLatitude, double userLongitude) {
        auto it = availableDrivers.lower_bound(userLatitude);
        if (it != availableDrivers.end()) {
            return it->second;
        }
        return nullptr;
    }
};

int main() {
    DriverManager manager;

    Driver driver1("Alice", 37.7749, -122.4194, Availability::AVAILABLE);
    Driver driver2("Bob", 37.7746, -122.4182, Availability::AVAILABLE);
    Driver driver3("Charlie", 37.7741, -122.4161, Availability::BUSY);

    manager.addDriver(&driver1);
    manager.addDriver(&driver2);
    manager.addDriver(&driver3);

    double userLatitude = 37.7748;
    double userLongitude = -122.4187;
    Driver* nearestDriver = manager.findNearestDriver(userLatitude, userLongitude);

    if (nearestDriver != nullptr) {
        std::cout << "Nearest available driver: " << nearestDriver->name << std::endl;
    } else {
        std::cout << "No available drivers nearby." << std::endl;
    }

    return 0;
}
