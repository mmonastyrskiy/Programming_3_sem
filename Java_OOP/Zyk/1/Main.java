import java.text.ParseException;
import java.util.Date;
import java.text.SimpleDateFormat;

class Departament{
    String dep_name;
    public Departament(String name){
        dep_name = name;
        System.out.println(dep_name);
    }
}

class Students{
    String st_name;
    Date date;
    Group current_group;
    Discipline[] dis = new Discipline[15];
    public Students(String name, Date dr){
        st_name = name;
        date = dr;
    }
    public void Perevod(Group new_group){
        current_group.drop_Student(this);
        current_group = new_group;
        current_group.add_Student(this);
    }
    public void Info(){
        System.out.println("Name of Student: " + st_name);
        System.out.println("Date of Student: " + date);
        System.out.println("Group of Student: " + current_group.group_name);
        System.out.print("Discipline of Student: ");
        for (int i = 0; i < dis.length; i++){
            try{

            System.out.println(dis[i].dis_name);
            } catch (NullPointerException e) {
                "".isEmpty();
            }
        }
    }
    public void everege_mark(){
        int sum = 0;
        float ev_mark;
        int counter = 0;
        for (int i = 0; i < dis.length; i++ ){
            if (dis[i] == null){
                continue;
            }
            sum += dis[i].dis_mark;
            counter++;
        }
        ev_mark = sum / counter;
        System.out.println("Everege Mark: " + ev_mark);
    }

    public void add_dis(Discipline new_dis){
        for(int i = 0; i < dis.length; i++){
            if (dis[i] == null){
                dis[i] = new_dis;
            }
        }
    }

}

class Group{
    public Group(String name, String sp, Departament dep){
        group_name = name;
        speciality = sp;
        depart = dep;

    }

    public void add_Student(Students new_st){
        for(int i = 0; i < st.length; i++){
            if (st[i] == null){
                st[i] = new_st;
            }
        }
    }
    public void drop_Student(Students bad){
        for(int i = 0; i < st.length; i++){
            if (st[i] == bad){
                st[i] = null;
            }
        }

    }
    String group_name;
    String speciality;
    Departament depart;
    Students[] st = new Students[100];


}

class Discipline{
    public Discipline(String name, int volume, int mark){
        dis_name = name;
        dis_volume = volume;
        dis_mark = mark;
    }
    String dis_name;
    int dis_volume;
    int dis_mark;

}

public class Main {
    public static void main (String[] args){

        Students[] all_students = new Students[100];
        int index = 0;
        String date = "02.03.2005";
        try {
            Date parced_date = new SimpleDateFormat("dd.MM.yyyy").parse(date);
            all_students[index] = new Students("Ivan Ivanov", parced_date);
        }
        catch(ParseException pe) {throw new RuntimeException(pe);}


        Departament dep = new Departament("IFTES");

        System.out.println(all_students[index].st_name);

    }
}
