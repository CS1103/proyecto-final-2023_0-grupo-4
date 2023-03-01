# Guion proyecto progra 3

## Introducción (máximo 20 segundos):

-Muy buenos días a todos, en esta oportunidad el grupo 4 del curso de programación 3 presentará el proyecto final MAZE, en este video tocaremos los siguientes puntos (eso se muestra con edición para ahorrar tiempo), ahora le doy la palabra a (integrante que sigue) que nos describirá las características de funcionamiento del proyecto.

## Descripción de las características de funcionamiento del proyecto (máximo 50 segundos):

- modos: 1 jugador y bot
- tamaño de laberinto modificable
- limite de tiempo para jugador

-Muchas gracias (integrante que hizo la introducción), el proyecto consiste en un juego de laberinto clasico realizado en c++. En primer lugar, el usuario debe configurar el tamaño del tablero, si desea jugar el mismo o si desea que un bot lo haga y, en caso eliga jugar el mismo, puede activar el modo contrareloj.
A continuación, generamos el laberinto perfecto mediante el uso del algoritmo de Wilson. Luego se colocan los puntos de entrada y meta de manera aleatoría e inicia el juego.
Para el modo de un jugaor, el juego termina al llegar a la meta.
Para el modo bot, el jugador puede elegir multiples veces que algoritmos desea que el bot utilize, en este caso, el juego no termina hasta que se cierra la ventana.

## Describir los algoritmos más importantes utilizados en el desarrollo (máximo 1 minuto):

El proyecto contiene 4 algoritmos de búsqueda y 2 algoritmos de generación del laberinto. El Depth First Search es un algoritmo el cual sigue un camino hasta llegar a su final y cuando no le quedan más caminos retrocede al ultimo nodo que posea caminos sin recorrer, así recursivamente o iterativamente hasta llegar a su destino.   El algoritmo Breadth First Search se diferencia del anterior porque este primero revisa todos los nodos adyacentes al punto inicial antes de pasar al siguiente y repetir el proceso hasta llegar al destino.

Los siguientes 2 algoritmos, Greedy Best First Search y A star, hace uso de una función euristica para determinar cual es el mejor camino a elegir, en nuestro proyecto usamos la distancia manhattan, la cual es un estimado de distancia de la posición actual a la meta. La diferencia entre estos 2 algoritmos es que el segundo tambien considera la cantidad de pasos que le tomo llegar a la posición actual, para asi evitar tomar caminos muy largos.

Para la generación del laberinto se utiliza el algoritmo Wilsons que funciona de la siguente manera:
Primero iniciamos el laberinto como un rectángulo cerrado, posteriormente se elige aleatoriamente el punto de partida y se elige un punto al azar no visitado, se inicia la caminata aleatoria hasta llegar al punto ya visitado, posteriormente se retrocede por el camino recorrido hasta llegar al punto de partida o a otro punto visitado anteriormente (de esta manera aseguramos que sea un laberinto perfecto) y se repite hasta haber visitado todas las celdas del laberinto. 
Un segundo algoritmo que consideramos es el de kruskal, que consiste en generar un arbol de expansión (no minimo) randomizado.

## Estructuras de datos:

- Stack, Queue, priority queue, unordered_set
- Vector2I

Principalmente el proyecto cuenta con 2 grandes grupos de estructuras de datos, los propios de la librería estándar “std::” y los que empleamos desde raylib, además de nuestra propia estructura **Vector2I** para la parte grafica. Por el lado de la librería estándar tenemos los que vimos en clase desde queue, vector, set, map, arrays, etc. Todo esto con el fin de optimizar el uso de contenedores a las necesidades especificas de cada tarea en el código fuente. Y por la parte de raylib tenemos principalmente rectangles, textures, color y Font, estos los explicaremos porque no son de conocimiento general en la clase. El rectangle crea una estructura que se representa como rectángulo, con alto, ancho y altura, para poder posicionar en la pantalla. El texture sirve para poder cargar texturas 2d en nuestro juego y pasar de una visualización tipo consola a una interfaz grafica. Color sirve para asignar colores usando la notación rbg como sus atributos y por ultimo Font es utilizado para las fuentes de texto del juego.

## Organización del código fuente:

Nuestro proyecto se divide principalmente en los siguientes módulos:
- Game: Encargado de la jugabilidad. Es decir, recibe la información de quien está jugando (un humano o el bot). Acto
seguido, si juega el bot, le otorgará a su funcionamiento el algoritmo de búsqueda seleccionado. Por el contrario, si 
juega un humano, habilitará los controles direccionales. 
- Bot: En resumen, se encarga de obtener y almacenar la solución de un laberinto. Tras recibir como entrada cualquiera 
de los 4 algoritmos, inicializará su funcionamiento. Almacenará por separado el camino recorrido y su solución, mientras 
que la vista es actualizada, aunque hablaré sobre eso más adelante. 
- Maze: Es el encargado de generar el laberinto en función de las entradas del usuario, como fue explicado en el punto 
anterior. Para ello, utilizamos un vector de vectores. Estos últimos almacenan objetos llamados square_type, divididos 
según su utilidad y comportamiento. 
- View: Encargado de la parte gráfica. Hace uso del patrón builder para generar los botones, entradas de texto y bloques
de texto. Además, muestra los menús y el laberinto. Su vista es actualizada tras cada movimiento, tanto del bot como del 
jugador humano. 

Mostrar funcionamiento (simplemente grabamos el juego funcionando)

## Conclusiones

Como podemos observar el programa cumple con todas las especificaciones mencionadas en el video, empleando los recursos de c++, sus librerías y los conocimientos adquiridos a lo largo del curso para generar este proyecto. Sumado a las diciplinas no propias de programación como es el trabajo en equipo y la gestión de equipos para el desarrollo del trabajo. Dando para nosotros un resultado satisfactorio.

## Recomendaciones:

