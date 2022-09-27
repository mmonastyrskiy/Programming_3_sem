class Wheel {
    int d;
    Wheel (int di){
        d = di;
    }
    public int hashCode(){
        final int prime = 53;
        return prime + this.d;
    }

    public boolean equals(Object object){
        if(this == object){return true;}
        if(object == null){return false;}
        if (this.getClass() != object.getClass())
            return false;
        Wheel other = (Wheel) object;
        return other.d == this.d;
    }
    }
public class Bike implements Cloneable {
    int wheelCount;
    Wheel w;

    public int hashCode(){
        final int prime = 59;
        final int constant = 2;
        return prime * constant + this.w.hashCode() + wheelCount;
    }

    public boolean equals(Object object){
        if(this == object){return true;}
        if(object == null){return false;}
        if (this.getClass() != object.getClass())
            return false;
        Bike other = (Bike) object;
        return this.w.equals(other.w) && this.wheelCount == other.wheelCount;
    }


    public Bike clone()throws CloneNotSupportedException{
        Bike clone = (Bike) super.clone();
        clone.w = new Wheel(this.w.d);
        return clone;

    }
    Bike(int wCount, int wDiameter) {
        wheelCount = wCount;
        w = new Wheel(wDiameter);
    }



    public static void main (String[] args) throws CloneNotSupportedException {
        Bike bike1 = new Bike(2, 26);
        Bike bike2 = bike1.clone();
        bike1.wheelCount = 1;
        bike1.w.d = 29;

        System.out.println (bike1.wheelCount);
        System.out.println (bike1.w.d);
        System.out.println("Clone:");
        System.out.println (bike2.wheelCount);
        System.out.println (bike2.w.d);
    }
}