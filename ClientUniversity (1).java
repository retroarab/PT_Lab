import java.util.*;

interface Condition{

    public boolean compliesToCondition(Teacher teacher);

}

class NameCondition implements Condition{

    private String nameToVerify;

    public NameCondition(String nameToVerify){

        this.nameToVerify = nameToVerify;

    }

    public boolean compliesToCondition(Teacher teacher){

        return teacher.getName().equals(this.nameToVerify);

    }


    public String getNameVerified(){

        return this.nameToVerify;

    }


}


class SalaryCondition implements Condition{

    public boolean compliesToCondition(Teacher teacher){

        return teacher.getSalary() > 4000;

    }

}



class TeacherAlreadyInUniversityException extends Exception{

    public TeacherAlreadyInUniversityException(String s){

        super(s);

    }

}


abstract class Teacher{

    private String personalID, teacherName;

    public Teacher(String teacherName, String personalID){

        this.teacherName = teacherName;
        this.personalID = personalID;

    }

    
    abstract public double getSalary();


    public String toString(){

        return this.personalID + " - " + this.teacherName + " - " + this.getSalary() + "\n";

    }


    public String getName(){

        return this.teacherName;

    }


    public boolean equals(Object o){

        if(o instanceof Teacher){

            return ((Teacher)o).personalID.equals(this.personalID) && ((Teacher)o).teacherName.equals(this.teacherName);

        }

        return false;

    }



}


class Permanent extends Teacher{

    private double flatSalary;

    public Permanent(String teacherName, String personalID, double flatSalary){

        super(teacherName, personalID);
        this.flatSalary = flatSalary;

    }

    public double getSalary(){

        return this.flatSalary;

    }


}



class HourlyPaid extends Teacher{

    private double workedHours;
    private int rate;

    public HourlyPaid(String teacherName, String personalID){

        super(teacherName, personalID);

    }

    public void setWorkedHours(double workedHours){

        this.workedHours = workedHours;

    }


    public void setRate(int rate){

        this.rate = rate;

    }

    public double getSalary(){

        return this.workedHours * this.rate;

    }


}



class University{

    private ArrayList<Teacher> memberUni = new ArrayList<Teacher>();

    public void addTeacher(Teacher teacher) throws TeacherAlreadyInUniversityException{

        if(memberUni.contains(teacher)){

            //try{

                throw new TeacherAlreadyInUniversityException("Teacher named " + teacher.getName() + " was already added!\n");

            //}finally{}

        }

        memberUni.add(teacher);

    }


    public String toString(){

        StringBuilder list = new StringBuilder();

        for(Teacher teacher: memberUni){

            list.append(teacher);

        }

        return list.toString();

    }


    public boolean isInUniversity(Condition condition){

        for(Teacher teacher: memberUni){

            if(condition.compliesToCondition(teacher)==true){

                return true;

            }

        }

        return false;


    }



}


class ClientUniversity{

    public static void main(String[]args){

        Teacher t1, t2, t3, t4, t5;
        University uni1, uni2;
        Condition c1, c2, c3;

        t1 = new Permanent("George Georgescu", "382022283",4500);
        t2 = new Permanent("Georgeta Georgescu", "23920323",3999);
        t3 = new HourlyPaid("Andreea Popescu", "854755546");
        t4 = new HourlyPaid("Andreea Popescu", "854755546");
        t5 = new Permanent("Andrei Popescu", "483930392", 3000);

        ((HourlyPaid)t3).setWorkedHours(100);
        ((HourlyPaid)t4).setWorkedHours(100);
        ((HourlyPaid)t3).setRate(30);
        ((HourlyPaid)t4).setRate(40);

        uni1 = new University();
        uni2 = new University();

        System.out.println("~University nr.1:\n");

        try{

            uni1.addTeacher(t1);
            uni1.addTeacher(t2);
            uni1.addTeacher(t3);
            uni1.addTeacher(t4);

        }catch(TeacherAlreadyInUniversityException e){

            System.out.println(e.getMessage());

        }

        System.out.println(uni1);

        System.out.println("~University nr.2:\n");

        try{

            uni2.addTeacher(t5);
            uni2.addTeacher(t2);

        }catch(TeacherAlreadyInUniversityException e){

            System.out.println(e.getMessage());

        }

        System.out.println(uni2);


        c1 = new NameCondition("George Georgescu");
        c2 = new NameCondition("Alexandra Dinulescu");
        c3 = new SalaryCondition();

        System.out.println(((NameCondition)c1).getNameVerified() + " is a teacher from university 1: " + uni1.isInUniversity(c1));
        System.out.println(((NameCondition)c2).getNameVerified() + " is a teacher from university 1: " + uni1.isInUniversity(c2));
        System.out.println("There exists a teacher from university 1 with a salary >4000: " + uni1.isInUniversity(c3));
        System.out.println("There exists a teacher from university 2 with a salary >4000: " + uni2.isInUniversity(c3));



    }


}