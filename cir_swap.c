/**
 *	cir_swap
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Swap circularly A = B, B = C, C = A
 *
**/

int cir_swap( int *A, int *B, int *C ){
	*A = *A ^ *B ^ *C ^ ( *B = *C ) ^ ( *C = *A );
}
