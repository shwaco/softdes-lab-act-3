const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

console.log("=== Terminal Calculator ===");

rl.question("Enter first number: ", function(num1Input) {
    
    rl.question("Enter second number: ", function(num2Input) {
        
        rl.question("Select Operation (+, -, *, /, %): ", function(operation) {

            let num1 = parseFloat(num1Input);
            let num2 = parseFloat(num2Input);
            let result;

            if (isNaN(num1) || isNaN(num2)) {
                console.log("Error: Please enter valid numbers.");
                rl.close();
                return;
            }

            if (operation === "+") {
                result = num1 + num2;
            } 
            else if (operation === "-") {
                result = num1 - num2;
            } 
            else if (operation === "*") {
                result = num1 * num2;
            } 
            else if (operation === "/") {
                if (num2 === 0) {
                    console.log("Error: Division by zero is not allowed.");
                    rl.close();
                    return;
                }
                result = num1 / num2;
            } 
            else if (operation === "%") {
                if (num2 === 0) {
                    console.log("Error: Modulo by zero is not allowed.");
                    rl.close();
                    return;
                }
                result = num1 % num2;
            } 
            else {
                console.log("Error: Invalid operation.");
                rl.close();
                return;
            }

            console.log("------------------");
            console.log("Result: " + result);
            console.log("------------------");
            
            rl.close();
        });
    });
});