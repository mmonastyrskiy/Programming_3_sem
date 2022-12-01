package org.Search;

import org.Saveable.Saveable;
import org.Searcher.Searcher;

public class Search implements Searcher {
    String[] query;
    public Search(){

    }

    public Saveable[] Search(String[] query) {
        this.query = query;


        }

    @Override
    public Saveable SearchFilmsByJanres() {
        return null;
    }

    @Override
    public Saveable SearchFilmByRaiting() {
        return null;
    }

    @Override
    public Saveable SearchFilmByYear() {
        return null;
    }

    @Override
    public Saveable SearchFilmByActor() {
        return null;
    }

    @Override
    public Saveable SearchActorByFilm() {
        return null;
    }

    @Override
    public Saveable SearchActorByChar() {
        return null;
    }

    @Override
    public Saveable SearchDirectorByFilm() {
        return null;
    }
}