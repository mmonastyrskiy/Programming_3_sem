import java.io.File;
import java.util.Scanner;

class Prompt{
    void showFiles(File[] files) {
        for (File file : files) {
            if (file.isDirectory()) {
                System.out.println("Directory: " + file.getAbsolutePath());
                showFiles(file.listFiles());
            } else {
                System.out.println("File: " + file.getAbsolutePath());
            }
        }
    }
}
public class Filesorter {
      void showFiles(File[] files) {
        for (File file : files) {
            if (file.isDirectory()) {
                System.out.println("Directory: " + file.getAbsolutePath());
                showFiles(file.listFiles());
            } else {
                System.out.println("File: " + file.getAbsolutePath());
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Prompt p = new Prompt();
        while (true) {
            String command = scanner.nextLine();
            switch (command){
                case "q" -> {
                    return;
                }
                case "ls"->{
                    p.showFiles();
                }

            }
        }


    }
}
