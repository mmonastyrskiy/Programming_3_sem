package org.Film;

import org.Person.Actor;
import org.Person.Director;
import org.Person.Person;
import org.Saveable.Saveable;

import java.util.Arrays;
import java.util.Scanner;

import static org.Terminal.StaticVars.persons;
/* Код был написан Дрюковой Анастасией Ивановной С21-703*/
public class Film implements Saveable{
    public String film_id;
    public String film_name;

    public int year;
    public String[] janres;
    public float Rating;
    public int ammount_of_votes;
    public Actor[] actors;
    public Director[] directors;


   public Film() {
       actors = new Actor[10];
       janres = new String[3];
       directors = new Director[10];
       Scanner scanner = new Scanner(System.in);
       System.out.println("Введите индентификатор фильма: ");
       this.film_id = scanner.nextLine();
       System.out.println("Введите название фильма: ");
       this.film_name = scanner.nextLine();
       System.out.println("Введите год создания фильма: ");
       this.year = scanner.nextInt();
       this.Rating = 0;
       this.ammount_of_votes = 0;
       System.out.println("Введите жанры фильма: ");
       janres = scanner.nextLine().split(" ");
       System.out.println("Введите айди актеров: ");
       for(String a: scanner.nextLine().split(" ")){
           for (Person actor:persons){
               if(actor != null && actor.person_id.equalsIgnoreCase(a)){
                   if(Arrays.asList(actors).contains(null)){
                       actors[Arrays.asList(actors).indexOf(null)] = (Actor) actor;
                   }
                   else {
                       actors = Arrays.copyOf(actors,actors.length+10);
                       actors[Arrays.asList(actors).indexOf(null)] = (Actor) actor;

                   }
               }
           }
       }


       System.out.println("Введите айди режиссеров: ");
       for(String a: scanner.nextLine().split(" ")){
           for (Person director:persons){
               if(director!= null&& director.person_id.equalsIgnoreCase(a)){
                   if(Arrays.asList(directors).contains(null)){
                       directors[Arrays.asList(directors).indexOf(null)] = (Director) director;
                   }
                   else {
                       directors = Arrays.copyOf(directors,directors.length+10);
                       directors[Arrays.asList(directors).indexOf(null)] = (Director) director;

                   }
               }
           }
       }





   }

    public Film(String[] arr){

    }

   @Override
    public String getDBInsertPrerapedFMT() {
       StringBuilder info = new StringBuilder();
       info.append(film_id);
       info.append(',');
       info.append(film_name);
       info.append(',');
       info.append(year);
       info.append("'");
       for(String s: janres){
           info.append(s+",");

       }
       info.substring(0,info.length()-1);
       info.append("'");
       info.append(",");
       info.append(Rating);
       info.append(",");
       for(Actor s: actors){
           info.append(s.person_id+",");

       }
       info.substring(0,info.length()-1);

       for(Director s: directors){
           info.append(s.person_id+",");

       }
       info.substring(0,info.length()-1);

       return "(" + info + ")";




    }

    @Override
    public String toString() {
       return this.film_name;
    }

    public static Film Constructor(){
    return new Film();

    }


}
