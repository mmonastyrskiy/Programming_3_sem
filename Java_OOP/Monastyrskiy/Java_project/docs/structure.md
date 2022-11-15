
##  Легенда:
"+ — public;"

"- — private;"

"# — protected;"

"~ — package."




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
    +String passwd
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
    <<final>>
    +SearchFilmsByJanres()
    +SearchFilmByRaiting()
    +SearchFilmByYear()
    +SearchFilmByActor()
    }
    
    Actor <|-- Person
    User <|-- Person
    Series <| -- Film
    Director <|-- Person
    Film <|.. Saveable
    Person <|.. Saveable
    Searcher o-- Film
    
    
    Terminal --> Searcher
    Terminal --> Actor
    Terminal --> User
    Terminal --> Director
     Terminal --> Person
      Terminal --> Film
    
    

```
---
---
### Аннотация 
Класс **Terminal** является управляющим классом всего проекта, его методы направлены на вызов методов остальных классов, работу с внутренними данными и реализацию работы с пользователем посредством обработки консольно вводимых команд

- Метод ***ParceQuery*** Занимается первоначальной обработкой вводимых пользователем данных, отделяя запрашиваемые действия (**Команды**) от **аргументов** и **ключей** к ним, а затем передает управление, вызывая требуемый метод. Также метод используется внутри любой другой функции класса **Terminal**, т. к. возвращает список переданных аргументов в виде списка вида:
  ```java
  private String[] ParceQuery(String input)
  ["Ключ", "Значение",...];
  ```
 метод ***Save(String query)*** интерфейса **Saveable** содержит три перегруженных варианта.  Класс **Terminal** вызывает нужный, основывясь на запросе переданным в строке *query*, в случае, если строка *query* содержит в себе команду **Save**.
 
  **первый**, не принимает аргументы:
  ```java
  public boolean Save()
  ```
  в таком случае, программа сохраняет все возможные данные классов, реализующих интерфейс **Saveable** в заранее определенные пути, из ~~конфигурационного файла?~~ 
  в противном случае, метод Save принимает в себя классы, реализующие интерфейс **Saveable**, и  путь к файлу, если аргумент пути не указан, то используется стандартный путь из ~~Файла конфигурации?~~
  ```java
  public boolean Save(Saveable data, Path path)
  public boolean Save(Saveable data)
  ```
  Метод возвращает  **True** Если сохранение прошло успешно
  
- Метод ***Load()*** интерфейса **Saveable** реализован также 3 перегрузками с аналогичным методу **Save()** применением, однако обратным эффектом.  Вызывается в случае, если *query* содержит команду **Load**

  ```java
  public boolean Load()
  public boolean Load(Saveable data, Path path)
  public boolean Load(Saveable data)
  ```
-  Метод ***Search()*** в качестве единственного **Обязательного** параметра принимает строку-запрос для поиска
    ```java
    private void Search(String SearchFor)
    ```
    создает экземпляр класса **Searcher**, который реализует дальнейшую логику поиска по объектам и возвращению результата. в основной код. 
    Строкой поиска считается строка, которая идет после команды **Search** в строке *query*
    
- Метод ***Stat()*** выводит статистику запрашиваемого человека, метод принимает в себя объект класса **Person**, для которого в дальнейшем, вызывается метод **GetStatistics()** конкретного класса, дочернего классу **Person** иск. класс **User**
Работа метода основана на том, что все методы класса **Searcher** результатом возвращают
```java
Person[] или Film[]
```
Прототип ф-ии **Stat**():
  ```java
  private void Stat(Person p)
```
Вызов осуществляется при помози команды **stat**


Применение методов **add()** и **del()** является очевидным, они запускают мастер создания нового объекта любого типа или процесс удаления существующего соответственно т. о.
```java
private void del()

private Series add()
private Film add()
private Actor add()
private User add()
private Director add()

```

Метод **quit()** используется для штатного завершения работы программы
```java
private void quit()
```
