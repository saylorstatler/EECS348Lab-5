#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;
//*prints a matrix to the screen
void printMatrix(const vector<vector<int>>& matrix) {
//Loop through each row, loop through each column in the current row, 
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}
//--------------------

//*adds two matrices together
vector<vector<int>> addMatrices(
    const vector<vector<int>>& matrix1,
    const vector<vector<int>>& matrix2
) {
//get the size of the matrix
    int N = matrix1.size();

//create a new matrix to store the answer
    vector<vector<int>> result(N, vector<int>(N));

//go through each row
    for (int i = 0; i < N; i++) {

//go through each column
        for (int j = 0; j < N; j++) {

//add the values at the same position
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

//return the finished matrix
    return result;
}

//--------------------

//*multiplies two matrices together
vector<vector<int>> multiplyMatrices(
    const vector<vector<int>>& matrix1,
    const vector<vector<int>>& matrix2
) {
//get the size of the matrix
    int N = matrix1.size();

//create a matrix filled with 0s to store the answer
    vector<vector<int>> result(N, vector<int>(N, 0));

//choose the row from matrix 1
    for (int i = 0; i < N; i++) {

//choose the column from matrix 2
        for (int j = 0; j < N; j++) {

//multiply the values and add them together
            for (int k = 0; k < N; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

//--------------------

//*calculates the two diagonal sums
void diagonalSums(const vector<vector<int>>& matrix) {

    int N = matrix.size();

//variables to store the two sums
    int mainSum = 0;
    int secondarySum = 0;

//go through each row
    for (int i = 0; i < N; i++) {

//add the main diagonal value a ii
        mainSum += matrix[i][i];

//add the secondary diagonal value a N-1-i
        secondarySum += matrix[i][N - 1 - i];
    }

//display the two sums
    cout << "\nMain Diagonal Sum: " << mainSum << endl;
    cout << "Secondary Diagonal Sum: " << secondarySum << endl;
}

//--------------------

//*swaps two rows in a matrix
void swapRows(vector<vector<int>>& matrix, int row1, int row2) {

    int N = matrix.size();

//check if both row numbers are valid
    if (row1 >= 0 && row1 < N && row2 >= 0 && row2 < N) {

//swap the two rows
        swap(matrix[row1], matrix[row2]);
    }
    else {
        cout << "Invalid row index." << endl;
    }
}

//--------------------

//*swaps two columns in a matrix
void swapColumns(vector<vector<int>>& matrix, int col1, int col2) {

    int N = matrix.size();

    if (col1 >= 0 && col1 < N && col2 >= 0 && col2 < N) {

//go through each row
        for (int i = 0; i < N; i++) {

//swap the values in the two columns
            swap(matrix[i][col1], matrix[i][col2]);
        }
    }
    else {
        cout << "Invalid column index." << endl;
    }
}

//--------------------

//*updates rows cols and adds a new val in the matrix
void updateElement(vector<vector<int>>& matrix, int row, int col, int newVal) {

    int N = matrix.size();
//goes through each row 
    if (row >= 0 && row < N && col >= 0 && col < N) {
        matrix[row][col] = newVal;
        }
    else {
        cout << "Invalid row or column index." << endl;
    }


}




//--------------------

int main() {
    string filename;

    cout << "Enter input file name: ";
    cin >> filename;
//Open the file for reading
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
}
//N will store the size of the matrices
    int N;
// Read the first number from the file
    inputFile >> N;
//Create the first and second N x N matrix
    vector<vector<int>> matrix1(N, vector<int>(N));
    vector<vector<int>> matrix2(N, vector<int>(N));
//Read values into the first matrix
    for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
//read a number from the file and store it at row i, column j
        inputFile >> matrix1[i][j];
    }
}
    for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        inputFile >> matrix2[i][j];
    }
}


//--------------------

//Print a heading for the matrix 1 and 2
    cout << "\nMatrix 1:\n";
//Call printMatrix function
    printMatrix(matrix1);
    cout << "\nMatrix 2:\n";
    printMatrix(matrix2);

//--------------------  

//Add two matrices
    vector<vector<int>> sum = addMatrices(matrix1, matrix2);
//Print sum matrix
    cout << "\nMatrix Addition:\n";
    printMatrix(sum);

//--------------------

//Multiply two matrices
vector<vector<int>> product = multiplyMatrices(matrix1, matrix2);
//Print multiplication result
cout << "\nMatrix Multiplication:\n";
printMatrix(product);

//--------------------

//calculate and print the diagonal sums
diagonalSums(matrix1);

//--------------------

//make separate copies of matrix 1 for problems 5 6 7
vector<vector<int>> rowMatrix = matrix1;
vector<vector<int>> colMatrix = matrix1;
vector<vector<int>> updateMatrix = matrix1;

//ask the user which rows to swap
int row1, row2;

cout << "\nEnter two rows to swap: ";
cin >> row1 >> row2;

//swap the rows
swapRows(rowMatrix, row1, row2);

//print the matrix after the swap
cout << "\nMatrix after row swap:\n";
printMatrix(rowMatrix);

//--------------------

//ask the user which columns to swap
int col1, col2;

cout << "\nEnter two columns to swap: ";
cin >> col1 >> col2;

//swap the columns
swapColumns(colMatrix, col1, col2);

//print the matrix after the column swap
cout << "\nMatrix after column swap:\n";
printMatrix(colMatrix);

//--------------------

//ask the user which rows,columns, and new value to swap/add
int row, col, newVal;

cout << "\nEnter row, column, and new value: ";
cin >> row >> col >> newVal;

//update the new matrix with the new value added
updateElement(updateMatrix, row, col, newVal);

//print the updated matrix
cout << "\nMatrix after element update:\n";
printMatrix(updateMatrix);

//--------------------

    return 0;
}