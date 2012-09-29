/**
 *	catalan_mod
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Calculate Nth Catalan number mod M
 *
**/

#define SIZE 1000

int cat[ SIZE ];

int catalan_mod( int N, int M ){
	int i, r = 1;
	if( cat[ N ] ) return cat[ N ];
	
	for( i = 1; i ^ N; i++ ){
		r += catalan( i, M ) * catalan( N - i, M );
		r %= M;
	}
	
	return cat[ N ] = r;
}
