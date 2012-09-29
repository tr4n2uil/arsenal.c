/**
 *	add
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Add A and B without using mathematical operators
 *
**/

int add( int A, int B ){
	int C = 0;
	
	while( B ){
		C = A & B;
		A = A ^ B;
		B = C << 1;
	}
	
	return A;
}
