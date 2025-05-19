#include <stdio.h>
#include <math.h>
int compare_array(int arr1[],int arr2[],int size){
    int i=0;
    int m=1;
        for(i=0;i<size;i++){
           if(arr1[i]==arr2[i]){
            continue;
           }
           else{
            for(int k=0,j =size-1;k<size,j>=0;k++,j--){
                if(arr1[k]!=arr2[j]){
                    m=0;
                }
                else{
                    m=-1;
                }
            }
           }
        }
        return m;
    }
int main(){
    int n,a[100000],b[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    printf("%d\n",compare_array(a,b,n));
    return 0;
}