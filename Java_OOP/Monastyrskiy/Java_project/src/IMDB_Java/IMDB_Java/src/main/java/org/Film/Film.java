package org.Film;
import org.Saveable.Saveable;

import java.nio.file.Path;

public class Film implements Saveable{
 public Film(String film_data){}

    @Override
    public String GetDBInsertPrerapedFMT() {
        return null;
    }

    @Override
    public void Save(Path path) {

    }

    @Override
    public void Load(Path path) {

    }


}
