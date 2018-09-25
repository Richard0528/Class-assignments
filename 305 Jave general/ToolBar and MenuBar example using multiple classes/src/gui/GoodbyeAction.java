/*
 * TCSS 305 example code
 */

package gui;

import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import javax.swing.AbstractAction;
import javax.swing.Action;

/**
 * The Action which occurs when Goodbye is selected.
 * 
 * @author Alan Fowler
 * @version 2.0
 */
public class GoodbyeAction extends AbstractAction {

    /** A generated serialization ID. */
    private static final long serialVersionUID = 5959325849437523778L;
    
    /** The JPanel to associate with this Action. */
    private final PaintPanel myPanel;

    /**
     * Construct this Action.
     * 
     * @param thePanel a JPanel to associate with this Action.
     */
    public GoodbyeAction(final PaintPanel thePanel) {
        super("Goodbye");
        myPanel = thePanel;
        putValue(Action.MNEMONIC_KEY, KeyEvent.VK_G);
        putValue(Action.SELECTED_KEY, true);
    }

    @Override
    public void actionPerformed(final ActionEvent theEvent) {
        myPanel.setText((String) getValue(Action.NAME));
        myPanel.repaint();
    }

}
