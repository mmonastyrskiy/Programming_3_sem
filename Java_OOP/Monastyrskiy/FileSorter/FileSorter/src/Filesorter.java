import java.io.File;
import java.nio.file.Paths;
import java.util.Scanner;

class Sorter extends File{

    public Sorter(String pathname) {
        super(pathname);
    }
}
class Prompt{
    void showFilesindir(File files) {
        for (File file : files.listFiles()) {
            if (file.isDirectory()) {
                System.out.println("Directory: " + file.getAbsolutePath());
                showFilesindir(file);
            } else {
                System.out.println("File: " + file.getAbsolutePath());
            }
        }
    }

}
public class Filesorter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Prompt p = new Prompt();
        while (true) {
            System.out.print(">");
            String command = scanner.nextLine();
            switch (command){
                case "q" -> {
                    return;
                }
                case "ls"->{
                    p.showFilesindir(Paths.get(".").toFile());
                }
                case "sort" ->{

                }
                case "pwd"->{
                    System.out.println(Paths.get(".").toAbsolutePath());

                }

            }
        }


    }
}
