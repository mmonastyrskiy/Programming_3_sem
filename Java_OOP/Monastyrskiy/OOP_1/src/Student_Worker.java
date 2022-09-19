import java.text.ParseException;
import java.util.Scanner;
import java.util.Date;
import java.text.SimpleDateFormat;


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
    Student[] students = new Student[10000];

    public Group(String group_name, String group_speciality, Department group_department) {
        name = group_name;
        speciality = group_speciality;
        department = group_department;
    }

    public void Enroll(Student Pervakur){
        for(int i =0; i < students.length; i++){
            if(students[i] == null) {
                students[i] = Pervakur;
            }
        }





    }


    public void drop(Student bad_student){

        for(int i=0;i < students.length; i++){
            if(students[i] == bad_student){
                students[i] = null;

            }
        }
    }

}


class Student {
    String full_name;
    Date birth_date;
    Group current_group;
    Subject[] subjects = new Subject[100];





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
        for (Subject subject : subjects) {
            try {
                System.out.print("  " + subject.name);
            } catch (NullPointerException e){
                "".isEmpty();

            }        }
        System.out.println();


    }
    public void showavg(){
        int sum=0;
        int ammount = 0;
        float avg;
        for (Subject subject : subjects) {
            if (subject == null){
                continue;
            }
            ammount+=1;
            sum+=subject.mark;
        }

        avg = sum / ammount;
        System.out.print("Средний балл студента:   ");
        System.out.print(avg);
        System.out.println();


    }


    public void AddDescipline(Subject new_subject ){
        for (int i=0;i < subjects.length;i++){
            if (subjects[i] == null){
                subjects[i] = new_subject;
            break;}
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
    public static void main(String[] args) {
        int max_N = 100;

        Department[] departments = new Department[max_N];
        Group[] groups = new Group[max_N];
        Student[] students = new Student[10000];

        int group_counter = 0;
        int department_counter = 0;
        int student_counter = 0;

        Scanner scanner = new Scanner(System.in);

        while (true) {
            String command;
            System.out.print("> ");
            command = scanner.nextLine();
            System.out.println(command);
            switch (command) {
                case "create.department" -> {
                    System.out.println();
                    System.out.println("Введите название: ");
                    System.out.print("> ");
                    String name = scanner.nextLine();
                    departments[department_counter] = new Department(name);
                    department_counter++;


                }
                case "create.group" -> {
                    System.out.println();
                    System.out.println("Введите название: ");
                    System.out.print("> ");
                    String name = scanner.nextLine();

                    System.out.println();
                    System.out.println("Введите специальность: ");
                    System.out.print("> ");
                    String spec = scanner.nextLine();

                    System.out.println();
                    System.out.println("Введите департамент: ");
                    System.out.print("> ");
                    String dep = scanner.nextLine();
                    boolean flag = false;
                    int idx = 0;
                    for (int i = 0; i < departments.length; i++) {
                        if (departments[i].current_name.equals(dep)) {
                            flag = true;
                            idx = i;
                            break;
                        }

                    }
                    if (!(flag)) {
                        System.out.println("Неверное значение");
                        continue;

                    }
                    groups[group_counter] = new Group(name, spec, departments[idx]);
                    System.out.println(group_counter+" "+groups[group_counter].name);
                    group_counter++;

                }
                case "create.student" -> {
                    System.out.println();
                    System.out.println("Введите ФИО: ");
                    System.out.print("> ");
                    String name = scanner.nextLine();

                    System.out.println();
                    System.out.println("Введите Дату рождения: ");
                    System.out.print("> ");
                    String date = scanner.nextLine();
                    try {
                        Date parced_date = new SimpleDateFormat("dd.MM.yyyy").parse(date);
                        students[student_counter] = new Student(name, parced_date);
                        student_counter++;
                    } catch (ParseException e) {
                        throw new RuntimeException(e);
                    }

                }
                case "enroll" -> {
                    for (int student_idx = 0; student_idx < students.length; student_idx++) {
                        try {
                            System.out.println(student_idx + " " + students[student_idx].full_name);
                        }
                        catch (NullPointerException e){continue;}
                        System.out.println();
                    }
                    System.out.println("Выберите студента: ");
                    System.out.print("> ");
                    int choose = scanner.nextInt();
                    System.out.println();
                    System.out.println("Введите группу: ");
                    System.out.print("> ");

                    try {


                        for (int i = 0; i < groups.length; i++) {
                            System.out.println(i + " " + groups[i].name);

                        }
                    } catch (NullPointerException e){"".isEmpty();}
                        int gr_choose = scanner.nextInt();
                        groups[gr_choose].Enroll(students[choose]);
                        try {


                            students[choose].current_group.drop(students[choose]);
                        } catch (NullPointerException e){"".isEmpty();}
                        students[choose].MoveToGroup(groups[gr_choose]);

                }
                case "details" -> {
                    try {


                    for (int student_idx = 0; student_idx < students.length; student_idx++) {
                        System.out.println(student_idx + " " + students[student_idx].full_name);
                        System.out.println();
                    }
                    }
                    catch (NullPointerException e){"".isEmpty();}
                    System.out.println("Выберите студента: ");
                    System.out.print("> ");
                    int choose = scanner.nextInt();
                    students[choose].ShowDetails();

                }
                case "avg" -> {
                    try{
                    for (int student_idx = 0; student_idx < students.length; student_idx++) {
                        System.out.println(student_idx + " " + students[student_idx].full_name);
                        System.out.println();
                    }
                    } catch (NullPointerException e){"".isEmpty();}
                    System.out.println("Выберите студента: ");
                    System.out.print("> ");
                    int choose = scanner.nextInt();
                    students[choose].showavg();
                }
                case "addDescipline" -> {
                    for (int student_idx = 0; student_idx < students.length; student_idx++) {
                        try {
                            System.out.println(student_idx + " " + students[student_idx].full_name);
                            System.out.println();
                        } catch (NullPointerException e){"".isEmpty();}
                    }
                    System.out.println("Выберите студента: ");
                    System.out.print("> ");
                    int choose = scanner.nextInt();
                    System.out.println("Название дисциплины ");
                    System.out.print("> ");
                    String Dname = scanner.next();
                    System.out.println(Dname);
                    System.out.println("Введите количество прослушанных часов: ");
                    System.out.print("> ");
                    int h = scanner.nextInt();
                    System.out.println("Введите оценку ");
                    System.out.print("> ");
                    int mark = scanner.nextInt();
                    students[choose].AddDescipline(new Subject(Dname, h, mark));

                }
                case "exit" -> {
                    return;
                }

            }
        }
    }
}
