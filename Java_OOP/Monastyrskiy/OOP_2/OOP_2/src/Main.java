class Workshop{
    interface Fixable{
           default void Fix(Bicycle b, String owner){
            if(b.NeedFix){
                b.IsAssembled = false;
                System.out.println("Велосипед разобран ");
                b.NeedFix = false;
                System.out.println("Ремонт произведен");
                b.IsAssembled = true;
                System.out.println("Велосипед собран");

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

}

class Bicycle_3 extends Bicycle{

    public Bicycle_3(){
        super(3);
    }
}

class Bicycle_2 extends Bicycle{

        public Bicycle_2(){
            super(2);
        }
    }
class Bicycle implements Workshop.Fixable {
    int wheels;
    String owner;
    boolean NeedFix = false;
    boolean IsAssembled = true;
    public Bicycle(int i){
        this.wheels = i;



    }

    public Bicycle buy(int i, String new_owner) {
        switch (i) {
            case 1: {
                Bicycle_1 b = new Bicycle_1();
                b.owner = new_owner;
                System.out.println("Владельцем" + new_owner + " Куплен" + b.wheels + "-х колесный велосипед");
                return b;
            }
            case 2: {
                Bicycle_2 b = new Bicycle_2();
                b.owner = new_owner;
                System.out.println("Владельцем" + new_owner + " Куплен" + b.wheels + "-х колесный велосипед");
                return b;

            }
            case 3: {
                Bicycle_3 b = new Bicycle_3();
                b.owner = new_owner;
                System.out.println("Владельцем" + new_owner + " Куплен" + b.wheels + "-х колесный велосипед");
                return b;

            }
            default:
                throw new IllegalArgumentException("Неверное количество колес");
        }


    }
}
public class Main {
}
