/**
 *	rmq_slider
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Support structures for Range Minimum/Maximum Query operations in Sliding Window in C++
 *
**/

class rmq_slider {
	private:
		const int SIZE = 400001;
		int *DQ, *Q, dq_front, dq_rear, q_front, q_rear;
	
	public:
		rmq_slider(int N): dq_front(0), dq_rear(-1), q_front(0), q_rear(-1) { DQ = new int[ N ]; Q = new int[ N ]; }
		~rmq_slider() { delete[] DQ; delete[] Q; }
	
		void push_min( int val ){
			if( ++q_rear > SIZE ){ 
				printf( "Overflow\n" );
				exit(-1);
			}
			
			while( dq_rear >= dq_front  && DQ[dq_rear] > val ){
				dq_rear--;
			}
			
			Q[q_rear] = val;
			DQ[++dq_rear] = val;
		}
		
		void push_max( int val ){
			if( ++q_rear > SIZE ){ 
				printf( "Overflow\n" );
				exit(-1);
			}
			
			while( dq_rear >= dq_front && DQ[dq_rear] < val ){
				dq_rear--;
			}
			
			Q[q_rear] = val;
			DQ[++dq_rear] = val;
		}
		
		int pop(){
			if( q_rear < q_front ){ 
				printf( "Underflow\n" );
				exit(-1);
			}
			
			int ret = Q[q_front++];
			if( ret == DQ[dq_front] ) dq_front++;
			return ret;
		}
		
		int head(){
			return DQ[dq_front];
		}
};
