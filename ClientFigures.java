import java.util.*;

interface Condition{

    public boolean compliesToCondition(Figure figure);

}


class ColorCondition implements Condition{

    private String colorToVerify;

    public ColorCondition(String colorToVerify){

        this.colorToVerify = colorToVerify;

    }

    public boolean compliesToCondition(Figure figure){

        return figure.getColor().equals(this.colorToVerify);

    }


    public String getColorToVerify(){

        return this.colorToVerify;

    }


}

/*
class NameCondition implements Condition{

    private String colorToVerify;

    public ColorCondition(String colorToVerify){

        this.colorToVerify = colorToVerify;

    }

    public boolean compliesToCondition(Figure figure){

        return figure.getColor().equals(this.colorToVerify);

    }


}*/


abstract class Figure{

    private String color, name;

    public Figure(String color, String name){

        this.color = color;
        this.name = name;

    }

    abstract public double getPerimeter();


    public String toString(){

        return this.name + " - " + this.color + " - " + this.getPerimeter()+"\n";

    }



    public String getName(){

        return this.name;

    }

     public String getColor(){

        return this.color;

    }


    public boolean equals(Object o){

        if(o instanceof Figure){

            return ((Figure)o).name.equals(this.name) && ((Figure)o).color.equals(this.color);

        }

        return false;

    }

}


class Circle extends Figure{

    private double perimeter;

    public Circle(String color, String name, double perimeter){

        super(color,name);
        this.perimeter = perimeter;

    }

    public double getPerimeter(){

        return this.perimeter;

    }


}


class Triangle extends Figure{

    private double side1, side2, side3;

    public Triangle(String color, String name){

        super(color,name);

    }

    public void setSide1(double side1){

        this.side1 = side1;

    }


     public void setSide2(double side2){

        this.side2 = side2;

    }


     public void setSide3(double side3){

        this.side3 = side3;

    }


    public double getPerimeter(){

        return this.side1 + this.side2 + this.side3;

    }


}


class FigureAlreadyStoredException extends Exception{

    public FigureAlreadyStoredException(String s){

        super(s);

    }



}




class Folder{

    ArrayList<Figure> memberFolder = new ArrayList<Figure>();

    public void addFigure(Figure figure) throws FigureAlreadyStoredException{

        if(memberFolder.contains(figure)){

            throw new FigureAlreadyStoredException("Figure " + figure.getName() + " was already stored!\n");

        }

        memberFolder.add(figure);


    }


    public String toString(){

        StringBuilder list = new StringBuilder();

        for(Figure figure: memberFolder){

            list.append(figure);

        }

        return list.toString();


    }


     public boolean isInFolder(Condition condition){

        for(Figure figure: memberFolder){

            if(condition.compliesToCondition(figure) == true){

                return true;

            }

        }

        return false;


    }


}



class ClientFigures{

    public static void main(String[]args){

        Figure f1, f2, f3;
        Folder fol1, fol2;
        Condition c1, c2;

        fol1 = new Folder();
        fol2 = new Folder();

        f1 = new Circle("red","Circle1",392.23);
        f2 = new Triangle("green","Triangle1");
        f3 = new Circle("red","Circle2",12.32);
        ((Triangle)f2).setSide1(1);
        ((Triangle)f2).setSide2(2);
        ((Triangle)f2).setSide3(3);


        c1 = new ColorCondition("red");
        c2 = new ColorCondition("blue");


        try{

            fol1.addFigure(f1);
            fol1.addFigure(f2);
            fol1.addFigure(f2);

        }catch(FigureAlreadyStoredException e){

            System.out.println(e.getMessage());

        }


        try{

            fol2.addFigure(f1);
            fol2.addFigure(f3);

        }catch(FigureAlreadyStoredException e){

            System.out.println(e.getMessage());

        }


        System.out.println("~Folder nr.1 :\n" + fol1);
        System.out.println("~Folder nr.2 :\n" + fol2);

        System.out.println("We have figures colored in " + ((ColorCondition)c1).getColorToVerify() + " :" + fol1.isInFolder(c1));
        System.out.println("We have figures colored in " + ((ColorCondition)c2).getColorToVerify() + " :" + fol2.isInFolder(c2));


    }



}