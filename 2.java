package org.example;

public class Interval {
    private IntervalType type;
    private int left;
    private int right;

    private Interval(IntervalType type, int left, int right) {
        this.type = type;
        this.left = left;
        this.right = right;
    }

    public boolean contains(int value) {
        if (type == IntervalType.OPEN){
            return value > left && value < right;
        }
        if (type == IntervalType.CLOSED) {
            return value >= left && value <= right;
        }
        if (type == IntervalType.OPEN_LEFT) {
            return value > left && value <= right;
        }
        if (type ==  IntervalType.OPEN_RIGHT) {
            return value >= left && value < right;
        }
        else {
            return false;
        }
    }

    public static Interval create(IntervalType type, int left, int right) {
        if (left >= right) {
            throw new IncorrectIntervalException("Invalid interval: left > right or left = right");
        }
        else {
            return new Interval(type, left, right);
        }
    }
}
