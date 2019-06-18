#ifndef _MATRIZ_H
#define _MATRIZ_H
#include <iostream>


typedef int MatrizData,    //nickname for int and int*
			*pMatrizData;

class Matriz{ 

 	std::string name;   
	MatrizData *data;	
	pMatrizData *rows;  //matrix form, using [][]
	int tam;            
private :

	void 
	init(int dim);   
	
	void
	free();			

public :

	Matriz(int dim,const char* lname); 
	
	Matriz(int dim);
	
	~Matriz();

	inline
	MatrizData
    Preencher(int pos, MatrizData n){   
		return data[pos] = n;
	}
	
	void
	Randmat(MatrizData n);    

	void
	Show();	

	void
	Assing(Matriz &a);   

	inline
	void
	operator=(Matriz a){ 
		Assing(a);
		
	}

	inline
	pMatrizData 
	operator[](int index){  
		return rows[index];
	}
	

	Matriz 
	Sum(Matriz &a);

	inline
	Matriz
	operator+(Matriz a){
		return Sum(a);
	}

	void 
	redim(int n);  //puts the dimension of the matrix parameter, in terms of who calls it;
	
	void 
	Transpose(); 

	Matriz
	Sub(Matriz &a);

	inline
	Matriz
	operator-(Matriz a){
		return Sub(a);
	}
		
	void Ord(int began, int end);
};



#endif
