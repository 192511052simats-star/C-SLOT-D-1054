#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double dailyRate;
    bool rented;

public:
    Vehicle(string r, double rate) {
        regNo = r;
        dailyRate = rate;
        rented = false;
    }

    virtual double charge(int days) = 0;

    virtual void display() {
        cout << "Registration: " << regNo
             << " | Daily Rate: " << dailyRate
             << " | Status: " << (rented ? "Rented" : "Available")
             << endl;
    }

    void rent() {
        if (!rented) {
            rented = true;
            cout << regNo << " rented successfully\n";
        } else {
            cout << regNo << " is already rented\n";
        }
    }

    void returnVehicle(int days) {
        if (rented) {
            rented = false;
            double lateCharge = days > 5 ? (days - 5) * 200 : 0;
            cout << regNo << " returned successfully\n";
            cout << "Rental Charge: " << charge(days) << endl;
            cout << "Late Charge: " << lateCharge << endl;
            cout << "Total Charge: " << charge(days) + lateCharge << endl;
        }
    }

    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate) : Vehicle(r, rate) {}

    double charge(int days) {
        return dailyRate * days;
    }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelLevel;
    string serviceDate;

public:
    MotorVehicle(string r, double rate, double fuel, string date)
        : Vehicle(r, rate) {
        fuelLevel = fuel;
        serviceDate = date;
    }
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string r, double rate, double fuel, string date)
        : MotorVehicle(r, rate, fuel, date) {}

    double charge(int days) {
        return dailyRate * days + 100;
    }
};

class Car : public MotorVehicle {
protected:
    int seatingCapacity;

public:
    Car(string r, double rate, double fuel,
        string date, int seats)
        : MotorVehicle(r, rate, fuel, date) {
        seatingCapacity = seats;
    }

    double charge(int days) {
        return dailyRate * days + 300;
    }
};

class ElectricCar : public Car {
private:
    double batteryCapacity;

public:
    ElectricCar(string r, double rate, double fuel,
                string date, int seats, double battery)
        : Car(r, rate, fuel, date, seats) {
        batteryCapacity = battery;
    }

    double charge(int days) {
        return dailyRate * days + batteryCapacity * 5;
    }
};

class ElectricBus : public MotorVehicle {
public:
    ElectricBus(string r, double rate, double fuel, string date)
        : MotorVehicle(r, rate, fuel, date) {}

    double charge(int days) {
        return dailyRate * days + 500;
    }
};

int main() {
    Vehicle* fleet[5];

    fleet[0] = new Bicycle("BIKE101", 100);
    fleet[1] = new TwoWheeler("BIKE202", 200, 80, "2026-12-01");
    fleet[2] = new Car("CAR303", 1000, 60, "2026-12-10", 5);
    fleet[3] = new ElectricCar("EV404", 1500, 90, "2026-12-15", 5, 60);
    fleet[4] = new ElectricBus("BUS505", 2500, 100, "2026-12-20");

    cout << "===== VEHICLE RENTAL FLEET =====\n";

    for (int i = 0; i < 5; i++) {
        fleet[i]->display();
    }

    cout << "\n===== RENTING VEHICLES =====\n";

    for (int i = 0; i < 5; i++) {
        fleet[i]->rent();
    }

    cout << "\n===== RETURNING VEHICLES =====\n";

    for (int i = 0; i < 5; i++) {
        fleet[i]->returnVehicle(7);
        cout << endl;
    }

    cout << "\n===== ADDING NEW VEHICLE TYPE =====\n";

    cout << "Electric Bus added without modifying existing classes\n";

    for (int i = 0; i < 5; i++) {
        delete fleet[i];
    }

    return 0;
}
