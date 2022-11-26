package org.Terminal;
import org.Film.Film;
import org.Person.Actor;
import org.Person.Director;
import org.Person.Person;
import org.Person.User;
import org.Saveable.*;
import org.Search.Search;


import java.io.Console;
import java.io.FileNotFoundException;
import java.sql.*;
import java.util.Arrays;
import java.util.Objects;
import java.util.Properties;
import java.util.Scanner;
import java.nio.file.*;

import static org.Terminal.StaticVars.*;

public class Terminal{
    public Terminal(){   //Конструктор класса терминал

    }
    private void quit(){
        System.exit(0); // Выход с кодом 0
    }

    private void Save(Saveable[] data, Path path){ // перегрузка функции для сохранения массива data по пути path, за счет вызова ф-ии Save интерфейса Saveable.
        for(Saveable object: data){
            object.Save(path);
        }


    }
    private void Save() throws SQLException { // перегрузка, для основного запуска сохранения
        System.out.print("Укажите путь для сохранения файла или введите sql для сохранения в БД: ");
        Scanner scanner = new Scanner(System.in);
        String pathS = scanner.nextLine(); // считываем строку, адрес файла в который будем писать
        if (!Objects.equals(pathS, "sql")) { // В случае если вместо пути введено sql, то записываем в БД
            Path path = Paths.get(pathS);
            if (Files.exists(path)) { // Проверяем, что файл существует, если да предлагаем перезаписать.
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
                    [2] люди\s
                    """);
            int option = scanner.nextInt();
            switch (option) { //Запускаем сохранение нужных элементов
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
            System.out.println("Введите имя пользователя БД"); // В случае если выбран вариант сохранения в БД, устанавливаем настройки
            Console c = System.console();
            String user = c.readLine();
            System.out.println("Введите пароль: ");
            String passwd = String.valueOf(c.readPassword());


            Properties properties = new Properties();
            properties.setProperty("user",user);
            properties.setProperty("password",passwd);
            properties.setProperty("ssl","false");
            Connection conn = DriverManager.getConnection(url,properties); // подключаемся



            System.out.println("""
                    Укажите объект сохранения:
                    [1] фильмы
                    [2] люди\s
                    """);

            int option = scanner.nextInt(); // Выбираем что сохранять
            switch (option) {
                case 1: {
                    for(Film film:Films){
                        if(film.getClass().equals( org.Film.Series.class)){
                            PreparedStatement statement = conn.prepareStatement("INERT INTO " + series_table + " VALUES " + film.getDBInsertPrerapedFMT());
                            statement.executeUpdate(); // Выполняем запросы
                            statement.close();
                        }
                        else {
                            PreparedStatement statement = conn.prepareStatement("INERT INTO " + film_table + " VALUES " + film.getDBInsertPrerapedFMT());
                            statement.executeUpdate();
                            statement.close();
                        }
                    }
                    conn.close();
                }
                case 2: {
                    for (Person person: persons){
                        if(person.getClass().equals(User.class)){

                            PreparedStatement statement = conn.prepareStatement("INERT INTO " + users_table + " VALUES " + person.getDBInsertPrerapedFMT());
                            statement.executeUpdate();
                            statement.close();
                        }
                        else {
                            PreparedStatement statement = conn.prepareStatement("INERT INTO " + staff_table + " VALUES " + person.getDBInsertPrerapedFMT());
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










    private void Load(Saveable[] data, Path path){ // Функция загрузки данных из файла path в массив data
        for(Saveable object: data){
            object.Load(path);
        }


    }
    private void Load() throws SQLException, FileNotFoundException {
        System.out.print("Укажите путь к  файлу или введите sql для загрузки из БД: ");
        Scanner scanner = new Scanner(System.in);
        String pathS = scanner.nextLine();
        if (!Objects.equals(pathS, "sql")) {
            Path path = Paths.get(pathS);
            if (!(Files.exists(path))) {
                System.out.println("Указанный файл не найден");
                throw new FileNotFoundException();
            }
            System.out.println("""
                    Укажите объект загрузки:
                    [1] фильмы
                    [2] люди\s
                    """);
            int option = scanner.nextInt();
            System.out.println("Удалить текущие данные?[Д/Н]");
            String mode = scanner.nextLine();

            if (mode.equalsIgnoreCase("Д") ||
                    mode.equalsIgnoreCase("Y") || mode.equalsIgnoreCase("Да") || mode.equalsIgnoreCase("Yes")) {
                switch (option){
                    case 1:Arrays.fill(Films,null);
                    case 2:Arrays.fill(persons,null);
                    default: {
                        System.out.println("Неизвестеая опция. Отмена загрузки");
                    }
                }
            }


            switch (option) {
                case 1: {
                    Load(Films,path);
                }
                case 2: {
                    Load(persons,path);

                }
                default: {
                    System.out.println("Неизвестеая опция. Отмена загрузки");
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
                    Укажите объект загрузки:
                    [1] фильмы
                    [2] люди\s
                    """);

            int option = scanner.nextInt();
            switch (option) {
                case 1: {
                    Statement statement = conn.createStatement();
                    ResultSet rs = statement.executeQuery("SELECT * FROM " + film_table);
                    ResultSet rs1 = statement.executeQuery("SELECT * FROM " + series_table);
                    statement.close();
                    while (rs.next()) {
                        Saveable.ObjCreator(rs, Films);
                        }
                    while(rs1.next()){
                        Saveable.ObjCreator(rs1, Films);
                    }
                    }
                    conn.close();
                case 2: {
                    Statement statement = conn.createStatement();
                    ResultSet rs = statement.executeQuery("SELECT * FROM " + staff_table);
                    ResultSet rs1 = statement.executeQuery("SELECT * FROM " + users_table);
                    statement.close();
                    while (rs.next()) {
                        Saveable.ObjCreator(rs, persons);
                    }
                    while(rs1.next()){
                        Saveable.ObjCreator(rs1, persons);
                    }
                }
                conn.close();
                default: {
                    System.out.println("Неизвестеая опция. Отмена сохранения");
                    conn.close();
                }
            }


        }
    }






