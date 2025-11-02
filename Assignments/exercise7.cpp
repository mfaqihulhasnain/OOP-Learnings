#include <iostream>
using namespace std;

class Angle {
private:
    int degrees;
    float minutes;
    char direction;   

public:
    Angle() : degrees(0), minutes(0.0), direction('E') {}  // default constructor

    void getAngle() {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N/S/E/W): ";
        cin >> direction;
    }

    void displayAngle() const {
        cout << degrees << "° " << minutes << "' " << direction;
    }
};

int main() {
    Angle latitude, longitude;

    cout << "Enter Latitude:\n";
    latitude.getAngle();

    cout << "\nEnter Longitude:\n";
    longitude.getAngle();

    cout << "\n--- Location ---\n";
    cout << "Latitude: ";
    latitude.displayAngle();
    cout << "\nLongitude: ";
    longitude.displayAngle();
    cout << endl;

    return 0;
}
