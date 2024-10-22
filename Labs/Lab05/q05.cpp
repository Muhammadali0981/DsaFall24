#include <iostream>

using namespace std;


bool is_safe(int** board, int row, int col, int size) {
    // Checking left side
    for (int j = col; j >= 0; j--) {
        if (board[row][j]) return false;// There's a queen on the left side
    }

    // Checking upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false; 
    }

    // Checking lower left diagonal
    for (int i = row, j = col; i < size && j >= 0; i++, j--) {
        if (board[i][j]) return false; 
    }

    return true; 
}


bool solution(int** board, int col, int size) {
    if (col >= size) return true; // Base case: all queens are placed

    for (int i = 0; i < size; i++) {
       
        if (is_safe(board, i, col, size)) {
            board[i][col] = 1; // Place the queen

            if (solution(board, col + 1, size))
                return true;

            board[i][col] = 0; // Remove the queen (backtrack)
        }
    }

    return false; // No valid placement found
}

void NQueen(int n) {
    
    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;  
        }
    }

    
    if (solution(board, 0, n)) {
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j]) {
                    cout << "Q ";  
                } else {
                    cout << ". "; 
                }
            }
            cout << "\n";
        }
    } else {
        cout << "No solution" << endl;  
    }

    
    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;
}

int main() {
    NQueen(4); 
    return 0;
}