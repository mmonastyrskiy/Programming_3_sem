package org.Person;

import org.Film.Film;

import java.nio.file.Path;

public class User extends Person {
    Film[] films;

    @Override
    public String getDBInsertPrerapedFMT() {
        return null; // TODO
    }

    public void AddFilm(Film f){

    }
    public void Delfilm(Film f){

    }


    @Override
    public Film[] getFilms() {
        return films;
    }
    @Override
    public void Save(Path path) {

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
