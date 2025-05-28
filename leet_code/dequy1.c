#include <stdio.h>
void convert(int N){
	if(N == 0) return;
	int b = N%2;
	convert(N/2);
	printf("%d",b);
}

int main(){
	int N; scanf("%d",&N);
	convert(N);
	return 0;
}