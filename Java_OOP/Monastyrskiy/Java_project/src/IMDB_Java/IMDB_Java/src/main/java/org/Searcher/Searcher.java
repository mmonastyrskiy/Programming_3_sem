package org.Searcher;

import org.Saveable.Saveable;

public interface Searcher {
Saveable SearchFilmsByJanres();
Saveable SearchFilmByRaiting();
Saveable SearchFilmByYear();
Saveable SearchFilmByActor();
Saveable SearchActorByFilm();
Saveable SearchActorByChar();
Saveable SearchDirectorByFilm();
}
