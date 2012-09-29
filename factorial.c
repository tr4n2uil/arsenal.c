/**
 *	factorial
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Calculate factorial of N
 *
**/

#define SIZE 1000

int fact[ SIZE ];

int factorial( int N ){
	if( fact[ N ] ) return fact[ N ];
	
	if( N == 0 ) return fact[ N ] = 1;
	
	return fact[ N ] = N * factorial( N - 1 );
}

/**
 *
 *	@desc 
 *	Calculate trailing zeros in factorial of N
 *
**/

int tzeros_fact( int N ){
	int R = 0;
	
	while( N ){
		N /= 5;
		R += N;
	}
	
	return R;
}
