/* Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. 

Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left /**       */

//to delete an element from an array 

#include<stdio.h> 
int main()
{ int n;
    printf("Enter the number of elements ");
    scanf("%d",&n);

    int a[n];
    printf("Enter the elements ");
    for( int i=0;i<n;i++)
    {scanf("%d",&a[i]);
    }
    
    int pos ;
    printf("Enter the position to delete ");
    scanf("%d",&pos);

    //to delete the element
    for(int i=pos-1;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    //print the updated array
    printf("Updated array:\n");
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",a[i]);
    }



    
    

    

}
