#include <stdio.h>
#define N 1000001
int a[N];
int n;
void swap(int i, int j){
  int t = a[i]; a[i] = a[j]; a[j] = t;
}
void heapify(int i, int n){
  int L = 2*i; int R = 2*i+1; int maxIdx = i;
  if(L <= n && a[maxIdx] < a[L]) maxIdx = L;
  if(R <= n && a[maxIdx] < a[R]) maxIdx = R;
  if(maxIdx != i){
    swap(i, maxIdx); heapify(maxIdx, n);
  }
}
void buildHeap(){
  for(int i = n/2; i >= 1; i--) heapify(i,n);
}
void heapSort(){
  buildHeap();
  for(int i = n; i >= 2; i--){ swap(1,i); heapify(1,i-1); }
}
int main(){
  scanf("%d",&n);
  for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
  heapSort();
  for(int i = 1; i <= n; i++) printf("%d ",a[i]);
	return 0;
}