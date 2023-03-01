<div align=center>
<img src="https://raw.githubusercontent.com/CS1103/proyecto-final-2023_0-grupo-4/main/readme/logo2.png" alt="Maze logo" height="600">
</div>


<div align="center">
<h1>MAZE GAME🐍</h1>
<p>
  Hola! 👨‍💻. Somos estudiantes del curso de Programación III de UTEC.  
  Hemos aplicado conocimientos aprendidos durante el curso de Programación para desarrollar el juego Maze en C++.
  </p>
</div>


<details open>
  <summary>Tabla de contenidos:</summary>
  <ol>
    <li><a href="#acerca-del-proyecto">
      Acerca del proyecto
      <ul>
        <li><a href="#descripción">Descripción</a></li>
        <li><a href="#características">Características</a></li>
        <li><a href="#tecnologías">Tecnologías</a></li>
        <li><a href="#temas-de-interés">Temas de interés</a></li>
        <li><a href="#algoritmos-y-contenedores-utilizados">Algoritmos y contenedores utilizados</a></li>
      </ul>
    </a></li>
    <li><a href="#instalación">
      Instalación
      <ul>
        <li><a href="#requisitos">Requisitos</a></li>
        <li><a href="#pasos-de-instalación">Pasos de instalación</a></li>
      </ul>
    </a></li>
    <li><a href="#instrucciones-de-uso">
      Instrucciones de uso
    </a></li>
    <li><a href="#licencia">
      Licencia
    </a></li>
    <li><a href="#diagrama">
      Diagramas
      <ul>
        <li><a href="#matriz-del-tablero">Matriz del Tablero</a></li>
      </ul>
    </a></li>
    <li><a href="#link-del-video">
      Link del video
    </a></li>
    <li><a href="#autores">
      Autores
    </a></li>
    <li><a href="#bibliografia">
      Bibliografía
    </a></li>
  </ol>
</details>

---

## Acerca del proyecto

### Descripción

Maze es un juego adictivo que tiene una fórmula clásica, debes deslizar y guiar al personaje a través del laberinto pero, ¡Cuidado! El tiempo puede estar corriendo. Tendrás que ser ágil al resolverlo para encontrar el camino adecuado para que llegue a su punto objetivo.

### Características

- Nuestro tablero es modificable.
- Tenemos dos opciones de juego: Bot y Human.
- Tiene timer.
- 4 Algoritmos distintos para el bot (DFS, BFS, GBFS, A*)

### Tecnologías

- Lenguaje de programación C++17 o posterior
- Librería raylib 
- Raylib-cpp (header only, fork)
- Doxyegn (documentación)

### Temas de interés

- El uso de raylib como interfaz gráfica.
- Algoritmos de busqueda
- Algoritmos de generación de laberintos perfectos (arboles de expansión minima)


### Algoritmos y contenedores utilizados

#### DFS (Depth First Search)
Este algoritmo emplea en su implementación el concepto de stack. Lo que hace es recorrer en su totalidad una estructura. 
Cada vez que se encuentra con dos o más caminos posibles, este recorrerá cada uno lo más profundamente posible, a la 
vez que almacena los nodos recorridos en un stack. Si alcanza un camino sin salida antes que el objetivo, este retrocede a 
la bifurcación anterior y repite el proceso. Este algoritmo, aunque puede cumplir con el objetivo, no es eficiente en lo 
absoluto, considerando que existen alternativas más eficientes.

<div align="center">
<img src="https://raw.githubusercontent.com/CS1103/proyecto-final-2023_0-grupo-4/main/readme/dfs.png" format=jpg&name=small" width="300px">
</div>


#### BFS(Breadth First Search)

Una búsqueda en anchura (BFS) es un algoritmo de búsqueda, recorre los nodos de un grafo, comenzando en la raíz para luego explorar todos los vecinos de este nodo. Además, para cada uno de los vecinos se exploran sus respectivos vecinos adyacentes, y así hasta que se recorra todo el grafo.

  BFS va formando un árbol a medida que va recorriendo un grafo y se usa para algoritmos en donde resulta crítico elegir el mejor camino posible en cada momento del recorrido.
  
  <div align="center">
<img src="https://raw.githubusercontent.com/CS1103/proyecto-final-2023_0-grupo-4/main/readme/bfs.png" format=jpg&name=small" width="500px">

</div>

#### GBFS (Greedy Best First Search)
Este es un algoritmo de búsqueda heurística, es decir, necesita información adicional específica relacionada con el 
problema a resolver. En el caso de un laberinto, lo que requiere es el número de casillas de distancia a la que se 
encuentra cada casilla del objetivo. Lo que el algoritmo GBFS busca es reducir este número conforme se mueve de casilla 
en casilla. Si alcanza un punto sin salida, retrocede de nuevo al último cruce. A pesar de siempre buscar la casilla 
más cercana al objetivo, no puede garantizar que el camino elegido será el más eficiente. 

<div align="center">
<img src="https://raw.githubusercontent.com/CS1103/proyecto-final-2023_0-grupo-4/main/readme/gbfs.png" format=jpg&name=small" width="500px">
</div>

#### A* Search Algorithm

Tenemos una celda inicial y una celda objetivo. Queremos llegar a la celda objetivo (si es posible) desde la celda inicial lo más rápido posible. Aquí A* Search Algorithm lo que hace es que, en cada paso, selecciona el nodo que le acorte o le permita llegar de manera más rapida u optimizada al punto de objetivo. Esto a menudo se denomina heurística, que no es más que una especie de suposición inteligente. Realmente no sabemos la distancia real hasta que encontramos el camino, porque todo tipo de cosas pueden estar en el camino.

