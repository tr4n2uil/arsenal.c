/**
 *	bin_search
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Binary search smallest V > K in array A from index l inclusive to h exclusive
 *
**/

int bin_search( int *A, int K, int l, int h ){
	int m;
	while( l < h ){
		m = l + ( h - l ) / 2;
		if( A[ m ] > K ){
			if( A[ m - 1 ] <= K )
				return m;
			else
				h = m - 1;
		}
		else
			l = m + 1;
	}
	return -1;
}
