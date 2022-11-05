
##  Легенда:
"+ — public;"

"- — private;"

"# — protected;"

"~ — package."




```mermaid
classDiagram
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
    	+getfilms()

    }
    class Actor{
    	<<final>>
    	+getCharacters()
    	+toString()



    }
    Actor <|-- Person  

```