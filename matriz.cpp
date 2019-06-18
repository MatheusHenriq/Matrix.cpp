#include <iostream>
#include "matriz.h"
#include <stdlib.h>
#include <time.h>
 
void Matriz::init(int dim){

	tam = dim;
	data = new MatrizData[tam*tam];
	rows = new pMatrizData[tam];
	
	

	for(int i=0 ;i<tam; i++){
		rows[i] = data + i*tam; //rows[i] point to start of every line, and u can use [][] to find an element
	}	

} 

Matriz::Matriz(int dim,const char* lname){

	init(dim);
	name = lname;

	
} 

Matriz::Matriz(int dim){

	init(dim);
	
}



Matriz::~Matriz(){
	
	delete[] data;
	delete[] rows;

}

void Matriz::Randmat(MatrizData n){

	for(int i=0;i<tam*tam;i++){
		data[i] = rand() % n;	
	}
	

}

void Matriz::Show(){
	
	std::cout<<"\t"<<name<<std::endl;

	for(int l=0; l<tam ; l++){
		for(int c=0; c<tam ; c++){
			std::cout<<	rows[l][c]<<"\t";
		}
	
		std::cout<<std::endl;
	}
	
	std::cout<<std::endl;
}



void Matriz::Assing(Matriz &a){
	
	for(int i=0;i<tam*tam;i++){
		data[i]=a.data[i];
	}
	 
}

Matriz Matriz::Sum(Matriz &a){
	
	a.redim(tam);
	Matriz b(tam);	
	
	for(int i=0; i<tam*tam; i++){
		b.data[i]= (data[i] + a.data[i]);		
	}
	
	return b;
		
}

void Matriz::free(){
	
	delete[] rows;
	delete[] data;
	
	tam  = 0;
	rows = NULL;
	data = NULL;
				
}

void Matriz::redim(int n){

	if(tam == n)
		return;
	
	free();

	tam = n;
	data = new MatrizData[tam*tam];
	rows = new pMatrizData[tam];

	for(int i=0;i<tam;i++)
		rows[i] = data + i*tam;
}

void Matriz::Transpose(){

	Matriz aux(tam);
	
	for(int i=0; i<tam*tam; i++){
		aux.data[i] = data[i]; 
	}	

	for(int l=0; l<tam; l++){

		for(int c=0; c<tam; c++){
			rows[l][c] = aux.rows[c][l];
		
		}
	}

	name = name + "'"; 
}

Matriz Matriz::Sub(Matriz &a){

	Matriz aux(tam);

	for(int l=0; l<tam; l++){
		for(int c=0; c<tam; c++){
			aux.rows[l][c] = rows[l][c] - a.rows[l][c];
		}				
	}

	return aux;

}

void Matriz::Ord(int began ,int end){  //QuickSort
	
	
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = data[(began + end) / 2];
	while(i <= j)
	{
		while(data[i] < pivo && i < end)
		{
			i++;
		}
		while(data[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = data[i];
			data[i] = data[j];
			data[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		Ord(began, j+1);
	if(i < end)
		Ord(i, end);
	
	
}

