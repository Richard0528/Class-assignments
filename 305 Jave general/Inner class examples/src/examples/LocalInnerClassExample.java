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
 * Tests the use of local inner classes to listen for button events.
 *
 * @author Daniel M. Zimmerman
 * @author Alan Fowler
 * @version 1.2
 */
@SuppressWarnings("serial")
public class LocalInnerClassExample extends JPanel {

    /**
     * The number of buttons to create.
     */
    public static final int NUM_BUTTONS = 7;

    /**
     * Constructs a new LocalInnerClassTest, by creating a bunch of buttons.
     */
    public LocalInnerClassExample() {
        super();
        createButtons();
    }

    /**
     * Creates some buttons.
     */
    private void createButtons() {
        for (int i = 0; i < NUM_BUTTONS; i++) {
            add(createButton(new NamedObject(String.valueOf(i + 1))));
        }
    }

    /**
     * Creates a single button that calls a method on the specified object when
     * pressed.
     *
     * @param theObject The object.
     * @return the button.
     */
    private JButton createButton(final NamedObject theObject) {
        final JButton button = new JButton(theObject.toString());

        /**
         * An inner class that calls doSomething() on the_object.
         */
        class AnActionListener implements ActionListener {

            /**
             * Calls doSomething() on the_object.
             *
             * @param theEvent The event, ignored.
             */
            public void actionPerformed(final ActionEvent theEvent) {
                theObject.doSomething();

                /*
                 * This is 'delegation' - we are getting some other class to do
                 * the work (NamedObject in this case)
                 */
            }
        }

        button.addActionListener(new AnActionListener());

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
        frame.add(new LocalInnerClassExample());
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
