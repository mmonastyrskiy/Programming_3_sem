import java.util.Arrays;
import java.util.Comparator;

class abcSort implements Comparator<String>{

    @Override
    public int compare(String o1, String o2) {
        return o1.compareToIgnoreCase(o2);
    }
}
class StringLengthSort implements Comparator<String> {
    @Override
    public int compare(String o1, String o2) {
        if(o1.length() > o2.length()){
            return 1;
        }else{
            if(o1.length() < o2.length()){
                return -1;
            }else{
                return 0;
            }
        }
    }
}
public class Main {
     static String str = "Strings are constant; their values cannot be changed \n" +
             "after they are created.";
     public static String sortWords(String inpStr){
         String[] s = inpStr.split(" ");
         Comparator<String> abc = new abcSort();
         Comparator<String> stringLengthComparator = new StringLengthSort();
         Arrays.sort(s,abc.thenComparing(stringLengthComparator));
         for(String st:s ){
             System.out.println(st);
         }
         return Arrays.toString(s);

     };
     public static void main(String[] args){
         sortWords(str);

     }
}
