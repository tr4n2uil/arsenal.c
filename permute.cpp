/**
 *	permute
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Generate all possible permutations of size K from a given string of length N
 *
**/

void swap( char *x, char *y ){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void select( char *input, int start, int N, char *selection, int length, int K, stack< string > &combinations ){
    if( start <= N ){
        if( length == K ){
            selection[ length ] = '\0';
            combinations.push( string( selection ) );
        }
        else {
            select( input, start + 1, N, selection, length, K, combinations );
            selection[ length ] = input[ start ];
            select( input, start + 1, N, selection, length + 1, K, combinations );
        }
    }
}

void permute( char *input, int index, int N, stack< string > &permutations )
{
   if( index == N )
        permutations.push( string( input ) );
   else {
        for( int i = index; i ^ N; i++ ){
            swap( input + index, input + i );
            permute( input, index + 1, N, permutations );
            swap( input + index, input + i );
        }
	}
}

void all_permutations( char *input, int K, stack< string > &permutations ){
    int N = strlen( input );
    stack< string > combinations;
    char *selection = new char[ K + 1 ];
    char *temp = new char[ K + 1 ];
    
    select( input, 0, N, selection, 0, K, combinations );
    while( ! combinations.empty() ){
        strcpy( temp, combinations.top().c_str() );
        permute( temp, 0, K, permutations );
        combinations.pop();
    }
}
