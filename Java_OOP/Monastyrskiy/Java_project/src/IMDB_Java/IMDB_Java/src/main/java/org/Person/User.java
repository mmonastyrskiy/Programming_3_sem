package org.Person;

import org.Film.Film;

import java.util.Arrays;
import java.util.Scanner;

import static org.Terminal.StaticVars.last_person;
import static org.Terminal.StaticVars.person_prefix;

public class User extends Person {
    Film[] films;

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


    public User(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Введите имя нового Режиссера");
        this.name = scanner.next();
        this.films = new Film[0];
        this.person_id =person_prefix + Integer.toString(last_person);
        last_person++;
    }
    public static User Constructor(){
        return new User(); // TODO
    }
}
