/**
 *	IO
 *	@author Vibhaj Rajan <vibhaj8@gmail.com>
 *
 *	@desc 
 *	Support structures for fast I/O in C++
 *
**/

class IO {
	private:
		static const int i_size = 512, o_size = 51200;
		int i_offset, i_max, o_offset;
		char *ibuffer, *obuffer;
		FILE *in, *out;
		
	public:
		IO(FILE *_in = stdin, FILE *_out = stdout): in(_in), out(_out) { 
			ibuffer = new char[ i_size ]; 
			obuffer = new char[ o_size ]; 
		}
		
		inline char read_char(){
			//return getc(in);
			if( ! ( i_offset ^ i_max ) ){
				i_max = fread( ibuffer, sizeof(char), i_size, in );
				i_offset = 0;
			}
			return ibuffer[ i_offset++ ];
		}
		
		inline int read_int(){
			char t = read_char();
			while( t < 48 ) t = read_char();
			
			int N = t-48;
			t = read_char();
			while( t > 47 ){
				N = N*10 + t - 48;
				t = read_char();
			}
			
			return N;
		}
		
		inline void flush(){
			fwrite( obuffer, sizeof(char), o_offset, out );
			o_offset = 0;
		}
		
		inline void write_char(char ch){
			if( ! ( o_offset ^ o_size ) )
				flush();
			obuffer[o_offset++] = ch;
		}
		
		inline void write_str( const char *str, int len ){
			if( o_offset + len > o_size )
				flush();
			for( const char* p = str; *p; p++ )
				obuffer[o_offset++] = *p;
		}
		
		inline void write_int(int v, char ch){
			if( o_offset + 11 > sizeof(obuffer) ) flush();
			if(ch) obuffer[o_offset++] = ch;
			if (v < 100000) {
				if (v < 1000) {
					if (v < 10) {
						obuffer[o_offset + 0] = v + 48;
						o_offset += 1;
					} else if (v < 100) {
						obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 0] = v + 48;
						o_offset += 2;
					} else {
						obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 0] = v + 48;
						o_offset += 3;
					}
				} else {
					if (v < 10000) {
						obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 0] = v + 48;
						o_offset += 4;
					} else {
						obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 0] = v + 48;
						o_offset += 5;
					}
				}
			} else {
				if (v < 100000000) {
					if (v < 1000000) {
						obuffer[o_offset + 5] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 0] = v + 48;
						o_offset += 6;
					} else if (v < 10000000) {
						obuffer[o_offset + 6] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 5] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 0] = v + 48;
						o_offset += 7;
					} else {
						obuffer[o_offset + 7] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 6] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 5] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 0] = v + 48;
						o_offset += 8;
					}
				} else {
					if (v < 1000000000) {
						obuffer[o_offset + 8] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 7] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 6] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 5] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 0] = v + 48;
						o_offset += 9;
					} else {
						obuffer[o_offset + 9] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 8] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 7] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 6] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 5] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
						obuffer[o_offset + 0] = v + 48;
						o_offset += 10;
					}
				}
			}
		}
};
