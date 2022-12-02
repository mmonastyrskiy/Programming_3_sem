package org.Film;
import org.Person.Actor;
import org.Person.Director;
import org.Saveable.Saveable;
public class Film implements Saveable{
    public String film_id;
    public String film_name;

    public int year;
    public String[] janres;
    public int Rating;
    public Actor[] actors;
    public Director[] directors;


   public Film() {
       

      
   }

   @Override
    public String getDBInsertPrerapedFMT() {


    }


    public static Film Constructor(){
    return new Film();

    }


}
