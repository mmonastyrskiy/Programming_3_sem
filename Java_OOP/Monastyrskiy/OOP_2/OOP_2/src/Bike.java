class Wheel {
    int d;
    Wheel (int di){
        d = di;
    }
}
public class Bike implements Cloneable {
    int wheelCount;
    Wheel w;

    public boolean equals(Object object){
        if(this == object){return true;}
        if(object == null){return false;}
        if (this.getClass() != object.getClass())
            return false;
        Bike other = (Bike) object;
        if(!(this.w.equals(other.w))&& !(this.wheelCount == other.wheelCount)){
            
        }


        return true;
    }


    public Bike clone(){
        Bike result = new Bike(this.wheelCount, this.w.d);
        result.w = new Wheel(this.w.d);
        return result;

    }
    Bike(int wCount, int wDiameter) {
        wheelCount = wCount;
        w = new Wheel(wDiameter);
    }



    public static void main (String[] arg) throws CloneNotSupportedException{
        Bike bike1 = new Bike(2, 26);
        Bike bike2 = (Bike) bike1.clone();
        bike1.wheelCount = 1;
        bike1.w.d = 29;
        System.out.println (bike2.wheelCount);
        System.out.println (bike2.w.d);
        System.out.println (bike1.wheelCount);
        System.out.println (bike1.w.d);
    }
}