import java.util.*;

abstract class Employee{

    private String nameEmployee, personalID;

    public Employee(String nameEmployee, String personalID){

        this.nameEmployee = nameEmployee;
        this.personalID = personalID;

    }

    abstract public double getSalary();

    public String toString(){

        return this.nameEmployee + " - " + this.personalID + " - " + this.getSalary() + "\n";

    }


    public boolean equals(Object o){

        if(o instanceof Employee){

            return ((Employee)o).nameEmployee.equals(this.nameEmployee) && ((Employee)o).personalID.equals(this.personalID);

        }

        return false;

    }


    public String getEmployeeName(){

        return nameEmployee;

    }


}


class Manager extends Employee{

    private double flatSalary;

    public Manager(String nameEmployee, String personalID, double flatSalary){

        super(nameEmployee, personalID);
        this.flatSalary = flatSalary;

    }

    public double getSalary(){

        return this.flatSalary;

    }


}


class Regular extends Employee{

    private double workedHours;
    private int rate;

    public Regular(String nameEmployee, String personalID){

        super(nameEmployee, personalID);

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


interface Condition{

    public boolean compliesToCondition(Employee employee);

}



class NameCondition implements Condition{

    private String employeeNameVerify;

    public NameCondition(String employeeNameVerify){

        this.employeeNameVerify = employeeNameVerify;

    }

    public boolean compliesToCondition(Employee employee){

        return employee.getEmployeeName().equals(this.employeeNameVerify);

    }


    public String getVerifiedName(){

        return employeeNameVerify;

    }


}



class SalaryCondition implements Condition{

    public boolean compliesToCondition(Employee employee){

        return employee.getSalary() == 1500;

    }


}





class EmployeeAlreadyInShopException extends Exception{

    public EmployeeAlreadyInShopException(String message){

        super(message);

    }


}



class Shop{

    ArrayList<Employee> memberShop = new ArrayList<Employee>();


    public void addEmployee(Employee employee) throws EmployeeAlreadyInShopException{

        if(memberShop.contains(employee)){


            throw new EmployeeAlreadyInShopException("Employee " + employee.getEmployeeName() + " was already added!\n");

        }

        memberShop.add(employee);


    }


    public String toString(){

        StringBuilder list = new StringBuilder();

        for(Employee employee: memberShop){

            list.append(employee);


        }

        return list.toString();


    }


    public boolean worksInShop(Condition condition){

        for(Employee employee: memberShop){

            if(condition.compliesToCondition(employee) == true){

                return true;

            }


        }

        return false;


    }



}

class ClientShop{

    public static void main(String[]args){

        Employee e1, e2;
        Shop shop1, shop2;
        Condition c1, c2, c3;

        e1 = new Manager("George","2829220",2000);
        e2 = new Regular("Georgiana","2494430");
        ((Regular)e2).setWorkedHours(15);
        ((Regular)e2).setRate(100);


        shop1 = new Shop();
        shop2 = new Shop();


        c1 = new NameCondition("George");
        c2 = new NameCondition("Alexandra");
        c3 = new SalaryCondition();


        try{

            shop1.addEmployee(e1);
            shop1.addEmployee(e2);
            shop1.addEmployee(e1);

        }catch(EmployeeAlreadyInShopException e){

            System.out.println(e.getMessage());

        }


        try{

            shop2.addEmployee(e1);

        }catch(EmployeeAlreadyInShopException e){

            System.out.println(e.getMessage());

        }

        System.out.println("~Shop nr.1 :\n" + shop1); 
        System.out.println("~Shop nr.2 :\n" + shop2);

        System.out.println("Employee " + ((NameCondition)c1).getVerifiedName() + " works in shop nr. 1: " + shop1.worksInShop(c1));
        System.out.println("Employee " + ((NameCondition)c2).getVerifiedName() + " works in shop nr. 1: " + shop1.worksInShop(c2));
        System.out.println("There is at least one employee with the salary of 1500 in shop nr. 1: " + shop1.worksInShop(c3));
        System.out.println("There is at least one employee with the salary of 1500 in shop nr. 2: " + shop2.worksInShop(c3));

    }


}