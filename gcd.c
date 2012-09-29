/**
 *	gcd
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	GCD of A and B by Euclid's method
 *
**/

int gcd( int A, int B ){
	int t;
	while( B ){
		t = B;
		B = A % B;
		A = t;
	}
	return A;
}
