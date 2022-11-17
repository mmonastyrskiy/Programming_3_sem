package org.IMDB_Main;
import org.Person.*;
import org.Film.*;
import org.Saveable.Saveable;
import org.Searcher.Searcher;
import org.Terminal.*;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String query;
        Terminal terminal = new Terminal();
        while (true){
            System.out.print("> ");
            query = scanner.nextLine();
            terminal.ParceQuery(query);

        }

    }
}