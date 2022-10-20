package com.company;

public class Bike3 extends Bike {
    Bike3(int wDiameter) {
        super(wDiameter);
        wheelCount = 3;
    }

    @Override
    public void repair() {
        System.out.println("Ремонт одноколёсного велосипеда");
    }
}
