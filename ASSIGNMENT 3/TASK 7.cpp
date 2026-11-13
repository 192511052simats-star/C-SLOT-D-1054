#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Constructor with real part
    Complex(double r) {
        real = r;
        imag = 0;
    }

    // Constructor with real and imaginary parts
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Addition
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Division
    Complex operator/(const Complex& c) const {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0) {
            throw "Division by zero impedance";
        }

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Equality
    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    // Magnitude
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Display
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main() {
    try {
        // Resistor, inductor and capacitor impedances
        Complex R(10, 0);
        Complex L(0, 5);
        Complex C(0, -2);

        // Series RLC circuit
        Complex series = R + L + C;

        cout << "Series Impedance: " << series << endl;
        cout << "Series Magnitude: "
             << series.magnitude() << endl;

        // Parallel circuit
        Complex Z1(10, 0);
        Complex Z2(0, 5);

        Complex parallel = (Z1 * Z2) / (Z1 + Z2);

        cout << "\nParallel Impedance: "
             << parallel << endl;

        cout << "Parallel Magnitude: "
             << parallel.magnitude() << endl;

        // Division by zero test
        Complex a(5, 3);
        Complex zero(0, 0);

        Complex result = a / zero;

        cout << result << endl;
    }
    catch (const char* error) {
        cout << "\nError: " << error << endl;
    }

    return 0;
}
