# Análisis de patrones de diseño

## Builder:

  El patron de diseño *Builder* consiste en implementar una interfaz para facilitar la creación de objetos complejos, en nuestro proyecto, el patron se utiliza para la creación de botones, cajas de texto y títulos.

  Tenemos 3 clases builder en el proyecto: *ButtonBuilder*, *TextBoxBuilder* y *TextBuilder*, estas clases
  definen varios métodos de configuración que devuelven una referencia 
  a la propia instancia (*this). Además, permiten establecer valores para los miembros de datos privados 
  de la clase ButtonBuilder de manera que se puedan concatenar uno con otro sin importar el orden.

  Los metodos implementados en ButtonBuilder son: Pos(), Text(), Texture(), FontSize() y Color().  
  La clase TextBoxBuilder implementa los metodos Pos(), Size(), Text() y Validator().  
  Por ultimo, la clase TextBuilder implementa los metodos Font(), Text(), FontSize() y Color().  

  Además de los Builders, tenemos un conjunto de funciones utilitarias que contienen configuraciones por defecto para los builder mas usados en el proyecto.

  ##### ViewUtils.cpp

  ###### Uso de la clase builder
  ``` cpp
  TextBoxBuilder DefaultTextBox(const rl::Vector2 &_pos, const rl::Vector2 &_size,
               std::function<bool(const std::string &)> _validator) {
  static TextBoxBuilder default_text_box = TextBoxBuilder();
  return default_text_box.Pos(_pos)
      .Size(_size)
      .Text(DefaultTextBoxText())
      .Validator(std::move(_validator));
  }
  ```

  ##### ButtonBuilder.hpp

  ###### Implementación de los metodos builder para Button
  ``` cpp
  ButtonBuilder &Text(const std::string &text);
  ButtonBuilder &Text(const rl::Text &text);

  ButtonBuilder &Texture(raylib::Texture &texture);

  ButtonBuilder &FontSize(const float &size);
  ButtonBuilder &Color(const rl::Color &color);
  ```



  
## Singleton:

  El patron de diseño *singleton* consiste en una clase que permite unicamente una instancia de objeto existente a la vez.  
  En el presente proyecto tenemos multiples texturas que debemos cargar en la memoria del GPU; 
  sin embargo, esta memoria es limitada, especialmente en maquinas de bajas caracteristicas.
  Por ello, implementamos una función estatica para cada una de las texturas, la cual actua como un 
  Singleton de [Meyer's](https://laristra.github.io/flecsi/src/developer-guide/patterns/meyers_singleton.html 
  "Meyer's singleton example").

  ##### Builders/TextBuilder.hpp:

  ```cpp
  inline static rl::Font &DefaultTextFont() {
      static rl::Font font{DEFAULT_TEXT_FONT_PATH.data(), // NOLINT
                           DEFAULT_FONT_SIZE};
      return font;
    }
  ```

  #### Motivación:

  Decidimos implementarlo como una función para que el singleton se inicialize de manera tardía 
  (Lazy initialization), y de esa manera evitar el fiasco de inicialización estatica.

## Mediator:

  Este patron de diseño se utiliza para reducir las dependencias entre objetos, de manera que cada objeto 
  no necesite conocer directamente todos los demás objetos con los que se comunica. En su lugar, se 
  utiliza un objeto mediador que se encarga de coordinar la comunicación entre los distintos objetos.

  En nuestro proyecto no tenemos ninguna clase mediator; sin embargo, tenemos multiples clases con buen encapsulamiento, lo que nos permite simplificar el código dentro de el archivo *main.cpp* y la funcionalidad del juego dentro del metodo **Game::run**. Además, **Game** es una clase template que funciona de manera distinta en función del tipo de jugador (Humano o computador).

##### main.cpp
```cpp
int main() {

  View view;

  view.StartScreen();
  Config settings = view.GetConfig();

  if (settings.playerT == PLAYER_TYPE::HUMAN) {

    Game<PLAYER_TYPE::HUMAN> game(settings, view);
    game.Run();

  } else {

    Game<PLAYER_TYPE::COMPUTER> game(settings, view);
    game.Run();

  }
}

```
##### Game.cpp
###### Funcionalidad del juego para humanos
```cpp
void Game<PLAYER_TYPE::HUMAN>::Run() {
  r_view.LoadMaze(m_maze.GetMaze(), m_maze.GetStart(), m_maze.GetGoal());
  r_view.HumanMode();
}

```
  
## Command:

  El patron de diseño **Command** consiste en transformar una petición en un objeto que contenga toda la información de dicha petición.


  En el proyecto implementa la clase Bot, la cual, a traves del metodo invocador *Bot::Solve* se encarga de buscar la solución a un laberinto utilizando diferentes 
  algoritmos de búsqueda y almacenar las casillas buscadas y la solución optima en 2 atributos tipo *std::queue* para facilitar su acceso en orden *FIFO*.

  La clase solve es una función template que acepta como parametro el tipo de metodo a usar en la solución, este puede ser **DFS**, **BFS**, **GBFS** o **A\***.

##### Bot.hpp 
###### Metodos de la clase Bot
``` cpp
  template <ALGORITHM T>
    requires IsDFSOrBFS<T> bool
  Solve(const Maze &maze);

  template <ALGORITHM T>
    requires IsGBFSOrA_STAR<T> 
  bool Solve(const Maze &maze);


  [[nodiscard]] std::queue<square> GetSolution() const;
  [[nodiscard]] std::queue<square> GetSearchedPath() const;

```


## Flyweight:


  Leer:
  https://stackoverflow.com/questions/16750758/what-are-the-practical-use-differences-between-flyweight-vs-singleton-patterns

  Explicar: ¿Porque no estamos usando el patron singleton en el código?
  (tenemos muchos singletons)




## Facade:

  La clase vista controla todo aquello relacionado a la parte grafica con una simple interfaz.

