/**
 *	is_prime
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Calculates whether N is a prime number
 *
**/

int is_prime( int N ){
    int r = 1, i, m = ( int ) sqrt( N );
    for( i = 3; i <= m && r; i += 2 )
        if( N % i == 0 )
           r = 0;
    return r;
}
