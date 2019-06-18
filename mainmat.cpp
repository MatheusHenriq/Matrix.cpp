#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

using namespace std;

int main(){
	Matriz a(3,"A"),b(3,"B"),c(3,"C");


	srand(time(NULL));
	
	a.Randmat(100);
	a.Show();
	
	b.Randmat(100);
	b.Show();




	b.Ord(0,9);
	b.Show();

		
	
	return 0;
}

