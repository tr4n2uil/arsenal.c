/**
 *	pow_mod
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Calculate B ^ E mod M using repeated squaring
 *
**/

#define MOD 1000000007

long long pow_mod( long long B, long long E, long long M ){
	long long R = 1LL;

	while( E > 0 ){
		if( E & 0x1 )
			R = R*B % M;
		E >>= 1;
		B = B*B % M;
	}
	
	return r;
}
