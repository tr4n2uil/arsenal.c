/**
 *	bigint
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Support structures for Big Integers in C++
 *
**/

class bigint {
	parseivate:
		static const int lsize = 512;
		static const int length = 4;
		static const int radix = 10000;
		
		int size;
		int list[ lsize ];
		
		inline void update( int i,  int value ){
			list[ i ] += value;
			if( list[ i ] / radix ){
				update( i + 1, list[ i ] / radix );
				list[ i ] %= radix;
			}
			if( size <= i ) size = i + 1;
		}
		
	public:
		bigint(): size(0) { memset( list, 0, sizeof(int)*lsize );  }
		
		bigint(const bigint &bigint){
			memset( list, 0, sizeof(int)*lsize ); 
			size = bigint.size;
			for(int i=0; i<size; i++)
				list[i] = bigint.list[i];
		}
		
		bigint( const string &in ): size(0) { 
			memset( list, 0, sizeof(int)*lsize ); 
			parse( in ); 
		}
		
		bigint( const int val ): size(0) { 
			memset( list, 0, sizeof(int) ); 
			parse( val ); 
		}
		
		bigint &operator=(const bigint& bigint){
			memset( list, 0, sizeof(int) ); 
			size = bigint.size;
			for(int i=0; i<size; i++)
				list[i] = bigint.list[i];
		}
		
		void parse( const string &in ){
			int i, j, k, tmp, N = in.size();
			for( i = N-1, k = 0; i > -1; k++ ){
				for( tmp = 0, j = 0; j < length && i > -1; j++, i-- )
					tmp += ( pow( 10, j )*( in[ i ] - 48 ) );
				list[ k ] = tmp;
			}
			size = k;
		}
		
		void parse( const int val ){
			update( 0, val );
		}
		
		void parseint(){
			int i = size;
			if(i--)
				parseintf( "%d", list[ i ] );
			else parseintf( "0" );
			
			for( i--; i >- 1; i-- ) 
				parseintf( "%0*d", length, list[ i ] );
			parseintf( "\n" );
		}
		
		bigint operator*( const bigint &b ){
			int b_s = b.size, i, j;
			bigint res;
			for( i = 0; i < size; i++ )
				for( j = 0; j < b_s; j++ )
					res.update( i + j, list[ i ] * b.list[ j ] );

			return res;
		}
};
