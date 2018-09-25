/*
 * TCSS 305 example code
 */

package gui;

import java.awt.EventQueue;

/**
 * Starts The Tool and Menu Bar Example.
 * 
 * @author Alan Fowler
 * @version 1.2
 */
public final class ProgramMain {

    /**
     * Private constructor to inhibit external instantiation.
     */
    private ProgramMain() {
        throw new IllegalStateException();
    }

    /**
     * The start point for the program; creates the GUI.
     * 
     * @param theArgs command line arguments - ignored in this program
     */
    public static void main(final String... theArgs) {

        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                new GUI();
            }
        });
    }

}
