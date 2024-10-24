#include<iostream>
#include<stdlib.h>
using namespace std;
void store(int** arr,int rows,int cols)  {
	cout<<"Enter elements in array: \n";
	for(int i=0;i<rows;i++)  {
		for(int j=0;j<cols;j++)  {
			cin>> arr[i][j];
		}
	}
}
void display(int** arr,int rows,int cols)  {
	cout<<"Display elements in array: \n";
	for(int i=0;i<rows;i++)  {
		for(int j=0;j<cols;j++)  {
			cout<<arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void add(int** arr,int** brr,int rows,int cols)  {
	int** crr = new int* [rows];   
	for(int i=0;i<rows;i++)  {
		crr[i] = new int[cols];
	}
	
	for(int i=0;i<rows;i++)  {
		for(int j=0;j<cols;j++)  {
			crr[i][j] = arr[i][j] + brr[i][j];
	    }
	}
	cout<<"Addition is: \n";
	display(crr,rows,cols);
}

void subtract(int** arr,int** brr,int rows,int cols)  {
	int** crr = new int* [rows];   
	for(int i=0;i<rows;i++)  {
		crr[i] = new int[cols];
	}
	
	for(int i=0;i<rows;i++)  {
		for(int j=0;j<cols;j++)  {
			crr[i][j] = arr[i][j] - brr[i][j];
	    }
	}
	cout<<"Subtraction is: \n";
	display(crr,rows,cols);
}
void transpose(int** arr,int rows,int cols)   {
	int tArr[rows][cols];  
	
	for(int i=0;i<rows;i++)  {
		for(int j=0;j<cols;j++)  {
			tArr[j][i]=arr[i][j];
		}
	}
	cout<<"Transpose of matrix: \n";
	for(int i=0;i<cols;i++)  {
		for(int j=0;j<rows;j++)  {
			cout<< tArr[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
}
void multiplication(int** A,int** B,int r1,int c1,int r2,int c2)  {
	
	if (c1 != r2) {  // Check if matrix multiplication is possible
        cout << "Multiplication is not possible.\n";
    }

    // Dynamically allocate the result matrix
    int** result = new int* [r1];  // r1 x c2 matrix
    for (int i = 0; i < r1; i++) {
        result[i] = new int[c2];
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;  // Initialize the result matrix to 0
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    // Display the result matrix
    cout << "Multiplication Result Matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j]<<" ";
        }
        cout <<"\n";
    }
}

int main()  {
	
	int choice;
	do {
		cout<<"\nWelcome to the world of 2D Array: \n";
		cout<<"Press 1 for Addition\n";
		cout<<"Press 2 for Subtraction\n";
		cout<<"Press 3 for Transpose of Matrix\n";
		cout<<"Press 4 for Multiplication\n";
		cout<<"Press 0 for Exit \n\n";
		
		cout<<"Enter your choice: ";
		cin>> choice;
		        
		switch(choice) {
			case 1:	{
				int rows, cols;
	            cout<<"Enter no of rows for matrix arr & brr: ";
	            cin>>rows;
	            cout<<"Enter no of cols for matrix arr & brr: ";
	            cin>>cols;
	            //arr1
	            int** arr = new int* [rows];   //Used double pointer here to create 2D array dynamically
	            for(int i=0;i<rows;i++)  {
		        arr[i] = new int[cols];
	            }
	            int** brr = new int* [rows];
	            for(int i=0;i<rows;i++)  {
		        brr[i] = new int[cols];
	            }
	
	            store(arr,rows,cols);
	            display(arr,rows,cols);
	
	            store(brr,rows,cols);
	            display(brr,rows,cols);
	            
				add(arr,brr,rows,cols);
			    break;
			} 
			case 2: {
			    int rows, cols;
	            cout<<"Enter no of rows for matrix arr & brr: ";
	            cin>>rows;
	            cout<<"Enter no of cols for matrix arr & brr: ";
	            cin>>cols;
	            //arr1
	            int** arr = new int* [rows];   //Used double pointer here to create 2D array dynamically
	            for(int i=0;i<rows;i++)  {
		        arr[i] = new int[cols];
	            }
	            int** brr = new int* [rows];
	            for(int i=0;i<rows;i++)  {
		        brr[i] = new int[cols];
	            }
	
	            store(arr,rows,cols);
	            display(arr,rows,cols);
	
	            store(brr,rows,cols);
	            display(brr,rows,cols);
	            
				subtract(arr,brr,rows,cols);
				break;
			}
				
			case 3:  {
				int rows, cols;
	            cout<<"Enter no of rows for matrix arr: ";
	            cin>>rows;
	            cout<<"Enter no of cols for matrix arr: ";
	            cin>>cols;
	            //arr1
	            int** arr = new int* [rows];   //Used double pointer here to create 2D array dynamically
	            for(int i=0;i<rows;i++)  {
		        arr[i] = new int[cols];
	            }
	            store(arr,rows,cols);
				display(arr,rows,cols);
				transpose(arr,rows,cols);
				break;
			}
			case 4:  {
				int r1, c1, r2, c2;
                cout << "Enter r1 and c1 for first matrix (A): ";
                cin >> r1 >> c1;
                cout << "Enter r2 and c2 for second matrix (B): ";
                cin >> r2 >> c2;

               // Dynamically allocate two matrices arr (A) and brr (B) based on input
               int** A = new int* [r1];
               for (int i = 0; i < r1; i++) {
                     A[i] = new int[c1];
               }
               int** B = new int* [r2];
               for (int i = 0; i < r2; i++) {
                     B[i] = new int[c2];
               }

               cout << "Enter elements for matrix A:" << endl;
               store(A, r1, c1);
               display(A, r1, c1);

               cout << "Enter elements for matrix B:" << endl;
               store(B, r2, c2);
               display(B, r2, c2);
               multiplication(A, B, r1, c1, r2, c2);
				break;
			}
			case 5:	
				exit(0);                
				break;
			default:
				cout<<"Invaliid choice!\n";	
		}
		
	}while(choice!=0);
	
	return 0;
		
}