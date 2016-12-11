#include<iostream>
#include<string>
#include<fstream>
using namespace std;

 int M;

void fillMasive(int **matrix,int M){
	int b;
	cout<<"Enter " << M * M << " numbers to fill-up the matrix: " <<endl;
        for(int i = 0; i < M; i++){
		for (int j = 0; j < M; j++){
			cout << "a[" << i << "][" << j <<"]= " ;
			cin>>b;
			matrix[i][j]=b;
		}
	}
}

void printM(int **matrix,int M){
	for (int i = 0; i < M; i++)
	{
	    cout<<endl;
		for (int j = 0; j < M; j++)
		{
			cout<<matrix[i][j]<<' ';
		}
	}
	cout << endl;
}

void matrixSum(int **matrix,int M){

 int sum =0;

 for (int i = 0; i < M; i++){
    for(int j = 0; j < M; j++){
    sum = sum + matrix[i][j];
    }
 }
 cout << "sum= " << sum << endl;

}

void printSumMatrix(int sumMatrix[],int M){
	cout<< endl;
	for (int i = 0; i < M; i++)
	{
			cout<<sumMatrix[i]<<' ';
	}
	cout << endl;
}

void findMin(int sumMatrix[],int M){
int holder;

   for (int i = 0 ; i < ( M - 1 ); i++)
  {
    for (int j = 0 ; j < M - i - 1; j++)
    {
      if (sumMatrix[j] > sumMatrix[j+1])
      {
        holder  = sumMatrix[j];
        sumMatrix[j]   = sumMatrix[j+1];
        sumMatrix[j+1] = holder;
      }
    }
  }

  cout << "Min="  << sumMatrix[0]<<endl;

}

void findMax(int sumMatrix[],int M){
int holder;

   for (int i = 0 ; i < ( M - 1 ); i++)
  {
    for (int j = 0 ; j < M - i - 1; j++)
    {
      if (sumMatrix[j] > sumMatrix[j+1])
      {
        holder  = sumMatrix[j];
        sumMatrix[j]   = sumMatrix[j+1];
        sumMatrix[j+1] = holder;
      }
    }
  }

  cout << "Max="  << sumMatrix[M-1]<<endl;

}

void matrixRowSum(int **matrix,int sumMatrix[], int M){

 int sum ;

 for(int i = 0; i < M; i++){
    sum = 0;
    for(int j = 0; j < M; j++){

     sum = sum + matrix[i][j];

    }
    sumMatrix[i] = sum;
 }
 printSumMatrix(sumMatrix,M);
 findMin(sumMatrix,M);
 findMax(sumMatrix,M);
}

void pringToTxtFile(int **matrix, int M){
    ofstream myFile("array.txt");
    for(int i = 0; i<M; i++){
     for(int j = 0; j < M; j++){
        myFile << matrix[i][j] << " ";
     }
     myFile << endl;
    }
    myFile.close();
}

void readFromTxtFile(int M){
 int readResult[M][M] ;

 ifstream myFile("array.txt");
 if(myFile.is_open()){
   for(int i = 0; i<M; i++){
     for(int j = 0; j < M; j++){
        myFile >> readResult[i][j] ;
     }
    }

 }
 myFile.close();
  cout << "reading from txt file matrix" << endl;
    for(int i = 0; i<M; i++){
     for(int j = 0; j < M; j++){
        cout << readResult[i][j] << " ";
     }
     cout << endl;
    }
}
int main(){

  cout<<"Matrix (MxM), Intup M: " << endl <<" Row: ";
  cin>>M;

  int **matrix=new int*[M];

	for (int i = 0; i < M; i++)
	{
		matrix[i]=new int[M];
	}

   int sumMatrix[M] ;

      fillMasive(matrix,M);
      printM(matrix,M);
      matrixSum(matrix,M);
      matrixRowSum(matrix,sumMatrix,M);
      pringToTxtFile(matrix,M);
      readFromTxtFile(M);

return 0;
}
