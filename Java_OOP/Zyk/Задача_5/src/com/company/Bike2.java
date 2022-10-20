package com.company;

public class Bike2 extends Bike {
    Bike2(int wDiameter) {
        super(wDiameter);
        wheelCount = 2;
    }

    @Override
    public void repair() {
        System.out.println("Ремонт одноколёсного велосипеда");
    }
}
