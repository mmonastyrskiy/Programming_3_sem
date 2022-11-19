package org.Terminal;
import org.Film.Film;
import org.Person.Person;
import org.Person.User;
import org.Saveable.*;

import java.io.Console;
import java.sql.*;
import java.util.Objects;
import java.util.Properties;
import java.util.Scanner;
import java.nio.file.*;

import static org.Terminal.StaticVars.*;

public class Terminal{
    public Terminal(){

    }
    private void SaveAll(){
        
    }
    private void quit(){
        SaveAll();
        System.exit(0);
    }

    private void Save(Saveable[] data, Path path){
        for(Saveable object: data){
            object.Save(path);
        }


    }
    private void Save() throws SQLException {
        System.out.print("Укажите путь для сохранения файла или введите sql для сохранения в БД: ");
        Scanner scanner = new Scanner(System.in);
        String pathS = scanner.nextLine();
        if (!Objects.equals(pathS, "sql")) {
            Path path = Paths.get(pathS);
            if (Files.exists(path)) {
                System.out.println("Файл уже существует, перезаписать?[Д/Н]");
                String t = scanner.nextLine();
                if (!(t.equalsIgnoreCase("Д") ||
                        t.equalsIgnoreCase("Y") || t.equalsIgnoreCase("Да") || t.equalsIgnoreCase("Yes"))) {
                    System.out.println("Отмена сохранения");
                    return;
                }
            }
            System.out.println("""
                    Укажите объект сохранения:
                    [1] фильмы
                    [2] актеры\s
                    """);
            int option = scanner.nextInt();
            switch (option) {
                case 1: {
                    Save(Films,path);
                }
                case 2: {
                    Save(persons,path);

                }
                default: {
                    System.out.println("Неизвестеая опция. Отмена сохранения");
                }
            }
        }
        else{
            System.out.println("Введите имя пользователя БД");
            Console c = System.console();
            String user = c.readLine();
            System.out.println("Введите пароль: ");
            String passwd = String.valueOf(c.readPassword());


            Properties properties = new Properties();
            properties.setProperty("user",user);
            properties.setProperty("password",passwd);
            properties.setProperty("ssl","false");
            Connection conn = DriverManager.getConnection(url,properties);



            System.out.println("""
                    Укажите объект сохранения:
                    [1] фильмы
                    [2] актеры\s
                    """);

            int option = scanner.nextInt();
            switch (option) {
                case 1: {
                    for(Film film:Films){
                        if(film.getClass().equals( org.Film.Series.class)){
                            PreparedStatement statement = conn.prepareStatement("INERT INTO " + series_table + " VALUES " + film.GetDBInsertPrerapedFMT());
                            statement.executeUpdate();
                            statement.close();
                        }
                        else {
                            PreparedStatement statement = conn.prepareStatement("INERT INTO " + film_table + " VALUES " + film.GetDBInsertPrerapedFMT());
                            statement.executeUpdate();
                            statement.close();
                        }
                    }
                    conn.close();
                }
                case 2: {
                    for (Person person: persons){
                        if(person.getClass().equals(User.class)){

                            PreparedStatement statement = conn.prepareStatement("INERT INTO " + users_table + " VALUES " + person.GetDBInsertPrerapedFMT());
                            statement.executeUpdate();
                            statement.close();
                        }
                        else {
                            PreparedStatement statement = conn.prepareStatement("INERT INTO " + staff_table + " VALUES " + person.GetDBInsertPrerapedFMT());
                            statement.executeUpdate();
                            statement.close();
                        }
                    }
                    conn.close();

                }
                default: {
                    System.out.println("Неизвестеая опция. Отмена сохранения");
                    conn.close();
                }
            }


        }
    }
    private void Load(String[] query){

    }
    private void Search(String[] query){


    }
    private void Stat(String[] query){

    }
    private void Add(String[] query){

    }
    private void Del(String[] query){

    }
    public String[] ParceQuery(String query) throws SQLException {
        String[] cmd = query.toLowerCase().split(" ");
        switch (cmd[0]){
            case "q":{quit();return cmd;}
            case "save":{Save();return cmd;}
            case "load":{Load(cmd);return cmd;}
            case "search":{Search(cmd);return cmd;}
            case "stat":{Stat(cmd); return  cmd;}
            case "add":{Add(cmd);return cmd;}
            case "del":{Del(cmd);return cmd;}
            default: return cmd;


        }
    }
}
