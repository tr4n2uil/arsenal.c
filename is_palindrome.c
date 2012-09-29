/**
 *	is_palindrome
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Calculates whether N is a palindrome number
 *
**/

int is_palindrome( int N ){
	int p = 0, q = N;
	while( N ){
		p = p*10 + N%10;
		N /= 10;
	}
	return p == q;
}
