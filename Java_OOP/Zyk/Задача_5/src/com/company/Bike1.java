package com.company;

public class Bike1 extends Bike {
    Bike1(int wDiameter) {
        super(wDiameter);
        wheelCount = 1;
    }

    @Override
    public void repair() {
        System.out.println("Ремонт одноколёсного велосипеда");
    }
}
