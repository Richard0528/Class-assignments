/*
 * TCSS 305 example code
 */

package gui;

import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;

import javax.swing.AbstractAction;
import javax.swing.Action;

/**
 * The Action which occurs when Hello is selected.
 * 
 * @author Alan Fowler
 * @version 1.2
 */
public class HelloAction extends AbstractAction {
    
    /** a generated version Id for serialization. */
    private static final long serialVersionUID = -2108193474363331716L;
    
    /** The ObservableText associated with this Action. */
    private final ObservableString myText;

    /**
     * Construct this Action.
     * 
     * @param theText the ObservableText associated with this Action.
     */
    public HelloAction(final ObservableString theText) {
        super("Hello");
        myText = theText;
        putValue(Action.MNEMONIC_KEY, KeyEvent.VK_H);
        putValue(Action.SELECTED_KEY, true);
    }

    @Override
    public void actionPerformed(final ActionEvent theEvent) {
        myText.setText((String) getValue(Action.NAME));
    }

}
