#include<stdio.h>
#include<stdlib.h>


int powercalc(int base, int exp) {
	int ans = 1;
	for(int i=1; i<=exp; i++) {
		ans = ans * base;
	}
	return ans;
}

int find_gcd(int m,int n) {
	int maxi = (m>n) ? m : n;
	int gcd = 1;
	maxi = maxi + 5;
	int freq1[maxi],freq2[maxi];
	for(int i=0; i<maxi; i++) {
		freq1[i] = 0;
		freq2[i] = 0;
	}
	while (m % 2 == 0) { 
        freq1[2]++;
        m = m / 2; 
    }   
     
    for (int i = 3; i*i <= m; i = i + 2) {         
        while (m % i == 0) { 
            freq1[i]++; 
            m = m / i; 
        } 
    }  
    
    if (m > 2) 
        freq1[m]++; 

    
    while (n % 2 == 0) { 
        freq2[2]++;
        n = n / 2; 
    }   
     
    for (int i = 3; i*i <= n; i = i + 2) {         
        while (n % i == 0) { 
            freq2[i]++; 
            n = n / i; 
        } 
    }  
    
    if (n > 2) 
        freq2[n]++; 

    for(int i=2; i<maxi; i++) {
    	if(freq1[i] == 0 || freq2[i] == 0)
    		continue;
    	int mini = (freq1[i]<freq2[i]) ? freq1[i] : freq2[i];
    	//printf("i %d freq1[i]: %d freq2[i]: %d\n", i, freq1[i], freq2[i]);
    	gcd = gcd * powercalc(i,mini);
    }

    return gcd;
}

int main() {
	int m,n;
	printf("Enter the first number: \n");
	scanf("%d",&m);
	printf("Enter the second number: \n");
	scanf("%d",&n);

	int gcd = find_gcd(m,n);
	printf("GCD is: %d\n", gcd);
}