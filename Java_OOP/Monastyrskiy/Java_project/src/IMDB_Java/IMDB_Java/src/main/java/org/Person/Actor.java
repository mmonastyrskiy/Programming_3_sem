package org.Person;

import org.Film.Film;
import org.Saveable.Saveable;

import java.nio.file.Path;

public class Actor extends Person implements Saveable {
    Film[] films;

    @Override
    public Film[] getFilms(){
        return  films;
    }

    @Override
    public String getDBInsertPrerapedFMT() {
        return null;
    }
    public Actor(){
        super();
    }
public static Actor Constructor(){ // TODO: Расписать логику создания строки
        return new Actor();
}
    @Override
    public void Save(Path path) {

    }

    @Override
    public void Load(Path path) {

    }
    public void GetStatistics(){

    }

    public void AddFilm(Film f){

    }
    public void DelFilm(Film f){

    }

}
