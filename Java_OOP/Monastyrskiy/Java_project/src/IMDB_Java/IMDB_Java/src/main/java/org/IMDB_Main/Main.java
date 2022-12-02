package org.IMDB_Main;
import org.Terminal.*;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.SQLException;
import java.util.Scanner;

public class Main {
    public static void ExHandler(Exception e){

    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String query;
        Terminal terminal = new Terminal();
        while (true){
            System.out.print("> ");
            query = scanner.nextLine();

            try {
                terminal.ParseQuery(query);
            } catch (SQLException | IOException | ClassNotFoundException e) {
               ExHandler(e);
            }
            finally {
                System.out.println("Done!");
            }

        }

    }
}