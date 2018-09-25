/*
 * TCSS 305 example code
 */

package gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.WindowEvent;
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
 * @version 2.0
 */
public class GUIMenuBar extends JMenuBar {

    /** A generated serialization ID. */
    private static final long serialVersionUID = -8420058521162304426L;

    /** The View menu. */
    private final JMenu myViewMenu;

    /** A button group for radio buttons. */
//    private final ButtonGroup myGroup;

    /** A button to exit the program. */
    private final JMenuItem myQuitButton;

    /**
     * Construct the menu bar.
     * 
     * @param theFrame the JFrame which will contain this JMenuBar
     */
    public GUIMenuBar(final JFrame theFrame) {
        super();
        
        myViewMenu = new JMenu("View");
//        myGroup = new ButtonGroup();
        myQuitButton = new JMenuItem("Quit");
        
        setup(theFrame);
    }

    /**
     * Sets up the components of the menu.
     * 
     * @param theFrame the JFrame containing this menu.
     */
    private void setup(final JFrame theFrame) {
        
        final JMenu homeMenu = new JMenu("Home");
        homeMenu.setMnemonic(KeyEvent.VK_O);
        
        myViewMenu.setMnemonic(KeyEvent.VK_V);

        // setup the Quit button
        myQuitButton.setMnemonic(KeyEvent.VK_Q);
        myQuitButton.addActionListener(new ActionListener() {
            public void actionPerformed(final ActionEvent theEvent) {
                
                // Now, how shall we close the application???
                
                /* This will certainly close the program, but is discouraged.
                 * This does not allow the application to close resources properly. */
                //System.exit(0);
                
                /* This works to completely close the program if the GUI does not include
                 *  multiple JFrames, a timer, or other elements running in separate threads.*/
                //theFrame.dispose();
                
                /* This works well even when multiple threads are running. The result here is
                 * the same as clicking on the close button in the JFrame's title bar. */
                theFrame.dispatchEvent(new WindowEvent(theFrame,
                                                       WindowEvent.WINDOW_CLOSING));
            }
        });

        homeMenu.add(myQuitButton);
        add(homeMenu);
        add(myViewMenu);
    }

    /**
     * Creates a radio button menu item, associates an action with the button,
     * adds the button to a button group, adds the button to the View menu.
     * 
     * @param theAction the Action to associate with the new button being
     *            created
     */
    public void createMenuButton(final Action theAction) {
        final JRadioButtonMenuItem createdButton = new JRadioButtonMenuItem(theAction);

//        myGroup.add(createdButton);
        myViewMenu.add(createdButton);
    }

}
