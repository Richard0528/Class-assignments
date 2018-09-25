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
 * @version 2.0
 */
public class HelloAction extends AbstractAction {

    /** A generated serialization ID. */
    private static final long serialVersionUID = -7054698136312723843L;
    
    /** The JPanel to associate with this Action. */
    private final PaintPanel myPanel;

    /**
     * Construct this Action.
     * 
     * @param thePanel a JPanel to associate with this Action.
     */
    public HelloAction(final PaintPanel thePanel) {
        super("Hello");
        myPanel = thePanel;
        putValue(Action.MNEMONIC_KEY, KeyEvent.VK_H);
        putValue(Action.SELECTED_KEY, "anything other than null!");
    }

    @Override
    public void actionPerformed(final ActionEvent theEvent) {
        myPanel.setText((String) getValue(Action.NAME));
        myPanel.repaint();
    }

}
