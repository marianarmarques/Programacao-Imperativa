#include <stdio.h>

//1.
float multInt1 (int n, float m){
	float r=0;

	while (n>0){
		r+=m;
		n--;
	}

	return r;
}

//2.
float multInt2 (int n, float m){
	float r=0;

	while (n>0){

		if (n%2 != 0) r+=m;

		n/=2;
		m*=2;
	}

	return r;
}

float multInt3 (int n, float m, int *count){
    float r=0;
   	*count = 0;

	while (n>0){

		if (n%2 != 0) r+=m;

		n/=2;
		m*=2;
		(*count)++;
	}

	return r;
}

//3
int mdc1 (int a, int b){
	int divisor, mdc=0;

	if (a<b){
		divisor=1;

		while(divisor<=a){
			if(a%divisor==0 && b%divisor==0) {
				mdc=divisor;
			}
		divisor++;
		}
	}
	else {
		divisor=1;

		while(divisor<=b){
			if(b%divisor==0 && a%divisor==0) {
				mdc=divisor;
			}
			divisor++;
		}
	}
	return mdc;
}

//4
int mdc2 (int a, int b){
	int mdc=0;

	while(a>0 && b>0) {

		if (a>b) {
			a-=b;
		} 

		if (a<b) {
			b-=a;
		}

		if (a==b) {
			mdc=a;
			break;
		}
	}
	return mdc;
}

int mdc3 (int a, int b, int *count){
    int mdc=0;
    *count=0;

	while(a>0 && b>0) {

		if (a>b) {
			a-=b;
		} 

		if (a<b) {
			b-=a;
		}

		if (a==b) {
			mdc=a;
			break;
		}
		(*count)++;
	}
	return mdc;
}

//5 --------------------------------



//6.a)
int fib1 (int n){
	if (n==0) return 0;
	if (n<=2) return 1;
	return fib(n-1) + fib(n-2);
}

//6.b) ------------------------------
