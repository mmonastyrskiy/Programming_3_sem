
##  Легенда:
"+ — public;"

"- — private;"

"# — protected;"

"~ — package."




```mermaid
classDiagram
    class Terminal{
    <<User input>>
    +String Query
    +ExecQuery()
    }
    
    class Film{
    	<<final>>
    	+String id
    	+String orig_name
    	+String ru_name
    	+String[] janres
    	+int release_year
    	+float rating
    	+int ammount
    	+Person[] directors
    	+Person[] writers
    	+Person[] produsers
    	+Actor[] actors
    	+toString()
    	+getCharacters()
    	+getAllTranslations()


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
    class Prosucer{
    <<final>>
    +GetStatistics()
    }
    
    class User {
    <<final>>
    +GetFavoriteActors()
    +GetFavoriteJanres()
    
    }
    
    class Saveable {
    <<interface>>
    +Save()
    +Load()
    }
    
    class Searcher{
    <<final>>
    <<>>
    +SearchFilmsByJanres()
    +SearchFilmByRaiting()
    +SearchFilmByYear()
    +SearchFilmByActor()
    +ExecQuery()
    }
    
    Actor <|-- Person
    User <|-- Person
    Prosucer <|-- Person
    Film <|.. Saveable
    Person <|.. Saveable
    Searcher o-- Film
    
    
    Terminal --> Searcher
    Terminal --> Actor
    Terminal --> User
    Terminal --> Saveable
    Terminal --> Prosucer
     Terminal --> Person
      Terminal --> Film
    
    

```
