#include <iostream.h>
#include <string.h>
#include <stdlib.h>

void Merge(int* A, int  nA, int* B, int nB, int* C)
{ //Merge of massive A size nA
  //  and massive B size nB
  //  rezult write to C

    int a=0, b=0; 

    while( a+b < nA+nB ) 
    {
	if( (b>=nB) || ( (a<nA) && (A[a]<=B[b]) ) )
	{ 
	    C[a+b] = A[a];
	    ++a;
	} else { 
	    C[a+b] = B[b];
	    ++b;
	}
    }
}

void MergeSort(int* A, int n)
{
//Sorting massive A size n

    if( n < 2 ) return; 

    if( n == 2 ) 
    {            
	if( A[0] > A[1] ) { int t=A[0]; A[0]=A[1]; A[1]=t; }
	return;
    }

    MergeSort(A    , n/2  ); 
    MergeSort(A+n/2, n-n/2); 

    int* B= new int[n] ; 

    Merge(A,n/2, A+n/2,n-n/2, B); 

    for(int i=0; i<n; ++i) A[i]=B[i];

    delete[n] B; 
}

int main()
{
	int a[100];
	randomize();
	int i;
	for (i=0;i<100;i++)
	{
	  a[i]=random(100);
	}
	MergeSort(a, 100);

	for(i = 0; i < 100; i++)
		cout << a[i] << " ";

	cout << endl;

	return 0;
}
