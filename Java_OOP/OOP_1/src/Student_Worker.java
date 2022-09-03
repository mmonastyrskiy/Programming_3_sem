import java.util.Scanner;
import java.util.Date;
import java.util.Arrays;



class Department {
     static String current_name;
     public Department( String name){
         current_name = name;

    }
}


class Group {
    String name;
    String speciality;
    Department department;
    Student[] students;

    public Group(String group_name, String group_speciality, Department group_department) {
        name = group_name;
        speciality = group_speciality;
        department = group_department;
    }

    public void Enroll(Student Pervakur){
        Student[] new_students = new Student[students.length+1];
        for(int i =0; i < students.length; i++){
            new_students[i] = students[i];
        }
        new_students[students.length] = Pervakur;
        students = new_students;




    }


    public void drop(Student bad_student){
        Student[] new_students = new Student[students.length - 1];

        for(int i=0;i < students.length; i++){
            int pointer = 0;
            if(students[i] == bad_student){
                continue;

            }
            else{
                new_students[pointer] = students[i];
                pointer++;

            }
        }
    }

}


class Student {
    String full_name;
    Date birth_date;
    Group current_group;
    Subject[] subjects;





    public Student(String student_full_name,Date student_birth_date){
        full_name = student_full_name;
        birth_date = student_birth_date;


    }

    public void MoveToGroup(Group new_group){
        current_group = new_group;

    }
    public void ShowDetails(){
        System.out.println("ФИО:    " + full_name);
        System.out.println("Дата рождения:    " + birth_date.toString());
        System.out.println("Группа:       " + current_group.name);
        System.out.print("Изученные дисцмплины");
        for(int i =0; i < subjects.length; i++ ){
            System.out.print("  " + subjects[i]);
        }
        System.out.println();


    }
    public void showavg(){
        int sum=0;
        float avg;
        for (int i =0; i < subjects.length;i++ ){
            sum += subjects[i].mark;
        }
        avg = sum / subjects.length;
        System.out.print("Средний балл студента:   ");
        System.out.print(avg);
        System.out.println();


    }


    public void AddDescipline(Subject new_subject ){
        Subject[] new_subjects = new Subject[subjects.length + 1];
        for (int i=0;i < subjects.length;i++){
            new_subjects[i] = subjects[i];
            new_subjects[new_subjects.length] = new_subject;
            subjects = new_subjects;
        }

    }

}


class Subject{
    String name;
    int hours;
    int mark;
    public Subject(String subject_name, int hours_listened, int exam_mark){
        name = subject_name;
        hours = hours_listened;
        mark = exam_mark;

    }




}

public class Student_Worker {
    public static void main(String[] args){
    }
}
