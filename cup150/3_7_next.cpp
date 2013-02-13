int getNextBig (int one){
	if (one == 0 || one + 1 == 0) return 0;
	int n = one;
	int b;
	int i = 0;
	int j = 0;
	while (n){
		b = n & 0x1;
		if (b != 0)
			i ++;
		if (!(b==1 && i != -1))
			j++;
	}
}
