package org.Person;

import org.Film.Film;

import java.nio.file.Path;

public class User extends Person {
    Film[] films;

    @Override
    public String GetDBInsertPrerapedFMT() {
        return null;
    }

    @Override
    public void Save(Path path) {

    }

    @Override
    public void Load(Path path) {

    }
}
