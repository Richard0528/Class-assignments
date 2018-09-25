/*
 * Nested and Inner Classes 
 * TCSS 305
 */

package examples;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * Tests the use of anonymous inner classes to listen for button events.
 * 
 * @author Daniel M. Zimmerman
 * @author Alan Fowler
 * @version 1.2
 */
@SuppressWarnings("serial")
public class AnonymousInnerClassExample extends JPanel {

    /**
     * The number of buttons to create.
     */
    public static final int NUM_BUTTONS = 7;

    /**
     * Constructs a new AnonymousInnerClassTest, by creating a bunch of buttons.
     */
    public AnonymousInnerClassExample() {
        super();
        createButtons();
    }

    /**
     * Creates some buttons.
     */
    private void createButtons() {
        for (int i = 1; i <= NUM_BUTTONS; i++) {
            add(createButton(new NamedObject(String.valueOf(i))));
        }
    }

    /**
     * Creates a single button that calls a method on the specified object when pressed.
     * 
     * @param theObject
     *            The object.
     * @return the button.
     */
    private JButton createButton(final NamedObject theObject) {
        final JButton button = new JButton(theObject.toString());
        button.addActionListener(new ActionListener() {
            // Anonymous class! A class with no name and no constructor!
            public void actionPerformed(final ActionEvent theEvent) {
                theObject.doSomething();
                /*
                 * This is 'delegation' - we are getting some other class to do
                 * the work (NamedObject in this case)
                 */
            }
        });

        return button;
    }

    /**
     * Creates a frame and adds a bunch of buttons, to illustrate inner classes
     * as listeners.
     * 
     * @param theArgs Command line arguments, ignored.
     */
    public static void main(final String[] theArgs) {
        final JFrame frame = new JFrame("My Frame");
        frame.add(new AnonymousInnerClassExample());
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
