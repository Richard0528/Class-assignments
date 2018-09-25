/*
 * TCSS 305
 * 
 * This driver program demonstrates a very poor way to 'test' the Point class.
 * A MUCH better way is to write unit tests for the Point class.
 */

package shapes;

import java.util.Locale;

/**
 * A 'driver' utility class for a few demonstrations.
 * 
 * @author Alan Fowler
 * @version 1.1
 */
public final class PointMain {
    
    /**
     * A private constructor to inhibit instantiation.
     */
    private PointMain() {
        // do nothing
    }

    /**
     * The start point for this program.
     * 
     * @param theArgs command line parameters - ignored in this program
     */
    public static void main(final String[] theArgs) {
        
        // Test 1
        // Create a point and print it to test the constructor and toString()
        
        final Point p1 = new Point(); // create a default Point - (0, 0)
        System.out.println(p1.toString()); // do we need to call p1.toString()?
        
        
        
        // Test 2
        // call setX() with a new value and then print the Point
        
        p1.setX(2);
        System.out.println(p1);
        

        // Are there other things in the Point class that we should test?
        
        
        
        
        
        
        // a bit of code to demonstrate how immutable objects work
        
//        final String s = "hello";
//        System.out.println(s);
//        final String s2 = s.toUpperCase(Locale.ROOT);
//        System.out.println(s); // unchanged
//        System.out.println(s2);
        
        
        // a bit of code to demonstrate an issue with primitive type double (and float)
        
//        System.out.println(".1 + .2 = " + (.1 + .2));

    }

}
