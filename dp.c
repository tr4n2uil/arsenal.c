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

/**
 *
 *	@dp04
 *	Largest Non Consecutive Subsequence: Given a sequence of N integers, devise an algorithm to 
 *	find a sub-sequence S[] for which sum of its elements is maximum and such that S contains no two consecutive elements from input sequence
 *
**/

int largest_non_consecutive(int input[], int N, int output[]){
	int sum[ N ], k=0, i;

	sum[ 0 ] = input[ 0 ];

	if(input[ 1 ] > input[ 0 ]){
		sum[ 1 ] =  input[ 1 ];
		output[ k++ ] = input[ 1 ];
	}
	else {
		sum[ 1 ] =  input[ 0 ];
		output[ k++ ] = input[ 0 ];
	}

	for( i = 2; i ^ N; i++ ){
		if( sum[ i - 1 ] > input[ i ] + sum[ i - 2 ] ){
			sum[ i ] =  sum[ i - 1 ];
		}
		else {
			sum[ i ] = input[ i ] + sum[ i - 2 ];
			output[ k++ ] = input[ i ];
		}
	}

	return sum[ N - 1 ];
}

/**
 *
 *	@dp05
 *	Largest Non 3 Consecutive Subsequence: Given a sequence of N integers, devise an algorithm to 
 *	find a sub-sequence S[] for which sum of its elements is maximum and such that S contains no three consecutive elements from input sequence
 *
**/

int max_three(int[] input, int N){
	int sum[] = new int[ N + 2 ], i;
	
	sum[ 0 ] = 0;
	sum[ 1 ] = input[ 0 ];
	sum[ 2 ] = input[ 0 ] + input[ 1 ];
	
	for( i = 2; i ^ N; i++ ){
		sum[ i + 1 ] = max( input[ i ] + sum[ i - 1 ], input[ i ] + input[ i - 1 ] + sum[ i - 2 ]);
		sum[ i + 1 ] = max( sum[ i + 1 ], sum[ i ] );
	}

	return sum[ N ];
}
