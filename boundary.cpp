/*
    Given a matrix, print it's boundary element;
*/

#include<iostream>
using namespace std;

class solution{
    public:
        int** make_matrix(int r,int c);

        void boundary(int** mat,int r,int c);
};

void solution::boundary(int** mat, int r,int c){

    for(int i=0;i<c;++i){
        cout<<mat[0][i]<<" ";
    }

    for(int i=1;i<r;++i){
        cout<<mat[i][c-1]<<" ";
    }

    if(r!=1){
        for(int i=c-2;i>=0;i--){
            cout<<mat[r-1][i]<<" ";
        }
    }
    if(c!=1){
        for(int i=r-2;i>=1;i--){
            cout<<mat[i][0]<<" ";
        }
    }

}

int** solution::make_matrix(int r,int c){
    int** mat=new int* [r];
    cout<<"Enter elements of matrix: ";

    for(int i=0;i<r;++i){
        mat[i]=new int[c];
        for(int j=0;j<c;++j){
            cin>>mat[i][j];
        }
    }

    return mat;
}

int main(){

    int r,c;
    cout<<"Enter number of rows and columnns: ";
    cin>>r>>c;

    solution sl;

    int** mat=sl.make_matrix(r,c);

    sl.boundary(mat,r,c);

    return 0;
}