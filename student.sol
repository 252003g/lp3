// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        uint rollNo;
        string name;
        uint marks;
    }

    Student[] public students; // Array of Student structures
    address public owner;

    constructor() {
        owner = msg.sender; // whoever deploys is owner
    }

    // Add new student details
    function addStudent(uint _rollNo, string memory _name, uint _marks) public {
        Student memory newStudent = Student({
            rollNo: _rollNo,
            name: _name,
            marks: _marks
        });
        students.push(newStudent);
    }

    // Get total number of students
    function getStudentCount() public view returns (uint) {
        return students.length;
    }

    // Get student details by index
    function getStudent(uint index) public view returns (uint, string memory, uint) {
        require(index < students.length, "Invalid index");
        Student memory s = students[index];
        return (s.rollNo, s.name, s.marks);
    }

    // Fallback function — triggers when Ether sent or wrong function called
    fallback() external payable {
        // Just accepts Ether
    }

    // Receive function — accepts Ether directly
    receive() external payable {}
}
