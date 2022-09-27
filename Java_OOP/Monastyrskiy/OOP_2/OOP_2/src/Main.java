import java.util.Random;
import java.util.Scanner;

class Workshop{
    public void Fix(Bicycle b, String client){
        if(b.owner.equals(client) && b.NeedFix){
            System.out.println("Произвожу ремонт велосипеда " + client);
            b.IsAssembled = false;
            System.out.println("Велосипед разобран");
            b.NeedFix = false;
            b.IsAssembled = true;
            switch (b.wheels){
                case 1-> System.out.println("Моноколесо отремонтировано");
                case 2-> System.out.println("Двухколесный велосипед отремонтирован");
                case 3-> System.out.println("Трехколесный велосипед отремонтирован");
            }
        }
    }
    public Workshop(){

    }
}


class Bicycle_1 extends Bicycle{
    public Bicycle_1(){
        super(1);
    }
    @Override
    public void ride(){
        if(this.NeedFix){
            System.out.println("Нельзя кататься, велосипед неисправен");
        }
        System.out.println("Катаемся на моноколесе");
        this.malfunction();
    }

}

class Bicycle_3 extends Bicycle{
    @Override
    public void ride(){

        if(this.NeedFix){
            System.out.println("Нельзя кататься, велосипед неисправен");
        }
        System.out.println("Катаемся на трехколесном велосипеде");
        this.malfunction();
    }


    public Bicycle_3(){
        super(3);
    }
}

class Bicycle_2 extends Bicycle{
    @Override
    public void ride(){
        if(this.NeedFix){
            System.out.println("Нельзя кататься, велосипед неисправен");
        }

        System.out.println("Катаемся на Двухколесном велосипеде");
        this.malfunction();
    }


    public Bicycle_2(){
            super(2);
        }
    }
class Bicycle  {
    int wheels;
    String owner;
    boolean NeedFix = false;
    boolean IsAssembled = true;
    public Bicycle(int i){
        this.wheels = i;



    }
    @Override
    public String toString(){
        return this.wheels + "-х колесный велосипед\t Владелец: " + this.owner;

    }

    public Bicycle buy(int i, String new_owner) {
        switch (i) {
            case 1 -> {
                Bicycle_1 b = new Bicycle_1();
                b.owner = new_owner;
                System.out.println("Владельцем" + new_owner + " Куплен" + b.wheels + "-х колесный велосипед");
                return b;
            }
            case 2 -> {
                Bicycle_2 b = new Bicycle_2();
                b.owner = new_owner;
                System.out.println("Владельцем" + new_owner + " Куплен" + b.wheels + "-х колесный велосипед");
                return b;

            }
            case 3 -> {
                Bicycle_3 b = new Bicycle_3();
                b.owner = new_owner;
                System.out.println("Владельцем" + new_owner + " Куплен" + b.wheels + "-х колесный велосипед");
                return b;

            }
            default -> throw new IllegalArgumentException("Неверное количество колес");
        }


    }
    public void ride(){
        System.out.println("Катаемся на велосипеде");
        this.malfunction();
    }
    protected void malfunction(){
        Random random = new Random();
        if(random.nextInt(100)% 100 < 10){
            this.NeedFix = true;
            System.out.println("Велосипед сломался после поездки");
        }

    }
}
public class Main {
    public static void main(String[] args){
        int ptr =0;
        Bicycle[] bikes = new Bicycle[1000];
        Scanner scanner = new Scanner(System.in);
        while (true){
            System.out.print(">");
            String command =scanner.nextLine();
            switch (command) {
                case "exit" -> {
                    return;
                }
                case "buy" -> {
                    Bicycle t = new Bicycle(1);
                    System.out.print("Введите число колес: ");
                    System.out.print("> ");
                    int w = scanner.nextInt();
                    System.out.println("Введите имя владельца: ");
                    System.out.print("> ");
                    String owner = scanner.nextLine();
                    Bicycle bike = t.buy(w, owner);
                    bikes[ptr] = bike;
                    ptr += 1;
                }
                case "ride" -> {
                   int i;
                   int idx;
                   for (i=0;i < bikes.length;i++){
                       System.out.println(i + " : " + bikes[i].toString());
                   }
                    System.out.print("Выберете велосипед для поездки: ");
                   idx = scanner.nextInt();
                   bikes[idx].ride();

                }
                case "show" -> {
                    int i;
                    for (i=0;i < bikes.length;i++){
                        System.out.println(i + " : " + bikes[i].toString());
                    }
                }
                case "fix" -> {
                    int i;
                    int idx;
                    String owner;
                    for (i=0;i < bikes.length;i++){
                        System.out.println(i + " : " + bikes[i].toString());
                        idx = scanner.nextInt();
                        owner = scanner.nextLine();
                        Workshop workshop = new Workshop();

                        workshop.Fix(bikes[idx],owner);
                    }
                }
            }

        }
    }
}
