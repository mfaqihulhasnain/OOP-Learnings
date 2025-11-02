#include <iostream>
using namespace std;

class Angle {
private:
    int degrees;
    float minutes;
    char direction;   // N, S, E, W

public:
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

class Ship {
private:
    static int count;
    int serialNum;
    Angle latitude;
    Angle longitude;

public:
    Ship() {
        count++;
        serialNum = count;
    }

    void getPosition() {
        cout << "Enter Latitude:\n";
        latitude.getAngle();
        cout << "Enter Longitude:\n";
        longitude.getAngle();
    }

    void report() const {
        cout << "\nShip Serial Number: " << serialNum << endl;
        cout << "Latitude: ";
        latitude.displayAngle();
        cout << "\nLongitude: ";
        longitude.displayAngle();
        cout << endl;
    }
};

int Ship::count = 0; // initialize static count

int main() {
    Ship ships[3];

    for(int i = 0; i < 3; i++) {
        cout << "\nEnter details for Ship " << i+1 << ":\n";
        ships[i].getPosition();
    }

    cout << "\n--- Ship Details ---\n";
    for(int i = 0; i < 3; i++) {
        ships[i].report();
    }

    return 0;
}
