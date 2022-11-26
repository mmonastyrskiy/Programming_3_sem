package org.Film;
import org.Saveable.Saveable;

import java.nio.file.Path;
public class Film implements Saveable{
    public String film_id;
    public int year;
 public Film(String film_data){}

   public Film() {
      
   }

   @Override
    public String getDBInsertPrerapedFMT() {
        return null;
    }

    @Override
    public void Save(Path path) {

    }
    public static Film Constructor(){ // TODO: Расписать логику создания строки
    return new Film();

    }


}
