/**
 *	compare
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Function callback for qsort
 *
**/

int compare (const void * a, const void * b){
  return ( *(int*) a - *(int*) b );
}
