#include <stdio.h>  
  
void bubble_sort(int arr[], int n) {  
  int i, j,count=0;  
  for (i = 0; i < n - 1; i++) {  
    for (j = 0; j < n - i - 1; j++) {
    count=count+1;  
      if (arr[j] > arr[j + 1]) {  
        int temp = arr[j];  
        arr[j] = arr[j + 1];  
        arr[j + 1] = temp;  
      }  
    }  
  } 
  printf("\n Operation Count :  %d\n",count); 
}  
int main() {  
  int arr[100];  
  printf("\n enter the size \n");
  int n;  
  scanf("%d",&n);
   printf("\n enter elements \n");
   for(int i=0;i<n;i++)
   	scanf("%d",&arr[i]);

  bubble_sort(arr, n);  
  printf("Sorted array: ");  
  for (int i = 0; i < n; i++) {  
    printf("%d ", arr[i]);  
  }  
  return 0;  
}  