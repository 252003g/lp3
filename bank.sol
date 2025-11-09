// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BankAccount {
    address public owner;
    uint public balance;

    constructor() {
        owner = msg.sender;
        balance = 0;
    }

    function deposit() public payable {
        require(msg.value > 0, "Amount must be greater than zero");
        balance += msg.value;
    }

    function withdraw(uint _amount) public {
        require(msg.sender == owner, "Only owner can withdraw");
        require(_amount <= balance, "Insufficient balance");
        balance -= _amount;
        payable(owner).transfer(_amount);
    }

    // function showBalance() public view returns (uint) {
    //     return balance;
    // }
}
