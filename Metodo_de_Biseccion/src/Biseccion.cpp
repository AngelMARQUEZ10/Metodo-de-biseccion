#include <iostream>
#include <iomanip> // setprecision
#include <cmath>
#define PRECISION 8
using namespace std;

double f(double x);
void imprimePuntos(double a, double b);


int main(){
	
	cout << setprecision(PRECISION); // Establecemos la precisión
	double a, b, Ite;
	float c[100];
	float ER[100];
	float er,tol,xr;
	char opc; 
	
	do{
		cout<<endl;
        cout<<"Hola te damos la bienvenida a nuestro programa el cual se encarga de realizar el calculo de las raices de una funcion\n"; 
        cout<<"por el metodo de biseccion.\n\n";
		cout<<"A continuacion podras selecionar el numero de la opcion por la que te gustaria encontrar la raiz de tu ecuacion\n";
        cout<<"1. Por iteraciones."<<endl;
		cout<<"2. Tolerancia del error relativo."<<endl;
		cout<<"3.-Salir"<<endl;
		cin>>opc;
		
		switch(opc){
			
			case'1':
				 cout << "\nIngrese el intervalo inicial [a, b]" << endl;
				 cout << "\na = ";
                 cin >> a;
                 cout << "b = ";
                 cin >> b;
                 
                 //tabular x y 
                 imprimePuntos(a, b);
                 cout << "\nEscoja el intervalo adecuado" << endl;
                 cout << "\na = ";
                 cin >> a;
                 cout << "b = ";
			   	 cin >> b;
				
				if (f(a) * f(b) > 0){
					cout << "\nNo se puede aplicar el metodo de la biseccion\n";
                    cout << "porque f(" << a << ") y f(" << b << ") tienes el mismo signo" << endl;
				}else{
				cout <<"\nIngresa el numero de iteraciones = ";
                cin >> Ite;
                cout << "\nIte.\ta\tb\tc\tf(c)\tER\t\n" << endl;
                c[0]=0;
                
                //ciclo para calcular la raiz 
				for (int i = 1; i <= Ite; i++){
		
					c[i] = (a + b) / 2.0;
					ER[i] = c[i] - c[i-1]; 
					cout << i << "\t" << a << "\t" << b << "\t" <<   c[i] << "\t" <<      f(c[i]) << "\t" <<                 ER[i] <<  endl;
					
					if((f(c[i])) <= 0){
						a = c[i];
					}else if(f(c[i]) >= 0){
						b = c[i];
					}if(i  >= Ite){
			        cout << "\n\nPara una iteracion " << Ite << " la raiz de f es " << c[i] << endl;
		         }
				}
			}
			break;
			
			case '2':
			
				
				case '3':
					cout<<endl<<"Adios";
				    break;
		            default: cout<<endl<<"Error de opcion";
		}
		
		
	}while(opc!='3'); 
	 
	 cin.get();
     cin.get();
     
   return 0;
	
}

double f(double x) 
{
   return pow(x,3)-7;
   //x*exp(x)-1;
   //pow(x,3)-7;//x*exp(x)-1;//pow(x,2) - 7 ;//funcion 1
        //pow(x,2) - cos(x)
        //pow(x,3)-x-3
}

#define INTERVALOS 6
void imprimePuntos(double a, double b)
{
   int puntos = INTERVALOS + 1;
   
   double ancho = (b - a) / INTERVALOS;
   
   cout << "\n";
   cout << "\tx\tf(c)\n" << endl;
   for (int i = 0; i < puntos; i++) {
      cout << "\t" << a << "\t" << f(a) << endl;
      a = a + ancho;
   }
}