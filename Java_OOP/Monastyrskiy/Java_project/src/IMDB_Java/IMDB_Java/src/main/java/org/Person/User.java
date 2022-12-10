package org.Person;

import org.Film.Film;
import org.Terminal.Terminal;

import java.io.UnsupportedEncodingException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import java.util.Scanner;

import static org.Terminal.StaticVars.*;

public class User extends Person {
    Film[] films;
    byte[] passwd;


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
    public boolean Auth() throws NoSuchAlgorithmException,UnsupportedEncodingException {
        MessageDigest md = MessageDigest.getInstance("MD5");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter password: ");
        String inp = scanner.nextLine();
            if (md.digest(inp.getBytes("UTF-8")).equals((this.passwd))){
                return  true;
        }
        return false;
    }

    public void RateFilm(){
        int t = 0;
        for(Film f: films){
            System.out.println(t + f.toString());
            t++;
        }
        Scanner scanner = new Scanner(System.in);
        int idx = scanner.nextInt();
        RateFilm(this.films[idx]);
    }
    public void RateFilm(Film f){
        System.out.printf("Введите оценку: " );
        Scanner scanner =  new Scanner(System.in);
        float r = scanner.nextFloat();
        f.Rating = (f.Rating* f.ammount_of_votes + r)/f.ammount_of_votes+1;
        f.ammount_of_votes++;

    }
    public void AddFilm(Film f){
        if(Arrays.asList(this.films).contains(f)){
            System.out.printf("Already Exists");
        }
        if(Arrays.asList(this.films).contains(null)){
            this.films[Arrays.asList(this.films).indexOf(null)] = f;
        }
        else{
            films = Arrays.copyOf(films,films.length + 10);
            AddFilm(f);

        }

    }
    public void Delfilm(Film f){
        if(Arrays.asList(this.films).contains(f)) {
            this.films[Arrays.asList(films).indexOf(f)] = null;
        }

    }


    @Override
    public Film[] getFilms() {
        return films;
    }


    public User() throws UnsupportedEncodingException, NoSuchAlgorithmException {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Введите имя нового Пользователя");
        this.name = scanner.nextLine();
        this.films = new Film[0];
        this.person_id =person_prefix + Integer.toString(last_person);
        last_person++;
        String pw = scanner.nextLine();
        MessageDigest md = MessageDigest.getInstance("MD5");
        this.passwd = md.digest(pw.getBytes("UTF-8"));
    }
    public static User Constructor() throws UnsupportedEncodingException, NoSuchAlgorithmException {
        return new User();
    }
}
