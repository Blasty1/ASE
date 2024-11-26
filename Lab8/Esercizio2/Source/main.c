#define RADIUS 5
extern int check_square(int, int, int);
extern float my_division(float *,float *);
extern int _Matrix_Coordinates;
extern int _ROWS;
extern int _COLUMNS;


int main(void){

	int index, x , y,dim = _ROWS *_COLUMNS;
	int* matrice=&_Matrix_Coordinates; //prendo l'indirizzo del primo valore della matrice
	volatile float partialResult;
	volatile float pi;
	float radiusPowered2= RADIUS*RADIUS;

	for(index=0; index < dim; index+=2)
	{
			x = *(matrice+index);
			y = *(matrice+index+1);
			partialResult +=check_square(x,y,RADIUS);
	}	
	
	pi=my_division((float *) &partialResult,&radiusPowered2);
	
	while(1);
}
