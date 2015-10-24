#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int[], int, int);
int max(int a, int b){ return (((a) > (b))? (a): (b)); }

int main()
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	int len = sizeof(a)/sizeof(a[0]);
	printf("largest sum = %d\n",maxSubArray(a,0,len-1));
    	return 0;
}

int maxSubArray(int array[],int low,int high){
     	/* No element in the array */
     	if (low > high)  
        	return 0;
     	/* One element in the array */
     	if (low == high) 
        	return max(0, array[low]);
     	/* Two element in the array */
       	if (high-low == 1)
		return array[low]+array[high];
     	/* Middle element of the array */   
     	int middle = (low + high) / 2;
    
     	/* find maximum sum crossing to left */
     	int leftMax = 0;
	int sum = 0;
	int i;
     	for (i = middle; i >= low; i--) {
        	sum += array[i];
        	if (sum > leftMax)
      	      		leftMax = sum;
     	}
    
     	/* find maximum sum crossing to right */
     	int rightMax = 0;
	sum = 0;
     	for (i = middle+1; i <= high; i++) {
        	sum += array[i];
        	if (sum > rightMax)
            		rightMax = sum;
     	}	
     
     	/* Return the maximum of leftMax, rightMax and their sum(cross) */
     	return max(leftMax + rightMax, 
     max(maxSubArray(array, low, middle), maxSubArray(array, middle+1, high)));
}

