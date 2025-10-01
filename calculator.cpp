#include <iostream>
#include <cmath>
using namespace std;

// ================== BASIC OPERATIONS ==================
class BasicOperations {
public:
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) {
        if (b != 0) return a / b;
        cout << "Error! Division by zero.\n";
        return NAN;
    }
    double power(double base, double exp) { return pow(base, exp); }
    double squareRoot(double a) {
        if (a >= 0) return sqrt(a);
        cout << "Error! Negative input.\n";
        return NAN;
    }
};

// ================== SCIENTIFIC OPERATIONS ==================
class ScientificOperations {
public:
    double sine(double angle) { return sin(angle); }
    double cosine(double angle) { return cos(angle); }
    double tangent(double angle) { return tan(angle); }
    double logarithm(double a) {
        if (a > 0) return log(a);
        cout << "Error! Logarithm not defined.\n";
        return NAN;
    }
};

// ================== EQUATION SOLVER ==================
class EquationSolver {
private:
    // Helper to calculate determinant of 3x3 matrix
    double determinant3x3(double a1, double b1, double c1,
                          double a2, double b2, double c2,
                          double a3, double b3, double c3) {
        return a1*(b2*c3 - b3*c2) - b1*(a2*c3 - a3*c2) + c1*(a2*b3 - a3*b2);
    }

public:
    // Quadratic equation solver
    void solveQuadratic(double a, double b, double c) {
        cout << "\nEquation: " << a << "x^2 + " << b << "x + " << c << " = 0\n";
        if (a == 0) {
            cout << "Not a quadratic equation.\n";
            return;
        }

        double D = b*b - 4*a*c;
        if (D > 0) {
            cout << "Roots: " << (-b + sqrt(D)) / (2*a)
                 << " , " << (-b - sqrt(D)) / (2*a) << endl;
        } else if (D == 0) {
            cout << "Root: " << -b / (2*a) << endl;
        } else {
            double realPart = -b / (2*a);
            double imagPart = sqrt(-D) / (2*a);
            cout << "Roots: " << realPart << " + " << imagPart << "i , "
                 << realPart << " - " << imagPart << "i\n";
        }
    }

    // Linear equations with 2 variables
    void solveLinear2Var(double a1, double b1, double c1,
                         double a2, double b2, double c2) {
        cout << "\nSystem of equations:\n";
        cout << a1 << "x + " << b1 << "y = " << c1 << endl;
        cout << a2 << "x + " << b2 << "y = " << c2 << endl;

        double D = a1*b2 - a2*b1;

        if (D == 0) {
            cout << "No unique solution.\n";
        } else {
            double x = (c1*b2 - c2*b1) / D;
            double y = (a1*c2 - a2*c1) / D;
            cout << "Solution: x = " << x << ", y = " << y << endl;
        }
    }

    // Linear equations with 3 variables (Cramer's Rule)
    void solveLinear3Var(double a1, double b1, double c1, double d1,
                         double a2, double b2, double c2, double d2,
                         double a3, double b3, double c3, double d3) {
        cout << "\nSystem of equations:\n";
        cout << a1 << "x + " << b1 << "y + " << c1 << "z = " << d1 << endl;
        cout << a2 << "x + " << b2 << "y + " << c2 << "z = " << d2 << endl;
        cout << a3 << "x + " << b3 << "y + " << c3 << "z = " << d3 << endl;

        double D  = determinant3x3(a1, b1, c1, a2, b2, c2, a3, b3, c3);
        double Dx = determinant3x3(d1, b1, c1, d2, b2, c2, d3, b3, c3);
        double Dy = determinant3x3(a1, d1, c1, a2, d2, c2, a3, d3, c3);
        double Dz = determinant3x3(a1, b1, d1, a2, b2, d2, a3, b3, d3);

        if (D == 0) {
            cout << "No unique solution (either infinite or none).\n";
        } else {
            double x = Dx / D;
            double y = Dy / D;
            double z = Dz / D;
            cout << "Solution: x = " << x << ", y = " << y << ", z = " << z << endl;
        }
    }
};

