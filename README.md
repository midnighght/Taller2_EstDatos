# Taller 2 Estructura de Datos
Integrantes: 
* Maximo Sarno Jiménez  21853202-0  maximo.sarno@alumnos.ucn.cl  C1
* Itzel Acuña Machuca   27067365-1  itzel.acuna@alumnos.ucn.cl   C1
* Danilo Lucero Rivera  21548694-K  danilo.lucero@alumnos.ucn.cl C2

## Resumen

Este proyecto implementa un algoritmo Minimax, y su version optimizada con Poda Alfa-Beta para jugar Tres en Línea (Tambien conocido como Gato y Tic-Tac-Toe) de manera óptima. El objetivo es demostrar como se pueden tomar en tiempo real las mejores decisiones de acuerdo a cierto parametro.

### Estructura del Programa
- **main.cpp**: Gestiona el menu y opciones de juego.
- **Board.cpp**: Representa y manipula el estado del tablero durtante el juego.
- **ATS.cpp**: Automated Tic-Tac-Toe System. Implementación de algoritmo Minimax.
- **ATOS.cpp**: Automated Tic-Tac-Toe Optimized System. Implementación de optimización Poda Alfa-Beta.

### Cómo ejecutar
1. **Abrir la terminal dentro de la carpeta del repositorio**

2. **Comando de compilacion**
   ```bash
    g++ -o main .\Board.cpp .\ATS.cpp .\ATOS.cpp .\main.cpp
   ```
3. **Ejecute el programa**
    ```
      .\main.exe
    ```

## Explicación
El algoritmo Minimax explora los posibles siguientes movimientos, asignandole un valor a cada resultado. En este caso, un valor de 10 o -10 dependiendo de que jugador gane, o un valor de 0 si se empata. El Minimizer busca el valor mas bajo, mientras que el maximizer el mas alto.

Por ejemplo, un posible caso donde es el turno del Maximizer, y hay dos casos posibles donde el juego termina con su victoria (valor de 10), pero una de estas tiene una profundidad de 2 y la otra de 4. Para encontrar no solo una buena jugada, sino la mejor de ellas, le restamos la profundidad del nodo evaluado. El agoritmo escogerá la primera, pues 10-2 es mayor que 10-4.

La poda Alfa-Beta optimiza el algoritmo Minimax reduciendo el número de nodos que se evalúan en el árbol de decisiones, al descartar ramas que no pueden influir en el resultado final. Esto lo hace guardando el mejor caso hasta el momento para cada jugador, si la rama que esta siendo explorado llega al punto donde seria un peor caso posible, se descarta instantáneamente.

### Ejemplo de Arbol

```
                                     X | O | X
                                     - | O | O
                                     - | X | -
                 +---------------------------+-------------------+
                 |                           |                   |
             X | O | X                   X | O | X           X | O | X
             X | O | O                   - | O | O           - | O | O
             - | X | -                   X | X | -           - | X | X
         +---------------+                   +--------...        +--------...
         |               |                   |                   |
     X | O | X       X | O | X           X | O | X           X | O | X
     X | O | O       X | O | O           O | O | O           O | O | O
     O | X | -       - | X | O           X | X | -           - | X | X
         +               +                  v=-10               v=-10    
         |               |   
     X | O | X       X | O | X  
     X | O | O       X | O | O  
     O | X | X       X | X | O  
        v=0             v=10
```

### Complejidad Temporal

La complejidad temporal del algoritmo Minimax sin optimizaciones es	``` O(b^d) ```, donde:
- b: Número de ramas posibles por nodo.
- d: Profundidad del árbol.
Utilizando la técnica de optimizacion de poda Alfa-Beta obtenemos que el mejor caso tiene una complejidad temporarl ``` O(b^(d/2)) ```. (El peor caso siendo la misma complejidad que Minimax no optimizado).