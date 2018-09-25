/*
 * TCSS 305 example code
 */

package gui;

import java.awt.BorderLayout;
import java.awt.Toolkit;
import javax.swing.Action;
import javax.swing.JFrame;

/**
 * The Graphical User Interface for this example program.
 * 
 * @author Alan Fowler
 * @version 2.1
 */
public class GUI {

    // no instance fields this time!

    /**
     * Construct the GUI.
     */
    public GUI() {
        // no fields to initialize...
        
        // just set up the GUI
        setup(); // could have called this from main instead...
    }

    /**
     * Sets up the GUI.
     */
    private void setup() {
        // This time the JFrame is a local variable instead of a field of the class
        final JFrame guiFrame = new JFrame("ToolBar and MenuBar Example");

        final GUIMenuBar menuBar = new GUIMenuBar(guiFrame);
        final GUIToolBar toolBar = new GUIToolBar();
        final PaintPanel panel = new PaintPanel();

        final Action[] actions = {new HelloAction(panel), new GoodbyeAction(panel)};

        for (final Action action : actions) {
            menuBar.createMenuButton(action);
            toolBar.createToolBarButton(action);
        }

        guiFrame.setJMenuBar(menuBar);

        guiFrame.add(toolBar, BorderLayout.SOUTH);
        guiFrame.add(panel, BorderLayout.CENTER);
        guiFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        guiFrame.pack();
        
        /** A ToolKit. */
        final Toolkit kit = Toolkit.getDefaultToolkit();
        
        guiFrame.setLocation(
            (int) (kit.getScreenSize().getWidth() / 2 - guiFrame.getWidth() / 2),
            (int) (kit.getScreenSize().getHeight() / 2 - guiFrame.getHeight() / 2));
        
        guiFrame.setVisible(true);
    }

}
