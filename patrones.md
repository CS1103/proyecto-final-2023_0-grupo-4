## Patrones de diseño

### Builder

Si se esta implementando este patrón de diseño y lo podemos ver en "ButtonBuilder.cpp", se puede ver la 
definición de la clase ButtonBuilder, que define varios métodos de configuración que devuelven una referencia 
a la propia instancia en (*this). Esos métodos permiten establecer valores para los miembros de datos privados 
de la clase ButtonBuilder, como la posición (pos), el texto (text) y la textura (texture). La clase también 
define un método estático llamado DefaultButtonTexture() que devuelve una textura predeterminada para los 
botones.

En TextBoxBuilder, se define la clase TextBoxBuilder que también tiene varios métodos de configuración 
(Pos(), Size(), Text(), Validator()) que establecen valores para los miembros de datos privados de la clase. 
También contiene una función de validación (validator) que se utiliza para validar la entrada de texto.

En ambos casos, los métodos de configuración se encargan de configurar un objeto complejo 
(Button y TextBox, respectivamente) proporcionando valores para sus miembros de datos. 
Los métodos de configuración se pueden llamar en cualquier orden y se pueden omitir para utilizar valores 
predeterminados.
Además, la clase ButtonBuilder y TextBoxBuilder se derivan de otras clases 
(TextBuilder) y utilizan miembros de datos definidos en esas clases. Esto demuestra la flexibilidad del patrón 
Builder para permitir la configuración de objetos complejos que son subtipos de otros objetos complejos.
  

### Flyweight:

Muchas de las texturas son compartidas por todos los objetos que las usan

### Facade:

La clase vista controla todo aquello relacionado a la parte grafica con una simple interfaz.

### Mediator:

En el proyecto no se está utilizando el patrón de diseño Mediator.
Este patron de diseño se utiliza para reducir las dependencias entre objetos, de manera que cada objeto 
no necesite conocer directamente todos los demás objetos con los que se comunica. En su lugar, se 
utiliza un objeto mediador que se encarga de coordinar la comunicación entre los distintos objetos.
La clase View no tiene un objeto mediador ni se encarga de coordinar la comunicación entre distintos objetos, 
por lo que no se está utilizando el patrón Mediator.

### Command:

Sí, el proyecto implementa el patrón de diseño Command. El método "Solve" es el comando y tiene diferentes 
implementaciones dependiendo del tipo de algoritmo que se desea utilizar. La clase Bot es el invocador que 
ejecuta el comando y, en este caso, se encarga de buscar la solución a un laberinto utilizando diferentes 
algoritmos de búsqueda.
En el codigo Bot se utiliza una plantilla (template) que recibe como parámetro el tipo de algoritmo que se 
quiere utilizar. La plantilla está restringida a tipos que sean de la clase de algoritmos 
DFS (Depth-First Search) o BFS (Breadth-First Search), mediante la restricción de conceptos "IsDFSOrBFS<T>". 
El tipo de algoritmo se utiliza para seleccionar la estructura de datos adecuada para la frontera de búsqueda 
(queue o stack) y para seleccionar la implementación correcta de la función de comparación utilizada en la 
búsqueda A* o Greedy Best First Search (GBFS).

También, se utiliza la clase Compare, que es un functor que compara nodos o cuadros (squares) dependiendo 
del tipo de algoritmo utilizado. La clase Compare es una especialización parcial de la plantilla 
Bot::Compare para los tipos de algoritmos A* y GBFS, y se utiliza en la implementación correspondiente 
del método Solve.
