enum CL {R, Y, G, B};
#define SIZE 4
void Hit (CL[] guess, CL[] solution){
	int rs = 0, ys = 0, gs = 0, bs = 0;
	for (int i = 0; i < SIZE; i++){
		if (solution[i] == R)
			rs ++;
		else if (solution[i] == Y)
			ys ++;
		else if (solution[i] == G)
			gs ++;
		else
			bs ++;
	}
	int hit = 0;
	for (int i = 0; i < SIZE; i++){
		if (solution[i] == guess[i])
			hit ++;
	}
}
