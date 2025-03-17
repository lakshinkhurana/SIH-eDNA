let balance = 10000;

function withdraw() {
    let amount = parseFloat(prompt("Enter the amount to withdraw: "));
    
    if (isNaN(amount) || amount <= 0) {
        console.log("Please enter a valid amount.");
        return;
    }
    
    try {
        if (amount > balance) {
            throw new Error("Insufficient balance");
        } else {
            balance -= amount;
            console.log("Withdrawal successful");
            checkBalance();
        }
    } catch (e) {
        console.log(e.message);
    }
}

function deposit() {
    let amount = parseFloat(prompt("Enter the amount to deposit: "));
    
    if (isNaN(amount) || amount <= 0) {
        console.log("Please enter a valid amount.");
        return;
    }
    
    try {
        balance += amount;
        console.log("Deposit successful");
        checkBalance();
    } catch (e) {
        console.log("Error occurred: ", e);
    }
}

function checkBalance() {
    console.log("Balance is: $" + balance);
};


