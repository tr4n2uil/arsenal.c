/**
 *	cnt_setbits
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Count the set bits in N
 *
**/

int cnt_setbit( int N ){
	int r = N ? 1 : 0;
	while( N = N & ( N - 1 ) ) r++;
	return r;
}
