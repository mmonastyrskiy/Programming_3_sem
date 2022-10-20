package com.company;
import java.util.Random;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        final int n = 8;
        Bike[] a = new Bike[n];

        Generation(a);


        System.out.println(" ");
        Repair r = new Repair();
        for (int i = 0; i < n; i++) {
            if (a[i].wheelCount == 1) {
                System.out.print((i + 1) + ") ");
                r.rep(a[i]);
            }
        }

        System.out.println(" ");
        System.out.println("После сортировки получится:");
        Arrays.sort(a);
        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + ") " + a[i].wheelCount + "-хколёсный велосипед с суммарным диаметром колёс " + a[i].sd());
        }
    }
    static void Generation (Bike[] velo){
        final int n = 8;
        Random rand = new Random();
        int randomDiameter, wheelNumber;
        System.out.println("Создаём 10 случайных велосипедов:");
        for (int i = 0; i < n; i++) {
            randomDiameter = rand.nextInt(25) + 15;
            wheelNumber = rand.nextInt(3) + 1;
            switch (wheelNumber) {
                case 1:
                    velo[i] = new Bike1(randomDiameter);
                case 2:
                    velo[i] = new Bike2(randomDiameter);
                case 3:
                    velo[i] = new Bike3(randomDiameter);
            }
            System.out.println((i + 1) + ") " + velo[i].wheelCount + "-хколесный велосипед с диаметром " + velo[i].w.d + " см.");
        }

    }

}
interface Fixable{
    void repair();

}