    private void Search(String[] query){
        Search search = new Search();
        search.Search(query);
    }
    private void Stat(){
        for(Person p : persons){
            if(p.getClass().equals( Actor.class) || p.getClass().equals(Director.class)){
                System.out.println("[" + Arrays.asList(persons).indexOf(p) + "] " + p);
            }
            Scanner scanner = new Scanner(System.in);
            System.out.println("Введите идентификатор для расчета статистики: ");
            int idx = scanner.nextInt();
            if(persons[idx].getClass().equals(Actor.class)){
                ((Actor)persons[idx]).GetStatistics();
            }
            else if (persons[idx].getClass().equals(Director.class)) {
                ((Director)persons[idx]).GetStatistics();

            }
            else {
                System.out.println("Для данного индекса нельзя посчитать статистику");
            }
        }

    }


    private void Add(String[] query){
        if(query[1].equalsIgnoreCase("film")){
            if(Arrays.asList(Films).contains(null)){
                Films[Arrays.asList(Films).indexOf(null)] = Film.Constructor();
            }
            else{
                Films = Arrays.copyOf(Films,Films.length + 1000);
                try {
                    ParseQuery(Arrays.toString(query));
                } catch (SQLException | FileNotFoundException e) {
                    throw new RuntimeException(e);
                }
            }
        }
        else if (query[1].equalsIgnoreCase("person")) {
            System.out.println(
                    """
                            Кого создать
                            [1] Пользователь
                            [2] Актер
                            [3] Режиссер\s
                            """
            );
            Scanner scanner = new Scanner(System.in);
            int sw = scanner.nextInt();
            switch (sw){
                case 1:{
                    if(Arrays.asList(persons).contains(null)){
                        persons[Arrays.asList(persons).indexOf(null)] = User.Constructor();
                    }
                    else {
                        persons = Arrays.copyOf(persons,persons.length+1000);
                        try {
                            ParseQuery(Arrays.toString(query));
                        } catch (SQLException | FileNotFoundException e) {
                            throw new RuntimeException(e);
                        }
                    }

                }
                case 2:{
                    if(Arrays.asList(persons).contains(null)){
                        persons[Arrays.asList(persons).indexOf(null)] = Actor.Constructor();
                    }
                    else {
                        persons = Arrays.copyOf(persons,persons.length+1000);
                        try {
                            ParseQuery(Arrays.toString(query));
                        } catch (SQLException | FileNotFoundException e) {
                            throw new RuntimeException(e);
                        }
                    }

                }
                case 3:{
                    if(Arrays.asList(persons).contains(null)){
                        persons[Arrays.asList(persons).indexOf(null)] = Director.Constructor();
                    }
                    else {
                        persons = Arrays.copyOf(persons,persons.length+1000);
                        try {
                            ParseQuery(Arrays.toString(query));
                        } catch (SQLException | FileNotFoundException e) {
                            throw new RuntimeException(e);
                        }
                    }

                }
            }

        }

    }
    private void Del(String[] query){
        if(query[1].equalsIgnoreCase("person")){
            PrintAll(persons);
            Scanner scanner = new Scanner(System.in);
            System.out.println("Введите индекс удаляемого объекта:");
            int idx = scanner.nextInt();
            persons[idx] = null;

        } else if (query[1].equalsIgnoreCase("film")) {
            PrintAll(Films);
            Scanner scanner = new Scanner(System.in);
            System.out.println("Введите индекс удаляемого объекта:");
            int idx = scanner.nextInt();
            Films[idx] = null;
        }
        else {
            System.out.println("Неизвестная опция");
        }



    }
    private void PrintAll(Saveable[] s){
        int id = 0;
        for (Saveable tmp:s){
            System.out.println("[" + id + "]" +tmp.toString());
            id++;

        }
    }
    private void PrintAll(String[] query){
        switch (query[1]){
            case "films":PrintAll(Films);
            case  "people":PrintAll(persons);
        }

    }
    public void  AddFilm(String[] query){
        int person = Integer.parseInt(query[1]);
        int film = Integer.parseInt(query[2]);
        if(persons[person].getClass().equals(Actor.class)){
            ((Actor)persons[person]).AddFilm(Arrays.asList(Films).get(film));
        } else if (persons[person].getClass().equals(Director.class)) {
            ((Director)persons[person]).AddFilm(Arrays.asList(Films).get(film));
        } else if (persons[person].getClass().equals(User.class)) {

            ((User)persons[person]).AddFilm(Arrays.asList(Films).get(film));
        }
        else {
            System.out.print("Error");
        }

    }
    public void DelFilm(String[] query){
        int person = Integer.parseInt(query[1]);
        int film = Integer.parseInt(query[2]);

        if(persons[person].getClass().equals(Actor.class)){
            ((Actor)persons[person]).DelFilm(Arrays.asList(Films).get(film));
        } else if (persons[person].getClass().equals(Director.class)) {
            ((Director)persons[person]).Delfilm(Arrays.asList(Films).get(film));
        } else if (persons[person].getClass().equals(User.class)) {

            ((User)persons[person]).Delfilm(Arrays.asList(Films).get(film));
        }
        else {
            System.out.print("Error");
        }
    }
 
    public void ParseQuery(String query) throws SQLException, FileNotFoundException {
        String[] cmd = query.toLowerCase().split(" ");
        switch (cmd[0]){
            case "q":{quit();}
            case "save":{Save();}
            case "load":{Load();}
            case "search":{Search(cmd);}
            case "stat":{Stat();}
            case "add":{Add(cmd);}
            case "del":{Del(cmd);}
            case "show":{PrintAll(cmd);}
            case  "addfilm":{AddFilm(cmd);}
            case "delfilm":{DelFilm(cmd);}
            default:


        }
    }
}
