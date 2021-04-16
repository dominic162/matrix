/*
    Given a matrix, rotate it by 90degree.
*/

#include<iostream>
using namespace std;

class solution{
    public:
        int** make_mat(int r,int c);

        void rot_90(int** mat,int r,int c);

        void disp_mat(int** mat,int r,int c);
};

void solution::disp_mat(int** mat,int r,int c){
    cout<<"Elements of matrix are:\n";
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solution::rot_90(int** mat,int r,int c){
    //First do transpose

    for(int i=0;i<r;++i){
        for(int j=i+1;j<c;++j){
            swap(mat[i][j],mat[j][i]);
        }
    }

    //now swap last row and 1st row and then 2nd last row to 2nd row
    for(int i=0;i<r/2;++i){
        int* temp=mat[i];
        mat[i]=mat[r-i-1];
        mat[r-i-1]=temp;
    }

}

int** solution::make_mat(int r,int c){
    int** mat=new int* [r]; 
    cout<<"Enter elements: ";
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
    cout<<"Enter number of rows and columns: ";
    cin>>r>>c;
    
    solution sl;
    int** mat = sl.make_mat(r,c);
    sl.disp_mat(mat,r,c);

    sl.rot_90(mat,r,c);

    sl.disp_mat(mat,r,c);
    return 0;
}