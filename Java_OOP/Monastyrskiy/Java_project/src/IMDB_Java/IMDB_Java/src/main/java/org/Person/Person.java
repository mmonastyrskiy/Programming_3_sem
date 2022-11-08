package org.Person;
import org.Film.Film;

 abstract  public class Person {
  String person_id;
  String name;
  Film[] films;



  public Film[] getFilms(){

   return new Film[0];
  };

}
class  User extends  Person {
    
}
class Director extends  Person{

}
class Actor extends  Person{

}

