import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

class Wheel{
    int diameter;
     public Wheel(int w){
        this.diameter = w;
    }
}
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
    public Bicycle_1(int d){
        super(1,d);
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


    public Bicycle_3(int d){
        super(3,d);
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


    public Bicycle_2(int d){
        super(2,d);
    }
}
class Bicycle implements Comparable<Bicycle> {
    int wheels;
    Wheel wheel;
    String owner;
    boolean NeedFix = false;
    boolean IsAssembled = true;

    public Bicycle(int i, int d) {
        this.wheel = new Wheel(d);
        this.wheels = i;


    }

    @Override
    public String toString() {
        return this.wheels + "-х колесный велосипед\t Владелец: " + this.owner;

    }

    public Bicycle buy(int i, int diameter, String new_owner) {
        switch (i) {
            case 1 -> {
                Bicycle_1 b = new Bicycle_1(diameter);
                b.owner = new_owner;
                System.out.println("Владельцем" + new_owner + " Куплен" + b.wheels + "-х колесный велосипед");
                return b;
            }
            case 2 -> {
                Bicycle_2 b = new Bicycle_2(diameter);
                b.owner = new_owner;
                System.out.println("Владельцем" + new_owner + " Куплен" + b.wheels + "-х колесный велосипед");
                return b;

            }
            case 3 -> {
                Bicycle_3 b = new Bicycle_3(diameter);
                b.owner = new_owner;
                System.out.println("Владельцем" + new_owner + " Куплен" + b.wheels + "-х колесный велосипед");
                return b;

            }
            default -> throw new IllegalArgumentException("Неверное количество колес");
        }


    }

    public void ride() {
        System.out.println("Катаемся на велосипеде");
        this.malfunction();
    }

    protected void malfunction() {
        Random random = new Random();
        if (random.nextInt(100) % 100 < 10) {
            this.NeedFix = true;
            System.out.println("Велосипед сломался после поездки");
        }

    }

    @Override
    public int compareTo(Bicycle o) {
        if (this.wheels * this.wheel.diameter > o.wheels * o.wheel.diameter) {
            return 1;
        }
        if (this.wheels * this.wheel.diameter < o.wheels * o.wheel.diameter) {
            return -1;
        }
        return 0;
    }


    public static class Main {
        static void fix_monowheels(Bicycle[] b) {
            int ptr;
            Workshop w = new Workshop();
            for (ptr = 0; ptr < 1000; ptr++) {
                if (b[ptr].getClass() == Bicycle_1.class) {
                    w.Fix(b[ptr], b[ptr].owner);
                }
            }

        }

        public static void main(String[] args) {
            int ptr = 0;
            Bicycle[] bikes = new Bicycle[1000];
            Scanner scanner = new Scanner(System.in);
            while (true) {
                System.out.print(">");
                String command = scanner.nextLine();
                switch (command) {
                    case "exit" -> {
                        return;
                    }

                    case "sort" -> Arrays.sort(bikes);


                    case "random" -> {
                        for (ptr = 0; ptr < 1000; ptr++) {
                            Random random = new Random();
                            Bicycle t = new Bicycle(1, random.nextInt() % 12);
                            int w = random.nextInt() % 3;
                            char[] name_char = new char[10];
                            for (int i = 0; i < 10; i++) {
                                name_char[i] = (char) (random.nextInt() % 25 + 65);
                            }
                            String name = Arrays.toString(name_char);
                            bikes[ptr] = t.buy(w, random.nextInt() % 12, name);
                        }
                        for (ptr = 0; ptr < 1000; ptr++) {
                            bikes[ptr].ride();
                        }
                        fix_monowheels(bikes);

                    }
                    case "buy" -> {
                        System.out.print("Введите диаметр колеса: ");
                        System.out.print("> ");
                        int d = scanner.nextInt();
                        Bicycle t = new Bicycle(1, d);
                        System.out.print("Введите число колес: ");
                        System.out.print("> ");
                        int w = scanner.nextInt();
                        System.out.println("Введите имя владельца: ");
                        System.out.print("> ");
                        String owner = scanner.nextLine();
                        try {

                            Bicycle bike = t.buy(w, d, owner);

                            bikes[ptr] = bike;
                            ptr += 1;
                        } catch (IllegalArgumentException e) {
                            System.out.println("Неверное кол-во колес[1-3]");

                            System.out.print("Введите число колес: ");
                            System.out.print("> ");
                            w = scanner.nextInt();
                            t.buy(w, d, owner);

                        }
                    }
                    case "ride" -> {
                        int i;
                        int idx;
                        for (i = 0; i < bikes.length; i++) {
                            System.out.println(i + " : " + bikes[i].toString());
                        }
                        System.out.print("Выберете велосипед для поездки: ");
                        idx = scanner.nextInt();
                        bikes[idx].ride();

                    }
                    case "show" -> {
                        int i;
                        for (i = 0; i < bikes.length; i++) {
                            System.out.println(i + " : " + bikes[i].toString());
                        }
                    }
                    case "fix" -> {
                        int i;
                        int idx;
                        String owner;
                        for (i = 0; i < bikes.length; i++) {
                            System.out.println(i + " : " + bikes[i].toString());
                            idx = scanner.nextInt();
                            owner = scanner.nextLine();
                            Workshop workshop = new Workshop();

                            workshop.Fix(bikes[idx], owner);
                        }
                    }
                }

            }
        }
    }
}
