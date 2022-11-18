



```mermaid
classDiagram
    class Terminal{
    <<final>>
    +String Query
    +ParceQuery(query)
    +Save(query)
    +Load(query)
    +Search(query)
    +Stat(query)
    +add(query)
    +del(query)
    +quit()
    
    }
    
    class Film{
    	+String id
    	+String orig_name
    	+String ru_name
    	+String[] janres
    	+int release_year
    	+float rating
    	+int ammount_of_votes
    	+Director[] directors
    	+Actor[] actors
    	+toString()
    	+getCharacters()
    	+getAllTranslations()


    }
    class Series {
    <<final>>
    + String parent_id
    +Film[] episodes
    +int episodes
    +int end_year
    
    }
    class Person{
    	+String person_id
    	+String name
    	+Film[] Films
    	+Getfilms()
        +toString()
        +Addfilm(Film f)
        +DelFilm(Film m)
        

    }
    class Actor{
    	<<final>>
    	+getCharacters()
    	+toString()
        +GetStatistics()


    }
    class Director{
    <<final>>
    +GetStatistics()
    }
    
    class User {
    <<final>>
    RateFilm();
    +Auth()
    +GetFavoriteActors()
    +GetFavoriteJanres()
    
    }
    
    class Saveable {
    <<interface>>
    +Save()
    +Load()
    +Parse()
    }
    
    class Searcher{
    <<interface>>
    +SearchFilmsByJanres()
    +SearchFilmByRaiting()
    +SearchFilmByYear()
    +SearchFilmByActor()
    +SearchActorByFilm()
    +SearchActorByChar()
    +SearchDirectorByFilm()
    }
    class View{
    <<final>>
    +Film film
    +User viewer
    +int Rate
    +String date
    
    }
    
    Actor <|-- Person
    User <|-- Person
    Series <| -- Film
    Director <|-- Person
    Film <|.. Saveable
    Person <|.. Saveable
    Searcher <|.. Film
    Searcher <|.. Actor
    
    
    View o-- Film
    View o-- User
    

```
---
---

### Аннотация 
Класс **Terminal** является управляющим классом всего проекта, его методы направлены на вызов методов остальных классов, работу с внутренними данными и реализацию работы с пользователем посредством обработки консольно вводимых команд.

- Метод ***ParceQuery*** занимается первоначальной обработкой вводимых пользователем данных, отделяя запрашиваемые действия (**команды**) от **аргументов** и **ключей** к ним, а затем передает управление, вызывая требуемый метод. Также метод используется внутри любой другой функции класса **Terminal**, т. к. возвращает  переданные аргументы списком вида:
  ```java
  public String[] ParceQuery(String input)
  ["Ключ", "Значение",...]
  ```
  
 - Метод ***Save(String query)*** интерфейса **Saveable** содержит три перегруженных варианта.  Класс **Terminal** вызывает нужный, основывясь на запросе, переданным в строке *query*. 
 Операция вызывается в случае, если строка *query* содержит в себе команду **Save**.
 Первый вариант метода не принимает аргументы:
  ```java
  public boolean Save() // Первый вариант перегрузки
  ```
  В этом случае программа сохраняет все возможные данные классов, реализующих интерфейс **Saveable** в заранее определенные пути, из ~~конфигурационного файла?~~ 
  В противном случае, метод Save принимает в себя классы, реализующие интерфейс **Saveable**, и  путь к файлу. Если аргумент пути не указан, то используется стандартный путь из ~~Файла конфигурации?~~
  ```java
  public boolean Save(Saveable data, Path path) // Перегрузка с указанием пути
  public boolean Save(Saveable data) // Перегрузка с сохранением по стандартному пути
  ```
  Метод возвращает  **True**, если сохранение прошло успешно.
  
- Метод **Load()** интерфейса **Saveable** реализован тремя перегрузками с аналогичным методу **Save()** применением, но с обратным эффектом.  Вызывается в случае, если *query* содержит команду **Load**.
  ```java
  public boolean Load()
  public boolean Load(Saveable data, Path path)
  public boolean Load(Saveable data)
  ```
  
-  Метод **Search()** в качестве единственного **обязательного** параметра принимает строку-запрос для поиска.
 ```java
private void Search(String SearchFor)
   ```
 Он создает экземпляр класса **Searcher**, который реализует дальнейшую логику поиска по объектам и возвращение результата в основной код (или выводу его на экран). 
 
 Строкой поиска считается строка, которая идет после команды **Search** в строке *query*.

- Метод ***Stat()*** выводит статистику запрашиваемого человека, метод принимает в себя объект класса **Person**, для которого в дальнейшем вызывается метод **GetStatistics()** конкретного класса, дочернего классу **Person**, исключая класс **User**.
Работа метода основана на том, что все методы класса **Searcher** в качестве результата возвращают списки:
```java
Person[] или Film[]
```
Прототип метода **Stat**():
  ```java
private void Stat(Person p)
```
Вызов осуществляется при помощи команды **stat**, аргументом принимается индекс фильма/человека.

