/*
 * TCSS 305 example code
 */

package gui;

import java.awt.EventQueue;

/**
 * Starts The Tool and Menu Bar Example.
 * 
 * @author Alan Fowler
 * @version 2.0
 */
public final class GUIMain {

    /**
     * Private constructor to inhibit external instantiation.
     */
    private GUIMain() {
        throw new IllegalStateException();
    }

    /**
     * The start point for the Hello/Goodbye program.
     * 
     * @param theArgs command line arguments - ignored
     */
    public static void main(final String... theArgs) {

        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                new GUI(); // create the graphical user interface
            }
        });
    }

}
