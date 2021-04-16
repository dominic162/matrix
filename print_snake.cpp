/*
    Given a 2d array. print it in snake pattern;
*/

#include<iostream>
using namespace std;

class solution{
    public:
        int** make_matrix(int r,int c);

        void snake_print(int** mat,int r,int c);
};

void solution::snake_print(int** mat,int r,int c){
    int i=0;
    cout<<"Snake print of array is: ";
    for(;i<r;){

        int j=0;
        for(;j<c;++j){
            cout<<mat[i][j]<<" ";
        }
        ++i;
        if(i<r){
            for(j=c-1;j>=0;j--){
                cout<<mat[i][j]<<" ";
            }
            ++i;
        }
    }
    return ;
}

int** solution::make_matrix(int r,int c){
    int** mat=new int*[r];
    cout<<"Enter elements: ";
    for(int i=0;i<r;++i){
        mat[i]= new int[c];
        for(int j=0;j<c;++j){
            cin>>mat[i][j];
        }
    }
    return mat;
}

int main(){
    int r,c;
    cout<<"Enter rows and column of matrix: ";
    cin>>r>>c;

    solution sl;
    int** mat=sl.make_matrix(r,c);

    sl.snake_print(mat,r,c);


    return 0;
}