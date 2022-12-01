package org.Person;

import org.Film.Film;
import org.Saveable.Saveable;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import static org.Terminal.StaticVars.last_person;
import static org.Terminal.StaticVars.person_prefix;

public class Actor extends Person implements Saveable {
    Film[] films;

    @Override
    public Film[] getFilms(){
        return  films;
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
    public Actor(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Введите имя нового Режиссера");
        this.name = scanner.next();
        this.films = new Film[0];
        this.person_id =person_prefix + last_person;
        last_person++;
    }
public static Actor Constructor(){ // TODO: Расписать логику создания строки
        return new Actor();
}



    public void GetStatistics(){
        Map<Integer, Integer> ans = new HashMap<>();
        for (Film f : films){
            if(!(ans.containsKey(f.year))){
                ans.put(f.year,1);
            }
            else {
                ans.put(f.year,ans.get(f.year)+1);
            }

        }
        for(Integer tmp: ans.keySet()){
            String key = tmp.toString();
            String val = ans.get(tmp).toString();
            System.out.println(key + " : " + val);

        }
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
    public void DelFilm(Film f){
        this.films[Arrays.asList(films).indexOf(f)] = null;

    }

}
