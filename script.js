// update logic

let currentParadigm = 'EDP';

function ParadigmTo(mode) {
    currentParadigm = mode;
    const modeIndicator = document.getElementById('set-display');
    modeIndicator.innerText = `Mode: ${mode} Paradigm`;

    console.log(`${mode} mode`);
}


function appendToDisplay(value) {
    const display = document.getElementById('display');
    display.value += value;
}

function clearDisplay() {
    document.getElementById('display').value = '';
}

// integration

async function calculate() {

    const displayElement = document.getElementById('display');

    const expression = displayElement.value;

    if (currentParadigm === 'EDP') {

    try {
        document.getElementById('display').value = eval(expression);
    } 
    catch (e) {
        document.getElementById('display').value = "Error";
    } 
} else { 
        const response = await fetch(`/api/calc?lang=${currentParadigm}&expr=${expression}`);
        const data = await response.json();
        document.getElementById('display').value = data.result;
    }

}