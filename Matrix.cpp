#include<iostream>
using namespace std;
int rows=0,columns=0;
int** create()
{
	cout<<"Enter number of rows:";
	cin>>rows;
	cout<<"Enter number of columns:";
	cin>>columns;
	int** array2D = 0;
    array2D = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
    	array2D[i] = new int[columns];
   	}
	int i,j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			cout<<"Enter ("<<i<<","<<j<<") element:";
			cin>>array2D[i][j];
		}
	}
	return array2D;
}
void display(int **matrix)
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}
int ** addition(int ** matrix1 , int ** matrix2)
{
	int i,j;
	int **array2D;
	array2D=new int*[rows];
	for(i=0;i<rows;i++)
	{
		array2D[i]=new int[columns];
	}
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			array2D[i][j]=matrix1[i][j]+matrix2[i][j];
		}
	}
	return array2D;
}
int ** multiplication(int ** matrix1 , int ** matrix2)
{
	if(rows==columns)
	{
		int i,j,k;
		int **array2D;
		array2D=new int*[rows];
		for(i=0;i<rows;i++)
		{
			array2D[i]=new int[columns];
		}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<columns;j++)
			{
				int sum=0;
				for(k=0;k<columns;k++)
				{
					sum=sum+((matrix1[i][k])*(matrix2[k][j]));
				}
				array2D[i][j]=sum;
			}
		}
		return array2D;
	}
	else
	{
		cout<<"Multiplication can not be calculated for given matrix.";
		return 0;
	}
}
int main()
{
	while(1)
	{
		int choice;
		int **matrix1;
		int **matrix2;
		int **resadd;
		int **resmul;
		cout<<endl<<endl<<endl;
		cout<<"Aryan Jain"<<endl;
		cout<<"1. Insertion"<<endl;
		cout<<"2. Addition"<<endl;
		cout<<"3. Multiplication"<<endl;
		cout<<"4. Display Matrixes"<<endl;
		cout<<"5. Display Addition Result"<<endl;
		cout<<"6. Display Multiplication Result"<<endl;
		cout<<"7. Exit"<<endl<<endl;
		cout<<"Enter choice:";
		cin>>choice;
		switch(choice)
		{
		case 1:
			{
				cout<<"For Matrix 1:"<<endl;
				matrix1=create();
				cout<<"For Matrix 2:"<<endl;
				matrix2=create();
				break;
			}
		case 2:
			{
				if(rows==0 && columns==0)
				{
					cout<<"Matrix Not Created Yet.";
					break;
				}
				resadd=addition(matrix1,matrix2);
				cout<<"Addition Done.";
				break;
			}
		case 3:
			{
				if(rows==0 && columns==0)
				{
					cout<<"Matrix Not Created Yet.";
					break;
				}
				resmul=multiplication(matrix1,matrix2);
				cout<<"Multiplication Done.";
				break;
			}
		case 4:
			{
				if(matrix1 == NULL || matrix2 == NULL)
				{
					cout<<"Matrix Not created yet";
					break;
				}
				cout<<"Elements of Matrix 1 are:"<<endl;
				display(matrix1);
				cout<<"Elements of Matrix 2 are:"<<endl;
				display(matrix2);
				break;
			}
		case 5:
			{
				cout<<"Added Matrix:"<<endl;
				display(resadd);
				break;
			}
		case 6:
			{
				cout<<"Multiplied Matrix:"<<endl;
				display(resmul);
				break;
			}
		case 7:
			{
				exit(1);
				break;
			}
		}
	}
	return 0;
}
