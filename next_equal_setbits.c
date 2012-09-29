/**
 *	next_equal_setbits
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Next smallest number greater than N having equal number of set bits
 *
**/

int next_equal_setbits( int N ){
	int K1 = N & -N;
	int M = N + K1;
	int K2 = M & -M;
	return K2 + ((K2/K1)>>1) - 1;
}
