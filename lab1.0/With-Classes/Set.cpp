#include <header.h>

Set Set::operator|(const Set&B){
	Set C;
	memcpy(C.A, A, n);
	C.n = n;
	for(int i = 0; i < B.n; i++){
		bool f = true;
		for(int j = 0; j < n; j++)
			if(B.A[i] == A[j])
				f = false;
		if(f)
			C.A[C.n++] = B.A[i];
	}
	C.A[C.n] = 0;
	return C;
}

Set Set::operator&(const Set&B){
	Set C;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < B.n; j++)
				if(A[i] == B[j])
					C.A[C.n++] = A[i];
		}
	C.A[C.n] = '\n';
	return C;
}

Set Set::operator~(const Set&B){
	
}

void Set::print(){

}

Set::Set(char){

}

Set::Set(){

}

Set::Set(const Set&){

}

Set::Set operator = (const Set&){

}
