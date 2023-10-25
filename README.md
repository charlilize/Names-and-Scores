# Names-and-Scores

This program reads student names and their corresponding scores from a text file and performs various operations on the data. It allows users to search for a specific student, calculate statistics such as minimum, maximum, sum, and average scores, and display the names and scores in both forward and reverse order.

## Getting Started

To run the program, you need to have a C++ compiler installed on your machine. The code has been tested with the g++ compiler.

1. Clone the repository to your local machine.
2. Open a terminal and navigate to the project directory.
3. Compile the code using the following command: `g++ main.cpp`
4. Run the program by executing the generated binary file: `./a.out`

## Usage

1. The program will prompt you to enter the name of the text file containing the student scores. Make sure to provide the correct file name.
2. Next, you will be asked to enter a name to search for in the student records.
3. The program will read the data from the file and perform the necessary calculations.
4. It will display the names and scores in both forward and reverse order.
5. Finally, it will provide the minimum, maximum, sum, and average scores for the searched student.

## Example

For data1.txt:

If you search for the name "alex", the program will output:

Names Forward: alex, john, jane, alex, alex, jane, john, ted
Scores Forward: 84, 97, 99, 91, 95, 100, 98, 55
Names Reverse: ted, john, jane, alex, alex, jane, john, alex
Scores Reverse: 55, 98, 100, 95, 91, 99, 97, 84
4 results for alex
Minimum: 84
Maximum: 95
Sum: 365
Average: 91.25
