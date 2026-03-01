const express = require('express');
const { exec } = require('child_process');
const cors = require('cors');
const app = express();
const port = 3000;

app.use(cors());

app.get('/api/calc', (req, res) => {

    const { lang, expr } = req.query;
    let command = '';

    const parts = expr.match(/(\d+\.?\d*)([\+\-\*\/\%])(\d+\.?\d*)/);

    if (!parts) return res.json({ result: "Invalid Format" });

    const [_, n1, op, n2] = parts;

    if (lang === 'Procedural') {
        command = `./c_calc ${n1} ${op} ${n2}`;
    } else if (lang === 'OOP') {
        command = `java SmartCalculator ${n1} ${op} ${n2}`;
    } else if (lang === 'Functional') {
        command = `python3 calc.py ${n1} ${op} ${n2}`;
    }

   
    exec(command, (error, stdout, stderr) => {
        if (error) {
            console.error(`Exec error: ${error}`);
            return res.json({ result: "Error" });
        }
     
        res.json({ result: stdout.trim() });
    });
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});