/*
 * TCSS 305
 * 
 * A simple class representing a mutable Point on a 2-dimensional plane.
 * This example is used to demonstrate some class design considerations.
 */

package shapes;

import java.util.Objects;

/**
 * Represents a point on a 2-dimensional plane.
 * 
 * @author Alan Fowler acfowler@uw.edu
 * @version 1.2
 */
public final class Point {

    // constants (static final fields)

    /** A default value for the x coordinate. */
    public static final double DEFAULT_X = 0;

    /** A default value for the y coordinate. */
    public static final double DEFAULT_Y = 0;

    // instance fields

    /** The x coordinate. */
    private double myX;

    /** The y coordinate. */
    private double myY;

    // constructors

    /**
     * Constructs a point using the provided coordinates.
     * 
     * @param theX The x coordinate to assign to this point.
     * @param theY The y coordinate to assign to this point.
     */
    public Point(final double theX, final double theY) {
        myX = theX;
        myY = theY;

        // OR if the setters are 'final'
        // Remember, do NOT call methods from a constructor which could be overridden!
        
        // setX(theX);
        // setY(theY);
    }

    /**
     * Constructs a point at the origin (0, 0).
     */
    public Point() {
        myX = DEFAULT_X;
        myY = DEFAULT_Y;

        // OR call the overloaded constructor
        // this(DEFAULT_X, DEFAULT_Y);
    }

    /**
     * This copy constructor creates a new Point
     * as a copy of the specified Point.
     * 
     * precondition: theOtherPoint is not null
     * 
     * @param theOtherPoint a Point object to copy.
     * @throws NullPointerException if the parameter is null
     */
    public Point(final Point theOtherPoint) {
        // The following 3 alternative implementations will all throw NullPointerException
        // if theOtherPoint is null:
        
        // implementation 1
        // myX = theOtherPoint.myX;
        // myY = theOtherPoint.myY;
        
        // implementation 2
        // or use a Java 7 feature to test for null
        myX = Objects.requireNonNull(theOtherPoint).myX;
        myY = theOtherPoint.myY;

        // implementation 3
        // OR call the overloaded constructor
        // this(theOtherPoint.myX, theOtherPoint.myY);
    }
    
    
    

    // queries (sometimes called 'accessors'; sometimes called 'getters')

    /**
     * What is the x coordinate?
     * 
     * @return the x coordinate
     */
    public double getX() {
        return myX;
    }

    /**
     * What is the y coordinate?
     * 
     * @return the y coordinate
     */
    public double getY() {
        return myY;
    }

    /**
     * What is the distance to the specified point?
     * 
     * precondition: theOtherPoint is not null
     * 
     * @param theOtherPoint The other point.
     * @return the distance from the current point to the specified point
     * @throws NullPointerException if theOtherPoint is null
     */
    public double calculateDistance(final Point theOtherPoint) {
        final double dx = myX - Objects.requireNonNull(theOtherPoint).myX;
        final double dy = myY - theOtherPoint.myY;
        return Math.sqrt(dx * dx + dy * dy);
    }
    
    
    
    

    // commands (sometimes called 'mutators'; sometimes called 'setters')

    /**
     * Set the x-coordinate to the specified value!
     * 
     * @param theX the new x value to set
     */
    public void setX(final double theX) {
        myX = theX;
    }

    /**
     * Set the y-coordinate to the specified value!
     * 
     * @param theY the new y value to set
     */
    public void setY(final double theY) {
        myY = theY;
    }

    /**
     * Translate by the specified values!
     * 
     * @param theX The x distance to translate by.
     * @param theY The y distance to translate by.
     */
    public void translate(final double theX, final double theY) {
        myX += theX;
        myY += theY;
    }
    
    
    

    // overridden methods from class Object

    // toString using String concatenation
//     /**
//     * Returns a String containing the coordinate pair for this Point.
//     *    
//     * {@inheritDoc}
//     */
//     @Override
//     public String toString() {
//     return "(" + myX + ", " + myY + ")";
//     }
    
    

    // toString using StringBuilder() - preferred
    /**
     * Returns a String containing the coordinate pair with a label : Point (x, y).
     * The coordinates are formatted to show 2 decimal places.
     * 
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder(); // size 16 buffer by default
        
        /* A format string for decimal numbers. */
        final String format = "%.2f"; // used to display exactly 2 decimal places
        
        sb.append(getClass().getSimpleName()); // the class name without the
                                               // package name
        sb.append(" (");
        sb.append(String.format(format, myX)); // display 2 decimal places
        sb.append(", ");
        sb.append(String.format(format, myY)); // display 2 decimal places
        sb.append(')'); // use single quotes '' to indicate a char
                        // use double quotes "" to indicate a String
        return sb.toString();

        /*
         * In modern VMs this compiles to the same byte code as return "(" +
         * String.format(FORMAT, myX) + ", " + String.format(FORMAT, myY) + ")";
         * because modern compilers can optimize string concatenations which
         * occur on a single line of code.
         */
    }
    
    
    /*
     * NOTE:
     * We could override other methods inherited from class Object
     * such as .equals(), .hashCode(), and .clone()
     * 
     * We will add these methods to this class a bit later in this course.
     */

}
