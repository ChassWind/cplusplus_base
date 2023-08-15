#include <iostream>
#include <cstdio>
void bubbleSort(int arr[],int len){
    for(int i = 0;i<len;++i){
        for(int j = 0;j<len-i-1;++j){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int arr[] = {7,5,6,1,2,3,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,len);
    for(int i = 0;i<len;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}