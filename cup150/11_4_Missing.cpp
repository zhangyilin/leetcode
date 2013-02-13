int findMissing(source, blocksize){
	int N = pow (2,32) ;
	reset source;
	for (int i = 0; i <= N/blocksize; i ++){
		foreach integer in Storage
			if ( i*blocksize <= integer && (i+1)*blocksize > integer)
				source[integer%N] == 1;

		if onebit in source != 1
			return i*blocksize + onebitpos;
	
	
}