<div align="center">
<img src="https://raw.githubusercontent.com/CS1103/proyecto-final-2023_0-grupo-4/main/readme/a_star.png" format=jpg&name=small" width="300px">
</div>

#### Wilsons

El algoritmo de Wilson utiliza caminatas aleatorias borradas en bucle para generar un árbol de expansión uniforme, una muestra imparcial de todos los árboles de expansión posibles. Este inicializa el laberinto con una celda de inicio arbitraria. Luego, se agrega una nueva celda al laberinto, iniciando una caminata aleatoria. La caminata aleatoria continúa hasta que se vuelve a conectar con el laberinto existente. Sin embargo, si la caminata aleatoria se cruza a sí misma, el bucle resultante se borra antes de que continúe la caminata aleatoria.

<div align="center">
<img src="https://raw.githubusercontent.com/CS1103/proyecto-final-2023_0-grupo-4/main/readme/wilsons.png" format=jpg&name=small" width="300px">
</div>

### Clases/funciones Templates

![Templates](https://raw.githubusercontent.com/CS1103/proyecto-final-2023_0-grupo-4/main/readme/templates.jpeg)

- Compare: función heuristica para GBFS/A*
- Solve: función para resolver el laberinto
- Class Game/GameBase: template en función del modo de juego 
- Utils::RandomNum: función robusta para generar aleatorios
- DrawAll: Función para dibujar caulquier tipo T con {T.Draw()}

## Instalación

### Requisitos

- Compilador compatible con c++20 o posterior
- Administrador de paquetes Cmake v3 o posterior
- Libreria raylib (previamente no incluida)

### Pasos de instalación

1. Clonación de repositorio con

```bash
git clone https://github.com/CS1103/proyecto-final-2023_0-grupo-4.git
cd proyecto-final-2023_0-grupo-4
mkdir build
cmake -B build
cd build
sudo make install
```

## Instrucciones de uso

- ejecutable Maze
  ```bash
  Maze
  ```
- Crear entrada de escritorio
  ```bash
  cd .. # Carpeta principal del repositorio
  cp Maze.desktop /usr/share/applications/
  ```


### Reglas de juego

#### Configuración

1. Elegir tamaño del tablero
2. Elegir modo de juego (Humano o computador)
3. Elegir limite de tiempo prendido o apagado

#### Jugabilidad

1. El laberinto tiene un punto inicial.

2. Luego, debes elegir un cuadrado adyacente, ya sea hacia adelante o hacia un lado. 

3. Continuas creando el camino que creas adecuado.

4. En caso llegues a un callejon sin salida, no podras avanzar, pero si retroceder.

5. Finalmente, al crear el camino correcto, llegarás al punto objetivo.


## Licencia

Distribuido bajo la licencia MIT. Ver [`LICENSE`](LICENSE) para más información.

## Diagrama

### Matriz del Tablero

![Matriz tablero](https://raw.githubusercontent.com/CS1103/proyecto-final-2023_0-grupo-4/main/readme/graph.png)

Decidimos usar una matriz como estructura de datos debido a que el laberinto es cuadrado 

## Link del video
[https://youtu.be/P9PDjKmyTfA](Video)

## Autores

- Camila Villasana Boggiano
- Diana Carolina Ñañez Andres
- Jaime Alfonso Ramos Talla
- Kevin Jonás Zevallos López
- Enrique Francisco Flores Teniente
- Luis Enrique Cortijo

## Bibliografía

- CS50 (2020). Search - Lecture 0 - CS50's Introduction to Artificial Intelligence with Python 2020 [https://cs50.harvard.edu/ai/2020/notes/0/](Search_algorithms)  
Utilizamos recursos provistos por un curso libre de harvard para aprender a fondo el funcionamiento de los distintos algoritmos de busqueda.

- Thee Buckblock (2011) - Jamis Buck
[https://weblog.jamisbuck.org/2011/1/20/maze-generation-wilson-s-algorithm](maze_generation)  
Utilizamos el block del desarrollador Jamis Buck para comparar y entender los diversos algorittmos de generación de laberintos existentes, en su block tiene multiples articulos para cada uno de los algoritmos junto con una comparación de ellos.

- Meyer's Singleto
[https://laristra.github.io/flecsi/src/developer-guide/patterns/meyers_singleton.html](meyers_singleton)  
En esta pagina encontramos un snipet para un singleto que nos llevo a entender más sobre el fiasco de inicialización y construir las funciónes estaticas de las texturas.

- Mejores prácticas para seguir con el proyecto y patrones de diseño para analizar.
Refactoring.Guru. (s. f.-b). Refactoring and Design Patterns. https://refactoring.guru/  
En esta pagina encontramos amplia información sobre refactoring, mejores practicas y, sobre todo, patrones de diseño.
La utilizamos principalemente para el análisis de patrones en [`patrones.md`](Patrones).

- Documentación de Raylib y Raylib-cpp  
[https://www.raylib.com/cheatsheet/cheatsheet.html](Raylib)  
[https://robloach.github.io/raylib-cpp/](Raylib-cpp)  
Documentación utilizada para la parte grafica del proyecto.



---

[Back To The Top](#readme-top)






