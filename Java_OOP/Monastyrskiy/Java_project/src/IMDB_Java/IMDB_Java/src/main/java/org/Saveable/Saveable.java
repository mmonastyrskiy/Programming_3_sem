package org.Saveable;

import org.Film.Film;
import org.Person.Actor;
import org.Person.Director;
import org.Person.Person;
import org.Terminal.Terminal;

import java.io.IOException;
import java.nio.file.Path;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Arrays;

import static org.Terminal.StaticVars.*;

public interface Saveable {
    String getDBInsertPrerapedFMT();

    static void ObjCreator( ResultSet obj_data, Saveable[] data_array,int mode) {
    if (mode == 1){
        String id = null;
        String name = null;
        String birth = null;
        String death = null;
        String proffession = null;
        String tittles = null;
        try {
            int columns = obj_data.getMetaData().getColumnCount();
            int i;
            for(i=1; i<= columns;i++){
                switch (i) {
                    case 1: id = obj_data.getString(i);
                    case 2: name = obj_data.getString(i);
                    case 3: birth = obj_data.getString(i);
                    case 4: death = obj_data.getString(i);
                    case 5: proffession = obj_data.getString(i);
                    case 6: tittles = obj_data.getString(i);
                };
            }
            String[] a = {id,name,birth,death,proffession,tittles};
            if(Arrays.asList(proffession.split(",")).contains("director")){
                Director director = new Director(a);
                if(Arrays.asList(persons).contains(null)){
                    persons[Arrays.asList(persons).indexOf(null)] = director;
                }
                else {
                    persons=Arrays.copyOf(persons,persons.length+1);
                    persons[Arrays.asList(persons).indexOf(null)] = director;
                }
            }
            if(Arrays.asList(proffession.split(",")).contains("actor")){
                Actor actor = new Actor(a);
                if(Arrays.asList(persons).contains(null)){
                    persons[Arrays.asList(persons).indexOf(null)] = actor;
                }
                else {
                    persons=Arrays.copyOf(persons,persons.length+1);
                    persons[Arrays.asList(persons).indexOf(null)] = actor;
                }
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }


    }


        if (mode == 0){
            String id = null;
            String ordering = null;
            String name = null;
            String region = null;
            String language = null;
            String types = null;
            String attr = null;
            String isorig = null;

            try {
                int columns = obj_data.getMetaData().getColumnCount();
                int i;
                for(i=1; i<= columns;i++){
                    switch (i) {
                        case 1: id = obj_data.getString(i);
                        case 2: ordering = obj_data.getString(i);
                        case 3: name = obj_data.getString(i);
                        case 4: region = obj_data.getString(i);
                        case 5: language = obj_data.getString(i);
                        case 6: types = obj_data.getString(i);
                        case 7: attr = obj_data.getString(i);
                        case 8: isorig = obj_data.getString(i);
                    };
                }
                String[] a = {id,ordering,name,region,language,types,attr,isorig};
                Film f = new Film(a);
                if(Arrays.asList(Films).contains(null)){
                    Films[Arrays.asList(Films).indexOf(null)] = f;
                }
                else {
                    Films=Arrays.copyOf(Films,Films.length+1);
                    Films[Arrays.asList(Films).indexOf(null)] = f;
                }


            } catch (SQLException e) {
                throw new RuntimeException(e);
            }


        }

    }
    }
