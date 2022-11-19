package org.Terminal;
import org.Film.Film;
import org.Person.Person;
import org.Person.User;
import org.Saveable.*;

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
                            PreparedStatement statement = conn.prepareStatement("INERT INTO " + series_table + " VALUES " + film.GetDBInsertPrerapedFMT());
                            statement.executeUpdate(); // Выполняем запросы
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



    }
    private void Stat(String[] query){

    }
    private void Add(String[] query){

    }
    private void Del(String[] query){

    }
    public String[] ParseQuery(String query) throws SQLException, FileNotFoundException {
        String[] cmd = query.toLowerCase().split(" ");
        switch (cmd[0]){
            case "q":{quit();return cmd;}
            case "save":{Save();return cmd;}
            case "load":{Load();return cmd;}
            case "search":{Search(cmd);return cmd;}
            case "stat":{Stat(cmd); return  cmd;}
            case "add":{Add(cmd);return cmd;}
            case "del":{Del(cmd);return cmd;}
            default: return cmd;


        }
    }
}
