package org.Terminal;
import org.Film.*;
import org.Person.*;

import java.util.HashMap;
import java.util.Map;

public class StaticVars {
    public static Film[] Films = new Film[100];
    public static Person[] persons = new Person[100];
    public static final String DB_name = "Java_imdb_db";
    public static final String url = "jdbc:postgresql://localhost/" +DB_name;
    public  static final String staff_table = "";
    public  static final String film_table = "title_akas";
    public  static final String series_table = "title_akas";
    public  static final String users_table = "";
    public static final  String person_prefix = "ucp";
    public static int last_person = 0;


}
