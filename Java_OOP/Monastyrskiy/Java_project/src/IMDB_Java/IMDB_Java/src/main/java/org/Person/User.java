package org.Person;

import org.Film.Film;

import java.nio.file.Path;

public class User extends Person {
    Film[] films;

    @Override
    public String getDBInsertPrerapedFMT() {
        return null; // TODO
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
