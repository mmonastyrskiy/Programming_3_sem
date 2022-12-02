package org.Search;

import org.Film.Film;
import org.Person.Actor;
import org.Person.Director;
import org.Person.Person;
import org.Saveable.Saveable;
import org.Searcher.Searcher;

import java.util.Set;

import static org.Terminal.StaticVars.*;
public class Search implements Searcher {
    String[] query;
    Set<Saveable> results;
    public Search(){

    }

    public void Search(String[] query) {
        this.query = query;


        }

    @Override
    public void SearchFilmsByJanres() {
        for (Film f: Films){
            for(String j: f.janres){
                for(String word: query){
                    if(word.equalsIgnoreCase(j)){
                        results.add(f);
                    }
                }
            }
        }
    }

    @Override
    public void SearchFilmByRaiting() {
        for (Film f: Films){
                for(String word: query){
                    try{
                    if(Float.parseFloat(word) == f.Rating) {
                        results.add(f);
                    }
                    } catch (RuntimeException e) {
                        "".isEmpty();
                    }
                }
            }
        }

    @Override
    public void SearchFilmByYear() {
        for (Film f: Films){
            for(String word: query){
                try{
                    if(Integer.parseInt(word) == f.year) {
                        results.add(f);
                    }
                } catch (RuntimeException e) {
                    "".isEmpty();
                }
            }
        }
    }

    @Override
    public void SearchFilmByActor() {
        for (Film f: Films){
            for(Actor j: f.actors){
                for(String word: query){
                    if(word.equalsIgnoreCase(j.toString())){
                        results.add(f);
                    }
                }
            }
        }
    }

    @Override
    public void SearchActorByFilm() {
        for(String word: query){
            for(Film f: Films){
                for(Actor a: f.actors){
                    if(word.equalsIgnoreCase(f.film_name)){
                        results.add(a);
                    }
                }
            }

        }
    }

    @Override
    public void SearchActorByChar() {
        for(Person a:persons){
            if(a.getClass().equals(Actor.class)){
                for(String c: ((Actor) a).chars){
                    for(String word: query){
                        if(word.equalsIgnoreCase(c)){
                            results.add(a);
                        }
                    }
                }

            }

        }
    }

    @Override
    public void SearchDirectorByFilm() {
        for (Film f: Films){
            for(Director j: f.directors){
                for(String word: query){
                    if(word.equalsIgnoreCase(j.toString())){
                        results.add(f);
                    }
                }
            }
        }
    }
}