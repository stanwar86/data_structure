#include<iostream>
using namespace std;
int main(){
	const int size=5;
	int arr[size]={1,4,4,1,2};
	int k=1;
	
	    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
	for(int i=1;i<size;i++){
		if(arr[i]!=arr[k-1]){
		arr[k]=arr[i];
		++k;
		}
	}
	for(int i=0;i<k;i++){
		cout<<arr[i];
	}
}	
