import sys

def add(a, b): return a + b
def subtract(a, b): return a - b
def multiply(a, b): return a * b
def divide(a, b): return "Error: Div by 0" if b == 0 else a / b
def modulus(a, b): return "Error: Mod by 0" if b == 0 else a % b

def calculate(n1, op, n2):
    ops = {'+': add, '-': subtract, '*': multiply, '/': divide, '%': modulus}
    return ops[op](n1, n2) if op in ops else "Error: Invalid Op"

if __name__ == "__main__":
    if len(sys.argv) == 4:
        try:
            num1 = float(sys.argv[1])
            op = sys.argv[2]
            num2 = float(sys.argv[3])
            print(calculate(num1, op, num2)) 
        except ValueError:
            print("Error: Invalid Input")