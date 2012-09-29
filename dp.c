/**
 *	DP
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Dynamic Programming experiences
 *
 *	@dp01
 *	Knight: Move knight only right and maximize pawns captured
 *
**/

for( j = N; j--; ){
	for( i = 0; i ^ N; i++ ){
		k = 0;
		if( ( j + 1 ) < N && ( i - 2 ) >= 0 ) k = max( k, R[ i - 2 ][ j + 1 ] );
		if( ( j + 2 ) < N && ( i - 1 ) >= 0 ) k = max( k, R[ i - 1 ][ j + 2 ] );
		if( ( j + 2 ) < N && ( i + 1 ) < N ) k = max( k, R[ i + 1 ][ j + 2 ] );
		if( ( j + 1 ) < N && ( i + 2 ) < N ) k = max( k, R[ i + 2 ][ j + 1 ] );
		
		if( B[ i ][ j ] == 'K' ){
			printf( "%d\n", k );
			break;
		}
		
		R[ i ][ j ] = k + ( B[ i ][ j ] == 'P' );
	}
	
	if( i < N ) break;
}

/**
 *
 *	@dp02
 *	Paying Up: Pay amount using some coins with given denominations
 *
 *	@sentinel cost[ N ] = -1;
 *
**/

int check( int *cost, int amount ){
	if( *cost == -1 ) return 0;
	
	if( *cost == amount ) return 1;
	
	if( *cost < amount )
		return check( cost + 1, amount - *cost ) || check( cost + 1, amount );
	
	return 0;
}

/**
 *
 *	@dp03
 *	Summing Triangles: Move down or right one step to find maximum sum within a triangle of numbers
 *
**/

#define max( a, b ) ( ( a ) > ( b ) ? ( a ) : ( b ) )

for( int i = 1; i < N; i++ ){
	tr[ i ][ 0 ] += tr[ i - 1 ][ 0 ];
	tr[ i ][ i ] += tr[ i - 1 ][ i - 1 ];
}

for( int i = 2; i < N; i++ )
	for(int j = 1; j < i; j++){
		tr[ i ][ j ] += max( tr[ i - 1 ][ j], tr[ i - 1 ][ j - 1] );
	}

int max = -1;
for( int i = 0; i < N; i++ )
	if( max < tr[ N - 1 ][ i ] )
		max = tr[ N - 1 ][ i ];

