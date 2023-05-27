#include <iostream> // Biblioteca estándar para operaciones de entrada y salida.
#include <stack> // Biblioteca para usar el contenedor de pila (stack) de la biblioteca estándar.
#include <queue> // Biblioteca para usar el contenedor de cola (queue) de la biblioteca estándar.
#include <bits/stdc++.h> // Biblioteca que incluye todas las bibliotecas estándar de C++.
using namespace std;

// Función para ordenar una pila de enteros.
stack<int> stackSorter(stack<int> &unsortedStack)
{
    // Creación de una pila auxiliar para ayudar en la ordenación.
    stack<int> auxiliaryStack;
 
    // Mientras la pila sin ordenar no esté vacía...
    while (!unsortedStack.empty())
    {
        // Guardamos el valor superior de la pila sin ordenar en una variable temporal.
        int temporaryVal = unsortedStack.top();
        // Eliminamos el valor superior de la pila sin ordenar.
        unsortedStack.pop();
 
        // Mientras la pila auxiliar no esté vacía y su valor superior sea mayor que el valor temporal...
        while (!auxiliaryStack.empty() && auxiliaryStack.top() > temporaryVal)
        {
            // Pasamos el valor superior de la pila auxiliar a la pila sin ordenar.
            unsortedStack.push(auxiliaryStack.top());
            // Eliminamos el valor superior de la pila auxiliar.
            auxiliaryStack.pop();
        }
        // Añadimos el valor temporal a la pila auxiliar.
        auxiliaryStack.push(temporaryVal);
    }
 
    // Devolvemos la pila auxiliar, que ahora está ordenada.
    return auxiliaryStack;
}

// Función principal.
int main()
{
  int randomNum; // Número aleatorio para llenar la pila inicial.
  stack<int> initialStack; // Pila inicial sin ordenar.
  stack<int> sortedStack; // Pila ordenada.
  
  // Llenamos la pila inicial con números aleatorios.
  for(int index=0; index<11; index++){
      randomNum=rand() % 10;
      initialStack.push(randomNum);
      cout<<initialStack.top()<<endl; // Imprimimos cada número aleatorio generado.
    }
    cout<<endl; // Imprimimos una línea vacía para separar las pilas.
 
  // Ordenamos la pila inicial.
  sortedStack = stackSorter(initialStack);
  
  // Mientras la pila ordenada no esté vacía...
  while(!sortedStack.empty()) {
        // Imprimimos el valor superior de la pila ordenada.
        std::cout << sortedStack.top();
        // Eliminamos el valor superior de la pila ordenada.
        sortedStack.pop();  
    }   
}
