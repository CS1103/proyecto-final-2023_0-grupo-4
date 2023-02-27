<div style = "margin-left: 220px;">
<img src=https://previews.123rf.com/images/dimajarm/dimajarm1710/dimajarm171000024/88771180-logotipo-laberinto-laberinto-moderno-vector-s%C3%ADmbolo-icono-de-cubo-isom%C3%A9trica-para-juego-de.jpg height="450px">
</div>

<img src =https://img.shields.io/tokei/lines/github/CS1103/proyecto-final-2023_0-grupo-4?style=plastic>

<div align="center">
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
    <li><a href="#diagramas">
      Diagramas
      <ul>
        <li><a href="#grafo-del-tablero">Grafo del tablero-11x11</a></li>
        <li><a href="#diagrama-de-clases">Diagrama de clases</a></li>
      </ul>
    </a></li>
    <li><a href="#link-del-video">
      Link del video
    </a></li>
    <li><a href="#autores">
      Autores
    </a></li>
    <li><a href="#referencias-y-links">
      Referencias y links
    </a></li>
  </ol>
</details>




# TODO

### media:

#### square types
- ~~WALL~~
- ~~EMPTY~~
- ~~START~~
- ~~GOAL~~

#### Sprites
- ~~button background~~
- game background
- Different end screens
- ~~Bot image~~

#### Music

### Para investigar:

#### Search algorithms

- ~~DFG (Depth First Search)~~
- BFG (Breadth First Search)
- ~~GBFG (Greedy Best First Search)~~
- A*

#### Maze generation algorithms

- Kruskal
- Wilsons (chosen one)

#### Librerias
 
- raylib 
- raylib-cpp (header only, fork)

# Name of the project
> Additional information

A brief description of your project, what it is used for and how does life get awesome when someone starts to use it.

## Installing / Getting started

A quick introduction of the minimal setup you need to get a hello world up &
running.

### Building
```shell
git clone ESTE_REPO && cd ESTE_REPO
mkdir build && cd build
cmake ..
sudo make install
```
### running
```shell
./EXECUTABLE
```

## Features

What's all the bells and whistles this project can perform?
* What's the main functionality
* You can also do another thing
* If you get really randy, you can even do this

### Search algorithms
#### DFG (Depth First Search)
Este algoritmo emplea en su implementación el concepto de stack. Lo que hace es recorrer en su totalidad una estructura. 
Cada vez que se encuentra con dos o más caminos posibles, este recorrerá cada uno lo más profundamente posible, a la 
vez que almacena los nodos recorridos en un stack. Si alcanza un camino sin salida antes que el objetivo, este retrocede a 
la bifurcación anterior y repite el proceso. Este algoritmo, aunque puede cumplir con el objetivo, no es eficiente en lo 
absoluto, considerando que existen alternativas más eficientes. 

#### GBFS (Greedy Best First Search)
Este es un algoritmo de búsqueda heurística, es decir, necesita información adicional específica relacionada con el 
problema a resolver. En el caso de un laberinto, lo que requiere es el número de casillas de distancia a la que se 
encuentra cada casilla del objetivo. Lo que el algoritmo GBFS busca es reducir este número conforme se mueve de casilla 
en casilla. Si alcanza un punto sin salida, retrocede de nuevo al último cruce. A pesar de siempre buscar la casilla 
más cercana al objetivo, no puede garantizar que el camino elegido será el más eficiente. 

## Links

Even though this information can be found inside the project on machine-readable
format like in a .json file, it's good to include a summary of most useful
links to humans using your project. You can include links like:

- Project homepage: https://cs1103.github.io/proyecto-final-2023_0-grupo-4/
- Repository: https://github.com/CS1103/proyecto-final-2023_0-grupo-4
- Issue tracker: https://github.com/your/awesome-project/issues
  - In case of sensitive bugs like security vulnerabilities, please contact
    my@email.com directly instead of using issue tracker. We value your effort
    to improve the security and privacy of this project!
- Related projects:
  - Your other project: https://github.com/your/other-project/
  - Someone else's project: https://github.com/someones/awesome-project/



## Autores

- Camila Villasana Boggiano
- Diana Carolina Ñañez Andres
- Jaime Alfonso Ramos Talla
- Kevin Jonás Zevallos López
- Enrique Francisco Flores Teniente
- Luis Enrique Cortijo

## Bibliografía
- CS50 (2020). Search - Lecture 0 - CS50's Introduction to Artificial Intelligence with Python 2020 [Video]. Edx. https://youtu.be/WbzNRTTrX0g 

## Licensing

Distribuido bajo la licencia MIT. Ver [`LICENSE`](LICENSE) para más información.
