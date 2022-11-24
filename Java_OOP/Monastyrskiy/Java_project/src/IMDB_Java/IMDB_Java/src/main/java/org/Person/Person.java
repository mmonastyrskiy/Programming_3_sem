package org.Person;
import org.Film.Film;
import org.Saveable.Saveable;

 abstract  public class Person implements Saveable {
  String person_id;
  String name;


  public Film[] getFilms(){

   return new Film[0];
  }

 }

