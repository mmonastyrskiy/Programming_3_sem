package org.Terminal;
import org.Film.*;
import org.Person.*;
public class StaticVars {
    public static Film[] Films;
    public static Person[] persons;
    public static int PersonSize = 1000;
    public static int FilmSize = 1000;
    public static int PersonSizeptr = 0;
    public static int FilmSizeptr = 0;
    public static final String DB_name = "Java_IMDB_DB";
    public static final String url = "jdbc:postgresql://localhost/" +DB_name;
    public  static final String staff_table = "";
    public  static final String film_table = "";
    public  static final String series_table = "";
    public  static final String users_table = "";
}
