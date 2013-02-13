#include <iostream>

using namespace std;

class queue{
	int size;
	int head;
	int tail;
	int * p;
	public:
		queue (int s = 16):size(s){
			p = new int[size];
			head = 0;
			tail = 0;
		}
		void add (int k){
			int tailn = tail + 1;
			if (tailn == size)
				tailn = 0;
			if ( tailn == head){
				int sizen = 2*size;
				int * pn = new int[sizen] ;
				//assign old array to new one
				for (int i = 0; i < size; i++){
					int pos = head + i;
					if (pos >= size)
						pos -= size;
					*(pn + i) = *(p + pos);
				}
				size = sizen;
				head = 0;
				tail = size - 1;
				*(pn + tail + 1) = k;
				tail = tail + 1;
			}
			else{
				*(p+tail) = k;
				tail = tailn;
			}
		}
		bool isEmpty () {
			return head == tail ;
		}

		int pop () {
			if (isEmpty())
				return -1;
			int rtn = *(p+head);
			head += 1;
			if (head == size)
				head -= size;
		}
		int top() {
			if (isEmpty())
				return -1;
			return *(p+head);
		}
};

int main(){
	int number = 10;
	queue * qp3 = new queue(32);
	queue * qp5 = new queue(32);
	queue * qp7 = new queue(32);
	qp3->add(3);
	qp5->add(5);
	qp7->add(7);
	int val = 1;
	cout<< val<< "\t";
	for (int i = 0; i < number; i++){
		val = min(qp3->top(), qp5->top());
		val = min(val, qp7->top());
		if (val == qp3->top()){
			qp3->pop();
			qp3->add(val*3);
			qp5->add(val*5);
			qp7->add(val*7);
		}
		else if (val == qp5->top()){
			qp5->pop();
			qp7->add(val*7);
		}
		else if (val == qp7->top())
			qp7->pop();
		cout << val<< "\t";	
	}
	cout<< endl;
}
