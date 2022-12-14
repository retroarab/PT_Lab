import java.util.*;

interface Condition{

    public boolean compliesToCondition(Figure figure);

}

class NameColorCondition implements Condition{

    private String nameFigureToVerify, colorFigureToVerify;

    public NameColorCondition(String colorFigureToVerify, String nameFigureToVerify){

        this.colorFigureToVerify = colorFigureToVerify;
        this.nameFigureToVerify = nameFigureToVerify;

    }

    public boolean compliesToCondition(Figure figure){

        return figure.getFigureColor().equals(this.colorFigureToVerify) && figure.getFigureName().equals(this.nameFigureToVerify);

    }

    public String getNameColor(){

        return "Figure " + this.nameFigureToVerify + ", having the color " + this.colorFigureToVerify + " is existent in the folder: ";

    }


}


class AreaColorCondition implements Condition{

    public boolean compliesToCondition(Figure figure){

        return figure.getFigureColor() == "blue" && figure.getArea() > 50;

    }


}

abstract class Figure{

    private String colorFigure, nameFigure;

    public Figure(String colorFigure, String nameFigure){

        this.colorFigure = colorFigure;
        this.nameFigure = nameFigure;

    }

    abstract public double getArea();

    public String toString(){

        return this.nameFigure + " - " + this.colorFigure + " - " + this.getArea() + "\n";

    }

    public boolean equals(Object o){

        if(o instanceof Figure){

            return ((Figure)o).nameFigure.equals(this.nameFigure) && ((Figure)o).colorFigure.equals(this.colorFigure);

        }

        return false;

    }

    public String getFigureName(){

        return this.nameFigure;

    }

    public String getFigureColor(){

        return this.colorFigure;

    }



}


class Square extends Figure{

    private double areaSquare;

    public Square(String colorFigure, String nameFigure, double areaSquare){

        super(colorFigure,nameFigure);
        this.areaSquare = areaSquare;

    }

    public double getArea(){

        return this.areaSquare;

    }


}


class Rectangle extends Figure{

    private double width, height;

    public Rectangle(String colorFigure, String nameFigure){

        super(colorFigure,nameFigure);

    }

    public void setWidth(double width){

        this.width = width;

    }

    public void setHeight(double height){

        this.height = height;

    }

    public double getArea(){

        return this.height * this.width;

    }


}


class FigureAlreadyInFolderException extends Exception{

    public FigureAlreadyInFolderException(String message){

        super(message);

    }


}



class Folder{

    ArrayList<Figure> memberFolder = new ArrayList<Figure>();

    public void addFigure(Figure figure) throws FigureAlreadyInFolderException{

        if(memberFolder.contains(figure)){

            throw new FigureAlreadyInFolderException("Figure " + figure.getFigureName() + " was already added!\n");

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


class ClientFolder{

    public static void main(String[]args) throws FigureAlreadyInFolderException{

        Figure f1, f2, f3;
        Folder fol1, fol2, fol3;
        Condition c1, c2, c3;

        f1 = new Square("red","Square1",12);
        f2 = new Rectangle("blue","Rectangle1");
        ((Rectangle)f2).setHeight(25);
        ((Rectangle)f2).setWidth(2);
        f3 = new Square("blue","Square2",60);

        fol1 = new Folder();
        fol2 = new Folder();
        fol3 = new Folder();

        c1 = new NameColorCondition("red", "Square1");
        c2 = new NameColorCondition("green", "Square1");
        c3 = new AreaColorCondition();




        try{

            fol1.addFigure(f1);
            fol1.addFigure(f2);
            fol1.addFigure(f3);

        }finally{}

        System.out.println("~The first folder:\n" + fol1);
        System.out.println(((NameColorCondition)c1).getNameColor() + fol1.isInFolder(c1));
        System.out.println(((NameColorCondition)c2).getNameColor() + fol1.isInFolder(c2));
        System.out.println("There is at least one figure respecting the mentioned property about AreaColor: " + fol1.isInFolder(c3));
        



        try{

            fol2.addFigure(f1);

        }finally{}

        System.out.println("\n~The second folder:\n" + fol2);
        System.out.println("There is at least one figure respecting the mentioned property about AreaColor: " + fol2.isInFolder(c3));




        try{

            fol3.addFigure(f1);
            fol3.addFigure(f1);

        }finally{}
        System.out.println("\n~The third folder:\n" + fol3);


    }



}