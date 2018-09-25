/*
 * TCSS 305 PowerPaint Pencil Action 
 */
package action;

import gui.PowerPaintPanel;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.net.URL;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.ImageIcon;
import tools.Pencil;
import tools.Tool;

/**
 * The Action which occurs when Pencil is selected.
 * 
 * @author richardyang
 * @version 11.9
 */
public class PencilAction extends AbstractAction {

    /** A generated serialization ID. */
    private static final long serialVersionUID = -1536332391064962366L;
    
    /** The JPanel to associate with pencil Action. */
    private final PowerPaintPanel myPanel;

    /** The selected tool. */
    private final Tool myTool;
    
    /**
     * Construct this Action.
     * 
     * @param thePanel a JPanel to associate with pencil Action.
     */
    public PencilAction(final PowerPaintPanel thePanel) {
        super("Pencil");
        myPanel = thePanel;
        final URL url = getClass().getResource("/pencil.gif");
        putValue(Action.MNEMONIC_KEY, KeyEvent.VK_P);
        putValue(Action.SELECTED_KEY, true);
        putValue(Action.SMALL_ICON, new ImageIcon(url));
        myTool = new Pencil();
    }

    @Override
    public void actionPerformed(final ActionEvent theEvent) {
        myPanel.setCurrentTool(myTool);
    }

}
