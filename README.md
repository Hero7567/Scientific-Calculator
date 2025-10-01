# OOPS Scientific Calculator in C++

## Description
This project is a **menu-driven scientific calculator** implemented in C++ using **Object-Oriented Programming (OOP) principles**. It can perform:

- **Basic Arithmetic Operations:** Addition, Subtraction, Multiplication, Division, Power, Square Root  
- **Scientific Functions:** Sine, Cosine, Tangent (angles in radians), Natural Logarithm  
- **Equation Solvers:**  
  - Quadratic Equations (1 variable, degree 2)  
  - Linear Equations with 2 variables  
  - Linear Equations with 3 variables (using Cramer’s Rule)  

The program is designed with **modular classes** for maintainability and clarity, and provides a **menu-driven interface** for easy user interaction.

---

## OOP Concepts Used

1. **Classes**
   - `BasicOperations` → Handles arithmetic operations.  
   - `ScientificOperations` → Handles trigonometric and logarithmic functions.  
   - `EquationSolver` → Solves quadratic and linear equations.  
   - `Calculator` → Integrates all components and provides the menu interface.

2. **Encapsulation**
   - Each class encapsulates its related methods.  
   - Private helper methods (like `determinant3x3`) hide internal implementation details.  

3. **Abstraction**
   - The `Calculator` class interacts with solver methods without knowing how calculations are performed internally.

4. **Composition**
   - `Calculator` contains objects of other classes:  
     ```cpp
     BasicOperations basic;
     ScientificOperations sci;
     EquationSolver solver;
     ```
   - Demonstrates a **“has-a” relationship**.

5. **Polymorphism (Conceptual)**
   - `EquationSolver` contains multiple solve methods for different equation types, representing the same conceptual operation “solve.”

6. **Private vs Public**
   - Private methods protect internal logic, while public methods provide access to essential operations.

7. **Modularity and Extensibility**
   - Each class has a single responsibility, making it easy to extend the calculator with new features like matrices or more variables in equations.

---

## How the Calculator Solves Equations

### 1. Quadratic Equations (`ax² + bx + c = 0`)
- Calculates the **discriminant**: `D = b² - 4ac`.  
- Determines the type of roots:
  - **D > 0:** Two real distinct roots: `x1 = (-b + √D)/2a`, `x2 = (-b - √D)/2a`  
  - **D = 0:** One repeated root: `x = -b/2a`  
  - **D < 0:** Two complex roots: `x = -b/2a ± i√(-D)/2a`  

### 2. Linear Equations with 2 Variables
For equations:
a1x + b1y = c1
a2x + b2y = c2

- Uses **Cramer’s Rule**:
  - Determinant: `D = a1*b2 - a2*b1`  
  - If `D != 0`:  
    ```
    x = (c1*b2 - c2*b1)/D
    y = (a1*c2 - a2*c1)/D
    ```
  - If `D == 0`: No unique solution.

### 3. Linear Equations with 3 Variables
For equations:
a1x + b1y + c1z = d1
a2x + b2y + c2z = d2
a3x + b3y + c3*z = d3

- Uses **Cramer’s Rule**:
  - Compute determinant of coefficient matrix `D` and determinants `Dx`, `Dy`, `Dz` by replacing columns with constants.  
  - If `D != 0`:  
    ```
    x = Dx / D
    y = Dy / D
    z = Dz / D
    ```
  - If `D == 0`: No unique solution (either infinite or none).  

---

## Stack for Memory Storage (Optional Feature)
- A **stack** can be used to **store results of previous calculations**, allowing recall or undo operations.  
- Example:
```cpp
#include <stack>
stack<double> memory;

double result = basic.add(a,b);
memory.push(result); // store result

double lastResult = memory.top(); // recall last result
memory.pop(); // undo last result
```
Benefits:


LIFO (Last-In-First-Out) ensures the most recent result is easily retrievable.
Supports “undo last calculation” and keeps track of history.
=====================================================================================================================================================

Summary:-
This calculator demonstrates effective use of OOP principles including classes, encapsulation, abstraction, composition, and modularity, providing a user-friendly, maintainable, and extensible scientific calculator that can handle arithmetic, scientific functions, and equations up to 3 variables.
