package org.Person;

import org.Film.Film;

import java.nio.file.Path;

public class Director extends Person {
    Film[] films;


    @Override
    public Film[] getFilms() {
        return films;
    }

    public Director(){
        super();
    }
    @Override
    public String getDBInsertPrerapedFMT() {
        return null;
    }

    @Override
    public void Save(Path path) {

    }
    public static Director Constructor(){ // TODO: Расписать логику создания строки
        return new Director();
    }

    @Override
    public void Load(Path path) {

    }
    public void GetStatistics(){

    }
}