// ================== MAIN CALCULATOR CLASS ==================
class Calculator {
private:
    BasicOperations basic;
    ScientificOperations sci;
    EquationSolver solver;

public:
    void displayMenu() {
        cout << "\n==== Scientific Calculator (OOP) ====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Power (x^y)\n";
        cout << "6. Square Root\n";
        cout << "7. Sine\n";
        cout << "8. Cosine\n";
        cout << "9. Tangent\n";
        cout << "10. Log (base e)\n";
        cout << "11. Solve Quadratic Equation\n";
        cout << "12. Solve Two Linear Equations (2 variables)\n";
        cout << "13. Solve Three Linear Equations (3 variables)\n";
        cout << "14. Exit\n";
    }

    void run() {
        int choice;
        double a, b, c;

        while (true) {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 14) {
                cout << "Exiting calculator...\n";
                break;
            }

            switch (choice) {
                case 1:
                    cout << "Enter two numbers: "; cin >> a >> b;
                    cout << "Result = " << basic.add(a, b) << endl; break;
                case 2:
                    cout << "Enter two numbers: "; cin >> a >> b;
                    cout << "Result = " << basic.subtract(a, b) << endl; break;
                case 3:
                    cout << "Enter two numbers: "; cin >> a >> b;
                    cout << "Result = " << basic.multiply(a, b) << endl; break;
                case 4:
                    cout << "Enter two numbers: "; cin >> a >> b;
                    cout << "Result = " << basic.divide(a, b) << endl; break;
                case 5:
                    cout << "Enter base and exponent: "; cin >> a >> b;
                    cout << "Result = " << basic.power(a, b) << endl; break;
                case 6:
                    cout << "Enter number: "; cin >> a;
                    cout << "Result = " << basic.squareRoot(a) << endl; break;
                case 7:
                    cout << "Enter angle (radians): "; cin >> a;
                    cout << "Result = " << sci.sine(a) << endl; break;
                case 8:
                    cout << "Enter angle (radians): "; cin >> a;
                    cout << "Result = " << sci.cosine(a) << endl; break;
                case 9:
                    cout << "Enter angle (radians): "; cin >> a;
                    cout << "Result = " << sci.tangent(a) << endl; break;
                case 10:
                    cout << "Enter number: "; cin >> a;
                    cout << "Result = " << sci.logarithm(a) << endl; break;
                case 11:
                    cout << "Enter coefficients (a, b, c): ";
                    cin >> a >> b >> c;
                    solver.solveQuadratic(a, b, c);
                    break;
                case 12: {
                    double a1, b1, c1, a2, b2, c2;
                    cout << "Equation form: a*x + b*y = c\n";
                    cout << "Enter coefficients of first equation (a1 b1 c1): ";
                    cin >> a1 >> b1 >> c1;
                    cout << "Enter coefficients of second equation (a2 b2 c2): ";
                    cin >> a2 >> b2 >> c2;
                    solver.solveLinear2Var(a1, b1, c1, a2, b2, c2);
                    break;
                }
                case 13: {
                    double a1,b1,c1,d1, a2,b2,c2,d2, a3,b3,c3,d3;
                    cout << "Equation form: a*x + b*y + c*z = d\n";
                    cout << "Enter coefficients of first equation (a1 b1 c1 d1): ";
                    cin >> a1 >> b1 >> c1 >> d1;
                    cout << "Enter coefficients of second equation (a2 b2 c2 d2): ";
                    cin >> a2 >> b2 >> c2 >> d2;
                    cout << "Enter coefficients of third equation (a3 b3 c3 d3): ";
                    cin >> a3 >> b3 >> c3 >> d3;
                    solver.solveLinear3Var(a1,b1,c1,d1,a2,b2,c2,d2,a3,b3,c3,d3);
                    break;
                }
                default:
                    cout << "Invalid choice!\n";
            }
        }
    }
};

// ================== MAIN ==================
int main() {
    Calculator calc;
    calc.run();
    return 0;
}
