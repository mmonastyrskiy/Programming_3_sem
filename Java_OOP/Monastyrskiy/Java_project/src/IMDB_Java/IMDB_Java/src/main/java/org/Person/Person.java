package org.Person;
import org.Film.Film;
import org.Saveable.Saveable;

import java.io.Serializable;

abstract  public class Person implements Saveable, Serializable {
  public String person_id;
  public String name;


  abstract public Film[] getFilms();
  @Override
  public String toString(){
   StringBuilder s = new StringBuilder(" Person id: " + person_id + "\n" + "name: " + name + "\n" + "Films: ");
   for (Film f : this.getFilms()){
    s.append(f.toString());
   }
   return s.toString();
  }

 }

