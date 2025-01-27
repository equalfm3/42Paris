# Import necessary modules: 're' for regular expressions and 'math' for mathematical operations
import re
import math

# Define the Polynomial class to represent and solve polynomial equations
class Polynomial:
    """
    This class encapsulates all functionality related to parsing, 
    representing, and solving polynomial equations up to degree 2.
    It uses object-oriented programming principles for a modular structure.
    """

    def __init__(self, equation):
        """
        Initialize the Polynomial object with the given equation.
        Sets up empty dictionaries and variables to be filled by parse_equation.
        
        Args:
            equation (str): The polynomial equation to be solved.
        """
        self.original_equation = equation
        self.coefficients = {}
        self.degree = 0
        self.parse_equation()

    def parse_equation(self):
        """
        Parse the input equation, validate its format, and extract coefficients.
        This method breaks down the input equation into its constituent parts.
        It uses regular expressions to identify coefficients and powers of each term.
        The method also handles the equation's left and right sides separately and combines them.
        
        Raises:
            ValueError: If the equation format is invalid.
        """
        # Remove all spaces from the equation for easier processing
        equation = self.original_equation.replace(" ", "")
        
        # Check if the equation contains an equals sign to ensure a valid equation format
        if '=' not in equation:
            raise ValueError("Invalid equation: must contain '='")
        
        # Split the equation into left and right sides
        left, right = equation.split('=')
        
        # Define a regular expression pattern to enforce the "a*X^p" format for each term
        pattern = r'^(([+-]?(?:\d*\.)?\d+)\*X\^(\d+)|([+-]?(?:\d*\.)?\d+)\*X|([+-]?(?:\d*\.)?\d+))+$'
        
        # Check if both sides of the equation match the required format
        if not (re.match(pattern, left) and re.match(pattern, right)):
            raise ValueError("Invalid format. Use the form 'a*X^p' for each term.")
        
        # Parse both sides of the equation
        left_terms = self.parse_side(left)
        right_terms = self.parse_side(right)
        
        # Combine terms by subtracting right side from left side
        for power, coeff in right_terms.items():
            if power in left_terms:
                left_terms[power] -= coeff
            else:
                left_terms[power] = -coeff
        
        # Store non-zero coefficients and determine the polynomial degree
        # Using a small threshold (1e-12) to handle floating-point imprecision
        self.coefficients = {k: v for k, v in left_terms.items() if abs(v) > 1e-12}
        self.degree = max(self.coefficients.keys()) if self.coefficients else 0

    def parse_side(self, side):
        """
        Parse one side of the equation, identifying coefficients and powers for each term.
        This method uses regular expressions to handle different term formats (aX^n, aX, constant).
        It combines like terms by summing coefficients for the same power.
        
        Args:
            side (str): One side of the equation to be parsed.
        
        Returns:
            dict: A dictionary mapping powers to coefficients.
        """
        terms = {}
        pattern = r'([+-]?(?:\d*\.)?\d+)\*X\^(\d+)|([+-]?(?:\d*\.)?\d+)\*X|([+-]?(?:\d*\.)?\d+)'
        matches = re.finditer(pattern, side)
        
        for match in matches:
            coeff_pow2, pow2, coeff_pow1, constant = match.groups()
            
            if coeff_pow2:
                power = int(pow2)
                coeff = float(coeff_pow2)
            elif coeff_pow1:
                power = 1
                coeff = float(coeff_pow1)
            else:
                power = 0
                coeff = float(constant)
            
            if power in terms:
                terms[power] += coeff
            else:
                terms[power] = coeff
        
        return terms

    def reduced_form(self):
        """
        Create the reduced form of the equation.
        This method normalizes coefficients by dividing by the leading coefficient.
        It formats each term, handling special cases like coefficients of 1 or -1.
        The terms are then combined into a single string, ensuring proper formatting.
        
        Returns:
            str: The reduced form of the equation.
        """
        if not self.coefficients:
            return "0 = 0"
        
        leading_coeff = self.coefficients[self.degree]
        terms = []
        for power in range(self.degree, -1, -1):
            if power in self.coefficients:
                coeff = self.coefficients[power] / leading_coeff
                if abs(coeff) > 1e-12:
                    if abs(coeff - 1) < 1e-12 and power > 0:
                        term = ""
                    elif abs(coeff + 1) < 1e-12 and power > 0:
                        term = "-"
                    else:
                        term = f"{coeff:+.6f}".rstrip('0').rstrip('.').rstrip('+')
                        if term == "+":
                            term = "1"
                        elif term == "-":
                            term = "-1"
                    
                    if power > 1:
                        term += f"X^{power}" if term else f"X^{power}"
                    elif power == 1:
                        term += "X" if term else "X"
                    terms.append(term)
        
        reduced = " ".join(terms).replace(" + -", " - ").replace(" 1X", " X").replace("-1X", "-X").strip()
        return reduced + " = 0"

    def solve(self):
        """
        Determine which solving method to use based on the polynomial degree.
        This method calls the appropriate solving method or returns a message for unsolvable cases.
        
        Returns:
            str: The solution or a message indicating why the equation can't be solved.
        """
        if self.degree > 2:
            return "The polynomial degree is strictly greater than 2, I can't solve."
        elif self.degree == 2:
            return self.solve_quadratic()
        elif self.degree == 1:
            return self.solve_linear()
        elif self.degree == 0:
            return self.solve_constant()
        else:
            return "All real numbers are solution."

    def solve_quadratic(self):
        """
        Solve quadratic equations using the quadratic formula.
        This method implements the quadratic formula to solve quadratic equations.
        It calculates the discriminant to determine the nature of the solutions.
        The method handles cases for zero, positive, and negative discriminants,
        returning real or complex solutions as appropriate.
        
        Returns:
            str: The solution(s) to the quadratic equation.
        """
        a = self.coefficients.get(2, 0)
        b = self.coefficients.get(1, 0)
        c = self.coefficients.get(0, 0)
        
        discriminant = b**2 - 4*a*c
        
        if abs(discriminant) < 1e-12:
            x = -b / (2*a)
            return f"Discriminant is zero, the solution is:\n{x:.6f}"
        elif discriminant > 0:
            x1 = (-b + math.sqrt(discriminant)) / (2*a)
            x2 = (-b - math.sqrt(discriminant)) / (2*a)
            return f"Discriminant is strictly positive, the two solutions are:\n{x1:.6f}\n{x2:.6f}"
        else:
            real = -b / (2*a)
            imag = abs(math.sqrt(-discriminant) / (2*a))
            return f"Discriminant is strictly negative, the two complex solutions are:\n{real:.6f} + {imag:.6f}i\n{real:.6f} - {imag:.6f}i"

    def solve_linear(self):
        """
        Solve linear equations using basic algebra.
        This method handles special cases where the equation reduces to 0 = 0 or 0 = non-zero constant.
        
        Returns:
            str: The solution to the linear equation or a message indicating the nature of the solution.
        """
        b = self.coefficients.get(1, 0)
        c = self.coefficients.get(0, 0)
        if abs(b) < 1e-12:
            return "All real numbers are solution." if abs(c) < 1e-12 else "No solution."
        x = -c / b
        return f"The solution is:\n{x:.6f}"

    def solve_constant(self):
        """
        Handle constant equations (degree 0).
        This method determines if all real numbers are solutions or if there is no solution.
        
        Returns:
            str: A message indicating whether all real numbers are solutions or there is no solution.
        """
        c = self.coefficients.get(0, 0)
        return "All real numbers are solution." if abs(c) < 1e-12 else "No solution."

# Main function to run the program
def main():
    """
    The main function that runs the program loop.
    It handles user input, creates Polynomial objects, displays results, and provides a way to exit the program.
    """
    while True:
        equation = input("Enter an equation (or 'quit' to exit): ")
        if equation.lower() == 'quit':
            break
        try:
            poly = Polynomial(equation)
            print(f"Reduced form: {poly.reduced_form()}")
            print(f"Polynomial degree: {poly.degree}")
            print(poly.solve())
        except ValueError as e:
            print(f"Error: {e}")
        print()

# Run the main function if this script is executed
if __name__ == "__main__":
    main()