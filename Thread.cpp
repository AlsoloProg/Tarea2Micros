#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

int numero[400000]; // Creaciòn del array con una capacidad de 400000 elementos

void power(int min, int max) {// Funciòn para elevar cada elemento del array al cuadrado
				// min y max determinan el rango a trabajar
	int i = min; // Variable utilizada para el ciclo "for" siguiente
	for (i = min; i <= max; i++) { // Ciclo "for" que abarca el rango establecido
		numero[i] = (numero[i]) * numero[i]; // Se eleva al cuadrado el elemento del array
	}
}

int main()
{
	auto startTime = high_resolution_clock::now(); //Se inicializa un reloj
	int i = 0; // Variable para el ciclo "for" siguiente
	for (i; i <= 399999; i++) { // Ciclo "for" utilizado para "introducir" los valores iniciales
	// Dentro de cada espacio en el array "numero"
		numero[i] = i;
	}
	thread t1(power, 0, 99999);
	thread t2(power, 100000, 199999);
	thread t3(power, 200000, 299999);
	thread t4(power, 300000, 399999);
	// Se llama a la funciòn power haciendo uso de Threads, en donde se intrucen los 4
	// rangos distintos utilizados para cada Thread
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	// Joins para evitar que se sigan ejecutando comandos dentro del main() antes de que
	// se terminen de ejecutar los threads
	auto stopTime = high_resolution_clock::now(); // Se detiene el reloj
	auto duration = duration_cast <microseconds>(stopTime - startTime); // Se almacena el 
	// Resultado del reloj en una variable
	cout << "El programa duro " << duration.count() << " microsegundos en ejecucion."<< endl; // Se imprime la duraciòn total del programa
	cout << "El cuadrado de los primeros 4 elementos del arreglo corresponden a: " <<  endl << numero[0] << endl << numero[1] << endl << numero[2] << endl << numero[3] << endl;
} // Se imprimen los primeros 4 elementos dentro del array para verificar el funcionamiento
// Del programa implementado
