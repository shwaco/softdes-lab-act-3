def add(a, b): 
    return a + b
def subtract(a, b): 
    return a - b
def multiply(a, b): 
    return a * b
def divide(a, b):
    return None if b == 0 else a / b
def modulus(a, b):
    return None if b == 0 else a % b

def get_operations():
    return {
        '+': add,
        '-': subtract,
        '*': multiply,
        '/': divide,
        '%': modulus
    }

def calculate(num1, op_symbol, num2):
    operations = get_operations()
    
    if op_symbol not in operations:
        return "Error: Invalid operation choice."
    
    result = operations[op_symbol](num1, num2)
    
    if result is None:
        if op_symbol == '/':
            return "Error: Cannot divide by zero."
        elif op_symbol == '%':
            return "Error: Cannot perform modulus by zero."
    
    return result

def run_calculator():
    print("--- Calculator ng malalakas ---")
    print("(Press Ctrl+C to exit the calculator)\n")
    
    while True:
        try:
            print("==================================")
            num1 = float(input("Enter first number: "))
            print("==================================")
            op_symbol = input("Enter operation (+, -, *, /, %): ")
            print("==================================")
            num2 = float(input("Enter second number: "))
            print("==================================")
        except ValueError:
            print("Error: Invalid numeric input. Try again.\n")
            continue
        
        result = calculate(num1, op_symbol, num2)
        print(f"Result: {result}")
        print("-" * 30)


if __name__ == "__main__":
    run_calculator()