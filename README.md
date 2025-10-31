# Student Management System (SMS)

A console-based Student Management System implemented in C++ that allows users to manage student records efficiently. The system uses a Binary Search Tree (BST) for ordered storage and an unordered map for fast lookups.

## Features

- **Add Student**: Insert new student records with name, USN, CGPA, and contact number.
- **Search Student**: Quickly find and display student details by USN.
- **Remove Student**: Delete student records from the system.
- **Modify Data**: Update existing student information.
- **Display Students**: View all students in sorted order (by USN).
- **Count Students**: Get the total number of students in the system.
- **Top K Students by CGPA**: Find the top K students with highest or lowest CGPA.
- **Duplicate Prevention**: Prevents adding students with duplicate USNs.

## Menu Options

1. **Add student**: Enter student details (Name, USN, CGPA, Contact No.)
2. **Search student**: Search by USN and display details
3. **Remove student**: Delete student by USN
4. **Modify data**: Update student information
5. **Display students**: Show all students in tabular format
6. **Count number of students**: Display total student count
7. **K number of students with maximum CGPA**: Show top K students by CGPA (descending)
8. **K number of students with minimum CGPA**: Show top K students by CGPA (ascending)
9. **Exit**: Terminate the program

## Technologies Used

- **C++**: Core programming language
- **Standard Template Library (STL)**: 
  - `unordered_map` for O(1) average-time complexity lookups
  - `vector` and `queue` for data manipulation
  - `algorithm` for sorting operations
- **Binary Search Tree (BST)**: For ordered storage and efficient operations
- **Console I/O**: Standard input/output streams for user interaction

## How to Compile and Run

### Prerequisites
- A C++ compiler (e.g., g++, clang++)
- The project files: `sms.cpp` and `STD_tree.hh`

### Compilation
```bash
g++ sms.cpp -o sms
```

### Running the Program
```bash
./sms
```

On Windows, you may need to use:
```bash
sms.exe
```

## File Structure

```
sms_proj/
├── sms.cpp         # Main program file with menu interface
├── STD_tree.hh     # Header file containing Student_info class and BST implementation
├── sms.exe         # Compiled executable (generated after compilation)
└── README.md       # This file
```

## Data Structure Details

- **Student Structure**: Contains name (string), USN (string), phone_no (long int), cgpa (float)
- **Binary Search Tree**: Ordered by USN for efficient insertion, deletion, and traversal
- **Unordered Map**: Provides fast O(1) average-time lookups for search operations
- **In-order Traversal**: Used for displaying students in sorted order

## Usage Example

```
WELCOME

Enter your choice
1. Add student
2. Search student
3. Remove student
4. Modify data
5. Display students
6. Count number of students
7. K number of students with maximum CGPA
8. K number of students with minimum CGPA
9. Exit
1
Please enter the details
Name: John Doe
USN: 1RV21CS001
Enter CGPA: 8.5
Contact No: 9876543210
```

This system provides a robust and efficient way to manage student data with both ordered and hashed data structures for optimal performance.
