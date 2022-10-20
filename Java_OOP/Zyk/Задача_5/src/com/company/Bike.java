package com.company;

abstract class Bike implements Comparable<Bike>, Fixable {
    int wheelCount;
    public Wheel w;

    Bike(int wDiameter) {
        this.w = new Wheel(wDiameter);
        wheelCount = 0;
    }

    public void repair() {
        System.out.println("Транспортное средство отремонтировано!");
    }

    @Override
    public int hashCode () {
        final int fix = 27;
        return w.d * wheelCount + fix;
    }

    public int compareTo (Bike b2){
        return Integer.compare(this.hashCode(), b2.hashCode());
    }

}
