package org.Person;

import org.Film.Film;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.nio.file.Path;
import java.util.Arrays;

public class Director extends Person {
    Film[] films;

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

    public Director(){
        super();
    }
    @Override
    public String getDBInsertPrerapedFMT() {
        String s;
        StringBuilder info;
        info = new StringBuilder(person_id + ',' + name + ',');
        for(Film f: films){
            info.append(f.film_id).append(':');
        }
        info.substring(0,info.length()-1);
        s = "( " + info+ ")";
        return s;
    }

    @Override
    public void Save(Path path) throws IOException {
        FileOutputStream fo = new FileOutputStream(path.toFile());
        ObjectOutputStream obj = new ObjectOutputStream(fo);
        obj.writeObject(this);
        obj.close();

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
