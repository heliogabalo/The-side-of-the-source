// fuente http://www.youtube.com/watch?v=m5Ovn8b3ZQg

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
int main() {
int vector[5], i,j,aux;
cout << "Metodo de la burbuja" << endl;
cout << "Lectura del vector:" << endl;

for (i=0; i<=4; i++){
	cout << "Vector ["<<i<<"]: ";
	cin >> vector[i];
}
cout << "Vector desordenado: " << endl;
for (i=0; i<=4; i++){
	cout << vector[i] << "   ";
}

// Uso del metodo para ordenar.

for (i=0; i<=3; i++){
	for (j=i+1; j<=4; j++){
		if (vector[i]>vector[j]){
			aux=vector[j];
			vector[j]=vector[i];
			vector[i]=aux;
		} 
	}
}

// El vector ordenado

cout << endl;
cout << "El Vector ordenado es: " << endl;
for (i=0; i<=4; i++){
	cout << vector[i] << "	 ";
}

cout << endl;
system("pause");
}

