/*
 * TCSS 305 example code
 */

package gui;

import java.awt.BorderLayout;
import java.util.Observable;
import java.util.Observer;

import javax.swing.Action;
import javax.swing.JFrame;

/**
 * The Graphical User Interface for this example program.
 * 
 * @author Alan Fowler
 * @version 1.2
 */
public class GUI implements Observer {

    /** The top level Window for this GUI. */
    private final JFrame myFrame;

    /**
     * Construct the GUI.
     */
    public GUI() {
        myFrame = new JFrame("ToolBar and MenuBar Example with Observer");
        setup();
    }

    /**
     * Sets up the GUI.
     */
    private void setup() {

        final GUIMenuBar menuBar = new GUIMenuBar(myFrame);
        final GUIToolBar toolBar = new GUIToolBar();
        final PaintPanel textPanel = new PaintPanel();
        
        final ObservableString displayedText = new ObservableString("Welcome");
        displayedText.addObserver(textPanel);
        displayedText.addObserver(menuBar);
        displayedText.addObserver(this);
        // it would be better for some other class to create observer and observers
        
        final Action[] actions = {new HelloAction(displayedText),
                                  new GoodbyeAction(displayedText) };

        for (final Action action : actions) {
            menuBar.createViewMenuButton(action);
            toolBar.createToggleButton(action);
        }

        myFrame.setJMenuBar(menuBar);
        myFrame.add(toolBar, BorderLayout.SOUTH);
        myFrame.add(textPanel, BorderLayout.CENTER);
        myFrame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        myFrame.pack();
        myFrame.setLocationRelativeTo(null);
        myFrame.setVisible(true);
    }

    
    // This class implements Observer
    /**
     * Enables or disables the JFrame's exit button.
     * 
     * {@inheritDoc}
     */
    @Override
    public void update(final Observable theObservable, final Object theArg) {
        if (theObservable instanceof ObservableString) {
            // OK, let's enable the frame's exit button based on the state of the panel's text
            if ("Goodbye".equals(theArg.toString())) {
                myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            } else {
                myFrame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
            }
        }
        
    }

}
