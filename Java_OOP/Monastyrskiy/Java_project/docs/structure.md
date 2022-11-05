
##  Легенда:
"+ — public;"

"- — private;"

"# — protected;"

"~ — package."




```mermaid
classDiagram
    class Film{
    	+String id
    	+String orig_name
    	+String ru_name
    	+String[] janres
    	+int release_year
    	+float rating
    	+int ammount
    	+Director[] directors
    	+Writer[] writers
    	+Producer[] produsers
    	+Actor[] actors
    	toString()
    	getCharacters()
    	getAllTranslations()
    	

    }
    class Person{
    	+String person_id
    	+String name
    	Film[] Films
    	getfilms()

    }
    class Actor{
    	getCharacters()

    }
    Person <|--  Actor 

```