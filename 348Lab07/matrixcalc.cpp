#include <iostream>

using namespace std;
const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
    int matrixData[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

public:
    // 1. Read values from stdin into a matrix
    void readFromStdin(){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                cin >> matrixData[i][j];
            }
        }
    }

    // 2. Display a matrix
    void display() const{
        for (int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                cout << matrixData[i][j] << " ";                
            }
            cout << endl;
        }
    }
    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const{
        Matrix sum;
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j< SIZE; j++){
                sum.matrixData[i][j] = matrixData[i][j] + other.matrixData[i][j];
            }

        }
        return sum;
    }
    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other) const{
        Matrix product;
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
            product.matrixData[i][j] = matrixData[i][j] * other.matrixData[i][j];
            }
        }
        return product;
    }
    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const{
        int sum = 0;
        for(int i = 0; i < SIZE; i++){
            sum += matrixData[i][i];
        }
        return sum;
    }

    // 6. Swap matrix rows
    void swapRows(int row1, int row2){
        int temp;
        for(int i = 0; i <SIZE; i++){
            temp = matrixData[row1][i];
            matrixData[row1][i] = matrixData[row2][i];
            matrixData[row2][i] = temp;
        }
    }
};

int main() {
    
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    
    cout << "Matrix 1:" << endl;
    mat1.display();

    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();

    int row1;
    cout << "Enter first row # to swap:" << endl;
    cin >> row1;

    int row2;
    cout << "Enter next row # to swap:" << endl;
    cin >> row2;

    cout << "Matrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    mat1.swapRows(row1, row2);

    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}
