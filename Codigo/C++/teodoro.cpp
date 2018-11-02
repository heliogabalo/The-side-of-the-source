#include <iostream>
#include <iomanip>

using namespace std;

double iva(double p, double m){
	double i;
	i = (p * m)/100;

	return i;

}

int main(){
double precio;
double por;

 	cout << "escribe un precio: " << endl;
 	cin >> precio;
 	cout << "porcentaje de IVA: " << endl;
 	cin >> por;

 		if (por==0){ 	
			cout << "el iva es: "
				 << iva(precio, 16) << endl;
		}
		else {	
 			cout << "el iva es: " 
 				 << iva(precio, por) << endl;
 	}

}