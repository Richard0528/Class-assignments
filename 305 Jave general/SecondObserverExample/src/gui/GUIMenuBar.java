/*
 * TCSS 305 example code
 */

package gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.WindowEvent;
import java.util.Observable;
import java.util.Observer;

import javax.swing.Action;
import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JRadioButtonMenuItem;

/**
 * The JMenuBar for this GUI example.
 * 
 * @author Alan Fowler
 * @version 1.2
 */
public class GUIMenuBar extends JMenuBar implements Observer {

    /** a generated version Id for serialization. */
    private static final long serialVersionUID = -2705926351768986030L;

    /** The Home menu. */
    private final JMenu myHomeMenu = new JMenu("Home");

    /** The View menu. */
    private final JMenu myViewMenu = new JMenu("View");

    /** A button group for the View menu radio buttons. */
    private final ButtonGroup myGroup = new ButtonGroup();

    /** A button to exit the program. */
    private final JMenuItem myQuitButton = new JMenuItem("Quit");

    /**
     * Construct the menu bar.
     * 
     * @param theFrame the JFram which will contain this JMenuBar
     */
    public GUIMenuBar(final JFrame theFrame) {
        super();

        myHomeMenu.setMnemonic(KeyEvent.VK_O);
        myViewMenu.setMnemonic(KeyEvent.VK_V);

        // setup the Quit button
        myQuitButton.setMnemonic(KeyEvent.VK_Q);
        myQuitButton.addActionListener(new ActionListener() {
            public void actionPerformed(final ActionEvent theEvent) {
                theFrame.dispatchEvent(new WindowEvent(theFrame, WindowEvent.WINDOW_CLOSING));
            }
        });
        myQuitButton.setEnabled(false);

        myHomeMenu.add(myQuitButton);

        add(myHomeMenu);
        add(myViewMenu);
    }

    /**
     * Creates a radio button menu item, associates an action with the button,
     * adds the button to a button group, adds the button to the View menu.
     * 
     * @param theAction the Action to associate with the new button being created
     */
    public void createViewMenuButton(final Action theAction) {
        final JRadioButtonMenuItem createdButton = new JRadioButtonMenuItem(theAction);

        myGroup.add(createdButton);
        myViewMenu.add(createdButton);
    }

    // This class implements Observer
    /**
     * Enables or disables the Quit button.
     * 
     * {@inheritDoc}
     */
    @Override
    public void update(final Observable theObservable, final Object theArg) {
        myQuitButton.setEnabled("Goodbye".equals(theArg.toString()));
    }

}
