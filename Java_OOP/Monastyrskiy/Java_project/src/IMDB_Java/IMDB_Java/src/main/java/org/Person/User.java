package org.Person;

import org.Film.Film;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.nio.file.Path;
import java.util.Arrays;

public class User extends Person {
    Film[] films;

    @Override
    public String getDBInsertPrerapedFMT() {
        return null; // TODO
    }

    public void AddFilm(Film f){
        if(Arrays.asList(this.films).contains(null)){
            this.films[Arrays.asList(this.films).indexOf(null)] = f;
        }
        else{
            films = Arrays.copyOf(films,films.length + 10);
            AddFilm(f);

        }

    }
    public void Delfilm(Film f){
        this.films[Arrays.asList(films).indexOf(f)] = null;

    }


    @Override
    public Film[] getFilms() {
        return films;
    }
    @Override
    public void Save(Path path) throws IOException {
        FileOutputStream fo = new FileOutputStream(path.toFile());
        ObjectOutputStream obj = new ObjectOutputStream(fo);
        obj.writeObject(this);
        obj.close();
    }

    @Override
    public void Load(Path path) {

    }
    public User(){
        super();
    }
    public static User Constructor(){
        return new User(); // TODO
    }
}
