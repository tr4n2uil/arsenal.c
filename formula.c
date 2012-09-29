/**
 *	formula
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Mathematical formulae for problems
 *
 *	@formula01
 *	Given surface area S and permeter P of volume, find maximum volume V
 *
**/

B = ( P + 2 * sqrt( P * P - 3 * S ) ) / 3;
H = ( P - B ) / 2;
L = P - B - H;

V = L * B * H;

/**
 *
 *	@formula02
 *	Given N, find Nth fibonacci number
 *
**/

sqrt5 = sqrt( 5 );
phi = ( 1 + sqrt5 ) / 2.0;
fn = ( pow( phi, N ) - pow( 1 - phi, N ) ) / sqrt5;
fn = ( int ) fn;

/**
 *
 *	@formula03
 *	Given N, find Nth solution to Josephus problem with k = 2 ( Eliminate alternate in circle and find the winner )
 *
 *	@desc
 *	N = 2 ^ M + L
 *	FN = 2 * L + 1
 *
**/

int msb_setbit( int N ){
	int r = N;
	while( r = N & ( N - 1 ) ) N = r;
	return N;
}

fn = 2 * ( N - msb_setbit( N ) ) + 1 )
