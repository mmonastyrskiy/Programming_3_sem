package org.Film;
import org.Saveable.Saveable;

import java.nio.file.Path;

public class Film implements Saveable{
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

    @Override
    public void Load(Path path) {

    }
    public static Film Constructor(){ // TODO: Расписать логику создания строки
    return new Film();

    }


}
