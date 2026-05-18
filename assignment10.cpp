#include<iostream> 
#include<vector>
using namespace std;

class Assignment_N_Queens {
public:

    bool isSafe(vector<string>& board, int row , int col,int n){
        // horizontal
        //Checks if another queen exists in same row.
        for(int i=0; i<n; i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }

        // vertical
        //Checks if another queen exists in same column.
        for(int j=0;j<n;j++){
            if(board[j][col] == 'Q'){
                return false;
            }
        }

        // // left diagonal
        for(int i=row,j=col; i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        // // right diagonal
        for(int i=row,j=col; i>=0 && j<n; i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        return true; //If none found -> Safe to place queen
    }

    void nQueens(vector<string>& board,int row , int n , vector<vector<string>>& ans){

        if(row==n){
            ans.push_back(board); // If we placed queens in all rows, we found a solution.
            return;
        }
        for(int j=0; j<n; j++){
            if(isSafe(board,row,j,n)){ // Trying to place a queen in every column of the current row.
                board[row][j] = 'Q';
                nQueens(board , row+1 , n, ans); // Recur to place queens in the next row.
                board[row][j] = '.';  // Backtrack: Remove the queen and try next column.
            }
        }
    }

    vector<vector<string>> solveNQueens(int n){
        // This function prepares the board and starts recursion.
        vector<string> board(n , string(n,'.')); // Creates a vector of given size, where every element is initialized with the given value./k
        vector<vector<string>> ans;

        nQueens(board, 0 , n , ans);

        return ans;
    }
};

int main(){

    int n;
    // input validation
    while(true){
        cout<<"Enter number of queens: ";
        cin>>n;
        if(cin.fail()){
            cout<<"Invalid input! Enter a valid integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(n <= 0){
            cout<<"Invalid input. Enter a positive number.\n";
        }
        else if(n > 10){
            cout<<"Input too large. Please enter n <= 10\n";
        }
        else{
            break;
        }
    }

    Assignment_N_Queens obj;
    vector<vector<string>> result = obj.solveNQueens(n);

    if(result.size() == 0){
        cout<<"No Solutions exists\n";
    }
    else{
        cout<<"\nTotal Solutions: "<<result.size()<<endl;
        for(int k=0;k<result.size();k++){
            cout<<"\nSolution "<<k+1<<":\n";
            for(string row : result[k]){
                cout<<row<<endl;
            }
        }
    }
    return 0;
}