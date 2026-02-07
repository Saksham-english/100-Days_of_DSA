#include<stdio.h> 
int main()
{int n, left=0 ,right=0;
    printf("Enter the number of elements  ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements  ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    while(left>right)
    { int temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
    printf("Reversed array is  ");
    for(int i=0;i<n;i++)    {
        printf("%d ",arr[i]);
    }

    return 0;

}