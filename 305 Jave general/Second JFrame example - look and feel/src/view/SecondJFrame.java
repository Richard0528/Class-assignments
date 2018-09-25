/*
 * TCSS 305
 * 
 * A first JFrame demo.
 */

package view;

import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * A second demonstration of JFrame.
 * 
 * This demonstration shows how to create a class that 'has a' JFrame.
 * 
 * @author Alan Fowler (acfowler@uw.edu)
 * @version 2.0
 */
public final class SecondJFrame {
    
    /** A size for the JFrame. */
    private static final Dimension FRAME_SIZE = new Dimension(400, 300);
    
    /* 
     * In this example we use composition instead of inheritance.
     * That is, instead of this class extending JFrame,
     * this class has a field of type JFrame.
     * 
     * One advantage of designing this way is that this class could still
     * extend some other class if needed.
     */
    
    /** The top level window for this application. */
    private final JFrame myFrame;
    
    /**
     * Initializes the JFrame.
     */
    public SecondJFrame() {
        myFrame = new JFrame("TCSS 305");
    }

    /**
     * Displays a simple JFrame.
     */
    public void start() {
        
        // Don't forget to set the close operation!
        myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // The default JFrame size is VERY small, so set it to something reasonable
        myFrame.setSize(FRAME_SIZE);

        /*
         * Attempt to center the frame on the screen.
         * There are better ways to do this which be demonstrated soon.
         */
        myFrame.setLocationRelativeTo(null);

        /*
         * This example uses the names "Foo" and "Bar" which often show up in Java examples. To
         * learn more about this and other hacker jargon, check out The New Hacker's Dictionary
         * at http://www.outpost9.com/reference/jargon/jargon_toc.html
         */
        
        // Note that BorderLayout is the default layout manager for JFrame.
        myFrame.add(new JButton("Foo"), BorderLayout.NORTH);
        myFrame.add(new JButton("Bar"), BorderLayout.WEST);

        

        // JPanel is a useful container for organizing components inside a JFrame
        final JPanel centerPanel = new JPanel();

        /*
         * FlowLayout is the default layout manager for JPanel.
         * When components are added to a JPanel the are added left to right by default.
         * Line wrapping will occur as necessary.
         */
        centerPanel.add(new JButton("Foo2"));
        centerPanel.add(new JButton("Bar2"));

        /*
         * Border Layout is the default layout manager for JFrame. 
         * If we do not specify a location within the layout, then components are added to
         * BorderLayout.Center by default. Therefore, the next line of code adds centerPanel
         * to the center of the JFrame.
         */
        myFrame.add(centerPanel, BorderLayout.CENTER);

        // pack() resizes the Frame to fit the contents of the frame
        // using this will ignore the size we set previously
        
        //myFrame.pack();

        myFrame.setVisible(true);
    }

}
