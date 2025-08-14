#include<stdio.h>
int main()
{
int i;
int arr[5] = {1};
for (i = 0; i < 5; i++)
printf("%d",arr[i]);
return 0;
}
/* the answer would be 10000 because once the array is initialised with an integer all the other elements gets initialised to 0 but if the array 
is empty then all values will be garbage values as the C++ standard says:
If there are fewer initializers than elements, the remaining elements are value-initialized.
For basic types like int, value initialization means set to 0.*/
