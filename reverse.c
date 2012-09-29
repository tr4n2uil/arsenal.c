/**
 *	reverse_bits
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Reverse the bits in N
 *
**/

unsigned int reverse_bits( unsigned int N ){
	// swap odd and even bits
	N = ( ( N >> 1 ) & 0x55555555 ) | ( ( N & 0x55555555 ) << 1 );
	// swap consecutive pairs
	N = ( ( N >> 2 ) & 0x33333333 ) | ( ( N & 0x33333333 ) << 2 );
	// swap nibbles ... 
	N = ( ( N >> 4 ) & 0x0F0F0F0F ) | ( ( N & 0x0F0F0F0F ) << 4 );
	// swap bytes
	N = ( ( N >> 8 ) & 0x00FF00FF ) | ( ( N & 0x00FF00FF ) << 8 );
	// swap 2-byte long pairs
	N = ( N >> 16 ) | ( N << 16 );
	
	return N;
}
