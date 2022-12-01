package org.Film;
import org.Saveable.Saveable;
import org.Film.Series;

public class Film implements Saveable{
    public String film_id;
    public int year;
 public Film(String film_data){

 }

   public Film() {

      
   }

   @Override
    public String getDBInsertPrerapedFMT() {
        return null;
    }


    public static Film Constructor(){
    return new Film("");

    }


}
