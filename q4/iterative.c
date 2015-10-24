#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int[], int);

int main()
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	int len = sizeof(a)/sizeof(a[0]);
	printf("largest sum = %d\n",maxSubArray(a,len));
    	return 0;
}

int maxSubArray(int arr[],int n){
	int max_so_far = 0;
	int max_ending_here = 0;
	int i;
	for(i=0; i<n; i++){
		max_ending_here = max_ending_here + arr[i];
		if(max_ending_here < 0)
			max_ending_here = 0;
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}

	return max_so_far;
}