- Применение методов **add()** и **del()** является очевидным, они запускают мастер создания нового объекта любого типа или процесс удаления существующего соответственно:
```java
private void del()

private Series add()
private Film add()
private Actor add()
private User add()
private Director add()

```
Вызов осуществляется при помощи команд **del** и **add** без аргументов.

- Метод **quit()** используется для штатного завершения работы программы:
```java
private void quit()
```
Вызов: **q**

Класс **Searcher** является поисковиком, который поволяет искать фильмы или людей по нескольким параметрам:
для фильмов:
1. жанр
2. рейтинг
3. год
4. актеры

для людей:
1. фильм
2.  персонаж

 Таким образом, прототипы функций класса **Searcher**:
 ```java
public Film[] SearchFilmsByJanres(String query)
public Film[]SearchFilmByRaiting(String query)
public Film[]SearchFilmByYear(String query)
public Film[]SearchFilmByActor(String query)
public Person[]SearchActorByFilm(String query)
public Person[]SearchActorByChar(String query)
public Person[]SearchDirectorByFilm(String query)
```

-  Для класса **Actor** специально определен метод **getCharacters()**, который возвращает
  список персонажей актера.
 ```java
 public String[] getCharacters()
 public String[] getCharacters(Film film)
```

- Для класса **Actor** перегружен метод **toString()** с целью удобного вывода информации для пользователя в терминал, при помощи стандратных методов Java.

- Для класса **User** был определен метод **RateFilm()**, который предназначен для оценивания фильма пользователем по факту просмотра.
 ```java
 public void RateFilm(Film film)
```

- Метод **Auth()** используется для авторизации по логину и паролю, вводимому с терминала.
```java
public boolean Auth()
```

- Методы **GetFavoriteActors()** и **GetFavoriteJanres()** нужны для определения любимых актеров и жанров пользователя, основываясь на списке просмотренных им фильмов.
```java
public Actor[] GetFavoriteActors()
public String[] GetFavoriteJanres()
```

Пара классов **Film** и **Series** содержит множество разнообразных полей:

Для **Series**:

| **Поле**             	| **Значение**                                                  	|
|------------------	|-----------------------------------------------------------	|
| String parent_id 	| Id объекта класса фильм, который ассоциируется с сериалом 	|
| Film[] episodes  	| Список эпизодов сериала                                   	|
| int episodes     	| Кол-во эпизодов                                           	|
| int end_year     	| Год конца, -1, если нет                                   	|

Для **Film**:

| **Поле**                 	| **Значение**                    	|
|----------------------	|-----------------------------	|
| String id            	| Id объекта                  	|
| String orig_name     	| Оригинальное название       	|
| String ru_name       	| Русское название, если есть 	|
| String[] janres      	| Массив жанров               	|
| int release_year     	| Год выхода                  	|
| float rating         	| Рейтинг фильма              	|
| int ammount_of_votes  |  Кол-во голосов       	    |
| Director[] directors 	| Массив режиссеров            	|
| Actor[] actors       	| Массив актеров              	|

Класс **Series** наследует **Film**, благодаря этому методы, определенные для **Film**, актуальны и для него.

- Для **Film** определен метод **toString()**, который нужен для корректного вывода информации в терминал.

- Метод **getCharacters()** нужен для получения списка персонажей, учавствующих в фильме.
```java
public String[] getCharacters()
```

- Так как в базах данных один и тот же фильм может быть представлен в нескольких вариантах, был создан метод **getAllTranslations()**, который возвращает все переводы фильма.
```java
public String[] getAllTranslations()
```

Класс **Person** является родителем для **User**, **Actor**,**Director**, а значит, все поля и методы у этих классов общие.

| **Поле**             	| **Значение**       	|
|------------------	|----------------	|
| String person_id 	| Id объекта     	|
| String name      	| Имя            	|
| Film[] Films     	| Список фильмов 	|

Для класса **Person** определены методы:
- **Getfilms()**, который используется для получения списка фильмов у каждого актера, режиссера или пользователя.
```java
public Film[] Getfilms()
```

 - Применение метода **toString()** очевидно.
 
-  Методы **Addfilm()** и **Delfilm()** нужны для добавления фильма в массив *Films* любого экземпляра **Person** или его детей.
```java
public void Addfilm(Film f)
public void DelFilm(Film m)
```

- Метод **Parse()** интерфейса **Saveable** используется для того, чтобы разобрать файлы баз данных и создать экземпляры классов.
```java
public void Parse(Path FilmsFile, Path ActorsFile)
public void Parse()
```
Второй вариант функции использует пути к файлам из ~~Файла конфигурации?~~
