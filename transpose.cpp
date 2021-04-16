/*
    Given a matrix. find it's transpose;
*/

#include<iostream>
using namespace std;

class solution{
    public:
        int** make_matrix(int r,int c);

        void transpose(int** mat,int r,int c);

        void disp_mat(int** mat,int r,int c);
};

void solution::disp_mat(int** mat,int r,int c){
    cout<<"\nElements of matrix are:\n";
    for(int i=0;i<r;++i){

        for(int j=0;j<c;++j){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;

    }
}

void solution::transpose(int** mat,int r,int c){

    for(int i=0;i<r;++i){
        for(int j=i+1;j<c;++j){
            swap(mat[i][j],mat[j][i]);
        }
    }

}

int** solution::make_matrix(int r,int c){

    cout<<"Enter elements of matrix: ";
    int** mat=new int* [r];
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
    cout<<"Enter number of rows and columns: ";
    cin>>r>>c;
    
    solution sl;

    int** mat=sl.make_matrix(r,c);

    sl.transpose(mat,r,c);

    sl.disp_mat(mat,r,c);
    
    return 0;
}