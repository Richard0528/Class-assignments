/*
 * TCSS 305 - Persistent graphics example 
 */

package view;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import tools.CircleTool;
import tools.LineTool;

/**
 * An example to demonstrate handling of persistent graphics.
 * 
 * @author Alan Fowler (acfowler@uw.edu)
 * @version 1.1
 */
public class ShapeGUI {

    /** The top level window for this application. */
    private final JFrame myFrame;
    
    /** A panel for drawing shapes. */
    private final DrawingPanel myPanel;
    
    /** A tool for drawing lines. */
    private final LineTool myLineTool;
    
    /** A tool for drawing circles. */
    private final CircleTool myCircleTool;

    /**
     * Initialize the GUI.
     */
    public ShapeGUI() {
        myFrame = new JFrame();
        myPanel = new DrawingPanel();
        myLineTool = new LineTool();
        myCircleTool = new CircleTool();
    }

    /** Sets up the elements of the GUI. */ 
    public void start() {
        myFrame.add(myPanel, BorderLayout.CENTER);

        final JRadioButton b1 = new JRadioButton("lines", true);
        final JRadioButton b2 = new JRadioButton("circles", false);

        // Anonymous inner class listeners (or lambda expressions) could be used here instead
        b1.addActionListener(new LineListener());
        b2.addActionListener(new CircleListener());
        myPanel.setCurrentTool(myLineTool);

        final JPanel p = new JPanel();
        p.add(b1);
        p.add(b2);
        final ButtonGroup group = new ButtonGroup();
        group.add(b1);
        group.add(b2);
        myFrame.add(p, BorderLayout.NORTH);

        myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        myFrame.pack();
        myFrame.setVisible(true);
    }



    /**
     * A listener for the 'lines' button.
     * 
     * @author Alan Fowler (acfowler@uw.edu)
     * @version 1.1
     */
    public class LineListener implements ActionListener {
 
        @Override
        public void actionPerformed(final ActionEvent theEvent) {
            myPanel.setCurrentTool(myLineTool);
        }
    }
    
    /**
     * A listener for the 'circles' button.
     * 
     * @author Alan Fowler (acfowler@uw.edu)
     * @version 1.1
     */
    public class CircleListener implements ActionListener {
        
        @Override
        public void actionPerformed(final ActionEvent theEvent) {
            myPanel.setCurrentTool(myCircleTool);
        }
    }

}
