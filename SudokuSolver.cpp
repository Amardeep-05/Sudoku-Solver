#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<char> >& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c){
                return false;
            }
            if(board[i][col]==c)return false;
            if(board[3*(row/3) +i/3][3*(col/3)+i%3]==c)return false;
        }
        return true;
    }
    bool solve(vector<vector<char> >& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board,i,j,c)==true){
                                board[i][j]=c;
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char> >& board) {
        solve(board);
        
    }
int main(){

    vector<vector<char> >board(9,vector<char>(9));

    cout<<"Enter the number"<<endl;
    cout<<"Use '.' for the empty boxes"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            char temp;
            cin>>temp;
            board[i][j]=temp;
        }
    }
    solveSudoku(board);
    cout<<endl;
    cout<<"Solved Sudoku"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    



return 0;
}