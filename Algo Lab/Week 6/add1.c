#include <stdio.h>
#include <stdlib.h>

int calc(int base, int exp) {
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	int res = 1;
	if(exp%2 == 1) {
		res = res*base;
		exp--;
	}
	int temp = calc(base,exp/2);
	res = res*temp*temp;
	return res;

}

int main() {
	int n,a;
	printf("Enter element and power: \n");
	scanf("%d%d",&a,&n);
	int ans = calc(a,n);
	printf("Result: %d\n",ans);
}
